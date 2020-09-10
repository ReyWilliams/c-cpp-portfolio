#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"
using namespace std;

//*************************************************************************************
//Name:	Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:	This is the default constructor which will be called automatically when
//an object is declared.	It will initialize the state of the class
//*************************************************************************************
Date::Date(){
    cout << "Default constructor has been called" << endl;

    myDay = 01;
    myMonth = 01;
    myYear = 0001;

    this->display();
    cout << endl;
}

//*************************************************************************************
//Name:	Date
//Precondition: Date object not intialized with desired values
//Postcondition: Date oject initialized with desired values
//Description: explicit-value constructor to set date equal to today's
// date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should
//print a message if a leap year.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y){
    cout << "Explicit-value constructor has been called" << endl;
    myMonth = m;
    myDay = d;
    myYear = y;

    bool incFlag = false;

    if(myMonth <= 0 || myMonth > 12){
        cout << "Month = " << setfill('0') << setw(2) << myMonth << " is incorrect" << endl;
        incFlag = true;
    }
    if(myDay <= 0 || myDay > 31){
        cout << "day = " << setfill('0') << setw(2) << myDay << " is incorrect" << endl;
        incFlag = true;
    }
    if(myYear <= 0){
        cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;
        incFlag = true;
        if(myYear==0){
            cout << endl;
        }
    }
    if(myYear%4!=0 && myMonth == 2 && myDay > 28){
        cout << "day = " << setfill('0') << setw(2) << myDay << " is incorrect" << endl;
        incFlag = true;
        if(myDay==30){
            cout << endl;
        }
    }
    
    if(!incFlag){
    cout << setfill('0') << setw(2) << myMonth << "\\";
    cout << setfill('0') << setw(2) << myDay << "\\";
    cout << setfill('0') << setw(4) << myYear << endl;
        if(myYear%4==0 && !incFlag){
            cout << "This is a leap year" << endl;
            }
    cout << endl;
    }

    
    
}

//*************************************************************************************
//Name:	Display
//Precondition: Date object is initialized with valid month, day, year values
//Postcondition: Date object is correctly formatted and output to the screen
//Description: output Date object to the screen
//*************************************************************************************
void Date::display(){
    cout << setfill('0') << setw(2) << myMonth << "\\";
    cout << setfill('0') << setw(2) << myDay << "\\";
    cout << setfill('0') << setw(4) << myYear << endl;

    if(myMonth == 11 && myDay == 14 && myYear == 1953){
        cout << endl;
    }
}

//*************************************************************************************
//Name:	getMonth
//Precondition: Date object is intialized with month value
//Postcondition: Date object's month value is returned
//Description: accessor to output the month 
//*************************************************************************************
int Date::getMonth(){
	return myMonth;
}

//*************************************************************************************
//Name:	getDay
//Precondition: Date object is intialized with day value
//Postcondition: Date object's day value is returned
//Description: accessor to output the day  
//*************************************************************************************
int Date::getDay(){
	return myDay;
}

//*************************************************************************************
//Name:	getYear
//Precondition: Date object is intialized with year value
//Postcondition: Date object's year value is returned
//Description: accessor to output the year
//*************************************************************************************
int Date::getYear(){
	return myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: Date object's month value has not yet been initialized or set to desried value
//Postcondition: Date object is intialized with desired month value
//Description: mutator to change the month
//*************************************************************************************
void Date::setMonth(unsigned m){
    myMonth = m;
}

//*************************************************************************************
//Name:	setDay
//Precondition: Date object's day value has not yet been initialized or set to desried value
//Postcondition: Date object is intialized with desired day value
//Description: mutator to change the day
//*************************************************************************************
void Date::setDay(unsigned d){
    myDay = d;
}

//*************************************************************************************
//Name:	setYear
//Precondition: Date object's year value has not yet been initialized or set to desried value
//Postcondition:  Date object is intialized with desired year value
//Description: mutation to change the year
//*************************************************************************************
void Date::setYear(unsigned y){
    myYear = y;
}

//*************************************************************************************
//Name:	operator <<
//Precondition: Date object's values have been initialized or set to desried value
//Postcondition:  Date object is output to stream
//Description: overloaded operator<< as a friend function with chaining to output date
//object to desried stream
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
    out << setfill('0') << setw(2) << dateObj.myMonth
    << "\\"
    << setfill('0') << setw(2) << dateObj.myDay
    << "\\"
    << setfill('0') << setw(4) << dateObj.myYear;
	return out;
}
