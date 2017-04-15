/* Author: Johnathan Lee
 * Class: CSCI 1106, Homework 2
 */

#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

auto mycomp = [](const int&a, const int& b) { return a < b; };
map<string, decltype (mycomp)> funcMap = {{"AS", mycomp}};

const int HEIGHT = 80, WIDTH = 80;
const int X = 0, Y = 1; // Rather than having two ints for position, let's clean
                        // things up a bit.
const int N = 0, E = 1, S = 2,
          W = 3; // We'll use directions corresponding to NESW = 0123;

int main(int argc, char *argv[]) {
  char display[HEIGHT][WIDTH] = {{0}}; // The drawing board we write on.
  int  turtlePos[2]           = {0};   // Keep track of position coordinates
  bool penIsDown              = false;
  int  direction              = E;



  return 0;
}
