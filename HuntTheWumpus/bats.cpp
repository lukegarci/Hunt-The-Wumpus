/*********************************************************************
** Program Filename:bats.cpp
** Author:Luke Garci
** Date:11/29/2023
** Description:Contains the definitions for the member functions of the Bats class
** Input:none
** Output:none
*********************************************************************/

#include "bats.h"
#include "game.h"



using namespace std;

//constructor
Bats::Bats(int r, int c) : Event(r,c){
    row = r;
    col = c;
}

void Bats::percepts() {
    cout << "You hear wings flapping." << endl;
}

bool Bats::encounter(Game& g) {
    cout <<  "\nThere are bats in this room!\nThe bats have confused you!" << endl;
    return true;
}

char Bats::get_abb() {
    return 'B';
}

Bats::~Bats(){}