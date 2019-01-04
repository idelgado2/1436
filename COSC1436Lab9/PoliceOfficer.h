#ifndef COSC1436Lab9_PoliceOfficer_h
#define COSC1436Lab9_PoliceOfficer_h
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <iostream>
using namespace std;

class PoliceOfficer{
private:
    string name;
    int badge;
    ParkedCar car; //creating instance of ParkedCar to set/print car information
    ParkingMeter meter; //creating instance of ParkingMeter to set/print parking time
    ParkingTicket ticket; //creating instacne of ParkingTicket to calculate and print amount fined
    
public:
    PoliceOfficer(string, int, string, string, string, string, int); //constructor; setting information
    void printTicket();
};


#endif
