#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

typedef string stack_element; //type definition for readability

class stack_node{   //stack node class so we can stare each value as a node
    public:
	    stack_element data; //data element 
	    stack_node *next;   //pointer to next element
};

class stack{ //stack class
    public:
	    stack();                //Initializes stack (default constructor)
	    ~stack();               //Deallocates stack dynamic memory (destructor)
	    stack(const stack &);   //performs a deep copy to another stack
	    stack_element top();    //returns the top element of the stack
	    void pop();             //pops top element off stack
	    void push(const stack_element&);    //pushes items onto top of the stack
	    void print();                       //prints all the nodes in stack
        void convert(string postfix);       //converts postfix expression to infix expression
    private:
	stack_node *s_top;     //pointer to top of stack
};

bool isValid(const string&); //determines if user-inputted postfix expression is valid

#endif
