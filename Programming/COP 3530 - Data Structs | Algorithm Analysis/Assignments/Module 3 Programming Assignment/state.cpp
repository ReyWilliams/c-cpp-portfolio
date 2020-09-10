#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
#include "state.h"
using namespace std; //Denotes names are being used in a standard way



/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{	
	//cout << "Default constructor for state_class has been called" << endl;

	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];

	ifstream in;
	in.open("census2020_data.txt");

	if(in.fail()){
		cout << "Opening input data file has failed, fix and try again." << endl;
		exit(1);
	}


	while(!in.eof()){
		string line = "";
		string numbers = "";
		
		getline(in, line);
		pop_DB[count].state_name = "";

		for(int i = 0; i < line.length(); i++){

			if(isalpha(line[i])){
				pop_DB[count].state_name += line[i];
			}else if(isdigit(line[i])){
				numbers += line[i];
			}else{
				pop_DB[count].state_name += line[i];
			}

		}

		int last = pop_DB[count].state_name.length() - 1;
		if(isspace(pop_DB[count].state_name[last]))
		pop_DB[count].state_name = pop_DB[count].state_name.substr(0,pop_DB[count].state_name.length()-2);

		pop_DB[count].population = stod(numbers);

		count++;

		if(Is_Full()){
			double_size();
		}
	}
	in.close(); //closes input file stream
	//cout << "Default constructor for state_class has finished" << endl;
}

