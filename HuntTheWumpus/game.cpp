/*********************************************************************
** Program Filename:game.cpp
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains all of the member functions for the game class.
** Input:The direction the player wants to move or fire an arrow. If the user selects to fire an arrow they will input a
 * direction.
** Output:Display the game board, based on debug mode it will display or hide the events.
*********************************************************************/

#include "game.h"
#include "bats.h"
#include "gold.h"
#include "wumpus.h"
#include "stalactites.h"



using namespace std;

//Game Implementation

Game::Game():
          length(0),
          width(0),
          num_arrows(0),
          wumpus_placed(false),
          player_placed(false),
          gold_placed(false),
          found_gold(false),
          wumpus_killed(false),
          start_row(0),
          start_col(0),
          bats_encounter_countdown(0){}

Game::~Game() {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (cave[i][j].get_event() != nullptr) {
                Event* current_event = cave[i][j].remove_event();
                delete current_event;

            }
        }
    }
}

void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

	// Create the game board: 2D vector of Room objects
    cave.resize(length, vector<Room>(width));
    place_wumpus();
    place_gold();
    place_bats();
    place_stalactite();
    place_player();
    player_position(start_row, start_col);
}

void Game::display_game() const {
    cout << endl << endl;
    cout << "Arrows remaining: " << this->num_arrows << endl;

    string line = "";
    for (int i = 0; i < this->width; ++i)
        line += "-----";
    for (int i = 0; i < this->length; ++i) {
        cout << line << endl;
        for (int j = 0; j < this->width; ++j) {
            //when the user has gold the starting row and col will display R
            if (i == start_row && j == start_col && found_gold && debug_view) {
                cout << " R ||";
            } else if (cave[i][j].has_player()) {
                //check if the room has the player
                if (debug_view) {
                    // Display both player and event abbreviation in debug mode
                    if (!cave[i][j].is_empty()) {
                        char event_abb = cave[i][j].get_event()->get_abb();
                        cout << " " << event_abb << "*||";
                    } else {
                        cout << " * ||";
                    }
                } else {
                    // Check if the room has an event
                    if (!cave[i][j].is_empty()) {
                        // Display both player and event abbreviation
                        char event_abb = cave[i][j].get_event()->get_abb();
                        cout << " " << event_abb << "*||";
                    } else {
                        // If the room only has the player, display player symbol
                        cout << " * ||";
                    }
                }
            } else {
                // Check if the room has an event and debug mode is enabled
                if (debug_view && !cave[i][j].is_empty()) {
                    // Display only event abbreviation in debug mode
                    char event_abb = cave[i][j].get_event()->get_abb();
                    cout << " " << event_abb << " ||";
                } else {
                    // If the room does not have the player or an event, print space " "
                    cout << "   ||";
                }
            }
        }
        cout << endl;
    }
    cout << line << endl;
}


bool Game::check_win() const{
	//check win
    int current_row, current_col;
    player_position(current_row, current_col);
    return found_gold && start_row == current_row && start_col == current_col;
}

bool Game::check_loss() const {
    int current_row, current_col, wumpus_row, wumpus_col;
    player_position(current_row, current_col);
    wumpus_position(wumpus_row, wumpus_col);
    //if the player has moved into the same room as the Wumpus
    if (current_row == wumpus_row && current_col == wumpus_col) {
        return true;
    }
    //if the player has encountered a falling stalactite (50% chance)
    if (!cave[current_row][current_col].is_empty()) {
        Event* event = cave[current_row][current_col].get_event();
        int random_value = rand() % 2;
        if (typeid(*event) == typeid(Stalactites) && random_value == 0) {
            cout << "The stalactite has fallen and killed you! Game over!\n";
            return true; // End the game
        }
    }
    return false;
}


void Game::move_up() {
    int current_row, current_col;
    player_position(current_row, current_col);
    if (current_row > 0) {
        // Move the player up
        cave[current_row][current_col].set_player(false);
        cave[current_row - 1][current_col].set_player(true);
        // Check for encounters after movement
        //check_encounter(current_row - 1, current_col);
    } else {
        cout << "You are already at the top of the cave! Try a different direction." << endl;
    }
}

void Game::move_down() {
    int current_row, current_col;
    player_position(current_row, current_col);
    if (current_row < length - 1) {
        // Move the player down
        cave[current_row][current_col].set_player(false);
        cave[current_row + 1][current_col].set_player(true);
        // Check for encounters after movement
        //check_encounter(current_row + 1, current_col);
    } else {
        cout << "You are already at the bottom of the cave! Try a different direction." << endl;
    }
}

void Game::move_left() {
    int current_row, current_col;
    player_position(current_row, current_col);
    if (current_col > 0) {
        // Move the player left
        cave[current_row][current_col].set_player(false);
        cave[current_row][current_col - 1].set_player(true);
        // Check for encounters after movement
        //check_encounter(current_row, current_col - 1);
    } else {
        cout << "You are already at the left edge of the cave! Try a different direction." << endl;
    }
}

