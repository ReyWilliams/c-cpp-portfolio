/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: July 7, 2020                      Total Points: 20
Assignment#: 6 (nursery_inv3.cpp)

Description: Program which uses input files to "process the customer purchase orders for a nursery" using arrays.
*************************************************************************************************************************/

#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way


//declaring capacity as a constant
const int CAPACITY = 100;

//Declaration for order record
class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	double quantity;
	double purchase_tax;
	double net_cost;
	double tax_rate;
	double discount;
	double total_cost;
};

//Function prototypes
void input(order_record STR[],int &count); 
void process(order_record STR[], int count);
void output(order_record STR[], int count);
double count_inventory(order_record STR[], int count);


//Function Declarations

///*************************************************************************************
//Name:  input
//Precondition: Parameters such as pname, cname, etc. have not yet been initialized into an order record array element.
//Postcondition: Parameters such as pname, cname, etc. will be initialized with appropriate values into an order record array element.
//Description:  Recieves input of parameters such as pname, cname, etc. from file and stores them in a unique order record array element.
//*************************************************************************************

void input(order_record STR[],int &count){
	ifstream in; //declares input file stream
	in.open("nursery_stock.txt"); //opens input data file
	
	while(!in.eof() && count < CAPACITY){
		in >> STR[count].pname;
		in >> STR[count].cname;
		in >> STR[count].plant_cost;
		in >> STR[count].quantity;
		count++;
	}

	//cout << "Count is: " << count;  //Test print for value of count(number of elements in array)
	in.close(); //closes input data file
}

//*************************************************************************************
//Name:  process
//Precondition: Parameters such as purchase_tax, discount, etc. are not yet initialized with appropriate values into pertinent order record array element.
//Postcondition: Parameters such as purchase_tax, discount, etc. will be initialized with appropriate values into pertinent order record array element.
//Description:  Calculates costs associated with order given input paramaters and stores them into appropriate fields in order record array element at proper index.
//*************************************************************************************

void process(order_record STR[], int count){
	int counter = 0;

	while(counter < count){
	//Calculates net cost
	STR[counter].net_cost = STR[counter].quantity * STR[counter].plant_cost;

	//Calculates purchase tax and tax rate using county name
	if(STR[counter].cname == "dade"){
		STR[counter].tax_rate = .065;
		STR[counter].purchase_tax = STR[counter].net_cost * STR[counter].tax_rate;
	}else if(STR[counter].cname == "broward"){
		STR[counter].tax_rate = .06;
		STR[counter].purchase_tax = STR[counter].net_cost * STR[counter].tax_rate;
	}else if(STR[counter].cname == "palm"){
		STR[counter].tax_rate = .07;
		STR[counter].purchase_tax = STR[counter].net_cost * STR[counter].tax_rate;
	}else{
		STR[counter].tax_rate = .06;
		STR[counter].purchase_tax = STR[counter].net_cost * STR[counter].tax_rate; 
		//Defualts to Florida 6% state sales tax 
	}

	//Caculates discount given quantity
	if(STR[counter].quantity <= 0){ //catches mistake in quantity to ensure they dont get 12% discount by default
		STR[counter].discount = 0;
	}else if(STR[counter].quantity >= 1 && STR[counter].quantity <= 5){
		STR[counter].discount = .01 * STR[counter].net_cost;
	}else if(STR[counter].quantity >= 6 && STR[counter].quantity <= 11){
		STR[counter].discount = .03 * STR[counter].net_cost;
	}else if(STR[counter].quantity >= 12 && STR[counter].quantity <= 20){
		STR[counter].discount = .05 * STR[counter].net_cost;
	}else if(STR[counter].quantity >= 21 && STR[counter].quantity <= 50){
		STR[counter].discount = .08 * STR[counter].net_cost;
	}else{
		STR[counter].discount = .12 * STR[counter].net_cost;
	}

	//Given other calculations, finds total cost;
	STR[counter].total_cost = STR[counter].net_cost + STR[counter].purchase_tax - STR[counter].discount;
	counter++;
	}
}

//*************************************************************************************
//Name:  output
//Precondition: Parameters such as pname, cname, etc. are initialized with appropriate values in an order record array element.
//Postcondition: Parameters such as pname, cname, etc. will be output to an output file stream.
//Description:  Stores each processed field of the order record from the array of order records to the specified output file stream.
//*************************************************************************************

void output(order_record STR[], int count){
	ofstream out; //declares output file stream
	out.open("nursery_run_results.txt"); //opens file to store data
	int counter = 0;

	//Magic Formula for output to file
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	while(counter < count){
	out << left << setw(15) << STR[counter].pname << "\t";
	out << left << setw(10) << STR[counter].cname << "\t";
	out << right << setw(7) << STR[counter].plant_cost << "\t";
		out.unsetf(ios::showpoint); //removes point for quantity
		out.precision(0);
	out << right << setw(6) << STR[counter].quantity << "\t";
		out.setf(ios::showpoint);
		out.precision(2);
	out << right << setw(8) << STR[counter].net_cost << "\t";
		out.precision(3); //changes precision for tax rate (3 places)
	out << right << setw(6) << STR[counter].tax_rate << "\t";
		out.precision(2); //switches back
	out << right << setw(7) << STR[counter].purchase_tax << "\t";
	out << right << setw(7) << STR[counter].discount << "\t";
	out << right << setw(9) << STR[counter].total_cost << "\t";
	out << endl;
	counter++;
	}

	out.close(); //closes output stream
}

//*************************************************************************************
//Name:  count_inventory
//Precondition: Parameter "total_cost" is initialized with an appropriate value in each order record array element.
//Postcondition: The average of the total order cost will be calculated and returned by function.
//Description: Calculates the average of the “total order cost” given value of the parameter in each order record array element.
//*************************************************************************************

double count_inventory(order_record STR[], int count){
	int counter = 0;
	double total = 0;

	while(counter < count){
		total += STR[counter].total_cost;
		counter++;
	}

	return total/count;
}


//Driver to test program
int main()
{
	order_record STR[CAPACITY]; //creates order_record array
	int count = 0;

	//Function calls
	input(STR, count);
	process(STR, count);
	output(STR, count);
	
	//Formatting output of count_inventory
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	cout << "Average Total Order Cost = " << count_inventory(STR, count) << endl;

	return 0;
}
