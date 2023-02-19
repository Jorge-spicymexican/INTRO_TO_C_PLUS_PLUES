/*
 * ThreeDShape.ccp
 *
 *  Created on: April 20, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class TwoDShape
 *
 */

 #include "ThreeDShape.h"
 #include <stdio.h>
 #include <string>
 #include <iostream>
 #include <sstream>

 using namespace std;

ThreeDShape::ThreeDShape(){ //will call the Shape class automatically
    volume = 0;
    surfaceArea = 0;
    //cannot access name for base class Shape
}
ThreeDShape::ThreeDShape(string name)
:Shape(name){
//well have to call the shape parameter constructor
//because the default constructor is automatically called
 volume = 0;
 surfaceArea = 0;
}
ThreeDShape:: ~ThreeDShape(){
}
float ThreeDShape::get_volume(){
    return volume;
}
float ThreeDShape::get_surfaceArea(){
    return surfaceArea;
}
string ThreeDShape::to_string(){
ostringstream out1;
ostringstream out2;
out1<<volume;
out2<<surfaceArea;
string ret;
ret = "ThreeDShape||";
ret = ret + "Volume: " + out1.str() + " SurfaceArea: " + out2.str();
return ret;
}
void ThreeDShape::calculateAll(){
    calculate_Volume();
    calculate_SurfaceArea();
}
