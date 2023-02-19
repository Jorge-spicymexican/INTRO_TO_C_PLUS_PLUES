/*
File created by: Jorge Jurado-Garcia
Name: food.h file
Date: 4/30/21
Modifications:
All rights reserved
Educational purposes
*/
#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED


//This will be the food for aphids

class Food
{
public:
    //constructors
    Food();   //generic
    Food(Food &FoodCopy); //copy
    ~Food(); // destructor

    int x;
    int y;
    char name;
};

#endif // FOOD_H_INCLUDED
