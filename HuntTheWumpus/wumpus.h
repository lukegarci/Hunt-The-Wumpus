/*********************************************************************
** Program Filename:wumpus.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the function declarations for the Wumpus class.
** Input:none
** Output:none
*********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H 

//Wumpus Interface

#include "event.h"
#include "game.h"
class Wumpus: public Event {
public:
    /********************************************************
    ** Function: Wumpus();
    ** Description:Constructs a Wumpus at a specific row and column
    ** Input: int r:the row where the wumpus will be. int c: the column where wumpus will be
    ** Pre-Conditions: none
    ** Post-Conditions: initialized values for row and column.
    ********************************************************/
    Wumpus(int r,int c);


    /********************************************************
    ** Function: percept()
    ** Description: displays a message indicating the Wumpus is nearby
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: message is displayed
    ********************************************************/
    void percepts() override;

    /********************************************************
    ** Function: encounter()
    ** Description: prints game over message, kills the player
    ** Input: reference to the game object
    ** Pre-Conditions: none
    ** Post-Conditions: returns true
    ********************************************************/
    bool encounter(Game&) override;

    /********************************************************
    ** Function:get_abb()
    ** Description:gets the abb for the wumpus and returns back a char
    ** Input:none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the abbreviation to show in the map for this event
    ********************************************************/
    char get_abb() override;

    /********************************************************
    ** Function: ~Wumpus() destructor
    ** Description: deallocates any memory
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: free dynamic memory
    ********************************************************/
    ~Wumpus() override;

};

#endif