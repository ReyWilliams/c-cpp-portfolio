/************************************************************************************************************************

Name: Reynaldo Williams  Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: June 23, 2020        Due Time: 11:59 PM
Total Points: 20
Assignment #: 4

Description: Implementing a program which will compute the area and semiperimeter 
of an arbitrary triangle given side legnths using a specific formula
*************************************************************************************************************************/

#include <iostream> //input/output stream 
#include <string> //library for use with strings
#include <fstream>  //library for file stream
#include <iomanip> //library for i/o manipulation
#include <cmath> //librabry for math functions
using namespace std; //standard namespace 

//function prototypes
void Compute(int a, int b, int c, double &area, double &semiperimeter);
bool isTri(int a, int b, int c);
void output(int a, int b, int c, double area, double semiperimeter);


int main(){

    int a,b,c; //ints for side lengths
    double area, semiperimeter; //doubles for calculated area and semiperimeter
    char cont = 'y'; //char to check if user wants to continue, defaulted as 'y'
    char contInv; //char to check if user wants to continue after invalid side lengths

    while(cont == 'y' || cont == 'Y'){

        area=0, semiperimeter=0; //resets both calculations to 0

        cout << "Enter the three side lengths of the triangle." << endl; //prompts user for input
        cout << "Side A: ";
        cin >> a;
        cout << "Side B: ";
        cin >> b;
        cout << "Side C: ";
        cin >> c;
        cout << endl;


        if(!isTri(a,b,c)){ //if lengths are not valid...
            cout << "Your lengths are invalid. Would you like to continue computing? (y or n): " << endl; //tests if they they would like to continue computing
            cin >> contInv;

            if(contInv == 'y' || contInv == 'Y'){ //if user wants to continue calculating with invalid lengths
            output(a,b,c,area,semiperimeter); //then output with area and SP as "invalid"
            }
        }else{
            cout << "That is a valid triangle. Here are your calculations:\n" << endl; //Tells user lengths are valid

            //Computers and outputs to console
            Compute(a,b,c,area,semiperimeter); //gives area & SP value
            output(a,b,c,area,semiperimeter); //outputs all fields to console
            }

        cout << "\nWould you like to try another calculation? (y or n): " << endl; //Prompts user for more calculations
        cin >> cont; 
    }
    
    return 0;
}


///*************************************************************************************
//Name:  isTri
//Precondition:  Parameters sides A, B, and C have been initialized.
//Postcondition: Parameters sides A, B, and C are checked to be valid triangle side lengths.
//Description:  Validates whether or not side lengths create a valid triangle.
//*************************************************************************************

bool isTri(int a, int b, int c){
return( (a + b > c) && (b + c > a) && (c + a > b));
}

///*************************************************************************************
//Name:  process
//Precondition: Parameters such as sides A, B, and C are initialized with appropriate values.
//Postcondition: Parameters area and semiperimeter will be initialized with appropriate values.
//Description:   Calculates area and semiperimeter given side lengths.
//*************************************************************************************

void Compute(int a, int b, int c, double &area, double &semiperimeter){
    semiperimeter = (a + b + c)/2.0;
    area = sqrt(semiperimeter * (semiperimeter-a) * (semiperimeter - b) * (semiperimeter - c));
}

///*************************************************************************************
//Name:  output
//Precondition: Parameters such as sides A, B, and C are initialized with appropriate values.
//Postcondition: Parameters such as csides A, B, and C will be output to the console for verificatgion
//Description:  Prints each inputted side and calculations to the console
//*************************************************************************************

void output(int a, int b, int c, double area, double semiperimeter){

    //Magic Formula 
    cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

    //Column headers
    cout << left << setw(8) << "Side A";
    cout << left << setw(8) << "Side B";
    cout << left << setw(8) << "Side C";
    cout << left << setw(8) << "Semi";
    cout << left << setw(8) << "Area";
    cout << endl; 

    cout << left << setw(8) << a;
    cout << left << setw(8) << b;
    cout << left << setw(8) << c;

    if(semiperimeter == 0){ //Checks if there is no value for semiperimter
        cout << left << setw(8) << "Invalid"; 
    }else{
        cout << left << setw(8) << semiperimeter;
    }
    if(area == 0){ //Checks if there is no value for semiperimter
        cout << left << setw(8) << "Invalid";
    }else{
        cout << left << setw(8) << area;
    }

    cout << endl; 
    

}