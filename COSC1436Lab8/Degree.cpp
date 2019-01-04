//
//  Degree.cpp
//  COSC1436Lab8
//
//  Created by Isaac Delgado on 11/23/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#include "Degree.h"

void Degree::setTemp(int t)
//purpose: to set the temperature
//pre-condition: a integer is to be passed to this function
//post-condition: the integer passed will be assigned to temp
{
    temp = t;
}

bool Degree::isEthylFreezing()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Ehyl
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted freezing point and false otherwise
{
    if (temp <= -173)
        return true;
    else
        return false;
}

bool Degree::isEthylBoiling()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Ehyl
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted boiling point and false otherwise

{
    if (temp >= 172)
        return true;
    else
        return false;
}

bool Degree::isOxygenFreezing()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Oxygen
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted freezing point and false otherwise

{
    if (temp <= -362)
        return true;
    else
        return false;
}

bool Degree::isOxygenBoiling()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Oxygen
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted boiling point and false otherwise

{
    if (temp >= -306)
        return true;
    else
        return false;
}

bool Degree::isWaterFreezing()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Water
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted freezing point and false otherwise

{
    if (temp <= 32)
        return true;
    else
        return false;
}

bool Degree::isWaterBoiling()
//purpose: to return a true or false depending if the temperature is past boiling or freezing points of Water
//pre-condition: nothing is passed to this fucntion it is simply gets the temperature data
//post-condition: returns a true if temperature pasted boiling point and false otherwise

{
    if (temp >= 212)
        return true;
    else
        return false;
}

