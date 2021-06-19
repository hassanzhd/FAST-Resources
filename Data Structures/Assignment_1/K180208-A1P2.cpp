#include <fstream>
#include <iostream>
using namespace std;

class Maze {
    int rows, column, count;
    ifstream inputFile;
    ofstream outputFile;
    int **array;

   public:
    Maze() {
        char digit;
        count = 0;
        inputFile.open("P2_input.txt");
        inputFile >> rows >> column;

        if (rows > 0 && column < 10) {
            array = new int *[rows];
            for (int i = 0; i < rows; i++) {
                array[i] = new int[column];
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < column; j++) {
                    inputFile >> digit;
                    array[i][j] = digit - '0'; /* as there is no seperator hence input is taken in char 
                                            and subtracted it with ascii value of 0 which gives int value */
                }
            }
            findPath(array, 0, 0);
        } else {
            outputFile.open("P2_output.txt");
            outputFile << "INVALID INPUTS.";
            outputFile.close();
        }
    }

    bool validate(int **_arr, int _x, int _y) {
        if ((_x >= 0 && _x < rows) && (_y >= 0 && _y < column) && _arr[_x][_y] == 0) {
            return true;
        }
        return false;
    }  // this function validates if the piece (row & column) being checked is a valid one

    bool findPath(int **_arr, int _x, int _y) {
        if (_x == rows - 1 && _y == column - 1) {
            count++;
        }  // checks if destination is reached

        if (validate(_arr, _x, _y) == true) {
            if (findPath(_arr, _x, _y + 1) == true) {
                return true;
            }  // right move

            if (findPath(_arr, _x + 1, _y) == true) {
                return true;
            }  // down move
        }
        return false;
    }

    ~Maze() {
        if (array != NULL) {
            for (int i = 0; i < rows; i++) {
                delete[] array[i];
            }
            delete array;

            outputFile.open("P2_output.txt");
            if (count == 0) {
                outputFile << "No Path";
            } else {
                outputFile << count;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Maze m;
    return 0;
}