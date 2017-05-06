/*
 Author: Johnathan Lee

 Class: CSCI 1106, Lab 14

 Randomly stores values into a user-defined-size array, then sorts and averages
 them.
*/
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void loadScores(int *a, int *nums, int *numEls);
void displayScores(int a[], int b[], int numEls);
void bubbleSort(int *a, int *nums, int numEls);
void swapVals(int *a, int firstIndex, int secondIndex);
double calculateAvg(int *a, int numEls);

int main() {
  int *scores,
      *testNums; // For displaying the sorted scores with proper numbers.
  int    numEls;
  double avg;

  cout << "Enter a number of scores: ";
  cin >> numEls;
  scores   = new int[numEls];
  testNums = new int[numEls];

  loadScores(scores, testNums, &numEls);
  displayScores(scores, testNums, numEls);
  bubbleSort(scores, testNums, numEls);
  avg = calculateAvg(scores, numEls);
  displayScores(scores, testNums, numEls);


  cout << "Test average: " << avg << endl;

  return 0;
}


/* loadScores
 * Randomly loads scores [1,100] into an array.
 * Pre: Arrays to hold the scores and test numbers. May or may not already have
 *  values. A number of test elements.
 * Post: Arrays now have scores/corresponding test numbers.
 */
void loadScores(int *a, int *nums, int *numEls) {
  srand(time(NULL));

  for (int i = 0; i < *numEls; i++) {
    *(a + i)    = rand() % 100 + 1;
    *(nums + i) = i + 1;
  }
}
/* displayScores
 * Loops through and prints all scores in an array with their corresponding test
 *  numbers.
 * Pre: An array holding scores, an array holding test numbers, the size of the
 *  arrays.
 * Post: Test scores are printed to output with corresponding test numbers.
 */
void displayScores(int a[], int b[], int numEls) {
  for (int i = 0; i < numEls; i++)
    cout << "Test" << setw(3) << *(b + i) << "|";

  cout << endl;
  for (int i = 0; i < numEls; i++)
    cout << setw(7) << *(a + i) << "|";

  cout << "\n\n";
}


/* bubbleSort
 * Sorts an array using the bubblesort algorithm.
 * Pre: Unsorted array of size numEls. Array holding corresponding test numbers.
 * Post: Array sorted in ascending order.
 */
void bubbleSort(int *a, int *nums, int numEls) {
  bool cleanPass = false;

  while (!cleanPass) {
    cleanPass = true;

    for (int i = 1; i < numEls; i++) {

      if (*(a + i) < *(a + i - 1)) {
        swapVals(a, i, i - 1);
        swapVals(nums, i, i - 1);
        cleanPass = false;
      }
    }
  }
}

/* calculateAvg
 * Calculates the average of an array.
 * Pre: An initialized array with values.
 * Post: Returns the average of the array elements.
 */
double calculateAvg(int *a, int numEls) {
  double sum = 0, avg;

  for (int i = 0; i < numEls; i++)
    sum += *(a + i);

  avg = sum / numEls;

  return avg;
}

/* swapVals
 * Swaps two values in an array. Modified to use all pointers.
 * Pre: An initialized array, two indicies.
 * Post: Values are swapped between firstIndex and secondIndex.
 */
void swapVals(int a[], int firstIndex, int secondIndex) {
  int temp           = *(a + firstIndex);
  *(a + firstIndex)  = *(a + secondIndex);
  *(a + secondIndex) = temp;
}
