/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: July 19, 2020                      Total Points: 10
Assignment#: 8 (nursery_dynamic.cpp)

Description: Program which uses input files to "process the customer purchase orders for a nursery" using  dynamic arrays.
*************************************************************************************************************************/

#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way

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


void initialize(order_record*& STR, int& count, int& size);
bool is_Empty(int count);
bool is_Full(int count, int size);
int search(order_record* STR, int  count, string key);
void add(order_record*& STR, int& count, int& size);
void remove(order_record* STR, int& count, string key);
void double_size(order_record*& STR, int  count, int& size);
void process(order_record* STR, int count);
void processRecord(order_record *STR, int index);
void print(const order_record* STR, const int  count);
void destory_STR(order_record* STR, int& count, int& size);

//Function Implementations

/*************************************************************************************************************************************************/
//Name: initialize
//Precondition: Nursery data from input file has not been read into order records in the dynamic array
//Postcondition: Nursery data from input file has been read into order records in the dynamic array
//Decription: Reads the data file of nursery info (plant name, county name, plant cost, quantity) into the dynamic 
//array of call record, STR. If the count because equal to the size the function double_size is called and the memory allocated to STR is doubled.
/***********************************************************************************************************************************************/

void initialize(order_record *&STR, int& count, int& size){
	count = 0;
	size = 1;

	STR = new order_record[size];

	ifstream in; //declares input file stream
	in.open("nursery_stock.txt"); //opens input data file

	if(in.fail()){ //if opening file failed...
		cout << "Opening input data file has failed, fix and try again." << endl;
	}else{ //if opening file did not fail...
			while(!in.eof()){ //while not at end of file...
				in >> STR[count].pname;
				in >> STR[count].cname;
				in >> STR[count].plant_cost;
				in >> STR[count].quantity;
				count++;
				if(is_Full(count, size)){
					double_size(STR, count, size); //if array is full double its size to accomodate more elements
				}
			}
		}

	in.close(); //closes input file stream
}

/**********************************************************************************************************************************/
//Name: is_Empty 
//Precondition: varibale count has been initialized to the number of elements in the order record array
//Postcondition: varibale count is used to determine whether or not the dynamic array is empty
//Decription: returns true if STR is empty
/*********************************************************************************************************************************/

