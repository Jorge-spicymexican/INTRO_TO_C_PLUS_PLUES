/*
 * rectangle.h
 *
 *  Created on: Mar 17, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the Rectangle class
 */


#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <string>
using namespace std;

class Rectangle{
public:
//all of these functions and variables are being given from
//UML class diagram ~lab2.pdf on canvas MSOE
  //this declares the variables being used
  int length;
  int width;

  //this declares the functions being used for this class
  Rectangle();
  int getArea();
  int getPerimeter();

};


#endif // RECTANGLE_H_INCLUDED
