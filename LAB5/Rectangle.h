/*
Created: Jorge Jurado-Garcia
Date: 4/16/21
modifications:
4/16 creation of virtual class
4/19 add set/get adding ~Rectangle
*/
#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <stdio.h>
#include "TwoDShape.h"
#include <string>
#include <iostream>

using namespace std;

class Rectangle: public TwoDShape {
private:
    float length;
    float width;
public:
    Rectangle();
    Rectangle(float len, float w, string name);
    virtual ~Rectangle();

    set_length(float len);
    set_width(float w);

    void calculateArea();
    void calculatePerimeter();
    virtual string to_string();
};
#endif // RECTANGLE_H_INCLUDED
