/*
  Programmed by: Johnathan Lee
  Class: CSCI 1106
  Lab 12

  Takes input from 5 judges and displays the average after dropping the
  lowest and highest scores.
*/

#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_SCORE = 10; // I doubt the lower bound would change,
                          // but the upper has a chance to.

const int NUM_JUDGES = 5;


void getJudgeData(double& targetVar, int judgeNum);
void calcScore(double inScores[], int size);
double findLowest(double inScores[], int size);
double findHighest(double inScores[], int size);


int main() {
  double scores[NUM_JUDGES];

  for (int i = 0; i < NUM_JUDGES; i++) {
    getJudgeData(scores[i], i);
  }

  calcScore(scores, NUM_JUDGES);

  return 0;
}


/*
  getJudgeData()

  Gets a number from user, validates, and stores into a variable

  Pre: A reference to an integer.
  Post: targetVar has a score stored in it.

*/
void getJudgeData(double& targetVar, int judgeNum) {
  cout << "Please enter a score for judge #" << judgeNum + 1 << ": ";
  cin >> targetVar;

  // Only accept scores in [0, MAX_SCORE]
  if (targetVar < 0 || targetVar > MAX_SCORE) {
    cout << "Error: Score out of bounds [0," << MAX_SCORE
         << "]. Terminating.\n";
    exit(1106 - 12);
  }
}


/*
  calcScore()

  Given an array of scores, prints the average after dropping the highest and
  lowest.

  Pre: An array of 'size' with values in all.
  Post: Output

*/
void calcScore(double inScores[], int size) {
  double lowest, highest, sum = 0, avg;

  for (int i = 0; i < NUM_JUDGES; i++) {
    sum += inScores[i];
  }


  lowest  = findLowest(inScores, size);
  highest = findHighest(inScores, size);
  sum -= lowest + highest; // Drop the lowest and highest.

  avg = sum / (NUM_JUDGES - 2); // Sub 2 to account for lowest/highest dropped.


  cout << fixed << showpoint << setprecision(2);

  cout << "The average of the " << NUM_JUDGES << " scores was: " << avg << endl
       << endl;
}


/*
  findLowest()

  Finds and returns the lowest value in a given array of 'size'.

  Pre: An array of 'size' with values in all.
  Post: The lowest value of the array.
*/
double findLowest(double inScores[], int size) {
  double lowest = MAX_SCORE;
  for (int i = 0; i < size; i++) {
    if (inScores[i] < lowest)
      lowest = inScores[i];
  }

  return lowest;
}


/*
  findHighest()

  Finds and returns the highest value in a given array of 'size'.

  Pre: An array of 'size' with values in all.
  Post: The highest value of the array.
*/
double findHighest(double inScores[], int size) {
  double highest = 0;
  for (int i = 0; i < size; i++) {
    if (inScores[i] > highest)
      highest = inScores[i];
  }

  return highest;
}
