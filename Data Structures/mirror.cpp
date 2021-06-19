#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int row = 3, column = 4;
    int arr[row][column] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int a;
    for (int i = 0, j = 0, k = column - 1; i < row;) {
        if (j == (column / 2)) {
            i++;
            j = 0;
            k = column - 1;
            continue;
        }
        cout << "i= " << i << endl;
        cout << "j= " << j << endl;
        cout << "k= " << k << endl;
        cout << "Before: ";
        cout << arr[i][j] << " " << arr[i][k] << endl;
        a = arr[i][j];
        arr[i][j] = arr[i][k];
        arr[i][k] = a;
        cout << "After: ";
        cout << arr[i][j] << " " << arr[i][k] << endl;
        j++;
        k--;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
