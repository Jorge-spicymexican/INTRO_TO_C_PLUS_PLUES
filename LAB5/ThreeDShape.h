/*
Created: ThreeDShape
 Author Jorge Jurado-Garcia
Date: 4/16/21
modifications:
4/16 creation of base sub class
*/
#ifndef THREEDSHAPE_H_INCLUDED
#define THREEDSHAPE_H_INCLUDED

#include <stdio.h>
#include <string>
#include <iostream>
#include "Shape.h"

using namespace std;

class ThreeDShape: public Shape{
protected:
    float volume;
    float surfaceArea;
public:
    ThreeDShape();
    ThreeDShape(string name);
    virtual ~ThreeDShape();

    float get_volume();
    float get_surfaceArea();

    virtual string to_string();
    virtual void calculateAll();

    virtual void calculate_Volume()=0;
    virtual void calculate_SurfaceArea()=0;
};


#endif // THREEDSHAPE_H_INCLUDED
