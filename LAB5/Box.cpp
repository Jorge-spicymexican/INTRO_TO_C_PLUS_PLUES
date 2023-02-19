/*
Created: Box.ccp
Author: Jorge Jurado-Garcia
Date: 4/20/21
modifications:
*/

#include "Box.h"
#include <iostream>
#include <sstream>
using namespace std;

Box::Box()
    :ThreeDShape("no name")
//only need to initalize in constructors
{
    length = 0;
    width = 0;
    height = 0;
}
Box:: Box(float len, float w, float h, string name)
   //only need to initalize in constructors
    :ThreeDShape(name)
{
    length = set_length(len);
    width = set_width(w);
    height = set_height(h);
}
Box:: ~Box(){
}
Box:: set_length(float len){
    if(len >= 0){
    length = len;
    }
    else{
    length = 0;
    cout<<"cannot have negative length"<<endl;
    }
    return 0;
}
Box:: set_width(float w){
    if(w >=0){
    width = w;
    }
    else{
    width = 0;
    cout<<"cannot have negative width"<<endl;
    }
    return 0;
}
Box:: set_height(float h){
    if(h >=0){
    height = h;
    }
    else{
    height = 0;
    cout<<"cannot have negative width"<<endl;
    }
    return 0;
}
void Box:: calculate_Volume(){
    //area in this case is inherit from TwoDshape
    volume = length * width * height;
}
void Box:: calculate_SurfaceArea(){
    //perimeter in this case is inherit from TwoDShape
    surfaceArea = 2*( width*length + height*length + height*width);
}
string Box:: to_string(){
    string ret;
    ostringstream l;
    ostringstream w;
    ostringstream h;
    l<<length;
    w<<width;
    h<<height;
    ret = Shape::to_string() +"["+ l.str() + "," + w.str() + "," + h.str() + "] " + ThreeDShape::to_string();
    return ret;
}
