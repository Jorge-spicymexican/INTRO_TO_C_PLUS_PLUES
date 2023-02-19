/*
File created by: Jorge Jurado-Garcia
Name: Aphids.h file
Abstract class
Date: 4/30/21
Modifications:
All rights reserved
Educational purposes
*/
#ifndef APHIDS_H_INCLUDED
#define APHIDS_H_INCLUDED

#include "Insect.h"

class Aphid:
    public Insect
{
    public:
    //generic constructor
    Aphid();

    //parameter constructor
    Aphid(Game* curgame, int X_coord, int Y_coord);

    int get_x();
    int get_y();

    //virtual functions to override
    virtual void death();
    virtual int check(int x, int y);
    virtual void movement();
    virtual void breed(); //breeds and returns a insect
    virtual int getInsect(); //return an aphid
    virtual std::string stats();
};

#endif // APHIDS_H_INCLUDED
