/*
 * Time.h
 *
 *  Created on: Mar 28, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the date for are calendar calculator
 *
 *  March 28, 2021 Added copy constructor to accept arguments
 */
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <string>
#include <stdio.h>

using namespace std;

class Time{
private:
    int hour;
    int minute;
    int seconds;
public:
    Time();

    Time(int h, int m, int s);

    int get_hour();
    int get_minute();
    int get_seconds();

    set_hour(int h);
    set_minute(int m);
    set_seconds(int s);

    //not finished operators
    const Time operator+(const Time& obj) const;
    const Time operator-(const Time& obj) const;

    bool operator==(const Time& obj) const;
    bool operator!=(const Time& obj) const;
    bool operator<(const Time& obj) const;
    bool operator>(const Time& obj) const;

    const Time& operator=(const Time& obj)

    string to_string();

};

#endif // TIME_H_INCLUDED
