/*
 * Circle.h
 *
 *  Created on: April 19, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class TwoDShape
 *
 */

  #include "Circle.h"
 #include <iostream>
 #include <sstream>

 using namespace std;
Circle::Circle()
    :TwoDShape("no name")
//only need to initalize in constructors
{
    radius = 0;
}
Circle:: Circle(float r, string name)
   //only need to initalize in constructors
    :TwoDShape(name)
{
    radius = set_radius(r);
}
Circle:: ~Circle(){
}
Circle:: set_radius(float r){
    if(r >= 0){
    radius = r;
    }
    else{
    radius = 0;
    cout<<"cannot have negative length"<<endl;
    }
    return 0;
}
void Circle:: calculateArea(){
    //area in this case is inherit from TwoDshape
    area = 3.1415*radius*radius;
}
void Circle:: calculatePerimeter(){
    //perimeter in this case is inherit from TwoDShape
    perimeter = (2*radius)*3.1415;
}
string Circle:: to_string(){
    string ret;
    ostringstream r;
    r<<radius;
    ret = Shape::to_string() +"["+ r.str() + "] " + TwoDShape::to_string();
    return ret;
}
