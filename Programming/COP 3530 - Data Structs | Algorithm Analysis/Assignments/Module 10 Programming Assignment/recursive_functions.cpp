#include <string>
#include <iostream>
using namespace std;

/*****************************************************************************
//P R O G R A M	H E A D E R
//
//	Name:	Reynaldo Williams
//	Z#:	23506395
//	Instructor:	Dr. Bullard
//	Class:	Data Structures
//	Term:	Fall 2020
//	Assignment #10 (recursion)
//	Due Date:	November 17, 2020
//	Due Time:	11:59PM
//	Points:	25
//
//	Description: This program accesses your understanding of recursion and recursive functions
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printIterReverse
//Precondition: user has entered test string
//Postcondition: reversed test string is returned
//Description: Returns reversed string of input argument
///////////////////////////////////////////////////////////////////////////////////////////////
string printIterReverse(string& s){
    string reversed = "";  //declare and initialize reverse to empty string

    for(int i = s.length() -1; i>= 0; i--){  //from the end of the word to the front,
        reversed += s[i];                    //append reverse with the characters from word
    }
    return reversed;                            //reverse the reversed word
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printReverse
//Precondition: user has entered test string
//Postcondition: reversed test string is returned
//Description: Returns reversed string of input argument
///////////////////////////////////////////////////////////////////////////////////////////////
string printReverse(string& s){
    string updatedString;
    if(s.length() == 1 || s.length() == 0){ //base case(anchor): if the word is one char
        return  s;       //return that one char
    }else{                  //recursive case(inductive): if word is more then one char
        updatedString = s.substr(0, s.length() -1);
        return s[s.length() - 1] + printReverse(updatedString);
        //return the last character and then run again to keep returning the last chars
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition: user has entered test string
//Postcondition: returns true or false, depending on whethere or not input argument is palindrome
//Description: Determines whether input argument is a palindrome
///////////////////////////////////////////////////////////////////////////////////////////////
bool palindrome(string& s){
    string palin;
    if(s.length() == 1 || s.length() == 0){     //(anchort)if the word is just one char
        return true;                            //return true
    }else if(s[0] == s[s.length() - 1]){        //recursive case(inductive): if word is more then one char, check the ends match
        palin = s.substr(1, s.length() - 2);    //remove the ends
        return palindrome(palin);               //calls recursively, check new ends until word is just one char
    }else{
        return false;                           //otherwise return false
    }
}


int main(){
    string testString;
    char userResponse = 'y';
    while(userResponse == 'y' || userResponse == 'Y'){

        cout << "Enter a word to test: ";
        getline(cin, testString);

        cout << endl;
        cout << "printIterReverse Output of [" << testString << "]: " << printIterReverse(testString) << endl << endl;
        cout << "printReverse Output of [" << testString << "]: " << printReverse(testString) << endl << endl;
        cout << "palindrome Output of [" << testString << "]: ";
        if(palindrome(testString)){
            cout << "True, [" << testString << "] is a palindrome." << endl << endl;
        }else{
            cout << "False, [" << testString << "] is not a palindrome." << endl << endl;
        }

        cout << "**************************************" << endl;
        cout << "Would you like to try again? (Enter 'y or 'n'): ";
        cin >> userResponse;
        cin.ignore();
    }

    return 0;
}
