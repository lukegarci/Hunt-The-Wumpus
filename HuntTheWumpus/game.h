/*********************************************************************
** Program Filename:game.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the function declarations and member variables for the game class.
** Input:none
** Output:none
*********************************************************************/

#ifndef GAME_H
#define GAME_H 
#include <vector>
#include <iostream>
#include "room.h"




using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
    vector<vector<Room>> cave;
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
    bool wumpus_placed;     //wumpus is placed in a room
    bool player_placed;     //player is placed in a room
    bool gold_placed;       //gold is placed in a room
    bool found_gold;        //the gold is found or not found
    int start_row;          //the row where the player starts
    int start_col;          //the column where the player starts
    bool wumpus_killed;     //wumpus is alive or dead
    int bats_encounter_countdown;       //the number of confused turns


public:

    /*********************************************************************
    ** Function:Game()
    ** Description:Constructor for Game class.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Initialized member variables
    *********************************************************************/
	Game();

     /*********************************************************************
     ** Function: ~Game()
     ** Description:Destructor for the Game class.
     ** Parameters:none
     ** Pre-Conditions:A Game object exists.
     ** Post-Conditions:The Game object is destroyed, freeing allocated resources.
     *********************************************************************/
	~Game();

     /*********************************************************************
     ** Function:set_up(int w, int l)
     ** Description:Sets up the game by initializing the game board and placing various elements (Wumpus, Gold, Bats, Stalactites, Player).
     ** Parameters:int l - length of the game board, int w - width of the game board
     ** Pre-Conditions:The Game object exists.
     ** Post-Conditions:The game is set up with the specified dimensions and elements placed on the board.
     *********************************************************************/
	void set_up(int l, int w);

     /*********************************************************************
     ** Function:display_game() const
     ** Description:Displays the current state of the game board, including player position, arrows remaining,
      * and event symbols.
     ** Parameters:none
     ** Pre-Conditions:The Game object exists.
     ** Post-Conditions:The game board is displayed to the console.
     *********************************************************************/
	void display_game() const;

    /*********************************************************************
    ** Function:check_win() const
    ** DescriptionChecks if the player has won the game by finding the gold and reaching the starting position.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Returns true if the player has won, false otherwise.
    *********************************************************************/
	bool check_win() const;

    /*********************************************************************
    ** Function:get_dir()
    ** Description:Prompts the user to enter the direction in which they want to fire an arrow.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Returns the direction entered by the user.
    *********************************************************************/
	char get_dir();

    /*********************************************************************
    ** Function:wumpus_move()
    ** Description:Moves the Wumpus to a different room with a 75% chance.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The Wumpus may be moved to a different room.
    *********************************************************************/
	void wumpus_move();

    /*********************************************************************
    ** Function:fire_arrow()
    ** Description:Fires an arrow in the specified direction and checks if it hits the Wumpus.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The arrow is fired, and the outcome is displayed.
    *********************************************************************/
	void fire_arrow();

     /*********************************************************************
     ** Function:move_up()
     ** Description:Moves the player character up in the cave.
     ** Parameters:none
     ** Pre-Conditions:The Game object exists.
     ** Post-Conditions:The player is moved up, and encounters are checked.
     *********************************************************************/
	void move_up();

    /*********************************************************************
    ** Function:move_down()
    ** Description:Moves the player character down in the cave.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The player is moved down, and encounters are checked.
    *********************************************************************/
	void move_down();

    /*********************************************************************
    ** Function:move_left()
    ** Description:Moves the player character to the left in the cave.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The player is moved to the left, and encounters are checked.
    *********************************************************************/
	void move_left();

    /*********************************************************************
    ** Function:move_right()
    ** Description:Moves the player character to the right in the cave.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The player is moved to the right, and encounters are checked.
    *********************************************************************/
	void move_right();

    /*********************************************************************
    ** Function:move(char c)
    ** Description:Handles the player's action, either moving or firing an arrow.
    ** Parameters:char c- representing the player's action
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:The player is moved or fires an arrow, and encounters are checked.
    *********************************************************************/
	void move(char c);

    /*********************************************************************
    ** Function:get_input()
    ** Description:Gets the player's input for movement or firing an arrow.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Returns a character representing the player's input.
    *********************************************************************/
	char get_input();

    /*********************************************************************
    ** Function: play_game
    ** Description: Plays the game with the specified width, length, and debug mode.
    ** Parameters:int w - width of the game board, int l - length of the game board, bool d - debug mode
    ** Pre-Conditions: The Game object exists.
    ** Post-Conditions: Plays the game until the player wins, loses, or hunts the Wumpus.
    *********************************************************************/
	void play_game(int w, int l, bool d);

    /*********************************************************************
    ** Function:place_player()
    ** Description:Places the player in a random empty room on the game board.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Places the player in a random empty room.
    *********************************************************************/
    void place_player();

    /*********************************************************************
    ** Function:place_wumpus()
    ** Description:Places the Wumpus in a random empty room on the game board.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Places the Wumpus in a random empty room.
    *********************************************************************/
    void place_wumpus();

    /*********************************************************************
    ** Function:place_gold()
    ** Description:Places the Gold in a random empty room on the game board.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Places the Gold in a random empty room.
    *********************************************************************/
    void place_gold();

    /*********************************************************************
    ** Function:place_bats()
    ** Description:Places the Bats in a random empty room on the game board.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Places the Bats in a random empty room.
    *********************************************************************/
    void place_bats();

    /*********************************************************************
    ** Function:place_stalactite()
    ** Description:Places Stalactites in a random empty room on the game board.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Places Stalactites in a random empty room.
    *********************************************************************/
    void place_stalactite();

    /*********************************************************************
    ** Function:player_position(int&, int&)
    ** Description:Determines the row and column of the player on the game board.
    ** Parameters: int row-reference to an integer variable to store the row of the player.
     * int col-reference to an integer variable to store the column of the player.
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Sets the row and col parameters to the player's position.
    *********************************************************************/
    void player_position(int &row, int &col) const;

        /*********************************************************************
    ** Function: wumpus_position
    ** Description: Determines the row and column of the Wumpus on the game board.
    ** Parameters:int row-reference to an integer variable to store the row of the Wumpus.
     * int col - reference to an integer variable to store the column of the Wumpus.
    ** Pre-Conditions: The Game object exists.
    ** Post-Conditions: Sets the 'row' and 'col' parameters to the Wumpus's position.
    *********************************************************************/
    void wumpus_position(int &row, int &col) const;

    /*********************************************************************
    ** Function: check_encounter(int, int)
    ** Description: Checks for encounters with events in the current room and handles the consequences.
    ** Parameters:int row-the row of the current room, int col-the column of the current room.
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Handles encounters with events in the specified room.
    *********************************************************************/
    void check_encounter(int row, int col);

    /*********************************************************************
    ** Function:check_percept(int, int) const
    ** Description:Checks and displays percepts for events in adjacent rooms to the player's position.
    ** Parameters:int player_row-the row of the player's current position, int player_col-the column of the player's
     * current position.
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Displays percepts for events in adjacent rooms to the player's position.
    *********************************************************************/
    void check_percept(int,int) const;

    /*********************************************************************
    ** Function:check_loss() const
    ** Description:Checks if the player has lost the game.
    ** Parameters:none
    ** Pre-Conditions:The Game object exists.
    ** Post-Conditions:Returns true if the player has lost, false otherwise.
    *********************************************************************/
    bool check_loss() const;

    /*********************************************************************
    ** Function:reverse_direction(char dir)
    ** Description:Reverses the given movement direction.
    ** Parameters:char dir - the direction to reverse.
    ** Pre-Conditions:none
    ** Post-Conditions:Returns the reversed direction.
    *********************************************************************/
    char reverse_direction(char dir);

    /*********************************************************************
    ** Function:check_bats(int, int)
    ** Description:Checks if the player has encountered bats in the current room.
    ** Parameters: int row - the row of the current room, int col - the column of the current room.
    ** Pre-Conditions:none
    ** Post-Conditions:Updates the bats_encounter_countdown if bats are encountered.
    *********************************************************************/
    void check_bats(int row,int col);

};
#endif