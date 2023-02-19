/*
File created by: Jorge Jurado-Garcia
Name: LadyBugs.h file
Abstract class
Date: 5/02/21
Modifications:
All rights reserved
Educational purposes
*/
#ifndef LADYBUG_H_INCLUDED
#define LADYBUG_H_INCLUDED

#include "Insect.h"
#include "Aphids.h"

class Ladybug:
    public Insect
{
    public:
    //generic constructor
    Ladybug();

    //parameter constructor
    Ladybug(Game* current_game, int X_coord, int Y_coord);

    //stats function
    virtual std:: string stats();

    //virtual bool check(int x, int y);
    //virtual functions to override
    virtual void movement();
    virtual int check(int x, int y);
    virtual void  death();
    virtual void breed(); //breeds and returns a insect
    virtual int getInsect(); //return an insect
};

#endif // LADYBUG_H_INCLUDED