/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: There is an already initialized state class
//Postcondition: There will be a deep copied state
//Description:  The function performs a deep copy of the formal parameter org. 
/************************************************************************************************************************************/
state_class::state_class(const state_class& org)
{
	//cout << "Copy constructor for state_class has been called" << endl;

	this->count = org.count;
	this->capacity = org.capacity;

	pop_DB = new population_record[capacity];

	for(int i = 0; i < capacity; i++){
		pop_DB[i] = org.pop_DB[i];
	}


}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: Population record array and its values have already been used
//Postcondition: population record array pointer is deleted from stack so it is not longer pointing to heap, deallocating memory and 
//Decription: de-allocates all memory allocated to pop_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
state_class::~state_class()
{
	//cout << "Destructor for state_class has been called" << endl;

	count = 0;
	capacity = 0;
	delete[] pop_DB; //delte pointer to heap, deallocating memory
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: The population record array is determined to be full as the number of elements matches the capacity of the array
//Postcondition: The population record array will double in size (size*2) to have more capacity for more elements
//Decription: doubles the size (capacity) of pop_DB
/******************************************************************************************************************************/
void state_class::double_size()
{
	capacity *= 2;
	//cout << "double_size function for state_class has been called" << endl;
	population_record *temp = new population_record[capacity];

	for(int i = 0; i<count; i++){
		temp[i] = pop_DB[i];
	}

	delete[ ] pop_DB;
	pop_DB = temp;

}

/*********************************************************************************************************************************/
//Name: operator+
//Precondition: The population record array is not full and has enough space to accomodate a new record
//Postcondition: A new population record is added to the population record array, more capacity is given if needed
//Decription: adds a new record to pop_DB; if pop_DB is full, double_size is called to increase the capacity of pop_DB.
/********************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	//cout << "operator+ function for state_class has been called" << endl;
	if(Is_Full()){
		double_size();
	}

	pop_DB[count].state_name = r.state_name;
	pop_DB[count].population = r.population;
	count++;

	//check again if array is full
	if(Is_Full()){
		double_size(); //if array is full double its size to accomodate more elements
	}

}

/**********************************************************************************************************************************/
//Name: Search
//Precondition: A state is determined and the population record array has been initalized with population records
//Postcondition: The index of population record with the state is returned
//Decription: locates state in pop_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int state_class::Search(const string& state)
{
	//cout << "Search function for state_class has been called" << endl;
	for(int i = 0; i < count; i++){ //loop through pop. records
		if(pop_DB[i].state_name == state){ //if pop record's state name matches state
			return i;			//return its index, [i]
		}
	}
	return -1;
}


/********************************************************************************************************************************/
//Name: Remove
//Precondition: There is a string state determined and pop. record array is initialized with proper values
//Postcondition: record with string state within the pop. record array is removed and records are shifted
//Decription: remove occurence of state from pop_DB if it is there.
/*******************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	//cout << "Remove function for state_class has been called" << endl;
	int index = Search(state);
	
	if(index != -1){
		for(int i = index; i < count-1; i++){
			pop_DB[i] = pop_DB[i+1];
		}

	count--;

	}
}


/****************************************************************************************************************************/
//Name: Print_ALL_To_File
//Precondition: Each pop. record is initized with state name and population
//Postcondition: Each pop. record is printed with formatted output to the output file 
//Decription: prints every field of every pop. record in pop_DB formatted to a file
/***************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	//cout << "Print_ALL_To_File function for state_class has been called" << endl;
	ofstream out;
	out.open(filename);

	if(out.fail()){
		cout << "Opening the output file has failed. Try again." << endl;
	}

	out.setf(ios::fixed);
	out.precision(0);
	
	for(int i = 0; i< count; i++){
		out << left << setw(20) << pop_DB[i].state_name << "\t";
		out << left << setw(9) << pop_DB[i].population << endl;
	}

	out.close();
}
/****************************************************************************************************************************/
//Name: Print_ALL
//Precondition: Each pop. record is initized with state name and population
//Postcondition: Each pop. record is printed with formatted output to the output log
//Decription: prints every field of every pop. record in pop_DB formatted to a output log
/***************************************************************************************************************************/
void state_class::Print_ALL()
{
	//cout << "Print_ALL function for state_class has been called" << endl;
	cout.setf(ios::fixed);
	cout.precision(0);

	for(int i = 0; i< count; i++){
		cout << left << setw(20) << pop_DB[i].state_name << "\t";
		cout << left << setw(9) << pop_DB[i].population << endl;
	}
}


/****************************************************************************************************************************/
//Name: Print_Range
//Precondition: Each pop. record is initized with state name and population
//Postcondition: Each within range order record is printed with formatted output to the output log
//Decription: prints each state name within range to output log
/***************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	//cout << "Print_Range function for state_class has been called" << endl;
	cout.setf(ios::fixed);
	cout.precision(0);

	for(int i = 0; i< count; i++){
		if(pop_DB[i].population >= min && pop_DB[i].population <= max){
			cout << left << setw(20) << pop_DB[i].state_name << "\t";
			cout << left << setw(9) << pop_DB[i].population << endl;
		}
	}
}


/****************************************************************************************************************************/
//Name: State_Count
//Precondition: Each pop record is initized with state name and population
//Postcondition: Each state within range is count and count is send to output log
//Decription: counts the number of states within range
/***************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	int countOfState = 0;
	//cout << "State_Count function for state_class has been called" << endl;

	for(int i = 0; i< count; i++){
		if(pop_DB[i].population >= min && pop_DB[i].population <= max)
			countOfState++;
	}

	return countOfState;
}

/******************************************************************************************************************************************************
//Name: Sort
//Precondition: Each pop. record is initized with state name and population
//Post-Condition: Each pop. record is sorted by alphabetical order
//Description: sorts each pop. record by alphabetical order
******************************************************************************************************************************************************/
void state_class::Sort()
{
	string target = "";

	for(int i = 1; i<count; i++){

			target = pop_DB[i].state_name;
			int j = i - 1;
			while(j>= 0 && pop_DB[j].state_name > target){
				string temp = pop_DB[j+1].state_name;
				pop_DB[j+1].state_name = pop_DB[j].state_name;
				pop_DB[j].state_name = temp;
				j--;
			}
		 pop_DB[j+1].state_name = target;
	}

}
