/*************************************************************************
 * Theater.cpp
 * Isaac Delgado
 * COSC1436
 * 9/15/2014
 * Purpose: The purpose of this program is to deliver a parking ticket.
 *          This program will demonstrate aggregation of classes, with 
 *          4 classes, Police Officer.h, ParkedCar.h, ParkingMeter.h,
 *          and ParkingTicket.h. The ParkedCar class will store and
 *          print the information of the car, the ParkingMeter will
 *          store and print the amount of time the car has been parked,
 *          ParkingTicket will calculate the amount fined and print it out,
 *          and lastly Police Officer will set all the information as well
 *          as the name and badge number of the Officer.
 *
 * Input:   The input of the program will be the informatino of the officer
 *          his name and badge number, followed but the information of the car
 *          the make, model, color, and license plate will be inputed by
 *          officer/user. Then lastly the amount of time that the car has
 *          been parked illegally.
 *
 * Output:  The output of this program will start off with labels of what
 *          the officer/user will be inputing. Then the program will output
 *          ticket information that will be printed out.
 **************************************************************************/
#include "PoliceOfficer.h"
#include <iostream>
using namespace std;


int main() {
    
    string name;
    string make;
    string model;
    string color;
    string license;
    int number = 0;
    int time = 0;
    
    cout<< "Welcome to Parking Ticket Program, Lab9\n";
    cout<< "Pleas fill out the following inforamtion for the parking ticket\n\n";
    
    cout<< "Officer Name: ";
    cin >> name;
    
    cout<< "Officer Badge number: ";
    cin >> number;
    
    cout<< "Car Make: ";
    cin >> make;
    
    cout<< "Car Model: ";
    cin >> model;
    
    cout<< "Car Color: ";
    cin >> color;
    
    cout<< "Car license: ";
    cin >> license;
    
    cout<< "How many minutes has the car been illegally parked for?: ";
    cin >> time;
    
    cout<< endl << endl;

    PoliceOfficer car(name, number, make, model, color, license, time);
    //creating and instance of the class PoliceOfficer passing the information of the car
    car.printTicket();
    //Printing out the Ticket for the officer/user
    
    return 0;
}
