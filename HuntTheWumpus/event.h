/*********************************************************************
** Program Filename:event.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains function declarations for event class.
** Input:none
** Output:none
*********************************************************************/
#ifndef EVENT_H
#define EVENT_H 
#include "game.h"

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{
protected:
    int row;
    int col;
public:

    /*********************************************************************
    ** Function:Event(int,int)
    ** Description:Member variables are constructed.
    ** Parameters:int r:the row where the event will be. int c: the column where event will be
    ** Post-Conditions:none
    *********************************************************************/
    Event(int, int);

    /*********************************************************************
    ** Function:percepts()
    ** Description:Pure virtual function representing the percepts of an event in a room. This function is meant
     * to be overridden by derived classes to provide specific percepts for each type of event.
    ** Parameters:none
    ** Pre-Conditions:An event object exists.
    ** Post-Conditions:The percepts of the event are conveyed.
    *********************************************************************/
    virtual void percepts() = 0;

    /*********************************************************************
    ** Function: encounter(Game&)
    ** Description: Pure virtual function representing the encounter between the player and an event in a room.
     * This function is meant to be overridden by derived classes to provide specific outcomes for each type of event
     * when encountered by the player.
    ** Parameters:Game& game- A reference to the Game object, which allows interaction with the game state.
    ** Pre-Conditions: An event object exists.
    ** Post-Conditions: The encounter between the player and the event is resolved, and the function returns a boolean
     * indicating the outcome.
    *********************************************************************/
    virtual bool encounter(Game&) = 0;

    /*********************************************************************
    ** Function: get_abb()
    ** Description: Pure virtual function to retrieve the abbreviation representing the event.
     * This function is meant to be overridden by derived classes to provide the specific abbreviation for each
     * type of event.
    ** Parameters:none
    ** Pre-Conditions:An event object exists.
    ** Post-Conditions:The function returns a character representing the abbreviation of the event.
    *********************************************************************/
    virtual char get_abb() = 0;

    /*********************************************************************
    ** Function: ~Event()
    ** Description:Destructor for the Event class.
    ** Parameters:none
    ** Pre-Conditions:An Event object exists.
    ** Post-Conditions:The Event object is destroyed, freeing allocated resources.
    *********************************************************************/
    virtual ~Event();
};
#endif
