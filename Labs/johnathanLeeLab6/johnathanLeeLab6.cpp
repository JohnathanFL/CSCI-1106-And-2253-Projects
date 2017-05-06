/*
Author: Johnathan Lee
Class: CSCI 1106
Lab: 6

Program Description: Calculates an exponential income using powers of 2.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int numDays = 0, dailySalary = 1, totalPayed = 0, prevSalary = 1;

	while (numDays < 1 || numDays > 30) {
		cout << "Please enter a number of days:  ";
		cin >> numDays;
	}


	cout << "    Day        Earned Today" << endl
		 << "-----------------------" << endl;


	for (int i = 1; i <= numDays; i++) {
		
		dailySalary *= 2;

		totalPayed += dailySalary / 2;
		cout << setw(7) << i << setw(8) << "$" << setw(12) << dailySalary / static_cast<double>(200) << endl;
	}

	cout << "\nTotal earned: $" << totalPayed / static_cast<double>(100);

	cin.ignore();
	cin.get();

	return 0;
}