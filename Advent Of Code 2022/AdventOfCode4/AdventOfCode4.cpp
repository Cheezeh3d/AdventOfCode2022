

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool partOne(int first, int second, int third, int fourth) {
	return( (first <= third && second >= fourth) || (third <= first && fourth >= second) );
}

bool partTwo(int first, int second, int third, int fourth) {
	return (
		//if first num is in between third and fourth 
		(first >= third && first <= fourth) ||
		//if second num is in between third and fourth
		(second >= third && second <= fourth) ||
		//if third num is in between first and second
		(third >= first && third <= second) ||
		//if fourth num is in between first and second
		(fourth >= first && fourth <= second)
		);
}


int main()
{
	fstream newFile;
	vector<string> firstElf(2);
	vector<string> secondElf(2);
	int tally = 0;
	newFile.open("input.txt", ios::in);

	//part 1
	if (newFile.is_open()) {
		//part 1
		while (getline(newFile, firstElf.at(0), '-')) {
			getline(newFile, firstElf.at(1), ',');
			getline(newFile, secondElf.at(0), '-');
			getline(newFile, secondElf.at(1));

			if (partOne((stoi(firstElf.at(0))), (stoi(firstElf.at(1))), (stoi(secondElf.at(0))), (stoi(secondElf.at(1))))) {
				tally++;
				cout << firstElf.at(0) << " " << firstElf.at(1) << " " << secondElf.at(0) << " " << secondElf.at(1) << endl;
			}
		}
		cout << tally << endl;
		cout << endl;
	}
	else {
		cout << "ERROR OPENING FILE" << endl;
	}
	newFile.close();
	tally = 0;

	//part 2
	newFile.open("input.txt", ios::in);
	if (newFile.is_open()) {
		while (getline(newFile, firstElf.at(0), '-')) {
			getline(newFile, firstElf.at(1), ',');
			getline(newFile, secondElf.at(0), '-');
			getline(newFile, secondElf.at(1));

			if ((partOne((stoi(firstElf.at(0))), (stoi(firstElf.at(1))), (stoi(secondElf.at(0))), (stoi(secondElf.at(1))))) ||
				(partTwo((stoi(firstElf.at(0))), (stoi(firstElf.at(1))), (stoi(secondElf.at(0))), (stoi(secondElf.at(1)))))) {
				tally++;
				cout << firstElf.at(0) << " " << firstElf.at(1) << " " << secondElf.at(0) << " " << secondElf.at(1) << endl;
			}
		}
		cout << tally << endl;
	}
	else {
		cout << "ERROR OPENING FILE" << endl;
	}
	newFile.close();


	return 0;
}


