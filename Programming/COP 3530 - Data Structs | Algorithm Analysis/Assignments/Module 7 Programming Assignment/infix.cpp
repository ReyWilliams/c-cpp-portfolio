/********************************************************************************************
Name: Reynaldo Williams	Z#: 23506395
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 10/20/20	Due Time: 11:59 PM
Total Points: 25 
Assignment 5: Module 7 Assignment

Description: Program that uses a stack, implemented as a  singly-linked list, to convert a postfix expression to the corresponding fully-parenthesized infix expression.
*********************************************************************************************/

#include <string>
#include <iostream>
#include "stack.h"
using namespace std;

int main(){
        string postExp;

        char userInput = 'n';
        do{
            stack userStack;
            cout << "Enter a postfix expression: " << endl;
            getline(cin, postExp);

            if(isValid(postExp)){
            userStack.convert(postExp);
            cout << "Infix Expression: ";
            userStack.print();
            userStack.~stack();
            }

            cout << "Enter 'Y' to do another conversion, or enter to 'N' to exit" << endl;
            cin >> userInput;
            cin.ignore(); //ignores the endline input into stream after user inputs response to continue 
            }
            while(userInput == 'Y' || userInput == 'y');

    return 0;
}
