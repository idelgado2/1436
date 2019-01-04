/****************************************************************
 * Theater.cpp
 * Isaac Delgado
 * COSC1436
 * 10/6/2014
 * Purpose: The purpose of this program is for the user to be able
 *          to create a profile where the user can then set up a
 *          First name, last name, username, and password for the
 *          created profile. The user will also be able to log in
 *          with the credentials that created by the user.
 *
 * Input:   The input for this program will be numbers for decison
 *          making, on going through the menu. If the user logs in
 *          The user will also be able to enter, their first and last
 *          name, as werll as a username, password, address, phone
 *          number and email.
 *
 * Output:  The output of this program will start off with a menu
 *          asking the user to either log in, sign up , or extit
 *          the program. By signing up the program will ask for
 *          first name, last name, username, and password as well
 *          verifiing the password. when loging in ther will outputed
 *          another menu on optinons of editing personal information
 *          it will ask for address, email, and phone number if
 *          user chooses.
 *****************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct address{     //Struct for the address
    int housenumber;
    string street;
    string city;
    string state;
};

struct profile{     //Struct for users profile
    string Fname;
    string Lname;
    string Uname;
    string pass;
    address location;
    string email;
    long long int phone;
};

int Search(vector<profile> &, int, string);  //to search through usernames
void info (vector<profile> &, int); //to disblay and function through persnal information of user
void ShowStruct(vector<profile> &, int);    //to show users personal information

int main (){
    int choice,
        count = 0,
        Aposition = 0,
        position = 0;
    
    bool repeat,
        validpass,
        validuser,
        validuser1;
    
    string vpass,
            username,
            password;
    
    
    vector <profile> person; ///vecotor of profile structs
    
    cout<<"Welcome to the Lab6, personal profile program\n\n";
    do{
        cout<<"1. Sign Up for the system\n";
        cout<<"2. Log In to the system\n";
        cout<<"3. Exit the system\n";
        cout<<"\t(Please enter the designated number for your choice)\n\n";
        cin >> choice;
        cin.ignore();
        
        switch(choice){
            case 1: //sign up as a new user
                person.push_back(profile());
                
                cout<<"1. Sign Up for the system\n" << endl;
                
                cout<<"Enter First Name: ";             //First Name
                getline(cin, person[Aposition].Fname);
                cout <<endl << endl;
                
                cout<<"Enter Last Name: ";              //Last Name
                getline(cin, person[Aposition].Lname);
                cout <<endl << endl;
                
                cout<<"Enter Username: ";               //Username
                getline(cin, person[Aposition].Uname);
                cout << endl << endl;
                
                
                do {
                    cout<<"Enter Password: ";               //Password
                    getline(cin, person[Aposition].pass);
                    cout <<endl << endl;
                    validpass = true;
                    
                    cout<< "Please re-enter password for varification: ";
                    getline(cin, vpass);
                    cout << endl << endl;
                    
                    if (person[Aposition].pass != vpass) {          // if varification password does not match
                        cout<< "*****Not equal, Please re-enter password*****\n" << endl;
                        validpass = false;
                    }
                    else{
                        cout<< "*****Password Varified, Thank You for signing up for Lab6*****\n"<< endl;
                    }
                    
                } while (!validpass);
                
                person[Aposition].phone = 0;    // initializing phone to 0 for this profile
                
                Aposition++;   //increment size of vector for next time another user signs up
                repeat = true;
                break;
            case 2: //Log in as a user
                cout<<"2. Log In to the system\n" << endl;
                do {
                    cout<< "Please enter Your Username and password below\n" << endl;
                    cout<< "Username: ";
                    getline(cin, username);
                    validuser = true;
                    position = Search(person, person.size(), username);         //searching if user exist or not
                    if (position < 0) {
                        cout << "*****There is no such Username, Please enter agin*****\n" << endl;
                        validuser = false;
                    }
                } while (!validuser);
                
                do {
                    cout<<"Password: ";
                    getline(cin, password);
                    
                    cout<< endl << endl;

                    if (person[position].pass == password) {        //checking if password is valid to the specific usernaem
                        cout<< "Welcome, " << person[position].Fname << endl << endl;
                        info(person, position);     //print out personal info and menu to edit peronal info
                        cout<< endl << endl;
                        count = 2;
                    }
                    else{
                        cout<< "*****Invalid Password, You have one more try*****\n" << endl;
                        count++;
                    }
                    
                } while (count < 2);
                repeat = true;
                break;
            case 3: //exit program
                cout<<"3. Exit the system\n";
                repeat = false;
                break;
            default:
                repeat = true;
                break;
        }
    }while(repeat);
    
    return 0;
}

int Search(vector<profile> &people, int length, string value)
//purpose: to search through a vector of profiles
//pre-condition: vecotor array of data type profile initialized, the length of the vecto, and a string of the username being searched for
//post-condition: returns the position of the username, or a -1 if the username was not found
{
    for (unsigned int i = 0 ; i < length; i++) {
        if (people[i].Uname == value)
            return i;
    }
    return -1;
}

void info(vector<profile> &edit, int i)
//purpose: to display the menus for editing personal profile, and changing the personal information
//pre-condition: vecotor array of data type profile initialized and integer representing the position of the struct
//post-condition: does not return anything but edits the contents in the passed vector
{
    int choice;
    bool repeat = true;
    do {
        
    cout<< endl<< endl;
    cout<< "*****Your Current information*****\n" << endl;
    ShowStruct(edit, i);
    cout<< endl << endl;
 
    cout<< "If you would like to edit your profile, please choose the item that you would like to edit\n";
    cout<< "Otherwise you can Sign out\n" << endl;
    cout<<"1. First Name\n";
    cout<<"2. Last Name\n";
    cout<<"3. Address\n";
    cout<<"4. E-mail\n";
    cout<<"5. Phone number\n";
    cout<<"6. Sign Out\n";
    cout<<"\t(Please enter the designated number for your choice)\n\n";
    
    cin >> choice;
 
    switch (choice) {
        case 1:
            cout<<"1. First Name\n";
            cout<< "Please type in your new First Name\n";
            cout<< "Enter First Name: ";
            cin >> edit[i].Fname;
            break;
        case 2:
            cout<<"2. Last Name\n";
            cout<< "Please type in your new Last Name\n";
            cout<< "Enter Last Name: ";
            cin >> edit[i].Lname;
            break;
        case 3:
            cout<<"3. Address\n";
            cout<< "Please type in your new Address\n";
            cout<< "Enter House number: ";
            cin >> edit[i].location.housenumber;
            cout<< "Enter Street Name: ";
            cin >> edit[i].location.street;
            cout<< "Enter City: ";
            cin >> edit[i].location.city;
            cout<< "Enter State: ";
            cin >> edit[i].location.state;
            break;
        case 4:
            cout<<"4. E-mail\n";
            cout<< "Please type in your new E-mail\n";
            cout<< "Enter E-mail: ";
            cin >> edit[i].email;
            break;
        case 5:
            cout<<"5. Phone Number\n";
            cout<< "Please type in your new Phone Number\n";
            cout<< "Enter Phone Number: ";
            cin >> edit[i].phone;
            break;
        case 6:
            cout<<"6. Sign Out\n";
            repeat = false;
            break;
            
        default:
            cout<< "*****Please input a valid choice*****\n\n";
            break;
    }
    
    } while (repeat);
 
 }

void ShowStruct(vector<profile> &info, int i)
//purpose: to display the contents of the users personal information
//pre-condition: vecotor array of data type profile initialized and integer representing the position of the struct
//post-condition: displays the contents does not return anything.
{
    cout<< "First Name:" << setw(10) << info[i].Fname << endl;
    cout<< "Last Name:" << setw(10) <<info[i].Lname << endl;
    cout<< "Address:" << setw(10) <<info[i].location.housenumber << " " << info[i].location.street << ", " << info[i].location.city << ", " << info[i].location.state<< endl;
    cout<< "E-mail:" << setw(10)<< info[i].email << endl;
    cout<< "Phone Number:"<< setw(10) << info[i].phone << endl;
}
