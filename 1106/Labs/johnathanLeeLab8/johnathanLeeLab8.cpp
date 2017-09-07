/*
	Programmer: Johnathan Lee
	Lab#: 8

	Description: Converts Powerball records into a usable format.
*/

#include <fstream>
#include <iostream>

using namespace std;


int main() {
	ifstream inFile;
	ofstream outFile;
	char line[18];

	inFile.open("pb_2014.txt");
	if (!inFile) {
		cout << "Error opening pb_2014.txt for input. Terminating.";
		exit(1106);
	}

	outFile.open("powerball.txt");
	if (!outFile) {
		cout << "Error opening powerball.txt for output. Terminating.";
		exit(1106);
	}

	while(!inFile.eof()) {
		inFile.ignore(10); // Ignore the date + 2 spaces.

		inFile.get(line, 18); // Each record we need is exactly 17 characters.

		outFile << line << endl;

		inFile.ignore(6); // Each record we need is followed by 6 uneeded characters (x numNum + newline).
	}
	return 0;
}