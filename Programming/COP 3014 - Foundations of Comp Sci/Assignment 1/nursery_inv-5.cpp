/***********************************************************
Reynaldo Williams	        Total Points:  10
Due Date:  May 24, 2020
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: Designing a program which serves as a mean to calculate the costs associated with a 
nursery depending on the location, type of plant, quantity of said plants, and other pertinent parameters
*************************************************************/


#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <iomanip>

using namespace std;

int main()
{

	//**********MAGIC FORMULA  WILL EXPLAIN**************************
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//***************************************************************

	string user_response = "y";

	string pname;   //string that holds the plant name
	string cname;   //string that holds the county name
	double plant_cost; //double that hold the cost of a plant;
	int quantity; //int that hold the number of plants purchased;
	double purchase_tax = 0; //purchase tax, depend on county
	double net_cost = 0; //net cost to be calculated
	double discount = 0; //discount to be determined by quantity
	double total_cost = 0; //final calculation 

	while (user_response == "y" || user_response == "Y")
	{
	  //The code to get the user's input if given in the following
		//Input Statements 
		cout << "Enter the Plant Name: ";
		cin >> pname;
		cout << "Enter the County Name: ";
		cin >> cname;
		cout << "Enter the Plant Cost: ";
		cin >> plant_cost;
		cout << "Enter the Quantity: ";
		cin >> quantity;

		//Calculations
		net_cost = quantity * plant_cost;

		//if-else statements to find discount given quantity and net cost
		if(quantity <= 0){
			discount = 0;
		}else if(quantity >= 1 && quantity <= 5){
			discount = .01 * net_cost;
		}else if(quantity >= 6 && quantity <= 11){
			discount = .03 * net_cost;
		}else if(quantity >= 12 && quantity <= 20){
			discount = .05 * net_cost;
		}else if(quantity >= 21 && quantity <= 50){
			discount = .08 * net_cost;
		}else{
			discount = .12 * net_cost;
		}

		if(cname == "dade"){
			purchase_tax = net_cost * .065;
		}else if(cname == "broward"){
			purchase_tax = net_cost * .06;
		}else if(cname == "palm"){
			purchase_tax = net_cost * .07;
		}

		//calculates the final total cost, given the entered parameters
		total_cost = net_cost + purchase_tax - discount; 

		//Output Statements
		cout << endl << endl; //flushes stream
		cout << "Plant Name: " << pname << endl;
		cout << "County Name: " << cname << endl;
		cout << "Plant Cost: " << plant_cost << endl;
		cout << "Quantity of Plants: " << quantity << endl;
		cout << "Net Cost of Purchase: " << net_cost << endl;
		cout << "Purchase Tax: " << purchase_tax << endl;
		cout << "Discount on Purchase: " <<	discount << endl;
		cout << "Total Cost of Purchase: " << total_cost << endl;


		//Tests if user would like to find another calculation based on response (Y or N)
		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}

	return  0;
}