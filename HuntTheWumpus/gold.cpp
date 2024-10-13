/*********************************************************************
** Program Filename:gold.cpp
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the definitions for the member functions of the Gold class
** Input:none
** Output:none
*********************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

Gold::Gold(int r, int c): Event(r,c){
    row = r;
    col = c;
}

void Gold::percepts() {
    cout <<  "You see a glimmer nearby." << endl;
}

bool Gold::encounter(Game &g) {
    cout <<  "You have found the gold!" << endl;
    return false;
}

char Gold::get_abb() {
    return 'G';
}

Gold::~Gold() {}


