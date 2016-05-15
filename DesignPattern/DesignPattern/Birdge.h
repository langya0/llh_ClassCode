#pragma once
#include<iostream>
using namespace std;

class Implementor
{
protected:
	Implementor(){}
public:
	virtual ~Implementor() = 0{}

	virtual void doSomething() = 0;
	virtual void doAnything() = 0;
};

class ConcreteImplementor1 :public Implementor
{
public:
	void doSomething()
	{
		cout << "1doSomething();" << endl;
	}
	void doAnything()
	{
		cout << "1doAnything();" << endl;
	}
};
class ConcreteImplementor2 :public Implementor
{
public:
	void doSomething()
	{
		cout << "2doSomething();" << endl;
	}
	void doAnything()
	{
		cout << "2doAnything();" << endl;
	}
};

class Abstraction
{
private:
	Implementor *_imp;
public:
	Abstraction(Implementor * imp)
		:_imp(imp)
	{}

	virtual void request()
	{
		_imp->doSomething();
	}
	Implementor* getImp()
	{
		return _imp;
	}
};

class RefinedAbstraction :public Abstraction
{
public:
	RefinedAbstraction(Implementor* imp)
		:Abstraction(imp)
	{}

	void request()
	{
		Abstraction::request();
		Abstraction::getImp()->doAnything();
	}
};

class Client
{
public:
	void operator()()
	{
		Implementor* imp = new ConcreteImplementor1();
		Abstraction* abs = new RefinedAbstraction(imp);
		abs->request();
	}
};