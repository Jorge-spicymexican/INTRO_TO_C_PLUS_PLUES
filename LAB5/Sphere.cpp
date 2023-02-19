/*
Created: Sphere.ccp
Author: Jorge Jurado-Garcia
Date: 4/20/21
modifications:
*/

#include "Sphere.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Sphere::Sphere()
    :ThreeDShape("no name")
//only need to initalize in constructors
{
    radius = 0;
}
Sphere:: Sphere(float r, string name)
   //only need to initalize in constructors
    :ThreeDShape(name)
{
    if(r>=0){
    radius = r;
    }
    else{
    radius = 0;
    }
}
Sphere:: ~Sphere(){
}

void Sphere:: calculate_Volume(){
    //area in this case is inherit from TwoDshape
    volume = 3.1415*radius*radius*radius*(4/3);
}
void Sphere:: calculate_SurfaceArea(){
    //perimeter in this case is inherit from TwoDShape
    surfaceArea = 4*radius*radius*3.1415;
}
string Sphere:: to_string(){
    string ret;
    ostringstream r;
    r<<radius;
    ret = Shape::to_string() +"["+ r.str() + "] " + ThreeDShape::to_string();
    return ret;
}

