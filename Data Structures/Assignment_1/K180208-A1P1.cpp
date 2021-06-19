#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Puzzle {
    int n, m, noOfQueries;
    char **words, **mWords, **invert, **mInvert;
    string *queries, *postions;
    ifstream inputFile;
    ofstream outputFile;

   public:
    Puzzle() {
        inputFile.open("P1_input.txt");
        inputFile >> n >> m;

        words = new char*[n];    // original array (right search)
        mWords = new char*[n];   // mirror original array (left search)
        invert = new char*[m];   // transposed array (down search)
        mInvert = new char*[m];  // mirror transposed array (up search)

        for (int i = 0; i < n; i++) {
            words[i] = new char[m];
            mWords[i] = new char[m];
        }

        for (int i = 0; i < m; i++) {
            invert[i] = new char[n];
            mInvert[i] = new char[n];
        }

        for (int i = 0, j = 0; i <= n; i++, j++) {
            if (i == 0) {
                inputFile.getline(words[j], m + 1);
                j = -1;
                continue;
            } /* this condition was added as it was taking empty value
                instead of string on next line so 0th iteration was skipped */
            inputFile.getline(words[j], m + 1);
            words[j][m] = '\0';
        }  // loop for puzzle input from file

        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                invert[j][i] = words[i][j];
            }
            invert[i][n] = '\0';
        }  // loop for transpose array (down search)

        for (int i = 0, j = 0, k = m - 1; i < n;) {
            if (j > (m / 2)) {
                mWords[i][m] = '\0';
                i++;
                j = 0;
                k = m - 1;
                continue;
            } else {
                mWords[i][j] = words[i][k];
                mWords[i][k] = words[i][j];
            }

            j++;
            k--;
        }  // loop for mirror of original array (left search)
        for (int i = 0, j = 0, k = n - 1; i < m;) {
            if (j > (n / 2)) {
                mInvert[i][n] = '\0';
                i++;
                j = 0;
                k = n - 1;
                continue;
            } else {
                mInvert[i][j] = invert[i][k];
                mInvert[i][k] = invert[i][j];
            }
            j++;
            k--;
        }  // loop for mirror transpose array (up search)

        inputFile >> noOfQueries;
        if (noOfQueries <= 10) {
            queries = new string[noOfQueries];
            postions = new string[noOfQueries];

            for (int i = 0, j = 0; i <= noOfQueries; i++, j++) {
                if (i == 0) {
                    getline(inputFile, queries[j]);
                    j = -1;
                    continue;
                }
                getline(inputFile, queries[j]);
            }  // loop for query input from file

            solve(words, mWords, invert, mInvert);
        } else {
            outputFile.open("P1_output.txt");
            outputFile << "QUERIES OUT OF RANGE";
            outputFile.close();
        }
        inputFile.close();
    }

    bool rightSearch(char** _oArray, string _query, int _iteration) {
        for (int i = 0; i < n; i++) {
            int found = ((string)_oArray[i]).find(_query);
            if (found != string::npos) {
                cout << _query << " found at: " << i << found << endl;  // i is the row and found is the column
                postions[_iteration] = to_string(i) + to_string(found);
                return true;
            } else {
                continue;
            }
        }
        return false;
    }

    bool downSearch(char** _iArray, string _query, int _iteration) {
        for (int i = 0; i < m; i++) {
            int found = ((string)_iArray[i]).find(_query);
            if (found != string::npos) {
                cout << _query << " found at: " << found << i << endl;  // found and i are interchaged compared to above as transpose is taken
                postions[_iteration] = to_string(found) + to_string(i);
                return true;
            } else {
                continue;
            }
        }
        return false;
    }

    bool leftSearch(char** _mOArray, string _query, int _iteration) {
        for (int i = 0; i < n; i++) {
            int found = ((string)_mOArray[i]).find(_query);
            if (found != string::npos) {
                found = (m - 1) - found; /* (m-1 - found): -1 for index and whole is formula for 
                                            index acc to original array (due to mirror) */
                cout << _query << " found at: " << i << found << endl;
                postions[_iteration] = to_string(i) + to_string(found);
                return true;
            } else {
                continue;
            }
        }
        return false;
    }

    bool upSearch(char** _mIArray, string _query, int _iteration) {
        for (int i = 0; i < m; i++) {
            int found = ((string)_mIArray[i]).find(_query);
            if (found != string::npos) {
                found = (n - 1) - found; /* (m-1 - found): -1 for index and whole is formula for 
                                            index acc to original array (due to mirror) found and i 
                                            are interchaged compared to above as transpose is taken */
                cout << _query << " found at: " << found << i << endl;
                postions[_iteration] = to_string(found) + to_string(i);
                return true;
            } else {
                continue;
            }
        }
        return false;
    }

    void solve(char** _oArray, char** _mOArray, char** _iArray, char** _mIArray) {
        bool validation;
        for (int i = 0; i < noOfQueries; i++) {
            validation = rightSearch(_oArray, queries[i], i);
            if (validation != true) {
                validation = downSearch(_iArray, queries[i], i);
            }

            if (validation != true) {
                validation = leftSearch(_mOArray, queries[i], i);
            }

            if (validation != true) {
                validation = upSearch(_mIArray, queries[i], i);
            }

            if (validation == false) {
                postions[i] = "n";
            }
        }
    }

    ~Puzzle() {
        if (noOfQueries <= 10) {
            outputFile.open("P1_output.txt");
            for (int i = 0; i < noOfQueries; i++) {
                outputFile << postions[i] << "\n";
            }
            outputFile.close();
        }

        if (words != NULL) {
            for (int i = 0; i < n; i++) {
                delete[] words[i];
                delete[] mWords[i];
            }

            for (int i = 0; i < m; i++) {
                delete[] invert[i];
                delete[] mInvert[i];
            }

            delete[] queries;
            delete[] postions;
            delete[] words;
            delete[] mWords;
            delete[] invert;
            delete[] mInvert;
        }
    }
};

int main(int argc, char const* argv[]) {
    Puzzle p;
    return 0;
}
