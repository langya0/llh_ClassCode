#include<iostream>
using namespace std;

void Test() throw()
{
	try
	{
		int i = 0;
		//throw i;
		char c = 0;
		throw c;
	}
	catch (double e)
	{
		cout << "Test" << endl;
	}
	cout << "In Test " << endl;

}

class B
{
public:
	virtual void f()
	{
		cout << "B::f()" << endl;
	}
};
class D :public B
{
public:
	void f()
	{
		cout << "D::f()" << endl;
	}
};

void main()
{
	D d;
	B b = d;
	b.f();
	d.f();

	/*FILE *FOut = fopen("y.cpp", "r");
	if (FOut == NULL)
	{
		cout << "File not find!" << endl;
		cout << errno << endl;
	}
	try
	{
		Test();
	}
	catch (char c)
	{
		cout << "char ERROR" << endl;
	}*/

}
