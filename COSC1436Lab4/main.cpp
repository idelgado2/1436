//
//  main.cpp
//  COSC1436Lab4
//
//  Created by Isaac Delgado on 10/7/14.
//  Copyright (c) 2014 Isaac Delgado. All rights reserved.
//

// This program demonstrates the use of dynamic arrays

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int modeOfArray( int *, int);
int medianOfArray( int *, int);


int main()

{
    
    int  *numbers;
    int	numOfNumbers,
    mode,
    median;
    
    cout<< endl;
    
    
    cout << "How many numbers do you want to put in your list: ";
    cin >> numOfNumbers;
    
    numbers = new int [numOfNumbers];
    
    
    cout << "Enter the numbers for each positions below\n";
    
    for ( int count = 0; count < numOfNumbers;  count++)
    {
        cout << "position  "
        << (count + 1)
        << ":";
        
        cin >> *(numbers + count);
	       
    }
    mode = modeOfArray(numbers, numOfNumbers);
    if(mode == -1)
        cout << "There is no mode in this list\n";
    else
        cout << mode << " is the mode of this list\n";
    median = medianOfArray( numbers, numOfNumbers);
    cout << median << " is the median of this list\n";
    cout << endl;
    for(int i = 0; i < numOfNumbers; i++)
    {
        
        cout<< *(numbers + i) << " ";
        
    }
    
    /* for ( count = 0; count < numOfNumbers; count++)
     {
     total = total + *(numbers + count);
     }
     
     average = (total / numOfNumbers);
     
     cout << "Average Monthly sale  is $" << average << endl;*/
    delete [] numbers;
    
    return 0;
}

int modeOfArray( int *array, int size){
    cout<< "in mode\n";
    int tem,
    j;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j > 0 && *(array + (j - 1)) > *(array + j)) {
            tem = *(array + j);
            *(array + j) = *(array + (j - 1)); //swaping elements
            *(array + (j - 1)) = tem;
            j--;
        }
    }
    
    int counter = 1,
    max = 0,
    mode = *(array + 0);
    bool xmode = false;
    for (int pass = 0; pass < size - 1; pass++)
    {
        if ( *(array + pass) == *(array + (pass + 1)) )
        {
            counter++;
            if ( counter > max )
            {
              		xmode = true;
                max = counter;
                mode = *(array + pass);
            }
        }
        
        else
            counter = 1; // reset counter.
    }
    //cout << "The mode is: " << mode << endl;
    
    for(int i = 0; i < size; i++)
    {
        
        cout<< *(array + i) << " ";
        
    }
    
    if(xmode == false)
        return -1;
    else
        return mode;
}

int medianOfArray(int *array, int size){
    cout<< "\nin median\n";
    int temp,
	  	temp2,
	  	j,
    median;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j > 0 && *(array + (j - 1)) > *(array + j)) {
            temp = *(array + j);
            *(array + j) = *(array + (j - 1)); //swaping elements
            *(array + (j - 1)) = temp2;
            j--;
        }
    }
    if(size % 2 != 0){// is the # of elements odd?
        temp2 = ((size+1)/2)-1;
        cout << "The median is " << *(array + temp2) << endl;
    }
    else{// then it's even! :)
        median = ((  *(array + ((size/2)-1)) +  *(array + (size / 2)) )   / 2    );
        //cout << "The median is "<< *(array + ((size/2)-1)) << " and " << *(array + (size / 2)) << endl;
    }
    
    
    /*for(int i = 0; i < size; i++)
     {
     
     cout<< *(array + i) << " ";
     
     }*/
    return median;
}

