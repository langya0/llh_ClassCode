#pragma once 
#include<hash_map>
#include<iostream>
using namespace std;

class Flyweight
{
private:
	//内部状态，非共享的状态
	string intrinsic;
protected:
	//外部状态,共享状态
	const string extrainsic;
public:
	Flyweight(string _ex)
		:extrainsic ( _ex)
	{
	}

	//定义业务操作
	virtual void operate(){}
	string getIntrinsic()
	{
		return intrinsic;
	}
	void setIntrinsic(string _in)
	{
		intrinsic = _in;
	}
};

class ConcreteFlyweight1 :public Flyweight
{
public:
	ConcreteFlyweight1(string ex)
		:Flyweight(ex)
	{}

	void operate()
	{
		//根据外部逻辑进行业务处理
		cout << "1根据外部逻辑进行业务处理!" << endl;
	}
};
class ConcreteFlyweight2 :public Flyweight
{
public:
	ConcreteFlyweight2(string ex)
		:Flyweight(ex)
	{}

	void operate()
	{
		//根据外部逻辑进行业务处理
		cout << "2根据外部逻辑进行业务处理!" << endl;
	}
};
class FlyweightFactory
{
private:
	static hash_map<string, Flyweight*> pool;
public:
	static Flyweight* getFlyweight(string ex)
	{
		hash_map<string, Flyweight*>::iterator it = pool.find(ex);
		if (it == pool.end())
		{
			cout << "Creat Flyweight1" << endl;
			pool[ex] = new ConcreteFlyweight1(ex);
			pool[ex]->setIntrinsic("lihui");
		}
		return pool[ex];
	}
};


hash_map<string, Flyweight*> FlyweightFactory::pool = hash_map<string,Flyweight*>();
class Clien
{
public:
	void operator()()
	{
		FlyweightFactory ff;
		Flyweight * pf = ff.getFlyweight("liang");
		pf->operate();
	}
};

//抽象享元角色一般为抽象类，实际项目中则是实现类，
//他是描述一类失误的方法。在其中一定将外部状态和内部状态定义出来（也可以没有内部状态，只有行为），避免子类虽易扩展




///////////////////////////////多线程编程学习
#include<thread>
//多线程情况
class MultiThread :public thread
{
private:
	Flyweight* _sign;
public:
	MultiThread(Flyweight* siginfo)
		:_sign(siginfo)
	{}
	void run()
	{
		if (_sign != NULL)
		{
			cout << "线程不安全了" << endl;
			exit(1);
		}
	}
};
class Client
{
public:
	void operator()()
	{
		FlyweightFactory::getFlyweight("科目1");
		FlyweightFactory::getFlyweight("科目2");
		FlyweightFactory::getFlyweight("科目3");
		FlyweightFactory::getFlyweight("科目4");

		Flyweight* tmp = FlyweightFactory::getFlyweight("科目2");
		while (true)
		{
			(new MultiThread(tmp))->run();
			(new MultiThread(tmp))->run();
		}
	}
};