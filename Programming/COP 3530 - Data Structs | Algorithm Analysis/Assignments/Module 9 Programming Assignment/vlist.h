#include <vector> 
#include <string>
using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist{
public:
	vlist(); 				//default constructor
	vlist(const vlist&); 	//copy constructor
	~vlist();				//destructor
	bool isEmpty() const;	//determines if vector is empty
	vector<string>::iterator search(const string&); //search function, returns iterator location 
													//otherwise end of vector iterator
	void insert(const string&);						//inserts element alphabetically into vector
	void remove(const string&); 					//removed element from vector
	void print();									//prints all elements of vector
private:
	vector<string> DB;								//vector of string, DB, stores all elements
	int count;										//integer to count all elements in vector
};

#endif


