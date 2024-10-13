/*********************************************************************
** Program Filename:bats.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the function declarations for the class Bats.
** Input:none
** Output:none
*********************************************************************/

#ifndef BATS_H
#define BATS_H 

//Bats Interface

#include "event.h"
#include "game.h"
class Bats: public Event {
public:
/********************************************************
** Function: Bats(int,int);
** Description:Constructs a Wumpus at a specific row and column
** Input: int r:the row where the wumpus will be. int c: the column where wumpus will be
** Pre-Conditions: none
** Post-Conditions:Initialized values for row and column.
********************************************************/
    Bats(int,int);


/********************************************************
** Function: percept()
** Description:Displays a message indicating a bat is nearby
** Input:none
** Pre-Conditions:none
** Post-Conditions:Percept is displayed.
********************************************************/
    void percepts() override;

/********************************************************
** Function: encounter(Game&)
** Description:Tells the player there are bats in the room and they have been confused.
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions:Will return true.
********************************************************/
    bool encounter(Game&) override;

/********************************************************
** Function:get_abb()
** Description:Gets the 'B' abbreviation for bat.
** Input:none
** Pre-Conditions: none
** Post-Conditions:'B' character is returned.
********************************************************/
    char get_abb() override;

    /********************************************************
   ** Function: ~Bats() destructor
   ** Description: deallocates any memory
   ** Input: none
   ** Pre-Conditions: none
   ** Post-Conditions: frees dynamic memory
   ********************************************************/
    ~Bats() override;
};
#endif