#ifndef SHARK_H_INCLUDED
#define SHARK_H_INCLUDED

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Shark{

private:
    int teeth_per_day;


    float age;

public:
    Shark(); //generic constructor
    Shark(int teeth_per_day,float age); //parameter constructor
    Shark(const Shark &Copy); //copy constructor


    float calculate();
    int get_teeth_per_day();
    float get_age();


    set_teeth_per_day(int t);
    set_age(int a);
 
};

#endif // SHARK_H_INCLUDED
