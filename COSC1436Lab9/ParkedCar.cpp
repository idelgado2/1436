//
//  ParkedCar.cpp
//  COSC1436Lab9
//
//  Created by Isaac Delgado on 11/23/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

#include "ParkedCar.h"
#include <iostream>
using namespace std;

void ParkedCar::set(string setMake, string setModel, string setColor, string setLicense )
//purpose: to set car inofrmation in private variables
//pre-condition: car make, model, color, and license initialized
//post-condition: this function will have set the car information in the private variables
{
    make = setMake;
    model = setModel;
    color = setColor;
    license = setLicense;
}
void ParkedCar::print()
//purpose: Print out the car information
//pre-condition: must have all ParkedCar private variables initialized
//post-condition: print car information
{
    cout<< "Car Make: " << make << endl;
    cout<< "Car Model: " << model << endl;
    cout<< "Car Color: " << color << endl;
    cout<< "Car License: " << license << endl << endl;
    
    
    
}

