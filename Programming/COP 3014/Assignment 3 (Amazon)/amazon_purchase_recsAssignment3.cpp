/************************************************************************************************************************

Name: Reynaldo Williams                              Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: June 14, 2020                     Due Time: 11:59 PM
Total Points: 20
Assignment #: 3

Description: Implementing a program which will process and display amazon customer order records through input, process, and output functions
that use a combination of call by value and call by reference parameters.

*************************************************************************************************************************/

#include <iostream> //input/output stream 
#include <string> //library for us with strings
#include <fstream>  //library for file stream
using namespace std; //standard namespace 


//function prototypes for input, output, and process functions

void input(ifstream &, string &, string &, double &, double &, int &); //takes input from data file
void output(string, string, double, double, int, double, double, double, double); //outputs data from input info and what is processed
void process(double, double, int, double &, double &, double &, double &); //processes input data

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition:  Parameters such as cell_number, item_number, etc. have not yet been initialized.
//Postcondition: Parameters such as cell_number, item_number, etc. will be initialized with appropriate values.
//Description:  Recieves input of parameters such as cell_number, item_number, etc. from file.
//*************************************************************************************

void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) 
{
	in >> cell_number;
	in >> item_number;
	in >> quantity;
	in >> price;
	in >> processing_plant;
}

///*************************************************************************************
//Name:  output
//Precondition: Parameters such as cell_number, item_number, etc. are initialized with appropriate values.
//Postcondition: Parameters such as cell_number, item_number, etc. will be output to the console for verificatgion
//Description:  Prints each inputed field of the customer order record to the console
//*************************************************************************************


void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{

	//Magic formula to properly format output
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/***************************************/

	//output statements, formatted with 8 width for better formatting
	cout << left << setw(8) << cell_number << "\t";
	cout << left << setw(8) << item_number << "\t";
	cout << left << setw(8) << static_cast<int>(quantity) << "\t";
	cout << left << setw(8) << price << "\t";
	cout << left << setw(8) << processing_plant << "\t";
	cout << left << setw(8) << static_cast<int>(tax_rate) << "\t";
	cout << left << setw(8) << order_tax << "\t";
	cout << left << setw(8) << net_cost << "\t";
	cout << left << setw(8) << total_cost << "\t";
	cout << left << setw(8) << endl; //new line so each order is on a new line

}

///*************************************************************************************
//Name:  process
//Precondition: Parameters such as cell_number, item_number, etc. are initialized with appropriate values.
//Postcondition: Parameters such as cell_number, item_number, etc. will be initialized with appropriate values.
//Description:   Calculates costs associated with customer's amazon order given input paramaters.
//*************************************************************************************


//Note: there is one 1 input/output parameter
void process(double quantity, double price, int processing_plant, double &tax_rate, double &order_tax, double &net_cost, double &total_cost){
		
	if(processing_plant >= 0 && processing_plant <= 50){
		tax_rate = 6;
	}else if(processing_plant >= 51 && processing_plant <= 110){
		tax_rate = 7;
	}else if(processing_plant >= 111 && processing_plant <= 200){
		tax_rate = 8;
	}else if(processing_plant >= 201 && processing_plant <= 500){
		tax_rate = 9;
	}else if(processing_plant > 500){
		tax_rate = 11;
	}else{
		tax_rate = 8.2; //defualts to average tax rate of all values if an inproper value, such as a negative number, is entered
	}

	order_tax = quantity * price * (tax_rate/100.0); //calculates tax on an order
	net_cost = quantity * price; //calculates the net cost on an order
	total_cost = net_cost + order_tax; //calculates net cost on an order_tax
}

//Main function to test and use program
int main()
{
	//defines variables used by functions
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;	//declares input file stream with name "in"
	in.open("purchase_data.txt"); //opens input file stream from file "purchase_data.txt"

	if (in.fail()) //checks if input file stream failed to open
	{
		cout << "Input file failed to open successfully, ensure input data file and program source file are in the same directory" << endl; 
		//gives feedback to terminal to inform user that file stream did not open correctly
	}
	else
	{
		while (!in.eof()) //checks that program has not reach the end of the file
		{
			//processes each order with input, process, and output functions
			input(in, cell_number, item_number, quantity, price, processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		}
	}

	in.close(); //closes input file stream, good habit to have

	return 0;
}


