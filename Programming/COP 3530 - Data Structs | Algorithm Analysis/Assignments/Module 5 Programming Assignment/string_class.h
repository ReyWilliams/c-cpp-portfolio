#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef STRING_CLASS
#define STRING_CLASS

class string_class{
    public:
    string_class(); //A default constructorthatsets “current_string”to an empty string (“”).
    string_class(const string&); //An explicit-value constructorthatsets “current_string” equalto the argument
                                    //that is passed to the explicit-value constructorwhena string_classobjectis
                                    //declared
    bool palindrome();  //returns true if the current_string reads the same forward as it doesbackwards 
                        //otherwise it return false. 
    void replace_all(string, string);   //replaces each occurrenceof “old_substring”with“new_substring” in
                                        //“current_string”
    friend ostream& operator<<(ostream&, string_class&); //Overload the insertion operator(<<) as a friend 
                                                                //function of the class with chaining to print 
                                                                //the contents of a string_class object’s “current_string”

    private:
    string current_string;  //private string variable “current_string”
};

#endif