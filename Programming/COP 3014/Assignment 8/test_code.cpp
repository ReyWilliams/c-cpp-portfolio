#include <iostream> //Allows use of cin and cout
#include <string>	//Allows use of strings
#include <fstream>  //Allows for the use of file input and output
#include <iomanip>	//Allows for the use of i/o manipulation to format output
using namespace std; //Denotes names are being used in a standard way


int character_count(){
cout << "Enter string: ";
string s;
getline(cin,s);
cout << "Enter character: ";
char ch;
cin >> ch;
int count = 0;
for (int i = 0; i < s.length(); i++)
{
if (s[i] == ch)
{
count++;
}
}
return count;
}

int main(){

    int i = 0;
    int& j = i;

    cout << "i is: " << i << ". j is: " << j << endl;

    j = 2;
    cout << "i is: " << i << ". j is: " << j << endl;
    i = 3;
    cout << "i is: " << i << ". j is: " << j << endl;

    cout << character_count()<< endl;


    

    return 0;
}

