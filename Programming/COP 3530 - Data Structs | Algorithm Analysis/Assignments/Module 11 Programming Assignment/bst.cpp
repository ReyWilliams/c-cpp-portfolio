#include "bst.h"
//*****************************************************************************
//P R O G R A M	H E A D E R
//
//	Name:	Reynaldo Williams

//	Z#:	23506395
//	Instructor:	Dr. Bullard
//	Class:	Data Structures
//	Term:	Fall 2020
//	Assignment #11 (BST)
//	Due Date:	December 1, 2020
//	Due Time:	11:59PM
//	Points:	25
//
//	Description: Assignment to reinforce BST concepts and ability to implement BST
//******************************************************************************

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: bst
//Precondition: bst not yet initialized
//Postcondition: bst initialized with values from data file
//Description: stores the data file into initial bst
///////////////////////////////////////////////////////////////////////////////////////////////
bst::bst(){
	root = 0; //initialize root with null value

	ifstream in;		//declare input file stream
	in.open("county_data.txt");	//open input file stream

	if(in.fail()){	//if file fials to open
		cout << "Opening the input file [county_data.txt] has failed. Resolve and again." << endl;
	}else{	//if file does not fail to open
		cout << endl; 
		cout << fixed;		//fixed precision
		cout.precision(0);	//precision of 0

		while(!in.eof()){	//while not at end of file

			//this is a process to parse each line of the input file and store the data accordingly
			string line = "";
			string county = "";
			string numbers = "";
			double pop;
			
			getline(in, line);

			for(int i = 0; i < line.length(); i++){

				if(isalpha(line[i]) || isspace(line[i])){
					county += line[i];
				}else if(isdigit(line[i])){
					numbers += line[i];
				}

			}

			int last = county.length() - 1;

			while(isspace(county[last])){
				county = county.substr(0,last);
				last = county.length() - 1;
			}
			pop = stod(numbers);

			insert(root, county, pop);	//insert a new record with parsed data
			cout << left << setw(20) << county << "\t"; //output parsed data
			cout << right << setw(10) << pop << endl;
			}
	}

	in.close();
	cout << endl;

}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~bst
//Precondition: bst initialized with values
//Postcondition: bst memory deallocated
//Description: de-allocates dynamic memory allocation
///////////////////////////////////////////////////////////////////////////////////////////////
bst::~bst(){
	while (root != 0){ //while root is not null(tree is not empty)
		del_name(root->county_name);	//keep deleting nodes
	}

	cout << "The Destructor called" << endl;	//output destructor call
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty
//Precondition: bst declared and/or initialized
//Postcondition: returns whether or not root is null
//Description: determines if bst is null
///////////////////////////////////////////////////////////////////////////////////////////////
bool bst::empty(){
	return (root == 0); //returns if root is null(bst is empty)
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert 
//Precondition: bst declared
//Postcondition: new node inserted into bst
//Description: inserts a new node into bst
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::insert(const string& item, const double& population){		//auxillary function

	insert(root, item, population);	//calls class function
}

void bst::insert(treenode*& loc_ptr, const string& item, const double& population){
	
	if(loc_ptr == 0){	//if pointer is null
		loc_ptr = new treenode;		//allocate memory 
		loc_ptr->lchild = loc_ptr->rchild = 0;	//set children to null
		loc_ptr->county_name = item;			//grab county name from input
		loc_ptr->population_size = population;	//grab pop size from input
	}
	else if(loc_ptr->county_name>item) //if county name is more than input
		insert(loc_ptr->lchild, item, population); //input to left
	else if(loc_ptr->county_name<item) //if county name is less than input
		insert(loc_ptr->rchild, item, population); //input to right
	else	//if we get here county name of node == item so it exists already..
		cout << "The county [" << item << "] is already in the tree" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: bst initialized with values
//Postcondition: bst searched for input argument
//Description: returns pointer to node containing input argument
///////////////////////////////////////////////////////////////////////////////////////////////
treenode* bst::search_tree(string item){ 	//auxillary function
	return search_tree(root, item);
}

treenode* bst::search_tree(treenode * loc_ptr, string item){
	if(loc_ptr != 0){
		if(loc_ptr->county_name == item)
			return loc_ptr;
		else if(loc_ptr->county_name>item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: bst initialized with values
//Postcondition: input argument removed from bst
//Description: removed node containing input argument(if it exists)
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::del_name(string item){	//auxillary function
	
	del_name(root, item);
}

void bst::del_name(treenode * & loc_ptr, string item){

	if(loc_ptr == 0) //if root is null
		cout << "The county [" << item << "] is not in the tree as tree is empty." << endl;
	else if(loc_ptr->county_name > item) 	//if county name more than input arg...
		del_name(loc_ptr->lchild, item); 	//head down left child
	else if (loc_ptr->county_name < item)	//if county name more than input arg...
		del_name(loc_ptr->rchild, item);	//head down right child
	else{									//if county name == to input arg
		treenode * ptr;	

		if (loc_ptr->lchild == 0){	//if the left child is null...
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0){		//if the right child is null...
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else{			//if neither child is null...
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: inorder_succ
//Precondition: bst initialized with values
//Postcondition: gets node that is successor to node input
//Description: returns a pointer to the inorder successor, based on county name. 
///////////////////////////////////////////////////////////////////////////////////////////////
treenode * bst::inorder_succ(treenode * loc_ptr){

	treenode *ptr = loc_ptr->rchild; //set pointer to right child

	while (ptr->lchild != 0)	//while the left child is not null
	{
		ptr = ptr->lchild;		//advance pointer to left child
	}
	return ptr;		//return pointer
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: bst initialized with values
//Postcondition: prints each county record
//Description: prints each county record to the screen sorted by county name
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::print_tree(){		//auxillary function
	print_tree(root);
}

void bst::print_tree(treenode*& loc_ptr){
	if (loc_ptr != 0){ //if current node is not null
		print_tree(loc_ptr->lchild); //print left children (resurively)
		cout << loc_ptr->county_name << endl; //print county name
		print_tree(loc_ptr->rchild); //print right children (recursively)
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: bst initialized with values
//Postcondition: prints each county record
//Description: prints each county record to the screen sorted by county name
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::sorted_info(){	//auxillary function

	ofstream out;	//declare stream

	out.open("county_info.txt"); //bind file to stream
	if(out.fail()){	//if fails
		cout << "Opening the output file has failed. Try again." << endl;
		return;	//exit
	}

	out << fixed; //fixed notation
	out.precision(0); //no precision

	sorted_info(out, root); 
	out.close();	//close stream
}

void bst::sorted_info(ofstream& out, treenode*& loc_ptr){

	//same approach as print function
	if (loc_ptr != 0){ 
		sorted_info(out, loc_ptr->lchild);
		out << left << setw(20) << loc_ptr->county_name << "\t";
		out << right << setw(9) << loc_ptr->population_size << endl;
		sorted_info(out, loc_ptr->rchild);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty_tree
//Precondition: bst initialized with values
//Postcondition: bst memory deallocated
//Description: de-allocates dynamic memory allocation
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::empty_tree(){
	while (root != 0){ //while root is not empty(not null)
		del_name(root->county_name);	//keep deleting nodes...
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: bst initialized with values
//Postcondition: outputs counties within range
//Description: prints all the county names to the screen that lie between min_name and max_name, inclusive. 
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::county_ranges(const string& min_name, const string& max_name){
	county_ranges(root, min_name, max_name);
}
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name){

	//same concept as print function, but with check for county name	
	if(loc_ptr != 0){ 
		county_ranges(loc_ptr->lchild, min_name, max_name);
			if(loc_ptr->county_name >= min_name && loc_ptr->county_name <= max_name)
				cout << loc_ptr->county_name << endl;
		county_ranges(loc_ptr->rchild, min_name, max_name);
	}
}

