#include <iostream>
#include <vector>
#include <string>
#include "vlist.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(){
	cout << "Default Constructor Invoked" << endl;
    count = 0; //sets count to 0, as no cells are filled
    DB.reserve(9); //reserve(allocate) 9 spaces for vector
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org){
    cout << "Copy Constructor Invoked" << endl;

    if(Org.isEmpty()){
        cout << "Vector empty, nothing to copy." << endl;
        return;
    }
    
    DB.clear();         //clear the current vector cells
    DB.shrink_to_fit(); //deallocate the cells

    for(auto n: Org.DB){    //copy elements into DB array
        DB.push_back(n);    //push back elements into the copied array
    }

    this->count = Org.count; //copy the count

    //Print the contents of each vlist object on seperate lines
    cout << "Orginal vector: ";
    cout << "[";
    for(int i = 0; i < Org.count; ++i){
        cout << Org.DB[i];
        if (i != Org.DB.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
    
    cout << "Copied vector: ";
    this->print();
    
    
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist(){
    cout << "Destructor Invoked" << endl;

    DB.clear(); //clear all cells of their value
    DB.shrink_to_fit(); //deallocate memory to fit number of cells(0) thus no memory
    count = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: isEmpty
//Precondition: An instance of a vlist object has been constructed
//Postcondition: Determined if vector of vlist object is empty
//Description: Detemined if vector of vlist object is empty.
///////////////////////////////////////////////////////////////////////////////////////////////
bool vlist::isEmpty() const{
    return this->count == 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search
//Precondition: An instance of a vlist object has been constructed
//Postcondition: Determined if vector of vlist object contains key and returns iterator to
//               location of item in the vector
//Description: Detemined if vector of vlist object contains key and returns iterator to it.
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string>::iterator vlist::search(const string& key){
    vector<string>::iterator it;

    if(isEmpty()){ //if the vector is empty, nothing can be search
        cout << "[" << key << "] not found. Vector is empty." << endl; //inform user
        it = DB.end(); //set the iterator to end
        return it; //exit function
    } 

    for(it = DB.begin(); it != DB.end(); it++){ //iterate through vector from begin to end
        if(*it == key){ //if value at iterater equals the key
            cout << "Item Found: "; //print that it has been found
            cout << "[" << key << "]" << endl << endl; //print the search key;
            return it; 
        }
    }

    cout << "Item Not Found" << endl;
    cout << "[" << key << "]" << endl << endl; //print the search key;
    it = DB.end(); //set the iterator to end
    return it;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: An instance of a vlist object has been constructed
//Postcondition: Key value is aplphabetically inserted into the vector
//Description: Inserts key into the vector
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::insert(const string& key){
    vector<string>::iterator it;
    
        if(isEmpty()){ //if vector is empty
            DB.push_back(key); //push key onto vector
            count++;
            return;     //exit, nothing else to be done
        }

    for(it = DB.begin(); it != DB.end(); it++){ //iterate through the vector
        if(*it >= key){             //if the key comes after the current element
                DB.insert(it, key); //insert it at that position
                count++;            //increment the count as another element is inserted
                return;             //exit the function, nothing else to be done
            }
        }
    DB.insert(DB.end(), key);   //if we get here then that means the element must come after all previous
                                //elements so insert it at the end
    count++;                    //increment the count
    }

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove
//Precondition: An instance of a vlist object has been constructed with key in vector
//Postcondition: Key value is removed from vector
//Description: Removes an item from the vector if it is there
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::remove(const string& key){
    vector<string>::iterator loc = search(key);

    if(isEmpty()){ //if vector is empty
        cout << "Item cannot be removed. Vector is empty." << endl;
        return;     //exit, nothing else to be done
        }

    if(loc != DB.end()){ //if the key exist in the vector
        DB.erase(loc);      //erase the element 
        count--;            //decrement count
    }else{  //if the key does not exist in the vector
        cout << "Item Not In Vector" << endl; //let user know
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print
//Precondition: An instance of a vlist object has been constructed
//Postcondition: prints all the items in the vector
//Description: Prints every item stored in the vector of the vlist object
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::print(){

    cout << "[";                    //print first bracket
    for(int i = 0; i < count; ++i){ //go through every element in vector
        cout << DB[i];              //print it
        if (i != DB.size() - 1)     //if we are not at the last element
            cout << ", ";           //print comma
    }
    cout << "]\n";                  //print last bracket
}

