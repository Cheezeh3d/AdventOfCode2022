#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream newFile;
    int currElf = 0;
    int maxElf = 0;
    int secElf = 0;
    int thirdElf = 0;

    newFile.open("Calories.txt", ios::in); //open a file to perform read operation using file object
    if (newFile.is_open()) { //checking whether the file is open
        string tp;
        while (getline(newFile, tp)) { //read data from file object and put it into string.
            if (tp == "") {
                if (maxElf < currElf) {
                    thirdElf = secElf;
                    secElf = maxElf;
                    maxElf = currElf;
                }
                else if (secElf < currElf) {
                    thirdElf = secElf;
                    secElf = currElf;
                }
                else if (thirdElf < currElf) {
                    thirdElf = currElf;
                }
                currElf = 0;
            }
            else {
                currElf += stoi(tp);
            }
        }
        cout << maxElf + secElf + thirdElf;
        newFile.close(); //close the file object.
    }

    return 0;
}