bool is_Empty(int count){
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: Variable count has been initialized to the number of elements in the order record array and variable size is initialized
//to the capacity of the order record array.
//Postcondition: Varibales count and size are used to determine if the number of elements matches the capacity, meaning the array is the full
//Decription: returns true if STR is full
/*********************************************************************************************************************************/

bool is_Full(int count, int size){
	return count == size;
}


/******************************************************************************************************************************/
//Name: double_size
//Precondition: The order record array is determine to be full as the number of elements matches the capacity of the array
//Postcondition: The order record array will double in size (size*2) to have more capacity for more elements
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/

void double_size(order_record *&STR, int count, int &size){
	size *= 2; //Doubles size variable
	order_record *temp = new order_record[size]; //Allocates memeory for expanded array

	for(int i = 0; i< count; i++){ //copies data in larger array
		temp[i] = STR[i];
	}

	delete[] STR; //deletes pointer in stack to old values, prevents memory leak
	STR = temp; //has STR point to new expanded array in heap

	//temp will be deleted once function is finished
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: A key is determined and the order record array has been initalized with order records
//Postcondition: The index of the first occurence of an order record with the key is returned
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/

int search(order_record *STR, int count, string key){

	for(int i = 0; i < count; i++){ //loop through order records
	
		if(STR[i].pname == key){ //if order record's plate name matches key
			return i;			//return its index, [i]

		}
	}

	return -1; //return -1 as no order record with plant name matching key is found.
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: The order record array is not full and has enough space to accomodate a new record
//Postcondition: A new order record is added to the order record array, more capacity is given if needed
//Decription: adds a new record to STR; if STR is full, double_size is called to increase the capacity of STR.
/********************************************************************************************************************************/

void add(order_record *&STR, int &count, int &size){

	if(is_Full(count,size)){
			double_size(STR, count, size); //if array is full double its size to accomodate more elements
	}

	//Prompting for and initializing input
	cout << endl; //Seperates outputs
	cout << "Enter a plant name: ";
	cin >> STR[count].pname;
	cout << "Enter a county name: ";
	cin >> STR[count].cname;
	cout << "Enter the plant cost: ";
	cin >> STR[count].plant_cost;
	cout << "Enter the plant quantity: ";
	cin >> STR[count].quantity;

	//Process single order record
	processRecord(STR, count); 

	count++; //Increments count to account for new order record

	//check again if array is full
	if(is_Full(count,size)){
			double_size(STR, count, size); //if array is full double its size to accomodate more elements
	}
}

/******************************************************************************************************************************/
//Name: process
//Precondition: There is an valid index for an order record within STR
//Postcondition: The order record at the valid index will be processed with net cost, tax rate, order tax, and total cost values
//Decription: calculate the net cost, tax rate, order tax and total cost for a single order record in STR.
/*****************************************************************************************************************************/

void processRecord(order_record *STR, int index){
	STR[index].net_cost = STR[index].quantity * STR[index].plant_cost;

	//Calculates purchase tax and tax rate using county name
	if(STR[index].cname == "dade"){
		STR[index].tax_rate = .065;
		STR[index].purchase_tax = STR[index].net_cost * STR[index].tax_rate;
	}else if(STR[index].cname == "broward"){
		STR[index].tax_rate = .06;
		STR[index].purchase_tax = STR[index].net_cost * STR[index].tax_rate;
	}else if(STR[index].cname == "palm"){
		STR[index].tax_rate = .07;
		STR[index].purchase_tax = STR[index].net_cost * STR[index].tax_rate;
	}else{
		STR[index].tax_rate = .06;
		STR[index].purchase_tax = STR[index].net_cost * STR[index].tax_rate; 
		//Defualts to Florida 6% state sales tax 
	}

	//Caculates discount given quantity
	if(STR[index].quantity <= 0){ //catches mistake in quantity to ensure they dont get 12% discount by default
		STR[index].discount = 0;
	}else if(STR[index].quantity >= 1 && STR[index].quantity <= 5){
		STR[index].discount = .01 * STR[index].net_cost;
	}else if(STR[index].quantity >= 6 && STR[index].quantity <= 11){
		STR[index].discount = .03 * STR[index].net_cost;
	}else if(STR[index].quantity >= 12 && STR[index].quantity <= 20){
		STR[index].discount = .05 * STR[index].net_cost;
	}else if(STR[index].quantity >= 21 && STR[index].quantity <= 50){
		STR[index].discount = .08 * STR[index].net_cost;
	}else{
		STR[index].discount = .12 * STR[index].net_cost;
	}

	//Given other calculations, finds total cost;
	STR[index].total_cost = STR[index].net_cost + STR[index].purchase_tax - STR[index].discount;
}

/******************************************************************************************************************************/
//Name: process
//Precondition: Each order record is initized with values pname, cname, plant cost, quantity
//Postcondition: Each order record is processed with net cost, tax rate, order tax, and total cost values
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
/*****************************************************************************************************************************/

void process(order_record *STR, int count){
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

/********************************************************************************************************************************/
//Name: remove
//Precondition: There is a string key determined and order record array is initialized with proper values
//Postcondition: All occurences of key within the order record array are removed and values are shift
//Decription: remove all occurences of key from STR if it is there.
/*******************************************************************************************************************************/

void remove(order_record *STR, int &count, string key){

	int index = 0;
	
	while(search(STR, count, key) != -1){ //while there exists an index in the array that contains key

		index = search(STR, count, key); //sets index to target index
		for(int i = index; i< count-1; i++){ //shift all elements
			STR[i] = STR[i+1];
		}
		count--; //derement the number of elements
	}
}


/****************************************************************************************************************************/
//Name: print
//Precondition: Each order record is initized with values pname, cname, plant cost, quantity and each record has been processed
//Postcondition: Each order record is printed with formatted output to the output file 
//Decription: prints every field of every order_record in STR formatted to the screen.
/***************************************************************************************************************************/

void print(const order_record *STR, int count){

	ofstream out; //declares output stream
	out.open("nursery_result20.txt", fstream::app); //attache ouput stream to file, allows for appending
	static int run = 1; //will not be reinitalized after each run, will hold value
	
	int counter = 0; //counter to track index

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

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;
	out.close(); //closes output stream
}

/****************************************************************************************************************************/
//Name: destroy_STR
//Precondition: Order record array and its values have already been used
//Postcondition: order record array pointer is deleted from stack so it is not longer pointing to heap, deallocating memory and 
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/

void destory_STR(order_record* STR, int& count, int& size){
	count = 0;
	size = 0;

	delete[] STR; //delte pointer to heap, deallocating memory
}

int main(){
	
	remove("nursery_result20.txt"); //removes the output file on each run
	int count = 0; //intializating count
	int size = 1;
	order_record* STR = 0;//declaring the dynamic array

	///Test 1:
	cout << "**********************************************************************\n";
	cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
	initialize(STR, count, size);
	process(STR, count);
	print(STR, count);
	cout << endl;
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";

	////Test 2:
	//void add(order_record * & STR, int & count, int & size);
	cout << endl;
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << endl;
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	
	////Test 3:
	////void remove(order_record * STR, int & count, string key);
	cout << endl;
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << endl;
	cout << "Removing rose\n";
	remove(STR, count, "rose");
	print(STR, count);
	cout << "Removing rose\n";
	remove(STR, count, "owl");
	print(STR, count);
	cout << endl;
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	

	////Test 4:
	////void add(order_record * & STR, int & count, int & size);
	cout << endl;
	cout << "Test 4: Testing add, double_size, process, is_full, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	
	////Test 5:
	////void destroy_STR(order_record  * STR, int & count, int & size);*/
	cout << endl;
	cout << "Test 5: destroy_STR and print " << endl;
	destory_STR(STR, count, size);
	cout << "size = " << size << endl;
	cout << "count = " << count << endl;
	cout << endl;
	cout << "End of Test 5" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	

	return 0;
}