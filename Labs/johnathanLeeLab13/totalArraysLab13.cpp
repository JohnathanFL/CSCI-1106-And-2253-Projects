/*
  Author: Johnathan Lee
  Class: CSCI 1106, Lab 13

  Totals collumns in a 2D array.

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


const int NUM_ROWS = 10, NUM_COLUMNS = 6;

void populateRandArray(int a[NUM_ROWS][NUM_COLUMNS], int rowCount, int colCount);
void sumArray(int a[NUM_ROWS][NUM_COLUMNS], int outColSum[], int outRowSum[], int rowCount, int columnCount);
void displaySums(int a[][NUM_COLUMNS], int inColSum[], int inRowSum[], int rowCount, int colCount);

int main() {
  int mainArray[NUM_ROWS][NUM_COLUMNS];
  int colSums[NUM_COLUMNS] = { 0 }, rowSums[NUM_ROWS] = { 0 };

  populateRandArray(mainArray, NUM_ROWS, NUM_COLUMNS);
  sumArray(mainArray, colSums, rowSums, NUM_ROWS, NUM_COLUMNS);
  displaySums(mainArray, colSums, rowSums, NUM_ROWS, NUM_COLUMNS);

  cout << endl;
  return 0;
}


/*
  Function: populateRandArray

  Takes a 2D array (with row/column counts) and populates it with random ints.

  Pre: An empty array and a count of the desired rows/columns.
  Post: Input array now has random ints in it.
*/
void populateRandArray(int a[NUM_ROWS][NUM_COLUMNS], int rowCount, int colCount) {
  srand(time(NULL));

  for (int i = 0; i < rowCount; i++) {
    for (int j = 0; j < colCount; j++) {
      a[i][j] = rand() % 100 + 1;

    }

  }
}


/*
Function: sumArray

Loops through an array and stores the sums of rows/columns in out variables.

Pre: A 2D array to sum, an array for column and row sums, column and row counts.
Post: Arrays for column and row sums.
*/
void sumArray(int a[NUM_ROWS][NUM_COLUMNS], int outColSum[], int outRowSum[], int rowCount, int columnCount) {

  for (int i = 0; i < rowCount; i++) {
    for (int j = 0; j < columnCount; j++) {
      outRowSum[i] += a[i][j];
      outColSum[j] += a[i][j];
    }
  }
}


/*
Function: displaySums

Takes a 2D array and its row/column sums and displays it as a grid.

Pre:  
Post: Input array now has random ints in it.
*/
void displaySums(int a[][NUM_COLUMNS], int inColSum[], int inRowSum[], int rowCount, int colCount) {

  for (int i = 0; i < rowCount; i++) {
    for (int j = 0; j < colCount; j++) {


      if (i >= rowCount)
        cout << setw(4) << inColSum[j] << "  ";
      else
        cout << setw(4) << a[i][j] << " +";
    }
    cout << "\b= " << inRowSum[i] << "||" << endl;
  }

  //          (4 width per number + 3 per plus sign)*5 + 5 more for total = 40
  for(int i = 0; i < 40; i++)
    cout << "=";
  cout << "||" << endl;

  for(int i = 0; i < colCount; i++)
    cout << setw(5) << inColSum[i] << "|";
  cout << endl;


}
