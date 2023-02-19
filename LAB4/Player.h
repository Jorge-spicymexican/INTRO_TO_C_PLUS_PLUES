/*
Created: Jorge Jurado-Garcia
Date: 4/3/21
modifications:
4/11/21 adding name string as a private variable and function called total.
*/
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Player{

private:
    int health;
    int power;
    int speed;
    int intelligence;
    string name;

public:
    Player(); //generic constructor
    Player(string n,int h, int p, int s, int intel); //parameter constructor
    Player(const Player &PlayerCopy); //copy constructor
    virtual ~Player(); //destructor

    int total() const;
    int get_health();
    int get_power();
    int get_speed();
    int get_intelligence();
    string get_name() const;

    set_health(int h);
    set_power(int p);
    set_speed(int s);
    set_intelligence(int intel);
    set_name(string n);

    const Player operator+(const Player& obj) const;
    const Player operator-(const Player& obj) const;
    const Player& operator=(const Player& obj);

    bool operator==(const Player& obj) const;
    bool operator<(const Player& obj) const;
    bool operator>(const Player& obj) const;
    bool operator<=(const Player& obj) const;
    bool operator>=(const Player& obj) const;

    string to_string() const;
};
#endif // PLAYER_H_INCLUDED
