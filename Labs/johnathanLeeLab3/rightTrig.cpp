//*******************************************************************************
// Programmer: Johnathan Lee
//
// Description: This program will ask the user for the two sides of a right 
//				triangle and determine the length of the hypotenuse.
//*******************************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){

	double side1,				// one of the legs of the triangle
		   side2,				// one of the legs of the triangle
		   hypotenuse;			// the hypotenuse of the triangle

	cout << setprecision(2) << fixed << showpoint;		// format the output

	cout << "Enter the length of one side of the triangle: " ;

	//Write the input statement for the user to input a value for side1
	cin >> side1;

	//Write the prompt for the user for the second side
	cout << "Enter the length of the next side of the triangle: ";
	//Write the input statement for the user to input a value for side2
	cin >> side2;
	
	//Write the assignment statement to calculate the hypotenuse 
	//(cmath has a built-in function called sqrt. The syntax is sqrt(variable_or_number)
	hypotenuse = sqrt(side1*side1 + side2*side2);

	//Write an output statement(s) to display the legs of the triangle and the hypotenuse of the triangle
	//in column format (appropriately labeled) with all decimal points lining up.

	cout //        Wasn't sure how wide you wanted it exactly, so I chose a number that
		 //        would fit most inputs.
		<< "Leg one   : " << setw(7) << side1 << endl
		<< "Leg two   : " << setw(7) << side2 << endl
		<< "Hypotenuse: " << setw(7) << hypotenuse << endl;

	return 0;
}// end main