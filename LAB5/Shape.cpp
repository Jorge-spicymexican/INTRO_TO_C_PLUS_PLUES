/*
 * Shape.ccp
 *
 *  Created on: April 16, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for abstract class Shape
 * 4/19/21 Creating set and get functions
 *
 */

 #include "Shape.h"
 #include <stdio.h>
 #include <string>
 #include <iostream>
 #include <sstream>

 using namespace std;

Shape::Shape(){
    name = "no name";
 }
Shape::Shape(string n){
    set_name(n);
}
Shape:: ~Shape(){
}
Shape::set_name(string n){
    name = n;
    return 0;
}
string Shape:: get_name(){
    return name;
}
string Shape:: to_string(){
 return name;
}
