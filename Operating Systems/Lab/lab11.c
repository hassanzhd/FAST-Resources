#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

sem_t semaphore;
int arr[] = {1, 2, 3};

void *reader(void *__args) {
    while (1) {
        sem_wait(&semaphore);  // non zero value => -1 , allows to enter critical section
                               // if zero value, then waits until, semaphore is 1

        for (int i = 0; i < 3; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        sem_post(&semaphore);  // increments the semaphore value by 1
    }

    return NULL;
}

void *writer(void *__args) {
    while (1) {
        sem_wait(&semaphore);

        for (int i = 0; i < 3; i++) {
            arr[i] += 1;
        }
        sem_post(&semaphore);
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    sem_init(&semaphore, 0, 1);
    pthread_t p1, p2;

    pthread_create(&p1, NULL, reader, NULL);
    pthread_create(&p2, NULL, writer, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    sem_destroy(&semaphore);
    return 0;
}

// Race condition => two different processes are accessing critical section (a single resource) at the same time
// sem_init, sem_wait, sem_post, sem_destroy