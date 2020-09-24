#include <iostream>
#include <string>
#include "sentence.h"
using namespace std;


//*************************************************************************************
//Name:	sentence
//Precondition: state variables are not intialized
//Postcondition: state variables are intialized will NULL
//Description: Initializes state variables
//*************************************************************************************
sentence::sentence(){
    front = NULL;   //front pointer set to NULL
    back = NULL;    //back pointer set to NULL
}

//*************************************************************************************
//Name:	sentence(const string& s)
//Precondition: state variables and nodes are not intialized with desired values
//Postcondition: state variables and nodes are intialized with desires values
//Description: Explicit value constructor initializes state variables and nodes with desired values
//*************************************************************************************
sentence::sentence(const string& s){
    cout << "Explicit-value constructor for sentence class called." << endl;
    string s1 = s;

    front = NULL;   //front pointer set to NULL
    back = NULL;    //back pointer set to NULL

    int length = static_cast<int>(s.length());    //length variable is length of string

    if(length == 0){     //if string is empty, return, nothing can be done with it
        return;
    }

    front = new word; //allocate space for a new word as there is data to be processed. store the returned pointed in front
    word* currentWord = front; //creates a pointer to the current word and initialized it to the front

    int i = length;

    while(i != 0){
            
            if(isspace(s1.front())){ //if the first character is space
                currentWord->term = s1.front(); //make the term a space
                s1 = s1.substr(1);  //shorten the string to not include the space anymore
                i--;           //decrament the length by 1
            }else{  //if the first term is NOT a space
                int n = static_cast<int>(s1.find_first_of(" ")); //find the first space
                
                if(n == -1) //if there are no more spacing, take the last index
                    n = static_cast<int>(s1.length());
                
                currentWord->term = s1.substr(0,n); //make the term everything UP to the first space (aka a word)
                i -= s1.substr(0,n).length();    //subtract the length of the last segment you substracted
                s1 = s1.substr(n);      //shorted the string not to include that word anymore
            }


        if(i <= 0){ //if we are at the last possible index..
                currentWord->next = NULL;    //have the next pointer be null as there are no other positions
                break;
        }else{      //if we are not at the end yet and still have more values
            currentWord->next = new word;   //return a pointer for the next word by allocating space using new
            currentWord = currentWord->next; //the new current word is what the next pointer is pointing to 
        }
    }


    back = currentWord; //pointer to the back is the currentWord pointer
    back->next = NULL;
}

//*************************************************************************************
//Name:	sentence(const sentence& org)
//Precondition: sentence object needed to be deep copied
//Postcondition: setence object and its nodes are deep copied with new points
//Description: copy constructor to be used during a call-by-value, return, or initialization/declaration of a sentence object
//*************************************************************************************
sentence::sentence(const sentence& org){
   
    if(org.front == NULL){ //if the orignal linked list is empty, they just make the copied one empty as well
        this->front = NULL;
        return; //end the function
    }

    this->front = new word;     //allocate space for front var

    word* temp1 = new word;     //allocate space for new temp var which will tranvswer the orignal linked list
    temp1 = org.front;          //place the trans pointer to the front of the orignal

    word* currentw1 = new word; //get a new word pointer which will make your new copied linked list
    this->front = currentw1;    //have your new front var point to the new word pointer (your new front)        

    while(temp1 != NULL){ //while the pointer that is transvering the orginal linked list is not null (aka at the end)
        currentw1->term = temp1->term; //have the current word pointer's term be the same as the term from the orignal list
        temp1 = temp1->next;    //advance the pointer

        if(temp1 != NULL){  //if the pointer is not null after advancing (its not at the end)
        currentw1->next = new word; //alocate space in the copied array for another word(node)
        currentw1 = currentw1->next;    //advance the copied string to the newly allocated space
        }else{
            this->back = currentw1;     //set the back of the new copied sentence to be its last word
            break;
        }

    }
}

//*************************************************************************************
//Name:	length
//Precondition: sentence object length (number of nodes) is needed
//Postcondition: sentence object length(number of nodes) is returned
//Description: Determines the length of the sentence
//*************************************************************************************
int sentence::length(){

    int count = 0;      //declare and initialize count as 0

    if(this->front == NULL){  //if front is NULL, as in there is no list
        return 0;       //return zero as there is no size either
    }


    word* currentw2 = new word; //allocate space for word
    currentw2 = this->front;    //have the current word point to front

    while(currentw2 != NULL){                   //while current word is not null is not null
        count += currentw2->term.length();      //increment the count
        currentw2 = currentw2->next;    //go to the next node
    }

    return count;
}

