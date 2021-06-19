#include <math.h>
#include <iostream>
using namespace std;

void merge(int original[], int left[], int right[], int llength, int rlength) {
    int i = 0, j = 0, k = 0;
    while (i < llength && j < rlength) {
        if (left[i] <= right[j]) {
            original[k] = left[i];
            k++;
            i++;
        } else {
            original[k] = right[j];
            k++;
            j++;
        }
    }

    while (i < llength) {
        original[k] = left[i];
        i++;
        k++;
    }

    while (j < rlength) {
        original[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int n) {
    if (n < 2) {
        return;
    } else {
        int mid;
        if (n % 2 == 0) {
            mid = n / 2;
        } else {
            mid = n / 2 + 1;
        }

        int leftArr[mid];
        int rightArr[n - mid];

        for (int i = 0; i < mid; i++) {
            leftArr[i] = A[i];
        }

        for (int i = mid; i < n; i++) {
            rightArr[i - mid] = A[i];
        }
        mergeSort(leftArr, mid);
        mergeSort(rightArr, n - mid);
        merge(A, leftArr, rightArr, mid, n - mid);
    }
}

int main(int argc, char const *argv[]) {
    int a[5] = {5, 4, 3, 2, 1};
    mergeSort(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }

    return 0;
}