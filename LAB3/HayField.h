/*
 * HayField.h
 *
 *  Created on: Mar 24, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the cow class
 *  This is the official lab being done
 *
 *  March 24, 2021 Added copy constructor to accept arguments
 */
#ifndef HAYFIELD_H_INCLUDED
#define HAYFIELD_H_INCLUDED

#include <string>
#include <stdio.h>
using namespace std;

class HayField{
public:
    HayField();
    HayField(float fieldsize, int balecount, float balesize, float drymatter);
    HayField( const HayField &fieldToCopy);

    float calculateYield();
    float calculatCarbonCapture();

    float get_fieldSize();
    int get_baleCount();
    float get_balsize();
    float get_drymatter();

    set_fieldsize(float fldsize);
    set_baleCount(int baleCt);
    set_balesize(float balesz);
    set_drymatter(float drymter);
private:
    float fieldsize;
    int balecount;
    float balesize;
    float drymatter;


};

#endif // HAYFIELD_H_INCLUDED
