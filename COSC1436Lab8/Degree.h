//
//  Degree.h
//  COSC1436Lab8
//
//  Created by Isaac Delgado on 11/22/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#ifndef COSC1436Lab8_Degree_h
#define COSC1436Lab8_Degree_h

class Degree{
private:
    int temp;   //storing temperature
public:
    void setTemp(int);
    bool isEthylFreezing(), //function deciding if temperature is past freezing point of Ethyl
    isEthylBoiling(),   //function deciding if temperature is past Boiling point of Ethyl
    isOxygenFreezing(), //function deciding if temperature is past freezing point of Oxygen
    isOxygenBoiling(),  //function deciding if temperature is past Boiling point of Oxygen
    isWaterFreezing(),  //function deciding if temperature is past freezing point of Water
    isWaterBoiling();   //function deciding if temperature is past Boiling point of Water
};



#endif
