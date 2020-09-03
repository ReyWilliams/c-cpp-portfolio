//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:  Lofton Bullard        Z#: Z111111111
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  06/05/2050           Due Time: 11:59 PM
Total Points: 2000
Assignment #: xyz.cpp

Description:

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



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
	void add( ); //adds a order record to STR
	void remove(const string key); //removes all items in STR with a plant name that matches key.
	void double_size();
	void process();
	void print(); //prints all the elements in STR to the screen
private:
	int count;
	int size;
	order_record *STR;
};




/************************************************************************************************************************************/
//Name: default constructor
//Precondition: 
//Postcondition: 
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, 
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
/************************************************************************************************************************************/
order_class::order_class()
{
	cout << "The default constructor has been called\n";

}

/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition: 
//Postcondition: 
//Decription: returns true if STR is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool order_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
{
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds a order_record to STR; if STR is full, double_size is called to increase the size of STR. The user 
//            is prompted to enter the plant name, county name, plant cost and quantity.
/********************************************************************************************************************************/
void order_class::add( )
{
}

/********************************************************************************************************************************/
//Name: remove
//Precondition: 
//Postcondition: 
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/
void order_class::remove(const string key)
{
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void order_class::double_size( )
{
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
//Precondition: 
//Postcondition: 
//Decription: calculate the net cost, tax rate, order tax, discount and total cost for every order record in STR. for every call record in STR.
/*****************************************************************************************************************************/
void order_class::process()
{
}


/****************************************************************************************************************************/
//Name: print
//Precondition: 
//Postcondition: 
//Decription: prints every field of every call_record in STR formatted to a file.
/***************************************************************************************************************************/
void order_class::print()
{
	ofstream out;
	out.open("nursery_result30.txt", fstream::app);
	static int run = 1;

	//put code here for the loop to print the data in the array to the stream out.

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;
	out.close();
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	cout << "The destructor has been called\n";
}


//Here is your driver to test the program
int main()
{
	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and print " << endl;
	myOrders.process();
	myOrders.print();
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1 
	myOrders.print();
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	//void remove(string key);
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << "Removing rose\n";
	myOrders.remove("rose");
	myOrders.print();
	cout << "Removing bergenia\n";
	myOrders.remove("bergenia");
	myOrders.print();
	cout << "Removing yarrow\n";
	myOrders.remove("yarrow");
	myOrders.print();
	cout << "Removing rose ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders.remove("rose");
	myOrders.print();
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