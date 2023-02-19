#include <stdio.h>
#include <string>
#include <iostream>

#include "Shark.h"

using namespace std;
Shark::Shark(int teeth_per_day,float age){//parameter constructor
    cout<<"***In parameter constructor***"<<endl;
    //  set_teeth_per_day(t);
      //  set_age(a);
 }
 float Shark:: calculate(){
    float age_in_day = 365.0*(this->age);
    float total = (this->teeth_per_day)*age_in_day;
    return total;
 }
