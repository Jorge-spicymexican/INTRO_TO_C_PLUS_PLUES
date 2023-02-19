/*
File created by: Jorge Jurado-Garcia
Name: insect.h file
Abstract class
Date: 4/30/21
Modifications:
5/9 changing pure virtual functions to virtual
    and deleting get/set function and creating data memembers
    as protected instead of private
All rights reserved
Educational purposes
*/

#ifndef INSECT_H_INCLUDED
#define INSECT_H_INCLUDED
#include "Game.h"

class Game;

class Insect
{
public:
    //generic
    Insect();

    //parameter constructor
    Insect(Game* curgame, int X_coord, int Y_coord);


    //THIS IS WILL BE NAME, X-LOCATION, AND Y-LOCATION

    //pure virtual functions makes insects abstract base class
    virtual int check(int x, int y)=0;  //pure virtual
    virtual int getInsect() = 0 ; //pure virtual
    virtual std::string stats(); //pure virtual;
    virtual void breed()=0;
    virtual void movement();
    virtual void death()=0;

    Game* current_game;
    //game* for current_game address of the address of gameptr
    int X_coord;
    int Y_coord;

    protected:
    int timestepcount;
    int breed_count;
    int food_count;
    int life; //life expedency
    int offspring; //production
    int moves; //moves
    int consumption; //ladybugs eaten
//end of class
};
#endif // INSECT_H_INCLUDED

