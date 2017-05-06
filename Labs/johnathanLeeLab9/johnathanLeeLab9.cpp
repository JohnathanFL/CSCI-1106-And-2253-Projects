// Computer Science 1106
// Programmer: Johnathan Lee
// Description: Takes an integer and says whether it's prime.

#include <cmath>
#include <iostream>

using namespace std;

void getValue(int &input);
bool isPositive(int num);
bool isEven(int num);
bool loopCheckVals(int value);

int main() {
	bool prime = true; // Assume we're prime to cut down on statements.
	int val;

	getValue(val);

	if (!isPositive(val)) {
		cout << "Error, entered a negative number. Terminating.\n\n";
		exit(1106);
	}

	if (isEven(val) && val > 2) {
		prime = false;
	} else {
		prime = loopCheckVals(val);
	}

	cout << val;
	if(prime)
		 cout << " is prime.\n";
	else
		cout << " is not prime.\n";

	return 0;
}

/*******************************************
    getValue
    Preconditions: An integer reference
    Returns: An integer by reference.

    Takes a reference to an integer, displays a prompt, then takes input
    into the integer.
********************************************/
void getValue(int &input) {
	cout << "Please enter a positive integer to check: ";
	cin >> input;
}

/*******************************************
    isPositive
    Preconditions: An integer
    Returns:	   A bool

    Takes an integer and returns whether or not that integer is positive (>0).
********************************************/
bool isPositive(int num) { return (num > 0); }

/*******************************************
    isEven
    Preconditions: An integer
    Returns: A bool

    Uses modulo to tell whether a number is even.
********************************************/
bool isEven(int num) {
	return (num % 2 == 0); // If the remainder is 0, it must be even.
}

/*******************************************
    loopCheckVals
    Preconditions: A non-even integer
    Returns: A bool

    Loops from 3 to the value's sqrt to check if it's prime.
********************************************/
bool loopCheckVals(int value) {
	bool isPrime = true;

	// We don't need to start at 1 and we already checked for divisible by
	// 2, so start at 3.
	for (int i = 3; i <= sqrt(value); i++) {
		if (value % i == 0)
			isPrime = false;
	}

	return isPrime;
}
