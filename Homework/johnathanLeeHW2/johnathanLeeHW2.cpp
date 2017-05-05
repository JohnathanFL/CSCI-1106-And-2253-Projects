/* Turtle-Writer
 * Author: Johnathan Lee
 * Class: CSCI 1106, Homework 2
 * Date: 5/5/17
 *
 * Reads an input file of commands (which can be line by line or sequential) and
 * uses them to draw an image in asterisks.
 *
 * NOTE: I have various debug couts commented out throughout the program in case
 * you wanted to take a look at them/to aid in examining the program.
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


const int NORTH = 0, EAST = 1, SOUTH = 2,
          WEST = 3, // Directions for easy reading.
    X = 1, Y = 0,   // Constants to beautify reading position code a little.
    WIDTH = 80, HEIGHT = 25; // Our display width/height.


void verifyPosition(int curPos[], int maxWidth, int maxHeight);
void parseCommand(char command, ifstream &file, bool &isDown, int &penDir,
                  int disp[][WIDTH], int height, int width, int pos[],
                  bool &quitFlag);
void render(int disp[][WIDTH], int height, int width);
void move(int disp[][WIDTH], int height, int width, int pos[], bool isDown,
          int distance, int dir);


int main() {
  bool     isDown              = true;
  int      dir                 = EAST;
  int      grid[HEIGHT][WIDTH] = {0};
  int      penPos[2]           = {0, 0};
  char     cmdBuffer;
  ifstream inFile;


  inFile.open("turtle.txt");
  if (!inFile) {
    cout << "Failed to open input file! Terminating...\n\n";
    exit(1106 - 2);
  }


  bool shouldQuit = false;
  while (inFile >> cmdBuffer && !shouldQuit) {
    parseCommand(cmdBuffer, inFile, isDown, dir, grid, HEIGHT, WIDTH, penPos,
                 shouldQuit);
    // render(display, HEIGHT); // For debugging or an "animation"
  }

  return 0;
}


/* verifyPosition
 * Ensures that a given position array (2 elements) is between 0 and the given
 *  max width/height.
 *
 * Pre: An array containing 2 ints for X and Y positions.
 * Post: If either position was outside the bounds, it was set to the closest
 *  bound. (i.e -1 becomes 0, 9999 becomes maxHeight or Width)
 */
void verifyPosition(int curPos[], int maxWidth, int maxHeight) {
  if (curPos[X] > maxWidth)
    curPos[X] = maxWidth;
  else if (curPos[X] < 0)
    curPos[X] = 0;

  if (curPos[Y] > maxWidth)
    curPos[Y] = maxWidth;
  else if (curPos[Y] < 0)
    curPos[Y] = 0;
}


/* parseCommand
 * Takes a command, file, grid, and some reference flags and evaluates the
 *  command.
 *
 * Pre: All variables must be pre-initialized.
 * Post: Command was evaluated and pen moved. isDown, penDir, and quitFlag may
 *  have new values.
 *
 * Note: Would a template<int width, int height> be a better way of passing
 *  width and height, since the WIDTH constant is already needed for disp's
 *  size?
 */
void parseCommand(char command, ifstream &file, bool &isDown, int &penDir,
                  int disp[][WIDTH], int height, int width, int pos[],
                  bool &quitFlag) {
  int moveSpaces = 0;

  switch (command) {
  case 'U':
    isDown = false;
    // cout << "Putting pen up.\n";
    break;

  case 'D':
    isDown = true;
    // cout << "Putting pen down.\n";
    break;

  case 'R':
    penDir++;
    if (penDir > 3)
      penDir = NORTH;
    // cout << "Turning right. \n";
    break;

  case 'L':
    penDir--;
    if (penDir < 0)
      penDir = WEST;
    // cout << "Turning left. \n";
    break;

  case 'F':
    file >> moveSpaces;
    /*cout << "Moving " << moveSpaces << " from " << pos[X] << "," << pos[Y]
         << " to the " << penDir << endl;*/
    break;

  case 'P':
    render(disp, height, width);
    // cout << "Printing. \n";
    break;

  case 'Q':
    quitFlag = true;
    break;

  default:
    break;
  }
  move(disp, width, height, pos, isDown, moveSpaces, penDir);
}


/* render
 * Displays an array of a given width and height to stdout. Prints * for 1,
 *  space for 0.
 *
 * Pre: Initialized array of height and width.
 * Post: Stars and spaces are printed for 1s and 0s to the stdout.
 */
void render(int disp[][WIDTH], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++)
      cout << (disp[i][j] ? "*" : " "); // if it's 1, render *.
                                        // Otherwise use space.
    cout << endl;
  }
}


/* move
 * Moves a position array depending on number of spaces and direction specified.
 *  Verifies that the position is within bounds once every movement. Changes
 *  elements at the position stored in pos to 1 or 0, depending on isDown.
 *
 * Pre: Initialized arrays for disp and pos. Height and width of disp. Distance
 * and direction to move. Whether the pen isDown.
 */
void move(int disp[][WIDTH], int height, int width, int pos[], bool isDown,
          int distance, int dir) {

  for (int i = 0; i < distance; i++) {
    if (isDown) // Use this instead of disp[y][x] = isDown to not erase things
      disp[pos[Y]][pos[X]] = 1;

    switch (dir) {

    case NORTH:
      // North moves us up, but since we are drawing top down, that's a negative
      // direction.
      pos[Y]--;
      break;

    case SOUTH:
      pos[Y]++;
      break;

    case EAST:
      pos[X]++;
      break;

    case WEST:
      pos[X]--;
      break;

    default:
      break;
    }
    verifyPosition(pos, height, width); // Make sure we're inside
                                        // the grid each "frame"
  }
}
