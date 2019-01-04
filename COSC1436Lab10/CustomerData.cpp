#include "CustomerData.h"

CustomerData::CustomerData()
//purpose:  to set the mcustomerNumber to a randome integer
//pre-condition: no precondition, custonmernumber must only be initialzed as an integer
//post-condition: randome number initalized to customerNumber
    {
        customerNumber = rand();
    }

int CustomerData::getCustomerNumber()
//purpose:  to return custonmerNumber
//pre-condition: no pre condition
//post-condition: returns the value in customerNumber
    {
        return customerNumber;
    }

void CustomerData::setMailingList(bool mail)
//purpose:  to set the memeber variable mail with parameter
//pre-condition: passed string for initializing member variable
//post-condition: memebre variable is initialized
    {
        mailingList = mail;
    }

bool CustomerData::getMailingList()
//purpose:  to return mailingList
//pre-condition: no pre condition
//post-condition: returns the value in mailingList
    {
        return mailingList;
    }

void CustomerData::printData()
//purpose:  prints out the customers personal information
//pre-condition: no pre condition
//post-condition: prints out the information of the customer

    {
    
        cout<< "Customer #" << getCustomerNumber() << endl;
    
        cout<< "Name: " << getLastName() << ", " << getFirstName() << endl;
    
        cout<< "Mailing Address: " << getAddress() << ", " << getCity() << ", " << getState() << ", " << getZip() << endl;
    
        cout<< "Phone #: " << getPhone() << endl;
    
        cout<< "*****Customer is on the Mailing List*****" << endl << endl;
    }
