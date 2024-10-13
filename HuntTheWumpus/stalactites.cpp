/*********************************************************************
** Program Filename:stalactite.cpp
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the member function definitions for the Stalactite class.
** Input:none
** Output:none
*********************************************************************/
#include "stalactites.h"


using namespace std;

Stalactites::Stalactites(int r, int c) : Event(r,c){
    row = r;
    col = c;
}

void Stalactites::percepts() {
    cout << "You hear water dripping." << endl;
}

bool Stalactites::encounter(Game& g) {
    cout <<  "\nThere is a stalactite above you!" << endl;
    return true;
}

char Stalactites::get_abb() {
    return 'S';
}

Stalactites::~Stalactites() {}