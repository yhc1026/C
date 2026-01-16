#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;
pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

void *producer(void *arg)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&not_full, &mutex);
        }
        buffer[in] = i;
        printf("%d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        while (count == 0)
        {
            pthread_cond_wait(&not_empty, &mutex);
        }
        int t = buffer[out];
        printf("%d\n", buffer[out]);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t producer_thread1, producer_thread2, producer_thread3, consumer_thread1, consumer_thread2, consumer_thread3, consumer_thread4;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&producer_thread1, NULL, producer, NULL);
    pthread_create(&producer_thread2, NULL, producer, NULL);
    pthread_create(&producer_thread3, NULL, producer, NULL);
    pthread_create(&consumer_thread1, NULL, consumer, NULL);
    pthread_create(&consumer_thread2, NULL, consumer, NULL);
    pthread_create(&consumer_thread3, NULL, consumer, NULL);
    pthread_create(&consumer_thread4, NULL, consumer, NULL);

    pthread_join(producer_thread1, NULL);
    pthread_join(producer_thread2, NULL);
    pthread_join(producer_thread3, NULL);
    pthread_join(consumer_thread1, NULL);
    pthread_join(consumer_thread2, NULL);
    pthread_join(consumer_thread3, NULL);
    pthread_join(consumer_thread4, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);
    return 0;
}