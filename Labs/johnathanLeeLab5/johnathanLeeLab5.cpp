/*
Name: Johnathan Lee
Class: CSCI 1106
Lab: 5
Date started: 2/7/15

Description: Takes an input color code and reports the contents of the cylinder based on that code.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    bool shouldQuit = false;
    bool validChoice;
    char choice;
    string contents;

    while (!shouldQuit) {
        validChoice = true;
        cout << "Please enter a color code:  ";
        cin >> choice;

        switch (choice) {
            case 'O':
            case'o':
                contents = "ammonia";
                break;

            case'Y':
            case'y':
                contents = "hydrogen";
                break;

            case 'B':
            case 'b':
                contents = "carbon monoxide";
                break;

            case 'G':
            case 'g':
                contents = "oxygen";
                break;

            case 'E':
            case 'e':
                shouldQuit = true;
                break;

            default:
                validChoice = false;
                break;
        }

        if (!shouldQuit) {
            if (validChoice)
                cout << "Your gas cylinder contained " << contents.c_str() << "!\n\n";

            else
                cout << "You entered an invalid choice! Please try again!\n";
        }
        else
            cout << "Shutting down.\n\n";
    }

    return 0;
}