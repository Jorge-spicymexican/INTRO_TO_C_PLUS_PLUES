/*
 * TwoDShape.ccp
 *
 *  Created on: April 16, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class TwoDShape
 *
 */

 #include "TwoDShape.h"
 #include <stdio.h>
 #include <string>
 #include <iostream>
 #include <sstream>

 using namespace std;

TwoDShape::TwoDShape(){ //will call the Shape class automatically
    area = 0;
    perimeter = 0;
    //cannot acces name for base class Shape
}
TwoDShape::TwoDShape(string name)
:Shape(name){
//well have to call the shape parameter constructor
//because the default constructor is automatically called
 area = 0;
 perimeter = 0;
}
TwoDShape:: ~TwoDShape(){
}
float TwoDShape::get_area(){
    return area;
}
float TwoDShape::get_perimeter(){
    return perimeter;
}
string TwoDShape::to_string(){
ostringstream out1;
ostringstream out2;
out1<<area;
out2<<perimeter;
string ret;
ret = "TwoDShape||";
ret = ret + "Area: " + out1.str() + " Perimeter: " + out2.str();
return ret;
}
void TwoDShape::calculateAll(){
    calculateArea();
    calculatePerimeter();
}
