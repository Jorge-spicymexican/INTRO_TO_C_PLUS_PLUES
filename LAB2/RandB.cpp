/*
 * RandB.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the Rectangle and Box class
 *
 */

 #include "MyBox.h"
 #include "rectangle.h"

 #include <iostream>
 #include <string>
 using namespace std;
//this holds all the functions guts form the two classes that we are using
Rectangle::Rectangle(){
    //called when object is being created
    cout<<"***In default constructor****"<<endl;
    length = 0;
    width = 0;
}

int Rectangle::getArea(){
    cout<<"your Area:"<<endl;
    return length*width;
}
int Rectangle::getPerimeter(){
    cout<<"your Perimeter:"<<endl;
    return (2*length)+(2*width);
}
MyBox:: MyBox(){
     //called when object is being created
    cout<<"***In default constructor****"<<endl;
    length = 0;
    width = 0;
    height =0;
}
int MyBox::getSurfaceArea(){
    cout<<"your SurfaceArea:"<<endl;
    return (2*length*width) + (2*length*height) + (2*height*width);
}
int MyBox::getVolume(){
    cout<<"your Volume:"<<endl;
    return (length*height*width);
}
