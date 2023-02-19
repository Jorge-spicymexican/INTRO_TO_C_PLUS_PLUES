/*
Created: Box.h
Author: Jorge Jurado-Garcia
Date: 4/20/21
modifications:
*/
#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <stdio.h>
#include "ThreeDShape.h"
#include <string>
#include <iostream>

using namespace std;

class Box: public ThreeDShape {
private:
    float length;
    float width;
    float height;
public:
    Box();
    Box(float len, float w, float h, string name);
    virtual ~Box();

    set_length(float len);
    set_width(float w);
    set_height(float h);

    void calculate_Volume();
    void calculate_SurfaceArea();
    virtual string to_string();
};
#endif // BOX_H_INCLUDED
