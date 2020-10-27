#include <iostream>
#include <string>
#include "bqueue.h"
using namespace std;

//*************************************************************************************
//Name:	bqueue
//Precondition: queue not intialized as yet
//Postcondition: queue initialized with null front
//Description: Initializes queue (default constructor)
//*************************************************************************************
bqueue::bqueue(){
    front = 0;
}

//*************************************************************************************
//Name:	empty
//Precondition: queue is declared
//Postcondition: queue is determined to be empty or not
//Description: determines if queue is empty
//*************************************************************************************
bool bqueue::empty(){
    return front==0;
}

//*************************************************************************************
//Name:	enqueue
//Precondition: queue initialized
//Postcondition: queue node added
//Description: pushes nodes to the back of queue
//************************************************************************************
void bqueue::enqueue(int num){
    if(this->empty()){          //if queue is empty...
        front = new bqnode;     //allocate memory for the new node
        front->priority = num;  //set the data of node 
        front->prev = front;    //set previous pointer of node to be itself
        front->next = front;    //set next pointer of node to be itself
        return;                 //exit function prematurely, nothing left to be done
    }
    
    //if queue is not empty...
    bqnode* curr = new bqnode; //allocate memory for the new node
    curr->priority = num;       //set the data of node
    curr->next = front;         //have the new back node point back to the front
    curr->prev = front->prev;   //have the new back node prev pointer point to the old back
    front->prev->next = curr;   //have the old back node point to the new back node
    front->prev = curr;         //have the front's previous element be the node back element
}

//*************************************************************************************
//Name:	dequeue
//Precondition: queue initialized with values
//Postcondition: queue front element removed
//Description: removes front element from queue
//*************************************************************************************
void bqueue::dequeue(){

    if(this->empty()){ //if the queue is empty...
        cout << "The queue is empty, populate with data before dequeueing." << endl;
        return;         //exit, nothing can be done
    }

    if(front == front->next ){  //if the front points back to itself (only one node)
         bqnode* temp = front;  //have a temp pointer to hold the front val
         front = 0;             //set front to 0 (null)
         delete temp;           //deallocate (delete) the temp pointer
         return;                //return to exit prematurely as nothing esle can be done
    }

    bqnode* temp = front;       //create temp pointer to hold front
    front = front->next;        //advance the front to the next item in queue
    temp->prev->next = front;   //set back's next pointer to the new front
    front->prev = temp->prev;   //set the previous of the new front to the back
    delete temp;                //get rid of temp and its old data/deallocate it
}

//*************************************************************************************
//Name:	~bqueue
//Precondition: queue initialized with values
//Postcondition:  queue nodes deallocated 
//Description: Deallocates queue dynamic memory (destructor)
//*************************************************************************************
bqueue::~bqueue(){
    while(front != 0){ //while front is not null
        this->dequeue(); //keep getting rid of items
    }
}

//*************************************************************************************
//Name:	bqueue (copy const.)
//Precondition: queue initialized with values
//Postcondition: queue deep copied to another queue
//Description: performs a deep copy to another queue
//*************************************************************************************
bqueue::bqueue(const bqueue& org){
    
    if(org.front == 0){   //if queue is empty...
        cout << "The queue is empty, populate with data." << endl;
        return;         //return as nothing can be done
    }
    
    bqnode* temp = new bqnode;
    bqnode* temp2 = new bqnode; //traversing poionter

    //copy the front node
    front = temp;       //set the front equal to newly allocated memory
    front->priority = org.front->priority;  //set data of front node to old front data
    //front->prev = new bqnode;       //allocate memory for back node
    //front->prev->priority = org.front->prev->priority; //set data of back node to old back data
    //front->prev->next = front; //set next pointer of back to front

    bqnode* curr = front; //trialing pointer
    temp2 = org.front->next;
    temp = new bqnode;
    front->next = temp;
    
    while(temp2 != org.front){
        //temp = new bqnode;      //allocate memory for new copied node
        temp->priority = temp2->priority; //have new node data set to data from old queue
        temp->prev = curr; //have prev pointer point to trailing point of current queue
        temp->next = new bqnode; //have next pointer be new memory
        curr = temp; //have curr pointer be the new node
        temp = temp->next; //advance the temp node
        temp2 = temp2->next; //advance the temp2 node
    }
    
    front->prev = curr; //set previous of front to back
    curr->next = front; //set the back's next pointer to the front
}

//*************************************************************************************
//Name:	print
//Precondition: queue initialized with values
//Postcondition: queue nodes printed to stream
//Description: prints all the nodes in queue, front to back
//*************************************************************************************
void bqueue::print(){
    //cout << "print function called" << endl;

    if(this->empty()){ //if the queue is empty...
        cout << "The queue is empty, populate with data before printing." << endl;
        return;         //exit, nothing can be done
    }

    bqnode* temp; //temp pointer to go through nodes
    temp = front; //have temp pointer point to front
    cout << "[ ";
    do{
        cout << temp->priority << " "; //print the int val
        temp = temp->next;  //advance to next node
    }while(temp->next != front->next); //while we are not back at the front
    cout << "]";
    cout << endl; //extra end line and empty space to differentiate prints
    
}


