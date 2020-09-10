/*						Total Points: 10
Reynaldo Williams
Z23506395
Due Date:  May 31, 2020
Course:  C0P3014
Assignment:  Assignment 1 - Nursery
Professor: Dr. Lofton Bullard

Description: Designing a program which serves as a mean to calculate the costs associated with a 
nursery depending on the location, type of plant, pQuan of said plants, and other pertinent parameters
*/


//Directives for commands like cout, cin, and string to work
#include <iostream>
#include <string> 
#include <iomanip>

//Indicates we are using names in a standard way
using namespace std;

int main(){

    //Formatting output to show decimal points and round to two places(precision)
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //String user input to indicate if they would like to continue
    string userCont = "y";

    //Declaring variables for calculations and further user input
    string pName; //Plant's name
    string cName; //Name of County
    int pQuan; //quantity of plants
    double pCost; //Cost of plant
    double purchTax; //Purchase Tax on Transaction
    double netCost; //Net cost of transaction
    double purchDiscount; //Calculated discount on purchase
    double finalCost; //Final Cost calculated by input

    while (userCont == "y" || userCont == "Y"){ //Gathers user input
		//Input Statements 
		cout << "Enter the Plant Name: ";
		cin >> pName;
		cout << "Enter the County Name: ";
		cin >> cName;
		cout << "Enter the Plant Cost: ";
		cin >> pCost;
		cout << "Enter the quantity: ";
		cin >> pQuan;

        //Calculating net cost
        netCost = pQuan * pCost; 

        //Calculating purchase tax given county
        if(cName == "dade"){
			purchTax = netCost * (6.5/100.0);
		}else if(cName == "broward"){
			purchTax = netCost * (6.0/100.0);
		}else if(cName == "palm"){
			purchTax = netCost * (7.0/100.0);
		}

        //if-else statements to find discount given quantity and net cost
		if(pQuan <= 0){
			purchDiscount = 0;
		}else if(pQuan >= 1 && pQuan <= 5){
			purchDiscount = (1.0/100.0) * netCost;
		}else if(pQuan >= 6 && pQuan <= 11){
			purchDiscount = (3.0/100.0) * netCost;
		}else if(pQuan >= 12 && pQuan <= 20){
			purchDiscount = (5.0/100.0) * netCost;
		}else if(pQuan >= 21 && pQuan <= 50){
			purchDiscount = (8.0/100.0) * netCost;
		}else{
			purchDiscount = (12.0/100.0) * netCost;
		}

        //Calculates Final cost read to user
        finalCost = netCost + purchTax - purchDiscount;


        //Output Statements
		cout << endl << endl; //flushes stream
		cout << "Plant Name: " << pName << endl;
		cout << "County Name: " << cName << endl;
		cout << "Plant Cost: " << pCost << endl;
		cout << "Quantity of Plants: " << pQuan << endl;
		cout << "Net Cost of Purchase: " << netCost << endl;
		cout << "Purchase Tax: " << purchTax << endl;
		cout << "Discount on Purchase: " <<	purchDiscount << endl;
		cout << "Total Cost of Purchase: " << finalCost << endl;


        //Checks if user would like to find another calculation based on response (Y or N)
		cout << "\nWould you like to do another calculation (Y or N): " << endl;
		cin >> userCont;

    }
    return 0;
}


