
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NBC 2
#define NBP 2

#define BUFFER_SIZE 20
#define boolean int
#define true 1
#define false 0

int count, in, out;
const int total_producer = 4;
const int total_consumer = 4;
boolean buffer[BUFFER_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t products = PTHREAD_COND_INITIALIZER;
pthread_cond_t freeslots = PTHREAD_COND_INITIALIZER;

pthread_cond_t sleepcond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t sleepmutex = PTHREAD_MUTEX_INITIALIZER;

int nbdisplay = 0;


void init() {
    int i;
    count = in = out = 0;
    for (i=0;i<BUFFER_SIZE;i++) buffer[i] = false;
    srand(time(NULL));
}
void display() {
    int i;
    printf("-");
    //for (i=0;i<BUFFER_SIZE;i++) printf("--");
    //printf("\n");
    printf("|");
    for (i=0;i<BUFFER_SIZE;i++) {
        if (buffer[i]) printf("x");
        else printf(" ");
        printf("|");
    }
    printf("%d", nbdisplay++);
    //printf("\n");
    //printf("-");
    //for (i=0;i<BUFFER_SIZE;i++) printf("--");
    //printf("\n");
    printf("\n");
}
void sleep() {
    struct timespec t;
    t.tv_sec = time(0) + (rand() % 2) + 1;
    t.tv_nsec = 0;
    pthread_mutex_lock(&sleepmutex);
    pthread_cond_timedwait(&sleepcond, &sleepmutex, &t);
    pthread_mutex_unlock(&sleepmutex);
}
void produce () {
    pthread_mutex_lock(&mutex);
    while (count == BUFFER_SIZE) {
        pthread_cond_signal(&products);
        pthread_cond_wait(&freeslots, &mutex);
    }
    //printf("Thread %lx producing...\n", pthread_self());
    buffer [in] = true;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    display();
    pthread_mutex_unlock(&mutex);
}
void consume () {
    pthread_mutex_lock(&mutex);
    while (count == 0) {
        pthread_cond_signal(&freeslots);
        pthread_cond_wait(&products, &mutex);
    }
    //printf("Thread %lx consuming...\n", pthread_self());
    buffer[out] = false;
    out = (out + 1) % BUFFER_SIZE;
    count--;
    display();
    pthread_mutex_unlock(&mutex);
}
void *consumer(void *threadid) {
    while (1) {
        consume();
        sleep();
    }
}
void *producer(void *threadid) {
    while (1) {
        produce();
        sleep();
    }
}

int main() {
    srand(time(NULL));
    init();
    pthread_t reader_tid[total_consumer];
    pthread_t writer_tid[total_producer];
    for (int i = 0; i < total_consumer; i++) {
        pthread_create(&reader_tid[i], NULL, consumer, NULL);
    }
    for (int i = 0; i < total_producer; i++) {
        pthread_create(&writer_tid[i], NULL, producer, NULL);
    }
    for (int i = 0; i < total_consumer; i++) {
        pthread_join(reader_tid[i], NULL);
    }
    for (int i = 0; i < total_producer; i++) {
        pthread_join(writer_tid[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&products);
    pthread_cond_destroy(&freeslots);
    return 0;
}



