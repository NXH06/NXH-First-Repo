#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Init mutex and conditions
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;
int reader_amt = 0;
int writer_waiting = 0; // amount of writers queueing
int writer_active = 0; // whether there is an active writer
const int total_reader = 6;
const int total_writer = 2;
const int max_reader = 3;
/* Engaging conditions 
pthread_cond_signal: restarts 1 blocked thread
pthread_cond_broadcast: restarts all blocked threads */
void begin_read() {
    pthread_mutex_lock(&mutex);
    while (writer_active || reader_amt == max_reader) {
        pthread_cond_wait(&can_read, &mutex); // must put in order (cond, mutex)
        // printf("(Max amount of readers reached by thread [%lx])\n", pthread_self());
    }
    reader_amt++;
    printf("Thread %lx enter read section... (r: %d/%d)\n", pthread_self(), reader_amt, max_reader);
    if (reader_amt == max_reader) {
        printf("(Max amount of readers reached by thread [%lx])\n", pthread_self());
    }
    pthread_mutex_unlock(&mutex);
}
void end_read() {
    pthread_mutex_lock(&mutex);
    reader_amt--;
    printf("Thread %lx exit read section... (r: %d/%d)\n", pthread_self(), reader_amt, max_reader);
    if (reader_amt == 0) {
        pthread_cond_signal(&can_write);
    }
    pthread_cond_broadcast(&can_read);
    pthread_mutex_unlock(&mutex);
}
void begin_write() {
    pthread_mutex_lock(&mutex); // since begin/end_write now also modify shared variables, mutex is necessary
    writer_waiting++;
    while (writer_active || reader_amt > 0) {
        pthread_cond_wait(&can_write, &mutex);
    }
    writer_waiting--;
    writer_active = 1;
    printf("Thread %lx enter write section... (w: 1/1)\n", pthread_self());
    pthread_mutex_unlock(&mutex);
}
void end_write() {
    pthread_mutex_lock(&mutex);
    writer_active = 0;
    printf("Thread %lx exit write section... (w: 0/1)\n", pthread_self());
    if (writer_waiting > 0) {
        pthread_cond_signal(&can_write); // tell 1 writer to join
    }
    else {
        pthread_cond_broadcast(&can_read); // tell all readers to join
    }
    pthread_mutex_unlock(&mutex);
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
    // No initialization is necessary here since the conditions have been defined statically
    pthread_t reader_tid[total_reader];
    pthread_t writer_tid[total_writer];
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
    // Free resources
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&can_read);
    pthread_cond_destroy(&can_write);
    return 0;
}