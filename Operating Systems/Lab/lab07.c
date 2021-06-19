#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Q1: calculate two different sum of tables and then display the result but concurrently

struct values {
    int factor1;
    int factor2;
    int firstSum;
    int secondSum;
};

void *threadFunction(void *__args) {
    struct values *temp = (struct values *)__args;
    int factor = temp->factor1;
    for (int i = 1; i <= 10; i++) {
        temp->firstSum = temp->firstSum + (factor * i);
    }
}

int main() {
    pthread_t threadID;

    struct values v;
    v.factor1 = 1;
    v.factor2 = 2;
    v.firstSum = 0;
    v.secondSum = 0;

    pthread_create(&threadID, NULL, threadFunction, &v);

    int factor = v.factor2;
    for (int i = 1; i <= 10; i++) {
        v.secondSum = v.secondSum + (factor * i);
    }

    pthread_join(threadID, NULL);

    printf("%d %d\n", v.firstSum, v.secondSum);

    return 0;
}