void Game::move_right() {
    int current_row, current_col;
    player_position(current_row, current_col);
    if (current_col < width - 1) {
        // Move the player right
        cave[current_row][current_col].set_player(false);
        cave[current_row][current_col + 1].set_player(true);
        // Check for encounters after movement
        //check_encounter(current_row, current_col + 1);
    } else {
        cout << "You are already at the right edge of the cave! Try a different direction." << endl;
    }
}

void Game::player_position(int &row, int &col) const {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (cave[i][j].has_player()) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void Game::wumpus_position(int &row, int &col) const {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            Event* current_e = cave[i][j].get_event();
            if (!cave[i][j].is_empty() && current_e != nullptr && typeid(*current_e) == typeid(Wumpus)) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void Game::check_encounter(int row, int col) {
    // Check for encounters with events in the current room
    if (!cave[row][col].is_empty()) {
        Event *event = cave[row][col].get_event();
        event->encounter(*this);

        // Check if the removed event is Gold
        if (typeid(*event) != typeid(Gold)){
            // If it's not Gold, add it back to the room
            cave[row][col].set_event(event);
        }
        else{
            found_gold = true;
            cave[row][col].remove_event();
            delete event;
        }
    }
}

void Game::check_bats(int row, int col) {
    if (!cave[row][col].is_empty()) {
        Event* event = cave[row][col].get_event();
        if (event != nullptr && typeid(*event) == typeid(Bats)) {
            bats_encounter_countdown = 5;
        }
    }
}


char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!!
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;


	cout << "Enter direction: ";
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move() {
    //75% chance that the Wumpus is moved to a different room
    if (rand() % 5 < 4) {  //equivalent to rand() % 5 <= 3
        int wumpus_row, wumpus_col;
        wumpus_position(wumpus_row, wumpus_col);

        //find a new random empty room for the Wumpus
        int new_row, new_col;
        do {
            new_row = rand() % cave.size();
            new_col = rand() % (cave.at(0)).size();
        } while (!cave[new_row][new_col].is_empty());

        delete cave[wumpus_row][wumpus_col].remove_event(); //remove Wumpus from the current room
        cave[new_row][new_col].set_event(new Wumpus(new_row, new_col)); //place Wumpus in the new room
    }
}

void Game::fire_arrow() {
    if (num_arrows == 0) {
        cout << "Out of arrows!\n";
        return;
    }

    char dir = get_dir();

    int current_row, current_col;
    player_position(current_row, current_col);

    int wumpus_row, wumpus_col;
    wumpus_position(wumpus_row, wumpus_col);

    //iterate over each step of the arrow's movement
    for (int i = 0; i < 3 && num_arrows > 0; ++i) {
        //check if the arrow is adjacent to the Wumpus before moving
        if ((abs(current_row - wumpus_row) == 1 && current_col == wumpus_col) ||
            (current_row == wumpus_row && abs(current_col - wumpus_col) == 1)) {
            //75% chance that the Wumpus is moved to a different room
            if (rand() % 5 < 4) {
                wumpus_move();
            }
        }

        switch (dir) {
            case 'w':
                if (current_row > 0) {
                    current_row--;
                } else {
                    cout << endl << "Arrow hit the cave wall.";
                    num_arrows--;
                    return;
                }
                break;
            case 'a':
                if (current_col > 0) {
                    current_col--;
                } else {
                    cout << endl << "Arrow hit the cave wall.";
                    num_arrows--;
                    return;
                }
                break;
            case 's':
                if (current_row < length - 1) {
                    current_row++;
                } else {
                    cout << endl << "Arrow hit the cave wall.";
                    num_arrows--;
                    return;
                }
                break;
            case 'd':
                if (current_col < width - 1) {
                    current_col++;
                } else {
                    cout << endl << "Arrow hit the cave wall.";
                    num_arrows--;
                    return;
                }
                break;
            default:
                cout << "Invalid direction.\n";
                return;
        }

        // Check if the arrow hits the Wumpus after movement
        if (current_row == wumpus_row && current_col == wumpus_col) {
            cout << "\nYou shot the Wumpus with your arrow!";
            wumpus_killed = true;
            num_arrows--;

            // Move the Wumpus
            wumpus_move();

            return;
        }
    }

    // If the loop completes without hitting the cave wall or the Wumpus, it missed the Wumpus
    cout << "\nYour arrow missed the Wumpus.";
    num_arrows--;

    if (num_arrows == 0) {
        cout << "\nYou are out of arrows!";
    }
}


char Game::reverse_direction(char dir) {
    // Reverse the movement direction
    switch(dir){
        case 'w':
            return 's';
        case 'a':
            return 'd';
        case 's':
            return 'w';
        case 'd':
            return 'a';
        default:
            return dir;
    }
}

void Game::move(char c) {
    // Handle player's action: move or fire an arrow
    if (c == 'f'){
        Game::fire_arrow();
        return;
    }

    //check if the user is confused
    if (bats_encounter_countdown > 0) {
        c = reverse_direction(c);
        bats_encounter_countdown--;
    }

    switch(c){
        case 'w':
            Game::move_up();
            break;
        case 'a':
            Game::move_left();
            break;
        case 's':
            Game::move_down();
            break;
        case 'd':
            Game::move_right();
            break;
    }
    int current_row, current_col;
    player_position(current_row, current_col);
    check_bats(current_row, current_col);
}

char Game::get_input() {
    char c;

    cout << endl << endl << "Player move..." << endl << endl;
    cout << "W-up" << endl;
    cout << "A-left" << endl;
    cout << "S-down" << endl;
    cout << "D-right" << endl;
    cout << "F-fire an arrow" << endl;

    //get input and convert to lowercase
    cout << "Enter input: ";
    cin >> c;
    cin.ignore(256, '\n');
    c = tolower(c);

    //reprompt user when they enter invalid user
    while (!(c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'f')) {
        cout << "Invalid input. Please enter a valid direction or 'f' to fire an arrow: ";
        cin >> c;
        cin.ignore(256, '\n');
        c = tolower(c);
    }

    return c;
}

void Game::place_player() {
    if (!player_placed) {
        int player_row, player_col;
        do {
            player_row = rand() % cave.size();
            player_col = rand() % (cave.at(0)).size();
        } while (!cave[player_row][player_col].is_empty());
        cave[player_row][player_col].set_player(true);
        player_placed = true;
    }
}

void Game::place_wumpus() {
    if (!wumpus_placed) {
        int wumpus_row, wumpus_col;
        do {
            wumpus_row = rand() % cave.size();
            wumpus_col = rand() % (cave.at(0)).size();
        } while (!cave[wumpus_row][wumpus_col].is_empty());
        cave[wumpus_row][wumpus_col].set_event(new Wumpus(wumpus_row, wumpus_col));
        wumpus_placed = true;
    }
}

void Game::place_gold() {
    if (!gold_placed) {
        int gold_row, gold_col;
        do {
            gold_row = rand() % cave.size();
            gold_col = rand() % (cave.at(0)).size();
        } while (!cave[gold_row][gold_col].is_empty() || cave[gold_row][gold_col].has_player());
        cave[gold_row][gold_col].set_event(new Gold(gold_row, gold_col));
        gold_placed = true;
    }
}

void Game::place_bats() {
    int bats_row, bats_col;
    do {
        bats_row = rand() % cave.size();
        bats_col = rand() % (cave.at(0)).size();
    } while (!cave[bats_row][bats_col].is_empty() || cave[bats_row][bats_col].has_player());

    cave[bats_row][bats_col].set_event(new Bats(bats_row, bats_col));

}

void Game::place_stalactite() {
    int stalactite_row, stalactite_col;
    do {
        stalactite_row = rand() % cave.size();
        stalactite_col = rand() % (cave.at(0)).size();
    } while (!cave[stalactite_row][stalactite_col].is_empty() || cave[stalactite_row][stalactite_col].has_player());

    cave[stalactite_row][stalactite_col].set_event(new Stalactites(stalactite_row, stalactite_col));
}

void Game::check_percept(int player_row, int player_col) const {
    // Check if the player perceives events in adjacent rooms
    const int distance = 1; // Check percepts for events within this distance

    for (int i = -distance; i <= distance; ++i) {
        for (int j = -distance; j <= distance; ++j) {
            int neighbor_row = player_row + i;
            int neighbor_col = player_col + j;

            if ((abs(i) == 1 && abs(j) == 0) || (abs(i) == 0 && abs(j) == 1)) {
                // Check if the neighbor is adjacent to the player
                if (neighbor_row >= 0 && neighbor_row < length &&
                    neighbor_col >= 0 && neighbor_col < width) {
                    // Check if there is an event in the adjacent room
                    if (!cave[neighbor_row][neighbor_col].is_empty()) {
                        cave[neighbor_row][neighbor_col].get_event()->percepts();
                    }
                }
            }
        }
    }
}

void Game::play_game(int w, int l, bool d) {
    Game::set_up(w, l);
    this->debug_view = d;

    char input;

    while (!Game::check_win() && !Game::check_loss() && !wumpus_killed) {
        Game::display_game();

        int current_row, current_col;
        player_position(current_row, current_col);
        check_percept(current_row, current_col);

        input = Game::get_input();

        Game::move(input);

        player_position(current_row, current_col);
        check_encounter(current_row, current_col);
    }

    if (Game::check_win() && found_gold) {
        cout << "\nCongratulations! You found the gold and escaped safely!\n" << endl;
    }
    else if (wumpus_killed) {
        cout << "\nCongratulations! You have successfully hunted the Wumpus!\n" << endl;
    }
    else{
        cout << "\nWould you like to try again?\n" << endl;
    }

    return;
}

