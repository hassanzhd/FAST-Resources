#ifndef SELECTION_H
#define SELECTION_H
#include <fcntl.h>
#include <math.h>
#include <omp.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "data.h"

/* Selection sort sequential implementation */

void selectionSortSequential() {
    insertElements();

    printf("\nOriginal Array:\n");
    for (int i = 0, j = numberOfElements; i < numberOfElements; i++, j--) {
        printf("%d ", selectionDataArray[i]);
    }
    printf("\n");

    printf("\n===============================\n");
    printf("SORTING USING SEQUENTIAL METHOD\n");
    printf("===============================\n");

    clock_t start;
    start = clock();

    for (int i = 0; i < numberOfElements; i++) {
        int temp = 0;
        int min = i;

        for (int j = i + 1; j < numberOfElements; j++) {
            if (selectionDataArray[j] < selectionDataArray[min]) {
                min = j;
            }
        }

        temp = selectionDataArray[i];
        selectionDataArray[i] = selectionDataArray[min];
        selectionDataArray[min] = temp;
    }

    start = clock() - start;
    printf("\nTime taken for sorting using OpenMP: %f seconds\n", (float)start / CLOCKS_PER_SEC);
}

/* Selection sort thread implementation */

#define THREAD_MAX 4  // maximum number of threads depending upon cores

int selectionThreadNumber = 0;  // helps in partitioning array (start/end values)
int *selectionThreadArr;        /* for minimum calculation as no inner loop exists hence array must be 
                        in sync with main loop. Increments with every iteration */
int boundary = 0;               /* helps in new array size calculation with every iteration  */
int min = 0;                    /* index of minimum value */

void *minimumThread(void *__args) {
    int i, start = selectionThreadNumber++;
    float factor = ceil((float)boundary / THREAD_MAX); /* 
        factor is used because with array size decreasing and partitioning being done, invalid 
        number can occur in start/ end values. 
     */
    for (i = start * (factor); (i < (start + 1) * factor) && i < boundary; i++) {
        if (selectionThreadArr[i] < selectionThreadArr[min]) {
            min = i;
        }
    }
}

void selectionSortThread() {
    pthread_t threads[THREAD_MAX];

    insertElements();

    printf("\n====================\n");
    printf("SORTING USING THREAD\n");
    printf("====================\n");

    clock_t start;
    start = clock();

    selectionThreadArr = selectionDataArray;
    boundary = numberOfElements;
    for (int i = 0; i < numberOfElements; i++) {
        for (int i = 0; i < THREAD_MAX; i++) {
            // creating THREAD-MAX number of threads
            pthread_create(&threads[i], NULL, minimumThread, (void *)NULL); /* 
                In selection sort costy operation is finding index of minimum values hence we
                used minimumThread() inside pthread_create()
             */
        }
        // joining all THREAD_MAX threads
        for (int i = 0; i < THREAD_MAX; i++) {
            pthread_join(threads[i], NULL);
        }
        int temp = *(selectionDataArray + i);
        selectionDataArray[i] = selectionThreadArr[min];
        selectionThreadArr[min] = temp;

        // updating/ resetting values
        selectionThreadNumber = 0;
        selectionThreadArr++;
        boundary--;
        min = 0;
    }

    start = clock() - start;
    printf("\nTime taken for sorting using threads: %f seconds\n", (float)start / CLOCKS_PER_SEC);
}

void selectionSortOMP() {
    insertElements();

    printf("\n=================\n");
    printf("SORTING USING OMP\n");
    printf("=================\n");

    clock_t start;
    start = clock();

#pragma omp parallel
    {
        omp_set_nested(1);

#pragma omp for
        for (int i = 0; i < numberOfElements; i++) {
#pragma omp parallel
            {
                int temp = 0;
                int min = i;
#pragma omp for
                for (int j = i + 1; j < numberOfElements; j++) {
                    if (selectionDataArray[j] < selectionDataArray[min]) {
                        min = j;
                    }
                }
                temp = selectionDataArray[i];
                selectionDataArray[i] = selectionDataArray[min];
                selectionDataArray[min] = temp;
            }
        }
    }
    start = clock() - start;
    printf("\nTime taken for searching: %f seconds\n", (float)start / CLOCKS_PER_SEC);
}

/* 
    clock_t start;
    start = clock();
    start = clock() - start;
    printf("Time taken for searching: %f seconds\n", (float)start / CLOCKS_PER_SEC);
*/

#endif