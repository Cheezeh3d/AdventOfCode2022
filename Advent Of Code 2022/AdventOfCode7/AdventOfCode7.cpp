#include <iostream>
#include <fstream>
using namespace std;

int directory() {




}

void partOne() {
	int total = 0;
	string tempString;
	char tempChar;

	//input file
	fstream input;
	input.open("input.txt", ios::in);

	//check that it opened successfully
	if (!input.is_open()) {
		cout << "ERROR OPENING FILE";
		return;
	}

	//Read file till empty
	while (!input.eof()) {




	}
}


int main()
{
	partOne();
	return 0;
}

