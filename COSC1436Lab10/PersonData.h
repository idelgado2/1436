#ifndef PersonData_H
#define PersonData_H
#include <iostream>
using namespace std;

class PersonData{
    
private:
    //customer information
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    
public:
    //accesor and mutator functions
    void setLastName(string);
    string getLastName();
    
    void setFirstName(string);
    string getFirstName();
    
    void setAddress(string);
    string getAddress();
    
    void setCity(string);
    string getCity();
    
    void setState(string);
    string getState();
    
    void setZip(string);
    string getZip();
    
    void setPhone(string);
    string getPhone();
};


#endif
