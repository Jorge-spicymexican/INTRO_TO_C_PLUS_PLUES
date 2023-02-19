/*
Created: Jorge Jurado-Garcia
Date: 4/16/21
modifications:
4/16 creation of virtual class
4/19 adding set/get declaration
    adding virtual destructors
*/
#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Shape{
private:
    string name;
public:
    Shape(); //default constructor
    Shape(string n); //parameter constructor
    virtual ~Shape();

    set_name(string n);
    string get_name();

    virtual string to_string();  //virtual function
    //pure virtual function that uses for all subclass
    virtual void calculateAll()=0;
};


#endif // SHAPE_H_INCLUDED
