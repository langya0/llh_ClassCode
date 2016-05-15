#pragma once 
#include<hash_map>
#include<iostream>
using namespace std;

class Flyweight
{
private:
	//�ڲ�״̬���ǹ����״̬
	string intrinsic;
protected:
	//�ⲿ״̬,����״̬
	const string extrainsic;
public:
	Flyweight(string _ex)
		:extrainsic ( _ex)
	{
	}

	//����ҵ�����
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
		//�����ⲿ�߼�����ҵ����
		cout << "1�����ⲿ�߼�����ҵ����!" << endl;
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
		//�����ⲿ�߼�����ҵ����
		cout << "2�����ⲿ�߼�����ҵ����!" << endl;
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

//������Ԫ��ɫһ��Ϊ�����࣬ʵ����Ŀ������ʵ���࣬
//��������һ��ʧ��ķ�����������һ�����ⲿ״̬���ڲ�״̬���������Ҳ����û���ڲ�״̬��ֻ����Ϊ������������������չ




///////////////////////////////���̱߳��ѧϰ
#include<thread>
//���߳����
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
			cout << "�̲߳���ȫ��" << endl;
			exit(1);
		}
	}
};
class Client
{
public:
	void operator()()
	{
		FlyweightFactory::getFlyweight("��Ŀ1");
		FlyweightFactory::getFlyweight("��Ŀ2");
		FlyweightFactory::getFlyweight("��Ŀ3");
		FlyweightFactory::getFlyweight("��Ŀ4");

		Flyweight* tmp = FlyweightFactory::getFlyweight("��Ŀ2");
		while (true)
		{
			(new MultiThread(tmp))->run();
			(new MultiThread(tmp))->run();
		}
	}
};