#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numberOfElements = 0;  // total number of array elements
int range = 0;             // total range of array elements
int *selectionDataArray;   // Array for selection sort sequential implementation

void insertElements() {
    srand(time(0));
    for (int i = 0, j = numberOfElements; i < numberOfElements; i++, j--) {
        selectionDataArray[i] = rand() % range;
    }
}

void makeArray() {
    printf("\nEnter number of elements: ");
    scanf("%d", &numberOfElements);
    selectionDataArray = (int *)calloc(numberOfElements, sizeof(int));

    printf("Enter range: ");
    scanf("%d", &range);
}

void cleanArray() {
    free(selectionDataArray);
}

#endif