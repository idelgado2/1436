
/****************************************************************
 * Lab10
 * Isaac Delgado
 * COSC1436
 * 11/29/2014
 * Purpose: The purpose of this program is to ask the user to input 
 *          his/herinfomration as a new customer, the customer information
 *          will then be saved and then the program will as for how much 
 *          has been spent on then cummiliate the amount of savingins depeding 
 *          on how much the customer has spent.
 *
 * Input:   The input for this program will start with numbers for the initial 
 *          menu, then the prorgram will ask for input on personal information 
 *          (last name, first name. address, etc.). the program i will then ask 
 *          for if user will want to be on mailing list. following will be input 
 *          on how much money has been spent.
 *
 * Output:  The output of this program will start off by displaying a menu on to 
 *          start a new customer or quit the program. The Program will then out 
 *          put lables for the user/customer to input personal information. the 
 *          program will then as the user if the user wants to be on the mailing 
 *          list. lastly there will be an out put of an accumulitative discount
 *          according to the amount the of money the user/customer has spent.
 *****************************************************************/
#include <iostream>
#include "PreferredCustomer.h"
using namespace std;

int main(){
    string last, first, address, city, state, zip, phone;   //Personal information variables
    int purchases;
    bool mail;
    int answer, answer2;
    cout<< "Hello, this is Lab10!\n";
    
    do {
        cout<< "PLease choice one o fthe following paths with the corresponding number\n";
        cout<< "1. New Customer\n";             //Menu
        cout<< "2. Quit Program\n";
        cout<< "(Please input a number)\n";
        
       
        cin >> answer;
         cin.ignore();
        
        
        switch (answer) {
            case 1:
            {
                cout<< "Please enter your information below, New Customer\n\n";
                
                PreferredCustomer customer; //creating PrefferredCustomer object
                
                cout<< "Last Name: ";
                getline(cin, last);
                customer.setLastName(last); //setting Lastname of customer from parent class "PersonData"
                
                cout<< endl << "First Name: ";
                getline(cin, first);
                customer.setFirstName(first);       //setting Firstname customer from parent class "PersonData"
                
                cout<< endl << "Address: ";
                getline(cin, address);
                customer.setAddress(address);       //setting addresss of customer from parent class "PersonData"
                
                cout<< endl << "City: ";
                getline(cin, city);
                customer.setCity(city);         //setting city of customer from parent class "PersonData"
                
                cout<< endl <<"State: ";
                getline(cin, state);
                customer.setState(state);           //setting state of customer from parent class "PersonData"
                
                cout<< endl << "Zip Code: ";
                getline(cin,zip);
                customer.setZip(zip);           //setting zip code of customer from parent class "PersonData"
                
                cout<< endl << "Phone #: ";
                getline(cin, phone);
                customer.setPhone(phone);           //setting phone of customer from parent class "PersonData"
                
                cout<< endl << "Would you like to be on the Mailing list?\n(input the number for the corresponding answer)\n\n";
                
                cout<< "1. Yes \n2. No\n";
                cin >> answer2;
                
                if (answer2 == 1)
                    mail = true;
                else
                    mail = false;
                
                customer.setMailingList(mail);      //setting of customer wants to be on mailing list from parent class "CustomerData.h"
                
                cout << endl << endl;
                
                customer.printData();   //Printing customer information
                
                cout<< "Please input how much money you have spent as our valued customer for possible discounts\n";
                cout << "cumulative purchases: ";
                cin >> purchases;
                customer.setPurchasesAmount(purchases);  //setting amount of purchases to variable in PreferredCustomer class
                
                cout<< "Congradulations you get a *** " << customer.getDiscountLevel() << "% dicount on all future items\n\n";
                //Printing out discount amount
                
                break;
            }
                
            case 2:
                cout<< "*****Goodbye*****\n\n";     //quitting program
                break;
                
            default:
                cout<< "*****Wrong input, please input correct input*****\n\n";  //input validation
                answer = 1;
                break;
        }

    } while (answer == 1);  //repeat 
    
    
    
    return 0;
}


