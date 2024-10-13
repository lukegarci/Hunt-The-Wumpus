/*********************************************************************
** Program Filename:wumpus.cpp
** Author: Luke Garci
** Date:11/29/2023
** Description:Contains the definitions for the member functions for the Wumpus class
** Input:none
** Output:none
*********************************************************************/

#include "wumpus.h"
#include "game.h"

#include <iostream>

using namespace std;


Wumpus::Wumpus(int r, int c) : Event(r,c){
    row = r;
    col = c;
}

void Wumpus::percepts() {
    cout << "You smell a terrible stench." << endl;
}

bool Wumpus::encounter(Game& g) {
    cout <<  "\nYou see the Wumpus and it kills you!\nGame Over!" << endl;
    return true;
}

char Wumpus::get_abb() {
    return 'W';
}

Wumpus::~Wumpus(){}

