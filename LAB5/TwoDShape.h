/*
Created: TwoDShape
Author: Jorge Jurado-Garcia
Date: 4/16/21
modifications:
4/16 creation of base sub class
4/19 adding virtual constructor
     fixing parameter functions for twoDshape
*/

#ifndef TWODSHAPE_H_INCLUDED
#define TWODSHAPE_H_INCLUDED

#include <stdio.h>
#include <string>
#include <iostream>
#include "Shape.h"

using namespace std;

class TwoDShape: public Shape{
protected:
    float area;
    float perimeter;
public:
    TwoDShape();
    TwoDShape(string name);
    virtual ~TwoDShape();

    float get_area();
    float get_perimeter();

    virtual string to_string();
    virtual void calculateAll();

    virtual void calculateArea()=0;
    virtual void calculatePerimeter()=0;
};

#endif // TWODSHAPE_H_INCLUDED
