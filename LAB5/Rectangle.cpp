/*
 * Rectangle.ccp
 *
 *  Created on: April 16, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class TwoDShape
 * 4/19 adding set definitions and changing float area to area
 * 4/20 changing code to set_lengt and set_width
 */

 #include "Rectangle.h"
 #include <iostream>
 #include <sstream>

 using namespace std;
Rectangle::Rectangle()
    :TwoDShape("no name")
//only need to initalize in constructors
{
    length = 0.0;
    width = 0.0;
}
Rectangle:: Rectangle(float len, float w, string name)
   //only need to initalize in constructors
    :TwoDShape(name)
{
    length = set_length(len);
    width = set_width(w);
}
Rectangle:: ~Rectangle(){
}
Rectangle:: set_length(float len){
    if(len >= 0){
    length = len;
    }
    else{
    length = 0;
    cout<<"cannot have negative length"<<endl;
    }
    return 0;
}
Rectangle:: set_width(float w){
    if(w >=0){
    width = w;
    }
    else{
    width = 0;
    cout<<"cannot have negative width"<<endl;
    }
    return 0;
}
void Rectangle:: calculateArea(){
    //area in this case is inherit from TwoDshape
    area = length * width;
}
void Rectangle:: calculatePerimeter(){
    //perimeter in this case is inherit from TwoDShape
    perimeter = (2*length)+(2*width);
}
string Rectangle:: to_string(){
    string ret;
    ostringstream l;
    ostringstream w;
    l<<length;
    w<<width;
    ret = Shape::to_string() +"["+ l.str() + "," + w.str() + "] " + TwoDShape::to_string();
    return ret;
}
