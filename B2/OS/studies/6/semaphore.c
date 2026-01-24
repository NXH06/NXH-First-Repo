#include <stdio.h>
#include <stdlib.h>
#include <time.h> // stdlib and time for seed randomization
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
/* Rules:
1. There can only be a maximum of [max_reader] readers and 1 writer at any moment
2. If there are readers, writers cannot join and vice versa
3. If there is no reading or writing happening, either a reader or a writer can join */

sem_t mutex; // for protecting shared variables
sem_t read_lock; // for blocking readers
sem_t write_lock; // for blocking writers
int reader_amt = 0; // amount of threads currently reading
const int total_reader = 6;
const int total_writer = 2;
const int max_reader = 3; // max allowed amount of readers at any moment

/* Engaging semaphore locks. See: "man7.org/linux/man-pages"
sem_wait(): if > 0, decrements semaphore. if == 0, waits until it's > 0
sem_post(): increments semaphore. if then > 0, wake up a blocked thread/process and then lock semaphore.
WARNING: Never block in a critical section without releasing the section, or:
Never block one semaphore while holding another semaphore that the thread unblocking the first semaphore needs.*/
void begin_read() {
    sem_wait(&read_lock); // get read_lock before getting mutex
    sem_wait(&mutex);
    reader_amt++;
    if (reader_amt == 1) {
        sem_wait(&write_lock); // if there is 1 reader, block writing
    }
    
    printf("Thread %lx enter read section... (r: %d/%d)\n", pthread_self(), reader_amt, max_reader);
    if (reader_amt == max_reader) {
        printf("(Max amount of readers reached by thread [%lx])\n", pthread_self());
    }
    sem_post(&mutex);
}
void end_read() {
    sem_wait(&mutex);
    reader_amt--;
    if (reader_amt == 0) { // if there are no readers, unblock writing
        sem_post(&write_lock);
    }
    printf("Thread %lx exit read section... (r: %d/%d)\n", pthread_self(), reader_amt, max_reader);
    sem_post(&mutex);
    sem_post(&read_lock); // release read_lock only after releasing mutex
    
}
void begin_write() {
    sem_wait(&write_lock);
    printf("Thread %lx enter write section... (w: 1/1)\n", pthread_self());
}
void end_write() {
    sem_post(&write_lock);
    printf("Thread %lx exit write section... (w: 0/1)\n", pthread_self());
}
// read and write functions
void *reader (void* arg) {
    begin_read();
    for (int i = 0; i < rand() % 3 + 1; i++) { // read data from 1 to 3 times
        printf("\t Reader thread %lx read data\n", pthread_self());
        usleep(200000); // from unistd.h: sleep 250ms
    }
    end_read();
}
void *writer (void* arg) {
    begin_write();
    for (int i = 0; i < rand() % 3 + 2; i++) { // write data from 2 to 4 times
        printf("\tWriter thread %lx write data\n", pthread_self());
        usleep(100000);
    }
    end_write();
}

int main() {
    printf("Simulation of writing and reading on critical sections, with semaphores implemented.\n");
    printf("Readers: %d (max %d), writers: %d (max 1).\n\n", total_reader, max_reader, total_writer);
    pthread_t reader_tid[total_reader];
    pthread_t writer_tid[total_writer];
    sem_init(&mutex, 0, 1);
    sem_init(&read_lock, 0, max_reader); // if max allowed amount of readers reached, block reading
    sem_init(&write_lock, 0, 1);
    srand(time(NULL)); // take the current time as the seed
    for (int i = 0; i < total_reader; i++) {
        pthread_create(&reader_tid[i], NULL, reader, NULL);
    }
    for (int i = 0; i < total_writer; i++) {
        pthread_create(&writer_tid[i], NULL, writer, NULL);
    }
    for (int i = 0; i < total_reader; i++) {
        pthread_join(reader_tid[i], NULL);
    }
    for (int i = 0; i < total_writer; i++) {
        pthread_join(writer_tid[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&read_lock);
    sem_destroy(&write_lock);
    return 0;
}