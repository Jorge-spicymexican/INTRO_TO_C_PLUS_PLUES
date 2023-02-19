/*
 * DairyCow.h
 *
 *  Created on: Mar 24, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the cow class
 *  This is the official lab being done
 *
 *  March 24, 2021 Added copy constructor to accept arguments
 */

#ifndef DAIRYCOW_H_INCLUDED
#define DAIRYCOW_H_INCLUDED

#include <string>
#include <stdio.h>
using namespace std;

class DairyCow{
public:
    //constructor generic
    DairyCow();

    //parameter constructor
    DairyCow(float food, float water);

    //copy constructor
    DairyCow(const DairyCow &CowToCopy);

    //milk produced
    float calculateMilkProduced();

    //wasted products
    float calculateWasteProduced();

    float get_food();

    float get_water();

    set_food(float fd);

    set_water(float wr);

private:
    float food;
    float water;
};

#endif // DAIRYCOW_H_INCLUDED
