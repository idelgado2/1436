//
//  ParkingMeter.cpp
//  COSC1436Lab9
//
//  Created by Isaac Delgado on 11/23/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#include "ParkingMeter.h"
#include <iostream>

using namespace std;

void ParkingMeter::set(int time)
//purpose: to set the time that the car was illegally parked in the private variable
//pre-condition: the time must have been passed to set the parkTime
//post-condition: sets the private variable parkTime
{
    parkTime = time;
}

void ParkingMeter::print()
//purpose: to print out the amount of time that the car illegally parked
//pre-condition: private variable named parkTime must have been initialized
//post-condition: print out the amount of time that the car illegally parked
{
    cout<< parkTime << " minutes over amount of parking time purchased\n\n";
}

