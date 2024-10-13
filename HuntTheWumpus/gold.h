/*********************************************************************
** Program Filename:gold.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the member function declarations for the Gold class.
** Input:none
** Output:none
*********************************************************************/

#ifndef GOLD_H
#define GOLD_H
#include "game.h"
#include "event.h"
class Gold: public Event {
public:
/********************************************************
** Function: Gold constructor
** Description: initializes row and column
** Input: row and column
** Pre-Conditions: none
** Post-Conditions: row and column are initialized
********************************************************/
    Gold(int r, int c);

/********************************************************
** Function: ~Gold()
** Description: deallocates any memory
** Input: none
** Pre-Conditions: none
** Post-Conditions: free dynamic memory
********************************************************/
    ~Gold() override;

/********************************************************
** Function: percept()
** Description: displays a message indicating the Gold is nearby
** Input: none
** Pre-Conditions: none
** Post-Conditions: message is displayed
********************************************************/
    void percepts() override;

/********************************************************
** Function: encounter()
** Description: changes has_gold to true for the player, changes picked_up to true
** Input: reference to the game object
** Pre-Conditions: none
** Post-Conditions: returns false
********************************************************/
    bool encounter(Game &) override;

/********************************************************
** Function: abbreviation()
** Description: returns the abbreviation to show in the map for this event
** Input: none
** Pre-Conditions: none
** Post-Conditions: returns the abbreviation to show in the map for this event
********************************************************/
    char get_abb() override;
};

#endif
