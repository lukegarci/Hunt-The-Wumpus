/*********************************************************************
** Program Filename:room.cpp
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the member function definitions for the Room class.
** Input:none
** Output:none
*********************************************************************/

#include "room.h"
#include "event.h"

using namespace std;

Room::Room() : event(nullptr), event_status(false), player_status(false),has_arrow(false){}

Room::~Room() {
    if (event_status){
        delete event;
    }
}

void Room::set_event(Event* new_event) {
    // Ensure there is no existing event
    if (event == nullptr) {
        event = new_event;
        event_status = true;
    }
}

Event* Room::get_event() const {
    return event;
}

bool Room::is_empty() const {
    return event == nullptr;
}

void Room::set_player(bool status){
    player_status = status;
}

bool Room::has_player() const {
    return player_status;
}

Event* Room::remove_event() {
    if (event_status) {
        Event* removed_event = event;
        event = nullptr;
        event_status = false;
        return removed_event;
    } else {
        return nullptr;
    }
}

bool Room::get_arrow() const {
    return has_arrow;
}