//*************************************************************************************
//Name: operator<<
//Precondition: sentence object and its nodes needs to be output to stream
//Postcondition: sentence object and its nodes are output to stream
//Description: Outputs sentence object and its nodes to output stream
//*************************************************************************************
ostream& operator<<(ostream& out, const sentence& org){

    //cout << "Operator << function for sentence class called." << endl;
    if(org.front == NULL) //if the front is NULL (no words)
        return out;
    
    word* currentw3 = new word; //allocate space for word
    currentw3 = org.front;    //have the current word point to front

    while(currentw3 != NULL){   //while current word is not null

        if(currentw3->term.length() != 0) //if the current word is NOT empty
        out << currentw3->term; //output the term and a single space to the stream
        
        currentw3 = currentw3->next;    //advance to the next node (word)
    }

    return out;
}

//*************************************************************************************
//Name: ~sentence
//Precondition: sentence object has memory allocated for nodes
//Postcondition: setence object and the memeory allocated by its nodes is freed
//Description: De-allocates all memory for a sentence
//*************************************************************************************
sentence::~sentence(){
    cout << "Destructor called" << endl;

    word* temp = new word;
    word* currentw4 = new word;
    currentw4 = front;


    while(currentw4 != NULL){
        temp = currentw4;               //set the temp value to the current word
        currentw4 = currentw4->next;    //advance the current word to the next one;
        delete temp;                    //deallocate the memory for temp(the previous word)
    }

}

//*************************************************************************************
//Name: isEqual
//Precondition: sentence object A and B are initialized with node values
//Postcondition: sentence objects A and B have nodes compared and equlaity is returned
//Description: Returns true if two sentence objects are equal
//*************************************************************************************
bool sentence::isEqual(sentence& B){
    
    if(this->length() != B.length()){   //first start by seeing is the two objects are even the same size
        return false;                   //if they are not, return false
    }

    word* tempA = new word;
    word* tempB = new word;

    tempA = this->front;
    tempB = B.front;

    while(tempA != NULL && tempB != NULL){  //ideally these should reach null at the same time as their lengths are the same but just in case
            if(tempA->term != tempB->term)  //if the terms of A and B (the current sentence and the secondary sentence) are not equal at any node
                return false;               //return false

        tempA = tempA->next;    //advance both the points to the next element
        tempB = tempB->next;    
    }

    return true;
}

//*************************************************************************************
//Name: add_back
//Precondition: sentence object is declared
//Postcondition: sentence object adds string s as a node to the back of the sentence(linked list)
//Description: Add a word (node) to the back of the sentence (the linked list)
//*************************************************************************************
void sentence::add_back(string& s){
    word* newElm = new word;
    
    if(front == NULL){ //if this one that you're adding is the only element...
            this->front = newElm; //set front to be that element as its now the first and only
            this->back = newElm; //set front to be that element as its now the last and only
            newElm->term = s;   //set the term to be the string arg
            newElm->next = NULL; //set the next param to be NULL as there is nothing next 
    }else{ //there are already elements
            this->back = newElm; //set the new back to be the new element
            newElm->term = s;   //set the term to be the string arg
            newElm->next = NULL; //set the next param to be NULL as there is nothing next 
    }
}

//*************************************************************************************
//Name: add_front
//Precondition: sentence object is declared
//Postcondition: sentence object adds string s as a node to the front of the sentence(linked list)
//Description: Add a word (node) to the front of the sentence (the linked list)
//*************************************************************************************
void sentence::add_front(string& s){
    word* newElm = new word;
    word* temp = new word;
    temp = front;
    
    if(front == NULL){ //if this one that you're adding is the only element...
            this->front = newElm; //set front to be that element as its now the first and only
            this->back = newElm; //set front to be that element as its now the last and only
            newElm->term = s;   //set the term to be the string arg
            newElm->next = NULL; //set the next param to be NULL as there is nothing next 
    }else{
            front = newElm;
            newElm->term = s;
            newElm->next = temp;
    }
}

