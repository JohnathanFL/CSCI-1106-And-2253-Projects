/* Author: Johnathan Lee
 * Class: CSCI 1106, Lab 13
 *
 * Benchmarks bubble and selection sorts.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

const int AR_SIZE = 200; // As before, go big or go home.

void populateArray(int a[], int numEls);
void copyArray(int source[], int dest[], int numEls);
void swapVals(int a[], int firstIndex, int secondIndex);
void bubbleSort(int a[], int numEls, int& numComps);
void selectionSort(int a[], int numEls, int& numComps);
void displayResults(int a[], int numEls, int numBub, int numSel);


int main() {
  int bubbleAr[AR_SIZE] = {0}, selectionAr[AR_SIZE] = {0};
  int numBubble = 0, numSelec = 0;

  populateArray(bubbleAr, AR_SIZE);
  copyArray(bubbleAr, selectionAr, AR_SIZE);

  bubbleSort(bubbleAr, AR_SIZE, numBubble);
  selectionSort(selectionAr, AR_SIZE, numSelec);

  // We could pass either array to display, doesn't matter here.
  displayResults(bubbleAr, AR_SIZE, numBubble, numSelec);

  return 0;
}


/* populateArray
 * Populates an array with random values
 * Pre: Initialized array of size numEls. srand() not yet called.
 * Post: Array filled with random values. srand() called.
 * Side note, that accidental alignment between pre/post is awesome.
 */
void populateArray(int a[], int numEls) {
  srand(time(NULL));

  for (int i = 0; i < numEls; i++)
    a[i] = rand() % numEls; // We'll go [0,numEls] for a better looking array.
}


/* copyArray
 * Copies an array into another array.
 * Pre: Two initialized arrays of size numEls. At least one should have values.
 * Post: Both arrays are identical.
 */
void copyArray(int source[], int dest[], int numEls) {
  for (int i = 0; i < numEls; i++)
    dest[i]  = source[i];
}


/* swapVals
 * Swaps two values in an array
 * Pre: An initialized array, two indicies.
 * Post: Values are swapped between firstIndex and secondIndex.
 */
void swapVals(int a[], int firstIndex, int secondIndex) {
  int temp       = a[firstIndex];
  a[firstIndex]  = a[secondIndex];
  a[secondIndex] = temp;
}


/* bubbleSort
 * Sorts an array using the bubblesort algorithm.
 * Pre: (Preferably) Unsorted array of size numEls. int& to hold number of
 *      comparions.
 * Post: Array sorted in ascending order.
 */
void bubbleSort(int a[], int numEls, int& numComps) {
  bool cleanPass = false;

  while (!cleanPass) {
    numComps++; // We compare cleanpass == false

    cleanPass = true;

    for (int i = 1; i < numEls; i++) {
      numComps++; // for condition
      if (a[i] < a[i - 1]) {
        numComps++;
        swapVals(a, i, i - 1);
        cleanPass = false;
      }
    }
  }
}


/* selectionSort
 * Sorts an array using the selection sort algorithm.
 * Pre: (Preferably) Unsorted array of size numEls. int& to hold number of
 *      comparions.
 * Post: Array sorted in ascending order.
 */
void selectionSort(int a[], int numEls, int& numComps) {
  int minIndex;

  for (int offset = 0; offset < numEls - 1; offset++) {
    numComps++; // for condition
    minIndex = 0 + offset;
    for (int i = 0 + offset; i < numEls; i++) {
      numComps += 2; // for condition and if
      if (a[minIndex] > a[i])
        minIndex = i;
    }
    swapVals(a, 0 + offset, minIndex);
  }
}


/* displayResults
 * Displays benchmark results to stdout.
 * Pre: Array to display of size numEls. Number of comparisons used for bubble
 *      and selection sorts.
 * Post: Information sent to stdout.
 */
void displayResults(int a[], int numEls, int numBub, int numSel) {
  cout << "Array of size " << numEls << ": \n";

  for (int i = 0; i < AR_SIZE; i++)
    //                     newline every 10 numbers, otherwise use separator.
    cout << setw(4) << a[i] << (!((i + 1) % 10) ? "\n" : "|");

  cout << endl;

  cout << "Was sorted in " << numBub << " comparisons with a bubble sort and "
       << numSel << " comparisons with the selection sort.\n\n";
}
