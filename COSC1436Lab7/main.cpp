/****************************************************************
 * Theater.cpp
 * Isaac Delgado
 * COSC1436
 * 11/2/2014
 * Purpose: The purpose of this program is for the user to input
 *          a string and the string can either be reversed or be
 *          determined to be a palindrome or not. (a sentence that
 *          is teh exact same reversed.And bonus the user can create
 *          an array and type a value and program will say if the
 *          value is a memeber of the array.
 *
 * Input:   The input for this program will be numbers for decison
 *          making, on going through the menu. The user will input
 *          any string theyw want on wither reverse or palindrome 
 *          decisions. The user will also input numbers for the array
 *          they wish to create and the calue they wish to search for.
 *
 * Output:  The output of this program will start off with a menu
 *          asking the user to either reverse a string or determine
 *          if string is a palindrome. the program will also output
 *          the string in reverse or true/false for outcome of 
 *          palindrome scan and array searching.
 *****************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void Reverse(string);   //reversign string function
void sort(int [], int); //sorting functino
string extra(string );  //removing extra whitespace and chanign upper case letter function
bool palindrome(string&, int , int);    //Palindrome indecater function
bool isMember(int[], int, int, int);    //isMember function

int main (){
    int choice,
        first,  //begging of array
        last,   //end of array
        list,   //size of array
        *array, //pointer to array
        length, //length of array
        target; //target value within array
    bool repeat;
    string input, newinput;
        cout<<"Welcome to the Lab7, Where I will reverse your words and identify palindrome\n\n";
    do{
        cout<<"1. Reverse words\n";
        cout<<"2. Palindrome identifier\n";
        cout << "3. ismember function\n";
        cout<< "4. quite programe\n";
        cout<<"\t(Please enter the designated number for your choice)\n\n";
        
        cin >> choice;
        cout<< endl;
        cin.ignore();
        
        switch(choice){
            case 1:
                cout<<"1. Reverse words\n";
                cout<< "Enter a word and I will write them in reverse:\n";
                getline(cin, input);
                cout<< endl;
                Reverse(input); //reversing inputed string
                cout<< endl << endl;
                repeat = false;
                break;
            case 2:
                cout<< "2. Palindrome identifier\n";
                cout<< "Enter a word or Phrase and I will decide if it is a palindrome or not\n\n";
                getline(cin, input);
                cout<< endl;
                if (input == "") {
                    cout<< "no information entered\n\n"; //if no input was typed in
                }
                else{
                    newinput = extra(input);
                    last = (newinput.length() - 1); //deffining subscript of last element
                    if (palindrome(newinput, first = 0, last)) {    //palindrome true or false
                        cout<< "True, this is a Palindrome\n\n";
                    }
                    else{
                        cout<< "False, this is not a Palindrome\n\n";
                    }
                }
                repeat = false;
                break;
            case 3:
                cout<<"Create a list and then enter a value and I will determine if it is in your list\n\n";
                cout<< "How long do you want your list?\n\n";
                cin >> list;
                cout<<"Please enter the contents of your list\n" << "(make sure each value entered numbers)\n";
                array = new int [list];
                for ( int i = 0; i < list;  i++)
                {
                    cout << "position  "        //for loop to input each element of array
                    << (i + 1)
                    << ":";
                    
                    cin >> array[i];
                }
                cout << endl;
                cout<< "what value would you like to look for in your list:";
                cin >> target;
                cout << endl;
                sort(array, list);
                if(isMember(array, target, first = 0, list)){ //isMember function true or false
                    cout<< target << " exist in your list\n\n";
                }
                else{
                    cout<< target << " Does not exist in your list\n\n";
                }
                repeat = false;
                break;
            case 4:
                cout<< "*****goodbye*****\n\n";
                repeat = true;
                break;
            default:
                cout<< "*****Invalid input*****\n\n";
                repeat = false;
                break;
        }
    } while (!repeat);
}

void Reverse(string name){
    //purpose: to reverse an inputed string
    //pre-condition: a string passed and inputed by user
    //post-condition: prints the string in reverse order
    if(name == "") // the base case
    {
        return;
    }
    else // the recursive stepr
    {
        Reverse(name.substr(1));
        cout<<name.at(0);
    }

}
string extra(string input){
    //purpose: removes the white spaces and converts uppers to lowers in string
    //pre-condition: a string passed and inputed by user
    //post-condition: returns the new array with no white spaces or upper case letters
    string newinput;
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i]) && islower(input[i])) {
            newinput += input[i]; //input each element into array
        }
        else if (isalpha(input[i])){
            newinput += tolower(input[i]); //convert upper to lower case and inputed into array
        }
    }
    return newinput;
}
bool palindrome(string &newinput, int first, int last){
    //purpose: to identifie a string as a palindrome or not
    //pre-condition: the adress of an array and the subscript of the first and last element of passed reference array
    //post-condition: returns a true or false depending on wheather or not the string is a palindrome
    if (newinput[first] == newinput[last]) {
        if ((first - last) == 0) { //base case if there is just one letter
            return true;
        }
        else if (first == (last - 1)){  //base case if ther are only two letter
            return true;
        }
        else{
            return palindrome(newinput, first + 1, last - 1); //recursive step
        }
    } else {
        return false;
    }
}
void sort(int array[], int length){
    //purpose: to sort an array
    //pre-condition: a string passed and length specified by the user
    //post-condition: sorts the array in ascending order
    int j, temp;
    for (int i = 1; i < length; i++) {
        j = i;
        while (j > 0 && array[j -1] > array[j]) {   //swaping/sorting srray
            temp = array[j];
            array[j] = array[j - 1];
            array[j] = temp;
            j--;
        }
    }
}
bool isMember(int array[], int value, int first, int last){
    //purpose: to find a specific value in an array specifiedby the user
    //pre-condition: a string passed created by the user, the value that is being looked for and the subscript of the first and last element of the array
    //post-condition: return a true or false  depending if value is found in array.
    while (first <= last) {
        int middle = ((first + last)/2);
        if(array[middle] == value){ //binary search
            return true;
        }
        else if(array[middle] < value ){
            first = middle + 1;
            return isMember(array, value, first, last);
        }
        else if(array[middle] > value){
            last = middle - 1;
            return isMember(array, value, first, last);
        }
        else{
            return false;
        }
    }
        return false;
}