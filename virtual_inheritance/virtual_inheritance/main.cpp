//
//#include"plan.h"

#include<iostream>
using namespace std;
class base{
public:	
	base():_b(0){}
	virtual void fun()
	{
		cout << "base::fun()" << endl;
	}
	int _b;
};

class Left :virtual public base{
public:
	Left():_left(1){}
	int _left;
	void fun()
	{
		cout << "Left::fun()" << endl;
	}
};

class Right :virtual public base{
public:
	Right():_right(2){}
	int _right;
	void fun()
	{
		cout << "Right::fun()" << endl;
	}
};

class Derive :public Left, public Right
{
public:
	Derive():_derive(4){}
	int _derive;
	void fun()
	{
		cout << "Derive::fun()" << endl;
	}
};

void Test1()
{
	Derive d;

	base *pb = &d;
	pb->fun();

	Left *pb1 = &d;
	pb1->fun();

	Right *pb2 = &d;
	pb2->fun();
	cout << endl;
	//cout << pb << endl;
	//cout << pb1 << endl;
	//cout << pb2 << endl;
	//cout << &d << endl;
}

class T{
public:
	T() :a(0){}
	virtual void f()
	{
		cout << "f()" << endl;
		cout << ++a << endl;
	}
	int a;
};
class t{};
class dddd :public T, public t{};

typedef void(__thiscall *PFUN)(void*);

void Test2();
#include<typeinfo>
void main()
{
	int a = 4;
	int b = 4;
	typeid([](int a, int b){return a + b; }            ).name();
	auto f = [](int a, int b)->int{return a + b; };
	cout << typeid(f).name() << endl;
	cout << f(a, b);
	//dddd d;
	//int **p = (int**)(&d);
	//((PFUN)p[0][0])(&d);
	//T t;
	//pr(&t);
	//Test1();
	//Test2();
}






//虚基类可定义问题。
class B{
	//virtual void test() = 0;
public:
	virtual void test() = 0
	{
		cout << "B::Test" << endl;
	}
};
class D :public B{
public:
	void test()
	{
		B::test();
	}
};

void Test2()
{
	D d;
	d.test();
}


//关于虚基类的构造问题。。
//class b{
//public:
//	b(int a = 1)
//		:a(a){}
//	int a;
//};

//class d :virtual public b{
//public:
//	d(int a):b(a){}
//};
//class f :public d{
//public:
//	f(int a) :
//		d(a)
//	//,b(a)
//	{}
//};


////重复继承问题。
//class b{};
//class T1:public b
//{};
////class T2 :public b, public b
////{};
//
//class T3 :public T1, public b{};
