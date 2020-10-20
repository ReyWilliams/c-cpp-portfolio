#include <string>
#include <iostream>
#include "stack.h"
using namespace std;

//*************************************************************************************
//Name:	stack
//Precondition: stack not intialized as yet
//Postcondition: stack initialized with null top
//Description: Initializes stack (default constructor)
//*************************************************************************************
stack::stack(){
    s_top = 0;
}

//*************************************************************************************
//Name:	~stack
//Precondition: stack initialized with values
//Postcondition:   stack elements deallocated 
//Description: Deallocates stack dynamic memory (destructor)
//*************************************************************************************
stack::~stack(){
    while(s_top != 0){ //which the top element is not null/0, keep popping elements
        pop();
    }
}

//*************************************************************************************
//Name:	pop
//Precondition: stack initialized with values
//Postcondition: stack top element removed
//Description: pops top element off stack
//*************************************************************************************
void stack::pop(){
	stack_node *p;

	if (s_top != 0){    //if stack is not empty...
		p = s_top;      //make temp the top of stack
		s_top = s_top->next;        //make the top the next element
		delete p;                   //delete the temp (old top)
	}
	
}

//*************************************************************************************
//Name:	push
//Precondition: stack initialized
//Postcondition: stack element added
//Description: pushes items onto the stack
//*************************************************************************************
void stack::push(const stack_element& item){
	stack_node *p = new stack_node; //allocate memeory for the new item

	p->data = item;     //set the data of the stack node to input param.
	p->next = s_top;    //set the next element of the new element to the old top
	s_top = p;          //set the top to the new element
}

//*************************************************************************************
//Name: top
//Precondition: stack initialized with values
//Postcondition: top stack element is returned
//Description: returns the top element of the stack
//*************************************************************************************
stack_element stack::top(){
	if (s_top == 0){    //if the top is null, the stack is empty
		cout << "Stack is empty, populate with data." << endl;   //let user know the stack is empty.
        exit(1);         //so exit the function
	}else{  //if stack is not empty
		return s_top->data; //return the data of the top element
	}
}

//*************************************************************************************
//Name:	isValid
//Precondition: user entered postfix expression
//Postcondition:  validity of postfix expression evaluated
//Description: determines if user-inputted postfix expression is valid
//*************************************************************************************
bool isValid(const string& userInput){
    int ops = 0;    //number of operands
    int oper = 0;   //number of operators

    for(int i = 0; i< userInput.length(); i++){ //count operands and operators
        if(isalnum(userInput[i]))
            ops++;
        else if(!isspace(userInput[i]))
            oper++;
    }

    //cout << ops << " " << oper << endl; //test print for values of ops and oper

    if(userInput.length() == 1 && ops == 1){ //single operand postfix expression
        return true;
    }

    if(userInput.length() == 0){ //empty string postfix expression
        return true;
    }

    if(oper >= ops){ //if there are more operators than operands
        cout << "Postfix expression invalid:\nToo many operators and not enough operands" << endl;
        return false;
    }else if(ops > 2 && ops >= oper*2){ //spacial case so cases like (a + b) do not fail
        cout << "Postfix expression invalid:\nToo many operands and not enough operators" << endl;
        return false;
    }else if(ops > oper*2){ //if there are more operands than operators
        cout << "Postfix expression invalid:\nToo many operands and not enough operators" << endl;
        return false;
    }

    return true;
}

//*************************************************************************************
//Name:	stack (copy const.)
//Precondition: stack initialized with values
//Postcondition:   stack deep copied to another stack
//Description: performs a deep copy to another stack
//*************************************************************************************
stack::stack(const stack & Org){
	(*this).s_top = 0;

	stack temp;
	stack_node *currNode =Org.s_top;
	while(currNode != 0){
		temp.push(currNode->data);
		currNode = currNode->next;	
	}

	currNode = temp.s_top;
	while (currNode != 0){
		(*this).push(currNode->data);
		currNode = currNode->next;
	}
}

//*************************************************************************************
//Name:	convert
//Precondition: user postfix expression is valid
//Postcondition: stack is not initialized with infix expression
//Description: converts postfix expression to infix expression
//*************************************************************************************
void stack::convert(string postfix){
    string fOp; //string element to hold first operand
    string sOp; //string element to hold second operand

    if(postfix.length() == 0){ //edge case for empty string
        push("");
        return;
    }
    if(postfix.length() == 1){  //edge case for single operand 
        push("(" + postfix + ")");
        return;
    }


    for(char o: postfix){ //for every character that is in the postfix expression
        if(isalnum(o)){     //if it is an alphabetical/numerical character...
            string temp(1,o);   //make it into a string(cant push chars)
            push(temp);         //push the char/string
        }else if(o == '+' || o == '-' || o == '*' || o == '/'){ //if it is an operator
                sOp = top();    //input the second operand as the top element 
                pop();          //pop so we can get the first operand
                fOp = top();    //input the first operand as the top element 
                pop();          //pop so we can replace with the result (pushed)
                string result = "("; //all formattting to push result
                result += (fOp);
                result += " ";
                result.push_back(o);
                result += " ";
                result += (sOp);
                result.push_back(')');
                push(result);   //push the reuslt
        }
    }
}

//*************************************************************************************
//Name:	print
//Precondition: stasck initialized with values
//Postcondition: stack values printed to stream
//Description: prints all the nodes in stack
//*************************************************************************************
void stack::print(){
	for(stack_node *currNode = s_top; currNode != 0; currNode = currNode->next){
		cout << currNode->data;
	}

    cout << endl;
}
