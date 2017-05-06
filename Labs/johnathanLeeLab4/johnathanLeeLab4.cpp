/*******************************************************************************
Programmer: Johnathan Lee
Class: CSCI 1106
Lab: 4
Submitted 2/7/17
Description:
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char temp;

    int    purchaseDollars,
           purchaseCents,
           dollarChangeLeft,
           smallChangeLeft,
           paymentAmount;  // Int as whole dollar payment is assumed.

    int pennies = 0, nickels = 0, dimes = 0, quarters = 0, oneBills = 0, fiveBills = 0, tenBills = 0, twentyBills = 0; // Change of each type.


    cout << "Please enter the purchase amount                     ==>  ";
    cin >> purchaseDollars >> temp >> purchaseCents;

    cout << "\n" 
         << "Please enter the payment amount (Whole numbers only) ==>   ";
    cin >> paymentAmount;

	if (purchaseCents > 0)
		dollarChangeLeft = paymentAmount - purchaseDollars - 1;
	else
		dollarChangeLeft = paymentAmount - purchaseDollars;

    if (dollarChangeLeft / 20 >= 1) {
        twentyBills = dollarChangeLeft / 20;
        dollarChangeLeft %= 20;
    }
    if (dollarChangeLeft / 10 >= 1) {
        tenBills = dollarChangeLeft / 10;
        dollarChangeLeft %= 10;
    }
    if (dollarChangeLeft / 5 >= 1) {
        fiveBills = dollarChangeLeft / 5;
        dollarChangeLeft %= 5;
    }
    if (dollarChangeLeft >= 1) {
        oneBills = dollarChangeLeft;
    }


	if (purchaseCents > 0)
		smallChangeLeft = 100 - purchaseCents;
	else
		smallChangeLeft = 0;


    if (smallChangeLeft / 25 >= 1) {
        quarters = smallChangeLeft / 25;
        smallChangeLeft %= 25;
    }
    if (smallChangeLeft / 10 >= 1) {
        dimes = smallChangeLeft / 10;
        smallChangeLeft %= 10;
    }
    if (smallChangeLeft / 5 >= 1) {
        nickels = smallChangeLeft / 5;
        smallChangeLeft %= 5;
    }

    pennies = smallChangeLeft;

    cout << "Your change: \n"
        << "Twenty Dollar Bills : " << twentyBills << endl
        << "Ten Dollar Bills    : " << tenBills << endl
        << "Five Dollar Bills   : " << fiveBills << endl
        << "Dollar Bills        : " << oneBills << endl
        << "Quarters            : " << quarters << endl
        << "Dimes               : " << dimes << endl
        << "Nickels             : " << nickels << endl
        << "Pennies             : " << pennies << endl << endl;
    
    cin >> temp; // For some reason, my version of VS refused to pause on end and a normal cin.get() didn't cover it this time.

    return 0;
}