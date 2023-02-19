/*
 * MyBox.h
 *
 *  Created on: Mar 17, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the Rectangle class
 */

#ifndef MYBOX_H_INCLUDED
#define MYBOX_H_INCLUDED

#include <string>
using namespace std;

class MyBox{
public:
//these are needed functions and variables given from UML box from
//kab2.pdf on canvas MSOE
    //variables
    int length;
    int width;
    int height;

    //functions
    MyBox();
    int getSurfaceArea();
    int getVolume();

};

#endif // MYBOX_H_INCLUDED
