#pragma once
#include<iostream>
using namespace std;

//ǰ������
class Context;
//����״̬�ඨ��
class State
{
protected:
	State(){}
public:
	virtual~State() = 0
	{};
	void setContext(Context *x)
	{
		_context = x;
	}
	virtual void handler1() = 0;
	virtual void handler2() = 0;
private:
	Context *_context;
};

//����״̬����
class ConcreteState1 :public State
{
public:
	ConcreteState1(){}
	~ConcreteState1(){}

	void handler1()
	{
		cout << "ConcreteState1::handler1" << endl;
	}
	void handler2()
	{
		cout << "ConcreteState1::handler2" << endl;
	}
private:

};

//����״̬����
class ConcreteState2 :public State
{
public:
	ConcreteState2(){}
	~ConcreteState2(){}

	void handler1()
	{
		cout << "ConcreteState2::handler1" << endl;
	}
	void handler2()
	{
		cout << "ConcreteState2::handler2" << endl;
	}
private:

};

//������
class Context
{
public:
	Context()
	:Sta1(new ConcreteState1)
	,Sta2(new ConcreteState2)
	{}
	State* getCurrentState()
	{
		return CurrentState;
	}
	void SetCurrentState(State* s)
	{
		CurrentState = s;
		CurrentState->setContext(this);
	}
	void handler1()
	{
		CurrentState->handler1();
	}
	void handler2()
	{
		CurrentState->handler2();
	}
	~Context(){}
private:
	//��ǰ״̬��������״̬�е�һ��
	State *CurrentState;
	//����״̬Ӧ������Ϊstatic�ȽϺ���
	State *Sta1;
	State *Sta2;
};

void TestState()
{
	Context * context = new Context();
	context->SetCurrentState(new ConcreteState1());

	context->handler1();
	context->handler2();
	context->SetCurrentState(new ConcreteState2());
	context->handler1();
	context->handler2();
}

