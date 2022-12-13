

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream newFile;
    int points = 0;
    string temp;
    char enemy;
    char us;
    newFile.open("input.txt", ios::in);
    if (newFile.is_open()) {
        while (getline(newFile, temp)) {
            enemy = temp[0];
            us = (char)(temp[2] - 23);
            //Need to Draw
            if (us == 'B') {
                points += (enemy - 64) + 3;
            }
            //Need to Win
            else if (us == 'C') {
                if (enemy == 'A') {
                    points += 8;
                }
                else if (enemy == 'B') {
                    points += 9;
                }
                else if (enemy == 'C') {
                    points += 7;
                }
            }
            //Need to Lose
            else if (us == 'A') {
                if (enemy == 'A') {
                    points += 3;
                }
                else if (enemy == 'B') {
                    points += 1;
                }
                else if (enemy == 'C') {
                    points += 2;
                }
            }
        }
        cout << points;
    }
    else {
        cout << "ERROR OPENING FILE" << endl;
    }
    newFile.close();
    return 0;
}