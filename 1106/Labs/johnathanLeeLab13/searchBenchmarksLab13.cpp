/* Author: Johnathan Lee
 * Class: CSCI 1106, Lab 13
 *
 * Benchmarks a linear search.
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

const int NUM_INTS = 50000; // Since it said "at least" 20 and the binary search
                            // is for large data sets, let's go big or go home.

void populateArray(int a[], int numEls);
int linearSearch(int a[], int target, int numEls, int& numComps);
int binarySearch(int a[], int target, int numEls, int& numComps);

int main() {
  int searchArray[NUM_INTS];
  int numLinear = 0, numBinary = 0,
      // We'll use a separate index for each search for debugging purposes.
      linIndex, binIndex, target;

  srand(time(NULL));
  target =
      rand() % NUM_INTS + 1; // We'll start at 0 to also benchmark worst case.

  cout << "Finding " << target << "...\n";

  populateArray(searchArray, NUM_INTS);


  linIndex = linearSearch(searchArray, target, NUM_INTS, numLinear);
  binIndex = binarySearch(searchArray, target, NUM_INTS, numBinary);

  cout << "Linear search found it at index " << linIndex
       << (linIndex == -1 ? "(Not found) " : "") << " using " << numLinear
       << " comparisons." << endl;

  cout << "Binary search found it at index " << binIndex
       << (binIndex == -1 ? "(Not found) " : "") << " using " << numBinary
       << " comparisons." << endl;

  return 0;
}


/* populateArray
 * Populates an integer array with numbers 1-(numEls)
 * Pre: Array initialized to 0
 * Post: Array contains numbers 1-(numEls)
 */
void populateArray(int a[], int numEls) {
  for (int i = 0; i < numEls; i++) {
    a[i] = i + 1;
  }
}


/* linearSearch
 * Sequentially checks all elements and returns the subscript of the target.
 *  Also returns number of comparisons used through reference.
 * Pre: A sorted integer array, target to search for, number of elements in the
 *  array, and a variable to hold the number of comparisons.
 * Post: Returns the target's index (or -1 for not found) and numComps has the #
 *  of comparisons.
 */
int linearSearch(int a[], int target, int numEls, int& numComps) {
  int index = -1;
  int i     = 0;
  while (i < numEls && index == -1) {
    numComps++; // Comparison at beginning of each loop

    if (a[i] == target) {
      numComps++;
      index = i;
    }
    i++;
  }

  return index;
}


/* binarySearch
 * Searches all elements with the binary search algorithm and returns the
 *  subscript of the target.
 *  Also returns number of comparisons used through reference.
 * Pre: A sorted integer array, target to search for, number of elements in the
 *  array, and a variable to hold the number of comparisons.
 * Post: Returns the target's index (or -1 for not found) and numComps has the #
 *  of comparisons.
 */
int binarySearch(int a[], int target, int numEls, int& numComps) {
  bool shouldContinue = true;
  int  index          = -1;
  int  first = 0, last = numEls - 1, mid = (first + last) / 2;

  while (shouldContinue && first < last) {
    numComps += 2; // While loop conditions.

    mid = (first + last) / 2;

    numComps++; // For the first if
    if (a[mid] == target) {
      index          = mid;
      shouldContinue = false;
    } else if (target < a[mid]) {
      last = mid;
    } else {
      first = mid;
      numComps++; // If we're here, the last elif also fired
    }
  }

  return index;
}
