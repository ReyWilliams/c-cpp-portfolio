// ConsoleApplication12.cpp : Defines the entry point for the console application.
//



#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Array_Class
{
public:
	Array_Class();
	void Double_Size();
	void Add(const int key);
	void Print() const;
	int Search(const int key) const;
	void Remove(int key);

	friend ostream & operator<<(ostream & out, Array_Class & org);

	Array_Class &  operator+(const int key);

private:
	int *A;
	int count;
	int size;
};

Array_Class::Array_Class()
{
	size = 2;
	count = 0;

	A = new int[size];

	for (int i = 0; i<20; i++)
	{
		if (count == size)
		{
			Double_Size();
		}
		A[i] = i + 100;
		count++;
	}
}


void Array_Class::Double_Size()
{
	size *= 2;

	int * t = new int[size];

	for (int i = 0; i<count; i++)
	{
		t[i] = A[i];
	}

	delete[] A;

	A = t;
}


void Array_Class::Add(const int key)
{
	if (count == size)
	{
		Double_Size();
	}

	A[count] = key;
	count++;
}

//overloading the plus operator+ as a member function with chaining
//This function has the same functionality as the Add function.
Array_Class &  Array_Class::operator+(const int key)
{
	if (count == size)
	{
		this->Double_Size();
	}

	this->A[count] = key;
	this->count++;

	return *this;

}

void Array_Class::Print() const
{
	for (int i = 0; i<count; i++)
	{
		cout << "A[ " << i << " ] = " << A[i] << endl;
	}
}

int Array_Class::Search(const int key) const
{
	for (int i = 0; i<count; i++)
	{
		if (A[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void Array_Class::Remove(int key)
{
	int loc = Search(key);

	if (loc != -1)
	{
		for (int j = loc; j<count - 1; j++)
		{
			A[j] = A[j + 1];
		}
		count--;
	}
}


//overloading the insertation operator<< as a member function with chaining
//This function has the same functionality as the Print function.
ostream & operator<<(ostream & out, Array_Class & org)
{
	for (int i = 0; i<org.count; i++)
	{
		out << "A[ " << i << " ] = " << org.A[i] << endl;
	}

	return out;


}

int main()
{
	Array_Class me;
	cout << endl << "A before 114 is removed" << endl;
	//me.Print();
	//me.Remove(114);
	cout << endl << "A after 114 is removed" << endl;
	//me.Print();
	cout << me<< me;//chaining as friend
	cout << endl << "*************************************\n";
	me + -999 + -888 + -777; //chaining as member
	cout << me << endl;
	return 0;
}
