/*
File created by: Jorge Jurado-Garcia
Name: Food.ccp file
class for foods
Date: 4/30/21
Modifications:
All rights reserved
Educational purposes
*/

#include "Food.h"
#include <stdlib.h> //srand and rand
#include <iostream>

Food:: Food()
{//generic constructor
    name = 'F';
    x = rand()%19+1;
    y = rand()%19+1;
}

Food:: Food(Food &FoodCopy)
{//copy constructor
    name = FoodCopy.name;
    this->x = FoodCopy.x;
    this->y = FoodCopy.y;
}

Food:: ~Food()
{
//nothing inside
}
