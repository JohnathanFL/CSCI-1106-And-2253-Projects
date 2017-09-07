/*
  Author: Johnathan Lee. 
    pointerFun function written by Timothy Wrenn, modified by Johnathan Lee.
    
  Class: CSCI 1106, Lab 14
*/

#include <iostream>

using namespace std;

void getVals(int *x, int *y);
int pointerFun(int *x, int *y);
void display(int *x, int *y, int *retVal);

int main() {
  int mainX, mainY, returnVal;

  getVals(&mainX, &mainY);

  returnVal = pointerFun(&mainX, &mainY);

  display(&mainX, &mainY, &returnVal);

  return 0;
}


/*
  getVals
  Handles input to two variables
  Pre: Two pointers to ints.
  Post: Input variables have user input in them.
*/
void getVals(int *x, int *y) {
  cout << "Please enter a value for x: ";
  cin >> *x;

  cout << "Please enter a value for y: ";
  cin >> *y;
}


/*
  pointerFun
  Takes 2 values by pointer, does math on them and returns the sum.
  Pre: 2 pointers to initialized variables.
  Post: x was multiplied by (y*10). y was multiplied by (x*10). Returned x+y
  */
int pointerFun(int *x, int *y) {
  int temp = *x;
  *x = (*y) * 10;
  *y = temp * 10;
  return (*x) + (*y);
}


/*
  display
  Takes 3 values and displays them
  Pre: 3 pointers to initalized values.
  Post: Contents of values are displayed.
*/
void display(int *x, int *y, int *retVal) {
  cout << "New x value is: " << *x << endl
    << "New y value is: " << *y << endl
    << "Return value was: " << *retVal << endl;
}
