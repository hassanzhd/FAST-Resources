#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    ifstream inputFile;
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                          'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};  // keys for all alphabets, which are found
    char original[80], formatted[80];

    inputFile.open("P3_input.txt");
    inputFile.getline(original, 80);
    strcpy(formatted, original);

    for (int i = 0, j = 0; original[i] != '\0'; i++) {
        if (original[i] == ' ') {
            continue;
        } else {
            if (alphabets[original[i] - 97] == '1') { /* 97 is the ascii value of lowercase 'a' hence
                                                    subtracting it with orginal string 's i' th character
                                                    gives us the key of alphabet whether is present or not */
                formatted[i] = '-';
            } else {
                alphabets[original[i] - 97] = '1'; /* if occurence is not found before we keep the
                                                    character as it is in string and mark key as '1' */
            }
        }
    }

    cout << "Formatted string is: ";

    for (int i = 0; formatted[i] != '\0'; i++) {
        cout << formatted[i];
    }

    ofstream outputFile;
    outputFile.open("P3_output.txt");
    outputFile << formatted;
    outputFile.close();

    return 0;
}