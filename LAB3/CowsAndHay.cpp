/*
 * Cows and Fields.ccp
 *
 *  Created on: Mar 24, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions in DairyCows and HayField
 *
 */

 #include "DairyCow.h"
 #include "HayField.h"

 #include <iostream>
 #include <stdexcept> //std::invalid argument
 #include <string>
 #include <cmath>
 using namespace std;
DairyCow::DairyCow(){
     //called when object is being created
    cout<<"***In default constructor****"<<endl;
    food = 0.0;
    water = 0.0;
}
DairyCow::DairyCow(float food, float water){
    cout<<"***In parameter constructor***"<<endl;
    set_food(food);
    set_water(water);
}
DairyCow::DairyCow(const DairyCow &CowToCopy){
    cout<<"**copy constructor***"<<endl;
    /*According to beginnerbooks.com the "this" pointer holds the address
    of current object.
    so for this problem the pointer for my variable length is equal
    to the dynamic integer of my object myRectangle. Which should have a length and width
    Reference: https://beginnersbook.com/2017/08/cpp-this-pointer/
    */
    this->food = CowToCopy.food;
    this->water = CowToCopy.water;
}
DairyCow:: set_food(float fd){
    cout<<"***setting food***"<<endl;
    if(fd<=0){
        cout<<"food cannot be negative or zero"<<endl;
        food = 0;
    }
    food = fd;
}
DairyCow:: set_water(float wr){
    cout<<"***setting water***"<<endl;
    if(wr<=0){
        cout<<"water cannot be negative or zero"<<endl;
        wr = 0;
    }
    water = wr;
}
float DairyCow:: get_food(){
    cout<<"food: ";
    return food;
}
float DairyCow:: get_water(){
    cout<<"water: ";
    return water;
}
float DairyCow::calculateMilkProduced(){
    if(water!=food){
        if(water>food){
            return 0.75*(food*2);
        }
        else{
            return 0.75*(water*2);
        }
    }
    else{
        return 0.75*(water+food);
    }
}
float DairyCow:: calculateWasteProduced(){
    if(water == food){
        return 0.35*(0.25*(food + water));
    }
    else{
         if(water>food){
            return 0.35*( (0.25*(food+food))+(water-food));
        }
        else{
            return 0.35*( (0.25*(water+water))+(food-water));
        }
    }
}
HayField::HayField(){
    cout<<"***Generic Constructor***"<<endl;
    float fieldsize=0;
    int balecount=0;
    float balesize=0;
    float drymatter=0;
}
HayField::HayField(float fieldsize, int balecount, float balesize, float drymatter){
    cout<<"***Parameter Constructor***"<<endl;
    set_fieldsize(fieldsize);
    set_baleCount(balecount);
    set_balesize(balesize);
    set_drymatter(drymatter);
}
HayField::HayField( const HayField &fieldToCopy){
 cout<<"**copy constructor***"<<endl;
    /*According to beginnerbooks.com the "this" pointer holds the address
    of current object.
    so for this problem the pointer for my variable length is equal
    to the dynamic integer of my object myRectangle. Which should have a length and width
    Reference: https://beginnersbook.com/2017/08/cpp-this-pointer/
    */
    this->fieldsize = fieldToCopy.fieldsize;
    this->balecount = fieldToCopy.balecount;
    this->balesize = fieldToCopy.balesize;
    this->drymatter = fieldToCopy.drymatter;
}
float HayField::calculateYield(){
 float top;
    top = (balecount*balesize*drymatter);
    float bottom;
    bottom = fieldsize;
    cout<<"hay [kg/hectare]: ";
    return top/bottom;
}
float HayField::calculatCarbonCapture(){
    cout<<"carbon captured [kg/hectare]: ";
    return 16000/fieldsize;
}
float HayField::get_fieldSize(){
    return fieldsize;
}
int HayField::get_baleCount(){
    return balecount;
}
float HayField::get_balsize(){
    return balesize;
}
float HayField::get_drymatter(){
    return drymatter;
}
HayField::set_fieldsize(float fldsize){
  cout<<"***setting fieldsize***"<<endl;
    if(fldsize<=0){
        cout<<"size cannot be negative or zero"<<endl;
        fieldsize = 0;
    }
    fieldsize = fldsize;
}
HayField::set_baleCount(int baleCt){
cout<<"***setting bale count***"<<endl;
    if(baleCt<=0){
        cout<<"count cannot be negative or zero"<<endl;
        balecount = 0;
    }
    balecount = baleCt;
}
HayField::set_balesize(float balesz){
cout<<"***setting bale size***"<<endl;
    if(balesz<=0){
        cout<<"size cannot be negative or zero"<<endl;
        balesize = 0;
    }
    balesize = balesz;
}
HayField::set_drymatter(float drymter){
cout<<"***setting drymatter***"<<endl;
    if(drymter<=0){
        cout<<"dry matter cannot be negative or zero"<<endl;
        drymatter = 0;
    }
    drymatter = drymter;
}
