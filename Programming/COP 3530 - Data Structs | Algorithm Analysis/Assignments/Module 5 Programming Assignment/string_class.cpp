#include <iostream>
#include <fstream>
#include <string>
#include "string_class.h"
using namespace std;

//*************************************************************************************
//Name:	string_class
//Precondition: string_class object is not initialized.
//Postcondition: string_class object is initialized with currrent string value of ""
//Description: default constructor for string_class
//*************************************************************************************
string_class::string_class(){
    cout << "Defualt constructor for string_class called" << endl;
    current_string = "";    //initialize current_string as empty string
}

//*************************************************************************************
//Name:	string_class
//Precondition: string_class object is not initialized.
//Postcondition: string_class object is initialized with desired valued
//Description: explicit-value constructor for string_class
string_class::string_class(const string& initVal){
    cout << "Explicit-value constructor for string_class called" << endl;
    current_string = initVal; //initialize current_string as value input by user or varibale
}

//*************************************************************************************
//Name:	palindrome
//Precondition: string_class object is initialized with current_string value.
//Postcondition: funtion returns boolean value that indicates if string object's current_string is palindrome
//Description: function to check if current_string is a palindrome
bool string_class::palindrome(){
    cout << "Palindrome function for string_class called" << endl;

    string checkVal = current_string;   //copy current string into checkVal varibale to be checked

    int size = checkVal.size(); //get size of string
    bool check = false;         //initialize check bool to false (fail safe so no false positives)

    for(int i = 0; i < size; i++){ //run through the string
        if(tolower(checkVal[i]) == tolower(checkVal[size-1-i])){ //if lowercase chars for corresponding locations match
            check = true;   //check is true...
        }else{
            check = false;  //check is false so
            break;          //break from this loop, as one mismatch means whole thing is not a palindrome
        }
    }

    return check;           //return the check value

}

//*************************************************************************************
//Name:	replace_all
//Precondition: string_class object is initialized with current_string value.
//Postcondition: string_class object current_string value is modified according to user input
//Description: function to replace each occurrence of “old_substring” with “new_substring” in “current_string”
void string_class::replace_all(string old_substring, string new_substring){
    int oldLen = old_substring.length();    //lengths of the old
    int newLen = new_substring.length();    //and new strings
    string newString = current_string;      //copy current string into newString, will be switched back at end
    string testString = "";                 //initilize the test string (for each substring) to be empty


    if(current_string.empty()){ //if the string is empty
        cout << "The current string object is empty. Please initialize." << endl;
    }else if(old_substring.size() > current_string.size()){ //or if the old_substring is larger than it...
        cout << "The old substring is larger than the current string object. Operation Invalid." << endl;
    }else{  //if everything is all good, and those checks are passed then continue to actually perform the replacement
        int loc = newString.find_first_of(old_substring[0]);    //location of first character 

        while(loc != string::npos){     //while there exists a location in the string where the old_sub might exist 
        testString = "";    //setup the test sting to be empty

        for(int i = loc; i< (loc + oldLen); i++)    //from such location to the adequte size that the old_sub would be...
            testString += newString[i];             //add characters


            if(testString == old_substring){        //if such characters make up the old_sub
                newString.erase(loc, oldLen);       //erase the old_sub
                newString.insert(loc, new_substring);   //insert the new_sub

                if(newString[loc] != old_substring[0] || newString[loc] == new_substring[0]){     //edge cases...(as indicis are changed) so if location index is not another possible choice or isnt just the changed string
                    loc = newString.find_first_of(old_substring[0], loc + 1);   //location much be search for beyond that index
                }else{
                    loc = newString.find_first_of(old_substring[0], loc);   //location should be searched for including that incex
                }

                continue;
            }else{ //if strings dont match, continue and find another location
                loc = newString.find_first_of(old_substring[0], loc + 1); //search rest of string for another lcoation
                continue;
            }
    }
        }
        current_string = newString; //change the current string into the newly replaced string
}

//*************************************************************************************
//Name:	operator<<
//Precondition: string_class object is initialized with current_string value.
//Postcondition: string_class object current_string value is output to desried stream
//Description: function to print the contents of a string_class object’s “current_string”
ostream& operator<<(ostream& out, string_class& obj){
    out << obj.current_string;  //output the current_string variable of the string_class object to the output stream
    return out; //return the stream so chaining is possible
}


