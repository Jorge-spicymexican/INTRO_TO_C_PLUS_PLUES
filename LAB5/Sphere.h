/*
Created: Sphere.h
Author: Jorge Jurado-Garcia
Date: 4/20/21
modifications:
*/
#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include "ThreeDShape.h"
#include <iostream>
#include <sstream>

 using namespace std;

class Sphere: public ThreeDShape {
private:
    float radius;
public:
    Sphere();
    Sphere(float r, string name);
    virtual ~Sphere();
    void calculate_Volume();
    void calculate_SurfaceArea();
    virtual string to_string();
};


#endif // SPHERE_H_INCLUDED
