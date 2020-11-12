#include <string>
#include <iostream>
using namespace std;

/*****************************************************************************
//P R O G R A M    H E A D E R
//
//    Name:    Reynaldo Williams
//    Z#:    23506395
//    Instructor:    Dr. Bullard
//    Class:    Data Structures
//    Term:    Fall 2020
//    Assignment #10B (recursion and lists)
//    Due Date:    November 17, 2020
//    Due Time:    11:59PM
//    Points:    25
//
//    Description: This program accesses your understanding of recursion and recursive functions
//               as they relate to lists
******************************************************************************/

class node{
    public:
        int data;   //data
        node* next; //address
};

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: fun
//Precondition: front and back pointers declared/initialized
//Postcondition: prints every other node then prints those nodes backwards
//Description: prints nodes in a fun way
///////////////////////////////////////////////////////////////////////////////////////////////
void fun(node* start){ 
    if(start == NULL) //if current node is null 
        return; //exit
    cout << start->data << " ";; //if not, print data of current node

    if(start->next != NULL ) //if the next node is not null
        fun(start->next->next); //call recursive to the node two over
    cout << start->data << " "; //after recursive call print current node
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: add_back
//Precondition: front and back pointers declared/initialized
//Postcondition: data value is added to the back
//Description: Adds a new node to the back of the linked list
///////////////////////////////////////////////////////////////////////////////////////////////
void add_back(node*& front, node*& back, int x){
        
        if(front == NULL){ //if the linked list is empty
            front = back = new node; //allocate memory for new node
            front->data = x; //set data of node to the int we are adding
            return;
        }

        back->next = new node; //allocate memory for the new node
        back = back->next; //advance the back pointer to the node node
        back->data = x;   //set data of node to the int we are adding
        back->next = NULL; //set address field of back node to null (not circular)
}

int main(){

    node* front = 0; //declare and initialize front and back nodes
    node* back = 0;

    for (int i = 1; i <= 6; i++){ //for int vales 1-6, add then as nodes to the back of a linked list
        add_back(front, back, i);
    }
    cout << "[ ";
    fun(front); //print out those nodes according to fun function
    cout << "]" << endl;

    return 0;
}
