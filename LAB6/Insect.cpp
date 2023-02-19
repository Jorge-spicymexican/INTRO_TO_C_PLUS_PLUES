/*
File created by: Jorge Jurado-Garcia
Name: insect.ccp file
Abstract class
Date: 4/30/21
Modifications:
All rights reserved
Educational purposes
*/

#include <sstream>
#include <iostream>
#include "Insect.h"

//generic constructor
Insect:: Insect()
{
    current_game = nullptr;
    X_coord = 0;
    Y_coord = 0;
    timestepcount = 0;
    breed_count = 0;
    food_count = 0;
    life = 0; //life expedency
    offspring = 0; //production
    moves = 0; //moves
    consumption = 0; //ladybugs eaten
}

Insect:: Insect(Game* curgame, int X_coord, int Y_coord)
{
    this->current_game = curgame;
    this->X_coord = X_coord;
    this->Y_coord = Y_coord;
    //timestepcount copies the timestepcount from class game
    //since current_game is a ptr to game game*
     breed_count = 0;
    food_count = 0;
    life = 0; //life expedency
    offspring = 0; //production
    moves = 0; //moves
    consumption = 0; //ladybugs eaten
    timestepcount = curgame->timeStepCount;
}

std::string Insect:: stats()
{
    std::string ret;
    ret = " Insect ";
    return ret;
}

void Insect:: movement()
{
    if(timestepcount==current_game->timeStepCount)
  {
      return;
  }
  timestepcount++;
}
