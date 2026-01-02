#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int n_reader = 0; // amount of readers
sem_t mutex;
sem_t write_lock;

void begin_read() {
    sem_wait(&mutex);
    if (n_reader == 0) {
        sem_wait(&write_lock);
    }
    n_reader++;
    sem_post(&mutex);
    printf("Thread %lx enter read section...\n", pthread_self());
}
void end_read() {
    sem_wait(&mutex);
    n_reader--;
    if (n_reader == 0) {
        sem_wait(&write_lock);
    }
    sem_post(&mutex);
    printf("Thread %lx exit read section...\n", pthread_self());
}
void begin_write() {
    sem_wait(&write_lock);
    printf("Thread %lx enter write section...\n", pthread_self());
}
void end_write() {
    sem_wait(&write_lock);
    printf("Thread %lx exit write section...\n", pthread_self());
}
void reader (void* arg) {
    begin_read();
    for (int i = 0; i < 10; i++) {
        printf("Thread %lx read data\n", pthread_self());
    }
    end_read();
}
void writer (void* arg) {
    begin_write();
    for (int i = 0; i < 10; i++) {
        printf("Thread %lx write data\n", pthread_self());
    }
    end_write();
}
int main() {
    int reader_tid[3];
    int writer_tid;
    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);
    for (int i = 0; i < 3; i++) {
        pthread_create(&reader_tid[i], NULL, reader, NULL);
    }
    pthread_create(&writer_tid, NULL, writer, NULL);
    for (int i = 0; i < 3; i++) {
        pthread_join(&reader_tid[i], NULL);
    }
    pthread_join(&writer_tid, NULL);
    return 0;
}