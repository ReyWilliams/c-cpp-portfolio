
/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: June 30, 2020                      Total Points: 10
Assignment#: 5 (nursery_inv3.cpp)

Description: Program which uses input files to "process the customer purchase orders for a nursery"
*************************************************************************************************************************/

#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std;	//Denotes names are being used in a standard way

//Declaration for order record
class order_record{
public:
	string pname;
	string cname;
	double plant_cost;
	int quantity;
	double purchase_tax;
	double net_cost;
	double tax_rate;
	double discount;
	double total_cost;
};

void input(ifstream& in, order_record& order_record); //Will use input file to input data
void output(ofstream& out, const order_record customer_order); //Will use input data to provide output to console
void process(order_record& order_record); //Will process input data to do calculations.

///*************************************************************************************
//Name:  input
//Precondition: Parameters such as pname, cname, etc. have not yet been initialized into an order record.
//Postcondition: Parameters such as pname, cname, etc. will be initialized with appropriate values into an order record.
//Description:  Recieves input of parameters such as pname, cname, etc. from file and stores them in an order record.
//*************************************************************************************

void input(ifstream& in, order_record& order_record){ 
	cout << "Running function input..." << endl; //gives feedback on function progress
	
	in >> order_record.pname;
	in >> order_record.cname;
	in >> order_record.plant_cost;
	in >> order_record.quantity;

	cout << "Successfully ran function intput!\n" << endl; //gives feedback on function progress
}

//*************************************************************************************
//Name:  process
//Precondition: Parameters such as pname, cname, etc. are initialized with appropriate values into an order record.
//Postcondition: Parameters such as purchase_tax, discount, etc. will be initialized with appropriate values into an order record.
//Description:  Calculates costs associated with order given input paramaters and stores them into appropriate fields in order record.
//*************************************************************************************

void process(order_record& order_record){
	cout << "Running function process..." << endl; //gives feedback on function progress

	//Calculates net cost
	order_record.net_cost = order_record.quantity * order_record.plant_cost;

	//Calculates purchase tax and tax rate using county name
	if(order_record.cname == "dade"){
		order_record.tax_rate = .065;
		order_record.purchase_tax = order_record.net_cost * order_record.tax_rate;
	}else if(order_record.cname == "broward"){
		order_record.tax_rate = .06;
		order_record.purchase_tax = order_record.net_cost * order_record.tax_rate;
	}else if(order_record.cname == "palm"){
		order_record.tax_rate = .07;
		order_record.purchase_tax = order_record.net_cost * order_record.tax_rate;
	}else{
		order_record.tax_rate = .06;
		order_record.purchase_tax = order_record.net_cost * order_record.tax_rate; 
		//Defualts to Florida 6% state sales tax 
	}

	//Caculates discount given quantity
	if(order_record.quantity <= 0){ //catches mistake in quantity to ensure they dont get 12% discount by default
		order_record.discount = 0;
	}else if(order_record.quantity >= 1 && order_record.quantity <= 5){
		order_record.discount = .01 * order_record.net_cost;
	}else if(order_record.quantity >= 6 && order_record.quantity <= 11){
		order_record.discount = .03 * order_record.net_cost;
	}else if(order_record.quantity >= 12 && order_record.quantity <= 20){
		order_record.discount = .05 * order_record.net_cost;
	}else if(order_record.quantity >= 21 && order_record.quantity <= 50){
		order_record.discount = .08 * order_record.net_cost;
	}else{
		order_record.discount = .12 * order_record.net_cost;
	}
	
	//Given other calculations, finds total cost;
	order_record.total_cost = order_record.net_cost + order_record.purchase_tax - order_record.discount;

	cout << "Successfully ran function process!\n" << endl; //gives feedback on function progress
}

///*************************************************************************************
//Name:  output
//Precondition: Parameters such as pname, cname, etc. are initialized with appropriate values in an order record.
//Postcondition: Parameters such as pname, cname, etc. will be output to an output file stream.
//Description:  Stores each inputted field of the order record from input file stream to the specified output file stream
//*************************************************************************************

void output(ofstream& out, const order_record customer_order){
	cout << "Running function output..." << endl; //gives feedback on function progress

	//"Magic Formula" for output formatting
 	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	//Outputs the data to console for verification, \t for formatting
	out << left << setw(15) << customer_order.pname << "\t";
	out << left << setw(10) << customer_order.cname << "\t";
	out << right << setw(7) << customer_order.plant_cost << "\t";
	out << right << setw(6) << customer_order.quantity << "\t";
	out << right << setw(8) << customer_order.net_cost << "\t";
	out.precision(3); //changes precision for tax rate (3 places)
	out << right << setw(6) << customer_order.tax_rate << "\t";
	out.precision(2); //switches back
	out << right << setw(7) << customer_order.purchase_tax << "\t";
	out << right << setw(7) << customer_order.discount << "\t";
	out << right << setw(9) << customer_order.total_cost << "\t";
	out << endl;

	cout << "Successfully ran function output!\n" << endl; //gives feedback on function progress

}

//Driver to test program
int main()
{

	//declare an order_record object
	order_record purchase_record;

	//Decleares the input file stream as "in"
	ifstream in;
	//Decleares the output file stream as "out"
	ofstream out;
	
	//Opens input and output file streams
	in.open("nursery_stock.txt");
	out.open("sells_results.txt");
	
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
			output(out, purchase_record);
		}
		cout << "\tInput file read to completion...\n" << endl; //gives feedback in console
	}

	//Closes open input and output file streams
	out.close();
	in.close();

	return 0;
}


