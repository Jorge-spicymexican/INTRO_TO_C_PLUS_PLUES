/*
 * Circle.h
 *
 *  Created on: April 19, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class TwoDShape
 *
 */

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "TwoDShape.h"
#include <iostream>
#include <sstream>

 using namespace std;

class Circle: public TwoDShape {
private:
    float radius;
public:
    Circle();
    Circle(float r, string name);
    virtual ~Circle();

    set_radius(float r);

    void calculateArea();
    void calculatePerimeter();
    virtual string to_string();
};

#endif // CIRCLE_H_INCLUDED
