/*********************************************************************
** Program Filename:room.h
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the function declarations for the Room class and member variables.
** Input:none
** Output:none
*********************************************************************/

#ifndef ROOM_H
#define ROOM_H

class Event;

class Room {
private:
    Event *event;
    bool event_status;
    bool player_status;
    bool has_arrow;

public:

    /*********************************************************************
    ** Function: Room ()
    ** Description:Default constructor for the Room class.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Initializes the Room object with default values.
    *********************************************************************/
    Room();

    /*********************************************************************
    ** Function: ~Room ()
    ** Description:Destructor for the Room class.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Frees memory occupied by the event object if it exists.
    *********************************************************************/
    virtual ~Room();

    /*********************************************************************
    ** Function:set_event()
    ** Description:Sets the event for the room.
    ** Parameters:Event* new_event -pointer to the Event object to be set for the room.
    ** Pre-Conditions:none
    ** Post-Conditions:Sets the event for the room if no existing event is present.
    *********************************************************************/
    void set_event(Event *new_event);

    /*********************************************************************
    ** Function: get_event()
    ** Description:Retrieves the event of the room.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Returns a pointer to the Event object in the room.
    *********************************************************************/
    Event *get_event() const;

    /*********************************************************************
    ** Function: is_empty()const
    ** Description:Checks if the room is empty (no event).
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Returns true if the room is empty, false otherwise.
    *********************************************************************/
    bool is_empty() const;

    /*********************************************************************
    ** Function: set_player(bool)
    ** Description:Sets the player status in the room.
    ** Parameters:bool player_status - true if player is present, false otherwise.
    ** Pre-Conditions:none
    ** Post-Conditions:The player status in the room is set to the provided value.
    *********************************************************************/
    void set_player(bool player_status);

    /*********************************************************************
    ** Function: has_player() const
    ** Description:Checks if the room has a player.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Returns true if the room has a player, false otherwise.
    *********************************************************************/
    bool has_player() const;

    /*********************************************************************
    ** Function: remove_event()
    ** Description:Removes and returns the event in the room, if any.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Returns a pointer to the removed event, or nullptr if there is no event.
    *********************************************************************/
    Event *remove_event();

    /*********************************************************************
    ** Function: get_arrow()const
    ** Description:Returns true if the room has an arrow, false otherwise.
    ** Parameters:none
    ** Pre-Conditions:none
    ** Post-Conditions:Returns true if the room has an arrow, false otherwise.
    *********************************************************************/
    bool get_arrow() const;

};

#endif