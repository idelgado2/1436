/*****************************************************
 * Theater.cpp
 * Isaac Delgado
 * COSC1436
 * 9/15/2014
 * Purpose: The purpose of this program is to start the program
 *          off with a visual seating chart of a theater made up
 *          of "#" for available seats and "*" for taken bought
 *          seats. The program will also keep track of the amount
 *          of money being spent and give the user opitions on
 *          seeing this total amount, throughout the program as 
 *          well as seeing the availablity of seats and seeing
 *          the seating chart agin.
 *
 * Input:   The input for this program is all numbers. The program
 *          will open a file called "prices.txt" and input prices
 *          to align to the specific rows in the program. The program
 *          expect to recive either a (1, 2, 3, 4, or 5) from user
 *          through (cin>>)commands.
 *
 * Output:  The output of this program will start off with a Table
 *          representing the theater of seats. then a menu follow.
 *          the menu will consist of 5 options, first if you want 
 *          to buy a ticket, second the availabilty of seats 
 *          (showing the available seats in each row, the whole theater
 *          and how many seats ahve been sold already), third will
 *          will show the total amount due, fourth will output the 
 *          the seating chart agin, and finally the fifth option
 *          will close the program. every out put in this program
 *          will be outputed through (cout<<) commands.
 ***************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int COLS = 30; //initialize columns of theater
const int ROWS = 15; //initialize rows of Theater
void showTheater(string[][COLS],int); //function to print out seating chart
int main(){
    string Theater[ROWS][COLS];
    bool available[15][30]; //parrallel 2D array for seats that are available or not
    double line, total;
    double prices[15];  //parallel array for prices of each row
    int choice, chosenRow, chosenSeat, soldseats = 0;
    bool error = true;
    ifstream myfile("prices.txt");    //inputing file of prices
    if (myfile.is_open()) {
        cout<< endl<< endl;
        cout<< "*****Inputing prices for rows from file*****.....\n";
        for (int i = 0; i <= 15; i++) {
            myfile >> line;
            prices[i] = line; //initializing price[] with prices
        }
        myfile.close();  //closing previously opened file
    }
    else{
        cout<< "*****Unable to open file****";
    }
    
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 30; y++) {
            //initializing Theater[][] with "#"
            Theater[x][y] = "#";
            //initializing available[][] with Truth values
            available[x][y] = true;
        }
    }
    cout<< endl;
    cout<< setw(35) << "Welcome to the Theater\n";
    showTheater(Theater, ROWS);    //priniting out the theater
    cout<< endl;
    do{
        cout<< endl;
        cout<< setw(20)<< "Menu\n";        //Menu and options printing
        cout<< "1. Buy Ticket(s)\n";
        cout<< "2. Availability\n";
        cout<< "3. Total Purchased\n";
        cout<< "4. Seating Chart\n";
        cout<< "5. Exit Program\n";
        cout<< "Please input (1, 2, 3, 4, or 5)\n";
        
        cin >> choice;
        switch (choice) {
            case 1:   //choice 1, buying a ticket
                do {
                   do {
                    do {
                        cout<<"What Row would you like to sit in\n";
                        cin >> chosenRow;     //getting desired row from user
                        error = true;
                        if(chosenRow < 1 || chosenRow > 15){
                            cout<<"*****PLease choose a valid row choose another*****\n\n";   //input validation
                            error = false;
                        }
                    } while (!error);
                    do {
                        cout << "What seat would you like\n";
                        cin >> chosenSeat;     // getting desired seat from user
                        error = true;
                        if(chosenSeat < 1 || chosenSeat > 30){
                            cout<< "*****PLease choose a valid seat choose another*****\n\n";   //input validation
                            error = false;
                        }
                    } while (!error);
                    
                    if (!available[chosenRow - 1][chosenSeat - 1]) {
                        cout<< "\n*****Sorry that Seat is already taken*****\n"; //input validation, if seat is available or already taken
                        cout<< "*****PLease choose another*****\n\n";
                        error = false;
                    }
                    else{
                        error = true;
                      }
                   } while(!error);
                    
                    Theater[chosenRow - 1][chosenSeat - 1] = "*"; //initalizing sold theater seat with "*" reaplacing "#"
                    available[chosenRow - 1][chosenSeat - 1] = false; //initalizing seats truth value
                    total += prices[chosenRow - 1];  //incrementing total cash due
                    soldseats++;  //incrementing number of sold seats
                    cout<< "*****Your Total is $"<< total <<"*****\n";
                    cout<< "Would you like to buy another ticket??\n";
                    cout<< "1. Yes\n2. No go back to menu\n";
                    cout<< "Please input (1 or 2)\n";
                    cin >> choice;  //choice to buy another ticket or go back to menu
                    if (choice == 1)
                        error = false;
                    else
                        error = true;
                } while (!error);
                
                break;
            case 2: //choice to see the availablity of seats
                cout<<"*****There has been " << soldseats << " seats sold so far*****\n";
                cout<< "*****There are currently "<< (450 - soldseats) << " seats left in the Theater*****\n";
                cout<< "***************************\n";
                for (int x = 0; x < 15; x++) {
                    int availseats = 0;
                    for (int y = 0; y < 30; y++) {   //nested for loops to show availablity of seats in each row
                        if (!available[x][y]) {
                            availseats++;
                        }
                    }
                    cout<<"Row "<< (x+1) <<" has " <<(30 - availseats) << "seats available\n";
                }
                cout<< "****************************\n";
                break;
            case 3: //choice to show total cash due
                cout<< "*****Your Total is $"<< total <<"*****"<< endl;
                break;
            case 4: //choice to show seating chart of theater
                showTheater(Theater, ROWS);
                cout<< endl;
                break;
            case 5: //choice to end program
                break;
            default:
                cout<<"*****PLease choose a valid choice*****\n\n";
                break;
        }
    } while (choice != 5); //input validation loop
    
    return 0;
}
void showTheater(string array[][COLS],int row){
    /* Purpose: Print out a table of 15 Rows and 30 Columns
                representing the Rows and Seats of a Theater, 
                using "*" for taken seats and "#" for available
                seats as well as print out defining Rows and seats
                along x-axis and y-axis.
       Precondition: A 2D array has been passed with pre-designated
                     constant varibles COLS, and row.
       Postcondition: The function will Print out the seating chart defining
                      the Rows and seats along the x-axis and y-axis.*/
    cout<< setw(25)<< "seats\n";
    cout<< setw(10);
    for (int i = 1; i < 10; i++) {
        //loop to print out first 9 seat lables on top of seating chart
        cout<< i;
    }
    
    for (int i = 0; i < 2; i++) {
    for (int h = 0; h < 10; h++)
        //nested loop to print out remaining seat lables
            cout<< h;
    }
            //printing out last lable of last column of seats
            cout<< 0;
    
    
    /* Split the printing seating chart into two nested loops to have 
       perfect alignment*/
    for (int x = 0; x < 9; x++) {
        cout<< endl;
        //printing out first 9 Rows and Row number
        cout<< "Row " << (x+1) << setw(5);
        for (int y = 0; y < 30; y++) {
            //printing out the actual chart of "#" and "*"
            cout<< array[x][y];
        }
    }
    
    for (int x = 9; x < 15; x++) {
        cout<< endl;
        //printing out last 21 Rows with Row numbers
        cout<< "Row "<< (x+1) << setw(4);
        for (int y = 0; y < 30; y++) {
            //printing out the actual chart of the last 21 rows
            //of "#" and "*"
            cout<< array[x][y];
        }
    }
    
    
}

