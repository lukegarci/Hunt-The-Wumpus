/*********************************************************************
** Program Filename:stalactites.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the member function declarations for the Stalactites class.
** Input:none
** Output:none
*********************************************************************/

#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"
#include "game.h"
class Stalactites: public Event {
public:

/********************************************************
** Function: Stalactites();
** Description:Constructs a stalactite at a specific row and column
** Input: int r -the row where the stalactite will be. int c: the column where stalactite will be
** Pre-Conditions:none
** Post-Conditions:Initialized values for row and column.
********************************************************/
    Stalactites(int r, int c);
/********************************************************
** Function: percept()
** Description:Displays a message indicating the stalactite is nearby.
** Input: none
** Pre-Conditions:none
** Post-Conditions:Percept is printed.
********************************************************/
    void percepts() override;
/********************************************************
** Function: encounter()
** Description:Stalactite is spotted in the same room.
** Input:Reference to the game object.
** Pre-Conditions:none
** Post-Conditions: Returns the encounter print along with making it true.
********************************************************/
    bool encounter(Game& g) override;
/********************************************************
** Function:get_abb()
** Description:gets the abb for the Stalactite and returns back a char
** Input:none
** Pre-Conditions: none
** Post-Conditions:Returns the abbreviation to show in the map for this event
********************************************************/
    char get_abb() override;

    /********************************************************
    ** Function: ~Stalactites() destructor
    ** Description: deallocates any memory
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: frees dynamic memory
    ********************************************************/
    ~Stalactites() override;
};
#endif