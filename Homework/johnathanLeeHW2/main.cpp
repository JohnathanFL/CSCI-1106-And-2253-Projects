/* Author: Johnathan Lee
 * Class: CSCI 1106, Homework 2
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int HEIGHT = 30, WIDTH = 80;
const int X = 0, Y = 1; // Rather than having two ints for position, let's clean
                        // things up a bit and use a 2-element array.
const int
    N = 0,
    E = 1, S = 2,
    W = 3; // We'll use directions corresponding to the normal NESW = 0123;

void render(int a[][WIDTH]);
void parseCommand(string cmd, int pos[], bool& isDown, int& facing);

int main(int argc, char* argv[]) {
  int      display[HEIGHT][WIDTH] = {0}; // The drawing board we write on.
  int      turtlePos[2]           = {0}; // Keep track of position coordinates
  bool     penDown                = false;
  int      direction              = E;
  ifstream commandFile;
  string   curCmd;

  commandFile.open("Commands.txt");
  if (!commandFile) {
    cout << "Couldn't open Commands.txt for writing!\n";
    exit(1106 - 2);
  }

  while (getline(commandFile, curCmd)) {
    parseCommand(curCmd, turtlePos, penDown, direction);
    render(display);
  }

  return 0;
}

void render(int a[][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void parseCommand(string cmd, int pos[], bool& isDown, int& facing) {
  switch (cmd[0]) {


  default:
    // TODO: Handle bad commands.
    break;
  }
}
