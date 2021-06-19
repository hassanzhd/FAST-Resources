#include <stdio.h>

#include "../includes/selection.h"

void selectionAnalysis() {
    printf("\n\n==============\n");
    printf("SELECTION SORT\n");
    printf("==============\n");
    selectionSortSequential();
    selectionSortThread();
    selectionSortOMP();
}

int main(int argc, char const *argv[]) {
    makeArray();
    selectionAnalysis();
    cleanArray();
    return 0;
}
