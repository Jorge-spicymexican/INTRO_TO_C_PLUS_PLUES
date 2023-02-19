/*
 * Player_functions.ccp
 *
 *  Created on: April 3, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for player.h hile
 *
 */

 #include "Player.h"
 #include <stdio.h>
 #include <string>
 #include <math.h>
 #include <iostream>
 #include <sstream>

 using namespace std;

 Player::Player(){
    // cout<<"***In default constructor****"<<endl;
    health = 0;
    power = 0;
    speed= 0;
    intelligence = 0;
    name = "no name";
 }
 Player::Player(string n,int h, int p, int s, int intel){
    //cout<<"***In parameter constructor***"<<endl;
    set_health(h);
    set_power(p);
    set_speed(s);
    set_intelligence(intel);
    set_name(n);
 }
 Player::Player(const Player &PlayerCopy){
   // cout<<"**copy constructor***"<<endl;
     this->health = PlayerCopy.health;
     this->power = PlayerCopy.power;
     this->speed = PlayerCopy.speed;
     this ->intelligence = PlayerCopy.intelligence;
     this ->name = PlayerCopy.name;
 }
 Player:: ~Player(){
 }
 int Player:: get_health(){
    return health;
 }
 int Player:: get_power(){
     return power;
 }
int Player:: get_speed(){
    return speed;
}
int Player:: get_intelligence(){
    return intelligence;
}
string Player:: get_name()const{
    return name;
}
Player::  set_health(int h){
    health = h;
    return 0;
}
Player:: set_power(int p){
    power = p;
    return 0;
}
Player:: set_speed(int s){
    speed = s;
    return 0;
}
Player:: set_intelligence(int intel){
    intelligence = intel;
    return 0;
}
Player:: set_name(string n){
    name = n;
    return 0;
}
const Player Player::operator+(const Player& obj) const{
    string super_name = this->name+"+"+obj.name;
    int super_health = this->health + obj.health;
    int super_power = this->power + obj.power;
    int super_speed = this->speed + obj.speed;
    int super_intelligence = this->intelligence + obj.intelligence;
    if( ( (super_health) || (super_power) || (super_speed) || (super_intelligence) ) >= 100){
        super_health = 100;
        super_power = 100;
        super_speed = 100;
        super_intelligence = 100;
    }
    Player S1(super_name,super_health, super_power, super_speed, super_intelligence);
    return S1;
}
const Player Player::operator-(const Player& obj) const{
     string super_name = this->name+"-"+obj.name;
    int super_health, super_power, super_speed, super_intelligence;
    super_health = this->health - obj.health;
    super_power = this->power - obj.power;
    super_speed = this->speed - obj.speed;
    super_intelligence = this->intelligence - obj.intelligence;
    Player S1(super_name,super_health, super_power, super_speed, super_intelligence);
    return S1;
}
const Player& Player:: operator=(const Player& obj){
    if(this != &obj){
        health = obj.health;
        power = obj.power;
        speed = obj.speed;
        intelligence = obj.intelligence;
        name = obj.name;
    }
    return *this;
}
bool Player:: operator==(const Player& obj) const{
    //If both the operands are non-zero, then the condition becomes true.
    //compates if they are equal to each other
    //if false the return value will be zero else one
    bool health_part = this->health == obj.health;
    bool power_part = this->power == obj.power;
    bool speed_part = this->speed == obj.speed;
    bool intel_part = this->intelligence == obj.intelligence;
    bool name_part = this->name == obj.name;
    //checks for all of the values return true
    //if all the same false if different
    return( name_part && health_part && power_part && speed_part && intel_part);
}
bool Player:: operator<(const Player& obj) const{
    float total1 = (this->total());
    float total2 = (obj.total());
    bool outcome = total1 < total2;
    return outcome;
}
bool Player:: operator>(const Player& obj) const{
    float total1 = this->total();
    float total2 = obj.total();
    bool outcome = total1 > total2;
    return outcome;
}
bool Player:: operator<=(const Player& obj) const{
    float total1 = this->total();
    float total2 = obj.total();
    bool outcome;
    if( (total1 == total2) || (total1 < total2) ){
        outcome = true;
    }
    else{
        outcome = false;
    }
    return outcome;
}
bool Player:: operator>=(const Player& obj) const{
    float total1 = this->total();
    float total2 = total();
    bool outcome;
    if( (total1 == total2) || (total1 > total2) ){
        outcome = true;
    }
    else{
        outcome = false;
    }
    return outcome;
}
string Player:: to_string() const{
    ostringstream convert_h;
    ostringstream convert_p;
    ostringstream convert_s;
    ostringstream convert_i;
    convert_h << health;
    convert_p << power;
    convert_s << speed;
    convert_i << intelligence;
    string output = name+"||"+"Health:" + convert_h.str() + " Power:" + convert_p.str();
    output = output + " Speed:" + convert_s.str() + " Intel:" + convert_i.str();
    return output;
}
int Player:: total() const{
    int totals = this->health+this->speed+this->power+this->intelligence;
    return totals;
}
