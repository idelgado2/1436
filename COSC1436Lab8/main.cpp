/********************************************************************
 * Theater.cpp
 * Isaac Delgado
 * COSC1436
 * 11/11/2014
 * Purpose: The purpose of this program is for the user to enter a 
 *          temperature and the program will output if Ethyl Alcohol
 *          Oxygen, and Water are freezing and boiling at the 
 *          temperature that was givin by the user.
 *
 * Input:   The input for this program will be simply the temperature
 *          givin by the user.
 *
 * Output:  The output of this program will be couts containing if
 *          Ethyl Alcool, Oxygen, or Water are freexing or boiling
 *          at this temperature.
 *********************************************************************/

#include <iostream>
#include "Degree.h"
using namespace std;


int main(){
    
    Degree test;
    
    int temperature, choice;
    bool repeat;
    do {
        
        temperature = 0; //default for temperature incase of repeat
        repeat = false; //default for repeat incase of repeat
        
        cout<< "Please enter a temperature and I will decide if Ethyl Alcohol, Water, or Oxygen boils or freezes at such a temperature\n\n";
        cout<< "Temperature: ";
        
        cin >> temperature;
        test.setTemp(temperature);  //setting temperature in class for functions
        
        
        if (test.isEthylFreezing())
            cout<<"Ethyl Alcohol is Freezing at this temperature\n";
        else if(test.isEthylBoiling())
            cout<<"Ethyl Alcohol is Boiling at this temperature\n";
        
        if (test.isOxygenFreezing())
            cout<<"Oxygen is Freezing at this temperature\n";
        else if(test.isOxygenBoiling())
            cout<<"Oxygen is Boiling at this temperature\n";
        
        if (test.isWaterFreezing())
            cout<<"Water is Freezing at this temperature\n";
        else if(test.isWaterBoiling())
            cout<<"Water is Boiling at this temperature\n";
        
        cout<< endl;
        
        cout<< "Would you like to test out another temperature??\n";
        cout<< "1. Yes \n2. No";
        cout<< "(please input the corresponding number)\n";
        
        cin >> choice;
        cout<< endl;
        
        if (choice == 1)
            repeat = true;
        
    } while (repeat); //repeat decison
    
    cout<< "*****goodbye*****\n";
    
    
    return 0;
}




