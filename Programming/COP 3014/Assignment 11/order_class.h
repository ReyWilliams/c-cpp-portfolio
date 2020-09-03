#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way

#ifndef ORDER_CLASS //if not defined


#define ORDER_CLASS  //define it

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

class order_class{
public:
	order_class();
    order_class(const order_class& org); //copy constructor
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




#endif //jump here if defined
