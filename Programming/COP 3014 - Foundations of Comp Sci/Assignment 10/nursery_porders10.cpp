/*************************************************************************************************************************
Name: Reynaldo Williams                            Z#: 23506395
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: July 29, 2020                      Total Points: 20
Assignment#: 10 (nursery_porders10.cpp)

Description: 
*************************************************************************************************************************/

#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way

class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	int quantity;
	double net_cost;
	double tax_rate;
	double purchase_tax;
	double discount;
	double total_cost;
};

class order_class
{
public:
	order_class();
	~order_class(); //de-allocates all memory allocate to STR by operator new.
	bool is_Empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key);//returns location of key if in STR; otherwise return -1
	void add(); //adds a order record to STR
	friend order_class& operator -(order_class &OC, const string key); //removes all items in STR with a plant name that matches key.
	void double_size();
	void process();
    void processRecord(int index);
	friend ostream& operator <<(ostream & out, order_class & ORG); //prints all the elements in ORG's STR to the screen
private:
	int count;
	int size;
	order_record *STR;
};

/************************************************************************************************************************************/
//Name: default constructor
//Precondition: Nursery data from input file has not been read into order records in the dynamic array
//Postcondition: Nursery data from input file has been read into order records in the dynamic array
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, 
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
/************************************************************************************************************************************/
order_class::order_class(){
    count = 0;
    size = 1;
    
	cout << "The default constructor has been called\n";

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
				if(is_full()){
					double_size(); //if array is full double its size to accomodate more elements
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
bool order_class::is_Empty(){
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: Variable count has been initialized to the number of elements in the order record array and variable size is initialized
//to the capacity of the order record array.
//Postcondition: Varibales count and size are used to determine if the number of elements matches the capacity, meaning the array is the full
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool order_class::is_full(){
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: A key is determined and the order record array has been initalized with order records
//Postcondition: The index of the first occurence of an order record with the key is returned
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key){
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
void order_class::add(){

    if(is_full()){
	double_size(); //if array is full double its size to accomodate more elements
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
	processRecord(count); 

	count++; //Increments count to account for new order record

	//check again if array is full
	if(is_full()){
			double_size(); //if array is full double its size to accomodate more elements
	}
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: There is a string key determined and order record array is initialized with proper values
//Postcondition: All occurences of key within the order record array are removed and values are shift
//Decription: remove all occurences of key from STR if it is there.
/*******************************************************************************************************************************/
order_class & operator-(order_class &OC, const string key){
	int index = 0;
	
	while(OC.search(key) != -1){ //while there exists an index in the array that contains key

		index = OC.search(key); //sets index to target index
		for(int i = index; i< OC.count-1; i++){ //shift all elements
			OC.STR[i] = OC.STR[i+1];
		}
		OC.count--; //derement the number of elements
	}
	return OC; //returning the current object
}

/****************************************************************************************************************************/
//Name: operator<<
//Precondition: Each order record is initized with values pname, cname, plant cost, quantity and each record has been processed
//Postcondition: Each order record is printed with formatted output to the output file 
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
/***************************************************************************************************************************/
ostream& operator<<(ostream &out, order_class &ORG){
		
	static int run = 1;

	int counter = 0; //counter to track index

	//Magic Formula for output to file
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	while(counter < ORG.count){
	out << left << setw(15) << ORG.STR[counter].pname << "\t";
	out << left << setw(10) << ORG.STR[counter].cname << "\t";
	out << right << setw(7) << ORG.STR[counter].plant_cost << "\t";
		out.unsetf(ios::showpoint); //removes point for quantity
		out.precision(0);
	out << right << setw(6) << ORG.STR[counter].quantity << "\t";
		out.setf(ios::showpoint);
		out.precision(2);
	out << right << setw(8) << ORG.STR[counter].net_cost << "\t";
		out.precision(3); //changes precision for tax rate (3 places)
	out << right << setw(6) << ORG.STR[counter].tax_rate << "\t";
		out.precision(2); //switches back
	out << right << setw(7) << ORG.STR[counter].purchase_tax << "\t";
	out << right << setw(7) << ORG.STR[counter].discount << "\t";
	out << right << setw(9) << ORG.STR[counter].total_cost << "\t";
	out << endl;
	counter++;
	}

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;

	return out;//returning object that invoked the function
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: The order record array is determine to be full as the number of elements matches the capacity of the array
//Postcondition: The order record array will double in size (size*2) to have more capacity for more elements
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void order_class::double_size( ){
	size *=2;
	order_record *temp = new order_record[size];

	for(int i=0; i<count; i++)
	{
		temp[i] = STR[i];
	}

	delete [ ] STR;
	STR = temp;
}

/******************************************************************************************************************************/
//Name: process
//Precondition: Each order record is initized with values pname, cname, plant cost, quantity
//Postcondition: Each order record is processed with net cost, tax rate, order tax, and total cost values
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
/*****************************************************************************************************************************/
void order_class::process(){
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

/******************************************************************************************************************************/
//Name: processRecord
//Precondition: There is an valid index for an order record within STR
//Postcondition: The order record at the valid index will be processed with net cost, tax rate, order tax, and total cost values
//Decription: calculate the net cost, tax rate, order tax and total cost for a single order record in STR.
/*****************************************************************************************************************************/
void order_class::processRecord(int index){
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

/****************************************************************************************************************************/
//Name: destructor
//Precondition: Order record array and its values have already been used
//Postcondition: order record array pointer is deleted from stack so it is not longer pointing to heap, deallocating memory and 
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	cout << "The destructor has been called\n";
    count = 0;
	size = 0;

	delete[] STR; //delte pointer to heap, deallocating memory

}

int main()
{
	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and operator<< " << endl;
	myOrders.process();
	cout<<myOrders;
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and operator<< " << endl;
	myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1 
	cout<<myOrders;
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	//operator-(string key);
	cout << "Test 3: Testing operator-, is_Empty, search and opertor<< " << endl;
	cout << "Removing rose\n";
	myOrders -"rose";
	cout<<myOrders;
	cout << "Removing bergenia and yarrow\n";
	myOrders - "bergenia" - "yarrow";
	cout<<myOrders;
	cout << "Removing rose ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders -"rose";
	cout<<myOrders;
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 4:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 4: Destructor called" << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}