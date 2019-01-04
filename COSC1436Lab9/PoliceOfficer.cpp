#include "PoliceOfficer.h"
#include <iostream>
using namespace std;


PoliceOfficer::PoliceOfficer(string officer, int number, string make, string model ,string color, string license, int time)
//purpose: to set Police Officer's informatino and to set other car information, time, and calculate fine
//pre-condition: name of officer, make of car, model of car, color of car, licenese of car, and amount of time parked should be intialized and passed
//post-condition: sets all the information int he private variables of all the classes
{
    name = officer;
    badge = number;
    
    car.set(make, model, color, license);
    meter.set(time);
    ticket.setFine(time);
}

void PoliceOfficer::printTicket()
//purpose: to print out The ticket issued by Officer/user
//pre-condition: all private variables for all classes must have been initialized
//post-condition: prints out car inforamtion, time parked, amount of money that is owed, and the name of the officer and badge number
{
    cout<< "**********Parking Violation, Ticket**********\n\n";
    cout<< "Ticket issued by:\n\n";
    cout<< "Officer: "<< name << endl;
    cout<< "Badge #: "<< badge << endl << endl;
    cout<< "**********Vehical Information**********\n\n";
    car.print();
    cout<< "**********Time ilegally parked**********\n\n";
    meter.print();
    cout<< "**********Amount fined**********\n\n";
    ticket.print();
    
}

