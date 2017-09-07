/*
* Programmer: Johnathan Lee
* Class: CSCI 1106
* Lab#: 7
*
* Description: Calculates batting average and slugging percentage based on a simulation.
*/

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

// Probability ranges for all possible actions.
const int OUT_MAX = 35, SINGLE_MAX = 20 + OUT_MAX, WALK_MAX = 16 + SINGLE_MAX,
		  DOUBLE_MAX = 15 + WALK_MAX, TRIPLE_MAX = 9 + DOUBLE_MAX, 
	      HOMERUN_MAX = 5 + TRIPLE_MAX; // This should be 100. Can be used to double check things.

// How many times will we run the sim? (The assignment said 1000 or more, so I 
// assumed this was a choice and left it const.)
const int NUM_SIMS = 1000;

int main() {
	int curRand, // A temp variable for each random number.
		numHits,
		numOuts = 0,     
		numWalks = 0,    // Number of each time 
		numSingles = 0,
		numDoubles = 0,
		numTriples = 0,
		numHomes = 0;

	double battingAvg, sluggingPct;
	
	srand(time(NULL));
	
	for (int i = 0; i < NUM_SIMS; i++) {
		curRand = 1 + rand() % 100; // Rand in [1,100]

		if (curRand <= OUT_MAX)
			numOuts++;
		else if (curRand <= SINGLE_MAX)
			numSingles++;
		else if (curRand <= WALK_MAX)
			numWalks++;
		else if (curRand <= DOUBLE_MAX)
			numDoubles++;
		else if (curRand <= TRIPLE_MAX)
			numTriples++;
		else // <= 100
			numHomes++;
	}

	numHits = NUM_SIMS - numOuts;
	
	battingAvg = static_cast<double>(numHits) / (NUM_SIMS - numWalks);

	sluggingPct = (numSingles + numDoubles * 2.0 + numTriples * 3.0 + numHomes * 4.0)
		            / (NUM_SIMS - numWalks);

	cout << fixed << showpoint << setprecision(2);

	cout<< "Number of hits: " << numHits << endl
		<< "Number of outs: " << numOuts << endl
		<< "Number of walks: " << numWalks << endl
		<< "Number of singles: " << numSingles << endl
		<< "Number of doubles: " << numDoubles << endl
		<< "Number of triples: " << numTriples << endl
		<< "Number of homerunes: " << numHomes << endl << endl
		<< "Batting average: " << battingAvg << endl
		<< "Slugging percentage: " << sluggingPct << endl << endl;

	return 0;
}