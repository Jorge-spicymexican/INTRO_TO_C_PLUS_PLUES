/*
 * DATE.h
 *
 *  Created on: Mar 28, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the date for are calendar calculator
 *
 *  March 28, 2021 Added copy constructor to accept arguments
 */
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <stdio.h>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date();

    Date(int y, int m, int d);

    int get_year();
    int get_month();
    int get_day();

    set_year(int y);
    set_month(int m);
    set_day(int d);

    //not finished operators

    const Date operator+(const Date& obj) const;
    const Date operator-(const Date& obj) const;

    bool operator==(const Date& obj) const;
    bool operator!=(const Date& obj) const;
    bool operator<(const Date& obj) const;
    bool operator>(const Date& obj) const;

    const Date& operator=(const Date& obj)

    string to_string();

};

#endif // DATE_H_INCLUDED