//*************************************************************************************
//Name: operator=
//Precondition: string is initialized with value
//Postcondition: sentence object A's nodes are set equal to nodes derived from string s
//Description: Assigns values of string to current setence object A
//*************************************************************************************
void sentence::operator=(const string& s){
    string s1 = s;

    front = NULL;   //front pointer set to NULL
    back = NULL;    //back pointer set to NULL

    int length = s.length();    //length variable is length of string

    if(length == 0){     //if string is empty, return, nothing can be done with it
        return;
    }

    front = new word; //allocate space for a new word as there is data to be processed. store the returned pointed in front
    word* currentWord = front; //creates a pointer to the current word and initialized it to the front

    int i = length;

    while(i != 0){
            
            if(isspace(s1.front())){ //if the first character is space
                currentWord->term = s1.front(); //make the term a space
                s1 = s1.substr(1);  //shorten the string to not include the space anymore
                i--;           //decrament the length by 1
            }else{  //if the first term is NOT a space
                int n = s1.find_first_of(" "); //find the first space
                currentWord->term = s1.substr(0,n); //make the term everything UP to the first space (aka a word)
                i -= s1.substr(0,n).length();    //subtract the length of the last segment you substracted

                if(i != 0)              //if the string is not completely parsed
                s1 = s1.substr(n);      //shorted the string not to include that word anymore
                
            }


        if(i == 0){ //if we are at the last possible index..
                currentWord->next = NULL;    //have the next pointer be null as there are no other positions
                break;
        }else{      //if we are not at the end yet and still have more values
            currentWord->next = new word;   //return a pointer for the next word by allocating space using new
            currentWord = currentWord->next; //the new current word is what the next pointer is pointing to 
        }
    }


    back = currentWord; //pointer to the back is the currentWord pointer
    back->next = NULL; //ensure that the back's next pointer is NULL

}

//*************************************************************************************
//Name: operator=
//Precondition: sentence object B is initialized with nodes
//Postcondition: sentence object A's nodes are set equal to nodes derived sentence object w
//Description: Assigns values of string to current setence object A
//*************************************************************************************
sentence& sentence::operator=(const sentence& w){
         if(w.front == NULL){ //if the orignal linked list is empty, they just make the copied one empty as well
        this->front = NULL;
        return *this; //end the function
    }

    this->front = new word;     //allocate space for front var

    word* temp1 = new word;     //allocate space for new temp var which will tranvswer the orignal linked list
    temp1 = w.front;          //place the trans pointer to the front of the orignal

    word* currentw1 = new word; //get a new word pointer which will make your new copied linked list
    this->front = currentw1;    //have your new front var point to the new word pointer (your new front)        

    while(temp1 != NULL){ //while the pointer that is transvering the orginal linked list is not null (aka at the end)
        currentw1->term = temp1->term; //have the current word pointer's term be the same as the term from the orignal list
        temp1 = temp1->next;    //advance the pointer

        if(temp1 != NULL){  //if the pointer is not null after advancing (its not at the end)
        currentw1->next = new word; //alocate space in the copied array for another word(node)
        currentw1 = currentw1->next;    //advance the copied string to the newly allocated space
        }else{
            this->back = currentw1;     //set the back of the new copied sentence to be its last word
            break;
        }

    }
    return *this;
}

void sentence::operator+(sentence& B){

    if(B.length() == 0){ //if B is empty, just return as nothing could be added
        return;
    }else if(this->length() == 0){ //if A is empty
        *this = B;  //make it equal to B
       return;
    }

    word* temp1 = new word;
    word* temp2 = new word;

    temp1 = this->getBack();
    temp2 = B.getFront();


    while(temp2 != NULL){

            temp1->next = new word; //alocate space for a word
            temp1 = temp1->next;    //adavnce to the next new node in A
            temp1->term = temp2->term;  //fill the allocated space with the term from B
            temp2 = temp2->next;    //advance to the next node in B

    }
}

//*************************************************************************************
//Name: remove
//Precondition: sentence object is initalized with nodes
//Postcondition: sentence object is parsed and the node matching string s is removed
//Description: Deletes the first occurrence of string s in the current sentence object
//*************************************************************************************
void sentence::remove(const string& s){

    word* temp1 = new word; //allocate space for two word pointers
    word* temp2 = new word;

    if(s.length() == 0 || this->length() == 0) //if the string s is empty, jump to end, nothing to remove
        return;

    temp1 = this->front;    //one pointer at the front
    temp2 = temp1->next;    //another right in front of it leading

    if(temp1->term == s){ //if the first node matches the string, remove it and make front point to the next element.
        this->front = temp2; //new front is the pointer that is leading

        if(temp1 != NULL)
        delete temp1; //delete the value
        return; //return as you are done
    }

     while(temp2 != NULL){ //stop when temp1 is at the last element(back) 

            if(temp2->term == s && temp2 != back){ //if the front checker is the term to be removed and it is not the last element
                temp1->next = temp2->next; //back element's next pointer is the current(front)'s next pointer
                
                if(temp2 != NULL)
                delete temp2;   //delete the matching element
                return; //exit as you are done
                
            }else{ //if it is not the right element
            temp2 = temp2->next; //keep advamncing through each node, temp1 following temp2
            temp1 = temp1->next;
            }

            if(temp2->term == s && temp2 == back){
                temp1->next = temp2->next;  //back element's next pointer is the current(front)'s next pointer
                back = temp1;   //make back equal to the term before last
                back->next = NULL;  //make the next element of the back null as that is what back points to

                if(temp2 != NULL)
                delete temp2;   //delete the matching element
                return; //exit as you are done
            }
     }


}


