/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: June 7, 2020                      Total Points: 20
Assignment#: 2 (nursery_inv2.cpp)

Description: Program which uses input files to "process the customer purchase orders for a nursery"

*************************************************************************************************************************/


#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>
using namespace std;	//Denotes names are being used in a standard way

//Declaration of order recoard which will be used to store information
class order_record
{
public: //accessable, defualt private
	string pname;
	string cname;
	double plant_cost;
	double quantity;
	double purchase_tax;
	double net_cost;
	double discount;
	double total_cost;
};

//Function prototypes
void input(ifstream&, order_record&); //Will use input file to input data
void output(const order_record&); //Will use input data to provide output to console
void process(order_record&); //Will process input data to do calculations.

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: Parameters such as pname, cname, etc. have not yet been initialized.
//Postcondition: Parameters such as pname, cname, etc. will be initialized with appropriate values.
//Description:  Recieves input of parameters such as pname, cname, etc. from file.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream& in, order_record& plant_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> plant_record.pname;
	in >> plant_record.cname;
	in >> plant_record.plant_cost;
	in >> plant_record.quantity;
}

///*************************************************************************************
//Name:  output
//Precondition: Parameters such as pname, cname, etc. are initialized with appropriate values.
//Postcondition: Parameters such as pname, cname, etc. will be output to the console for verificatgion
//Description:  Prints each inputted field of the order record to the console
//*************************************************************************************

void output(const order_record& plant_record)
{
	//Formatting output using "magic formulaa"
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	//Outputs the data to console for verification, \t for formatting
	cout << left << setw(10) << plant_record.pname << "\t";
	cout << left << setw(10) << plant_record.cname << "\t";
	cout << left << setw(10) << plant_record.plant_cost << "\t";
	cout << left << setw(10) << plant_record.quantity << "\t";
	cout << left << setw(10) << plant_record.net_cost << "\t";
	cout << left << setw(10) << plant_record.discount << "\t";
	cout << left << setw(10) << plant_record.purchase_tax << "\t";
	cout << left << setw(10) << plant_record.total_cost << "\t";
	cout << endl;

}

///*************************************************************************************
//Name:  process
//Precondition: Parameters such as pname, cname, etc. are initialized with appropriate values.
//Postcondition: Parameters such as purchase_tax, discount, etc. will be initialized with appropriate values.
//Description:  Calculates costs associated with order given input paramaters.
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record& plant_record)
{
	//Calculates net cost
	plant_record.net_cost = plant_record.quantity * plant_record.plant_cost;

	//Calculates purchase tax
	if(plant_record.cname == "dade"){
		plant_record.purchase_tax = plant_record.net_cost * .065;
	}else if(plant_record.cname == "broward"){
		plant_record.purchase_tax = plant_record.net_cost * .06;
	}else if(plant_record.cname == "palm"){
		plant_record.purchase_tax = plant_record.net_cost * .07;
	}else{
		plant_record.purchase_tax = plant_record.net_cost * .06; 
		//Defualts to Florida 6% state sales tax 
	}

	//if-else statements to find discount given quantity and net cost
	if(plant_record.quantity <= 0){
		plant_record.discount = 0;
	}else if(plant_record.quantity >= 1 && plant_record.quantity <= 5){
		plant_record.discount = .01 * plant_record.net_cost;
	}else if(plant_record.quantity >= 6 && plant_record.quantity <= 11){
		plant_record.discount = .03 * plant_record.net_cost;
	}else if(plant_record.quantity >= 12 && plant_record.quantity <= 20){
		plant_record.discount = .05 * plant_record.net_cost;
	}else if(plant_record.quantity >= 21 && plant_record.quantity <= 50){
		plant_record.discount = .08 * plant_record.net_cost;
	}else{
		plant_record.discount = .12 * plant_record.net_cost;
	}

	//Uses prior calculations to find total cost
	plant_record.total_cost = plant_record.net_cost + plant_record.purchase_tax - plant_record.discount;
}

//Here is your driver to test the program
int main()
{

	order_record purchase_record;

	//Decleares the input file stream as "in"
	ifstream in;
	//Opens the input file stream
	in.open("nursery_stock.txt");

	if (in.fail())  //Checks for case where input file stream fails to open
	{
		cout << "Input file could not be properally opened/accessed" << endl;
	}
	else
	{   //processes each record one at a time
		while (!in.eof()) //ensures that program has not reached EOF or end-of-file and continues checking while it has not
		{
			input(in, purchase_record);
			process(purchase_record);
			output(purchase_record);
		}
	}

	//Closes open input file stream, good habit to have.
	in.close(); 

	return 0;
}


