

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;

void readChart(vector<vector<char>>& diagram, fstream &theFile) {
    char inputChar;
    int spaces = 0;
    int curCol = 0;
    int curRow = 0;
    bool finished = false;
    while (!finished) {
        inputChar = theFile.get();

        switch (inputChar) {
        case ' ':
            spaces++;
            if (spaces == 3) {
                curCol++;
                spaces = -1;
            }
            break;
        case '[':
            inputChar = theFile.get();
            diagram.at(curCol).push_back(inputChar);
            curCol++;
            inputChar = theFile.get();
            spaces = -1;
            break;
        case '\n':
            spaces = 0;
            curCol = 0;
            curRow++;
            break;
        case 'm':
            finished = true;
            break;
        }
    }
}

void printChart(vector<vector<char>>& diagram) {
    cout << "PRINTING CHART: " << endl;
    string output = "";
    for (int i = 0; i < diagram.size(); i++) {
        for (int j = 0; j < diagram.at(i).size(); j++) {
            output += diagram.at(i).at(j);
        }
        cout << setw(50) << right << output << endl;
        output = "";
    }
    cout  << endl << endl;
}

void printEachTop(vector<vector<char>>& diagram) {
    cout << "PRINTING EACH TOP: " << endl << endl << endl;
    for (int i = 0; i < diagram.size(); i++) {
        if (diagram.at(i).size() != 0) {
            cout << i + 1 << ": " << diagram.at(i).front() << endl;

        }
        else {
            cout << i + 1 << ": Empty" << endl;

        }
    }
    cout << endl << endl;
}

void moveChartPartOne(vector<vector<char>>& diagram, fstream &theFile) {
    char input;
    int qty = 0;
    int from = 0;
    int to = 0;
    int count = 0;
    int whileCount = 1;
    bool finished = false;

    //Read file until we reach first move line
    while (!finished) {
        input = theFile.get();
        if (input == 'm') {
        finished = true;
        }
    }

    //Read rest of file
    while (!theFile.eof()) {
        //Get character by character until we get our qty, from, and to
        //values
        input = theFile.get();
        if (isdigit(theFile.peek())) {
            count++;
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                qty += (int(input) - 48);
                whileCount *= 10;
            }
            whileCount = 1;
            input = theFile.get();
            while (!isdigit(theFile.peek())) {
                input = theFile.get();
            }
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                from += int(input) - 48;
                whileCount *= 10;
            }
            whileCount = 1;
            input = theFile.get();
            while (!isdigit(theFile.peek())) {
                input = theFile.get();
            }
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                to += int(input) - 48;
                whileCount *= 10;
            }
            whileCount = 1;
            try {
                //Move them blocks
                if (qty > diagram.at(from - 1).size()) {
                    qty = diagram.at(from - 1).size();
                }
                for (qty; qty > 0; qty--) {
                    diagram.at(to - 1).insert(diagram.at(to - 1).begin(),
                        make_move_iterator(diagram.at(from - 1).begin()),
                        make_move_iterator(diagram.at(from - 1).begin() + 1));

                    diagram.at(from - 1).erase(diagram.at(from - 1).begin(), diagram.at(from - 1).begin() + 1);
                }
            }
            catch (...) {
                continue;
            }
            qty = 0;
            to = 0;
            from = 0;
        }
    }
    return;
}

void moveChartPartTwo(vector<vector<char>>& diagram, fstream& theFile) {
    char input;
    int qty = 0;
    int from = 0;
    int to = 0;
    int count = 0;
    int whileCount = 1;
    bool finished = false;

    //Read file until we reach first move line
    while (!finished) {
        input = theFile.get();
        if (input == 'm') {
            finished = true;
        }
    }

    //Read rest of file
    while (!theFile.eof()) {
        //Get character by character until we get our qty, from, and to
        //values
        input = theFile.get();
        if (isdigit(theFile.peek())) {
            count++;
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                qty += (int(input) - 48);
                whileCount *= 10;
            }
            whileCount = 1;
            input = theFile.get();
            while (!isdigit(theFile.peek())) {
                input = theFile.get();
            }
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                from += int(input) - 48;
                whileCount *= 10;
            }
            whileCount = 1;
            input = theFile.get();
            while (!isdigit(theFile.peek())) {
                input = theFile.get();
            }
            while (isdigit(theFile.peek()) || theFile.peek() == '0') {
                input = theFile.get();
                qty *= whileCount;
                to += int(input) - 48;
                whileCount *= 10;
            }
            whileCount = 1;
            try {
                //Move them blocks
                if (qty > diagram.at(from - 1).size()) {
                    qty = diagram.at(from - 1).size();
                }
                    diagram.at(to - 1).insert(diagram.at(to - 1).begin(),
                        make_move_iterator(diagram.at(from - 1).begin()),
                        make_move_iterator(diagram.at(from - 1).begin() + qty));

                    diagram.at(from - 1).erase(diagram.at(from - 1).begin(), diagram.at(from - 1).begin() + qty);
            }
            catch (...) {
                continue;
            }
            qty = 0;
            to = 0;
            from = 0;
        }
    }
    return;
}

//Part one
void partOne() {
    //First, we need to go translate the chart at
    //the top of the input file into a vector of vectors.

    //diagram - column, row
    vector<vector<char>> diagram(9);

    fstream theFile;
    theFile.open("input.txt", ios::in);

    if(theFile.is_open()){
        readChart(diagram, theFile);
        printChart(diagram);
        theFile.close();
        theFile.open("input.txt", ios::in);
        moveChartPartOne(diagram, theFile);
        printChart(diagram);
        printEachTop(diagram);
    }
    else {
        cout << "ERROR OPENING FILE IN PART ONE" << endl;
    }
    theFile.close();
    return;
}

//Part two
void partTwo() {
    //First, we need to go translate the chart at
    //the top of the input file into a vector of vectors.

    //diagram - column, row
    vector<vector<char>> diagram(9);

    fstream theFile;
    theFile.open("input.txt", ios::in);

    if (theFile.is_open()) {
        readChart(diagram, theFile);
        printChart(diagram);
        theFile.close();
        theFile.open("input.txt", ios::in);
        moveChartPartTwo(diagram, theFile);
        printChart(diagram);
        printEachTop(diagram);
    }
    else {
        cout << "ERROR OPENING FILE IN PART ONE" << endl;
    }
    theFile.close();
    return;
}

int main()
{
    partOne();

    partTwo();

    return 0;
}

