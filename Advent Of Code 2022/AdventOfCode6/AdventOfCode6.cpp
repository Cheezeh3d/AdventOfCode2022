
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool checkForDup(char input[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] == input[j]) {
                return true;
            }
        }
    }
    return false;
}

void partOne() {
    cout << "PART ONE: " << endl;
    fstream inputFile;
    inputFile.open("input.txt", ios::in);

    if (inputFile.is_open()) {
        char input[5] = "";
        int count = 4;
        inputFile.read(input, 4);

        if (!checkForDup(input, 4)) {
            cout << input;
            return;
        }
        while (!inputFile.eof()) {
            //shift
            for (int i = 0; i < 3; i++) {
                input[i] = input[i + 1];
            }
            input[3] = inputFile.get();
            count++;
            if (!checkForDup(input, 4)) {
                cout << count;
                return;
            }
        }
        inputFile.close();
    }
    else {
        cout << "ERROR OPENING FILE" << endl;
    }
    return;
}

void partTwo() {
    cout << endl << "PART TWO: " << endl;
    fstream inputFile;
    inputFile.open("input.txt", ios::in);

    if (inputFile.is_open()) {
        char input[14] = "";
        int count = 14;
        inputFile.read(input, 14);

        if (!checkForDup(input, 14)) {
            cout << input;
            return;
        }
        while (!inputFile.eof()) {
            //shift
            for (int i = 0; i < 13; i++) {
                input[i] = input[i + 1];
            }
            input[13] = inputFile.get();
            count++;
            if (!checkForDup(input, 14)) {
                cout << count;
                return;
            }
        }
        inputFile.close();
    }
    else {
        cout << "ERROR OPENING FILE" << endl;
    }
    return;
}


int main()
{
    partOne();

    partTwo();
    return 0;
}