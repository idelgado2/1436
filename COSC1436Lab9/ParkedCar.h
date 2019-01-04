//
//  ParkedCar.h
//  COSC1436Lab9
//
//  Created by Isaac Delgado on 11/23/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#ifndef COSC1436Lab9_ParkedCar_h
#define COSC1436Lab9_ParkedCar_h
#include <iostream>
using namespace std;

class ParkedCar{
private:
    string make;
    string model;
    string color;
    string license;
public:
    void set(string, string , string, string); //set car information
    void print();
};


#endif
