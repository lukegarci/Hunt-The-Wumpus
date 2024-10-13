/*********************************************************************
** Program Filename:main.cpp
** Author:Luke garci
** Date:11/29/2023
** Description: This program simulates a text-based adventure game where the player explores a cave, encounters events,
 * and tries to achieve specific goals. The cave's dimensions and gameplay options are customizable.
** Input: User inputs for the width and length of the cave, as well as an option to enable or disable debug mode.
** Output: Displays the game interface, prompts, and relevant information during the gameplay. Informs the player about
 * game outcomes, such as finding the gold, hunting the Wumpus, or losing the game.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

int valid_int(const string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < minValue || value > maxValue) {
            cin.clear();
            while (cin.get() != '\n');  // Clear input space
            cout << "Invalid input! Please enter a valid value between " << minValue << " and " << maxValue << "." << endl;
        } else {
            break;
        }
    }
    return value;
}

bool valid_bool(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input == "true" || input == "false") {
            return (input == "true");
        } else {
            cout << "Invalid input! Please enter 'true' or 'false'." << endl;
        }
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    int playAgain;
    do {
        int wid = valid_int("Enter the width of the cave (4 - 50): ", 4, 50);
        int len = valid_int("Enter the length of the cave (4 - 50): ", 4, 50);
        bool debug = valid_bool("Enter debug mode (true/false): ");

        Game g;

        // Play the game
        g.set_up(wid, len); // Initialize the game
        g.play_game(wid, len, debug);

        // Ask the player if they want to play again
        cout << "Do you want to play again? (1 for yes, 0 for no): ";
        cin >> playAgain;

        // Check if the player wants to play again
        if (playAgain != 1) {
            cout << "Thanks for playing! Goodbye." << endl;
            break;
        }

    } while (playAgain == 1);

    return 0;
}

