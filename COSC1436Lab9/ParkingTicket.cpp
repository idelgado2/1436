//
//  ParkingTicket.cpp
//  COSC1436Lab9
//
//  Created by Isaac Delgado on 11/23/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#include "ParkingTicket.h"
#include <iostream>
using namespace std;

void ParkingTicket::setFine(int T)
//purpose: calculates and sets the amount fined
//pre-condition: the amount of time must have been passed and intialized
//post-condition: sets the amount fined
{
    if (T < 60){
        fine = 25; //first hour illegally parked is $25
    }
    else{
        if (T % 60 == 0) {
            fine = (((T / 60) - 1) * 10) + 25; //every other hour of part of hour is $10 added to the first $25 dollar fine
        }
        else{
            fine = (floor(T / 60) * 10) + 25; //every other hour of part of hour is $10 added to the first $25 dollar fine
        }
    }
}

void ParkingTicket::print()
//purpose: to print out the amount of moey fined
//pre-condition: must have the fine initialized in the private variable
//post-condition: prints out the amount fined in parking ticket
{
    cout<< setprecision(2)<< fixed <<"\t*****Amount fined, $" << fine << "*****" << endl;
}

