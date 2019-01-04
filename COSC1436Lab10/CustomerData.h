#ifndef CustomerData_H
#define CustomerData_H
#include "PersonData.h"

class CustomerData : public PersonData{
    
private:
    int customerNumber; //cutomer ID randome()
    bool mailingList;
    
public:
    //accesor and mutator functions
    CustomerData();
    int getCustomerNumber();
    
    
    void setMailingList(bool);
    bool getMailingList();
    
    void printData();
};


#endif

