/*
 * DateTime.h
 *
 *  Created on: Mar 28, 2021
 *      Author: Jorge Jurado-Garcia
 *
 *	Declares the date and time for are calendar calculator
 *
 *  March 28, 2021 Added copy constructor to accept arguments
 */

#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include "Time.h"
#include "DATE.h"
#include <string>
#include <stdio.h>

using namespace std;

class DateTime: public Time,DATE {
private:
    Date my_data;
    Time my_time;

public:
    DateTime();
    DateTime(Date,Time);

};

#endif // DATETIME_H_INCLUDED
