

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int checkForDuplicate(string& theString) {
    //cout << temp.length() << endl;
    for (int i = 0; i < (theString.length() / 2); i++) {
        for (int j = (theString.length() / 2); j < theString.length(); j++) {
            if (theString[i] == theString[j]) {
                if (islower(theString[i])) {
                    //cout << theString << " " << theString[i] << " " << (theString[i] - 96) << endl;
                    return (theString[i] - 96);
                }
                else if (isupper(theString[i])) {
                    //cout << theString << " " << theString[i] << " " << (theString[i] - 38) << endl;
                    return (theString[i] - 38);
                }
            }
        }
    }
}

int checkForAllThree(string& first, string& second, string& third) {
    for (int i = 0; i < first.length(); i++) {
        for (int j = 0; j < second.length(); j++) {
            for (int k = 0; k < third.length(); k++) {
                if (first[i] == second[j] && second[j] == third[k]) {
                    if (islower(first[i])) {
                        cout << first << " " << first[i] << " " << (first[i] - 96) << endl;
                        return (first[i] - 96);
                    }
                    else if (isupper(first[i])) {
                        cout << first << " " << first[i] << " " << (first[i] - 38) << endl;
                        return (first[i] - 38);
                    }
                }
            }
        }
    }
}


int main()
{
    fstream newFile;
    string temp;
    int priority = 0;
    newFile.open("input.txt", ios::in);

    if (newFile.is_open()) {
        while (getline(newFile, temp)) {
            priority += checkForDuplicate(temp);
        }
        cout << priority << endl;
    }
    else {
        cout << "ERROR OPENING FILE" << endl;
    }
    newFile.close();



    //second part
    newFile.open("input.txt", ios::in);
    string first;
    string second;
    string third;
    priority = 0;
    if (newFile.is_open()) {
        while (getline(newFile, first)) {
            getline(newFile, second);
            getline(newFile, third);
            priority += checkForAllThree(first, second, third);
        }
        cout << priority << endl;
    }
    else {
        cout << "ERROR OPENING FILE" << endl;
    }
    newFile.close();
    return 0;
}