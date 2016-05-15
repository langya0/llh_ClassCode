#pragma once
#include<stack>
#include<iostream>
using namespace std;
class Object;
class Context;
//������ʽ

//������ʽ�������﷨����/�﷨���Ĺؼ���ÿ���﷨�������ָ���﷨��������ͨ���ݹ���÷�ʽ���
class Expression
{
public:
	virtual Object* interpreter(Context *ctx) = 0
	{
		cout << "If you Can, you Don't" << endl;
		return NULL;
	};
};
//�ս�����ʽ�򵥣���Ҫ������Ԫ�غ����ݵ�ת��
//�ս�����ʽ
class TerminalExpression :public Expression
{
	Object* interpreter(Context*ctx)
	{
		cout << "TerminalExpression::interpreter" << endl;
		return NULL;
	}
};

//ÿ�����ս�����ʽ����ʾһ���ķ�����ÿ���ķ�������ֻ�����ܱ��ķ�����Ľ�������Ծͻ��еݹ���ö�����
//���ս�����ʽ
class NonterminalExpression :public Expression
{
public:
	NonterminalExpression(Expression* x1, ...)
	{
		for (int i = 0; i < 4; ++i)
		{
			_st.push(x1);
		}
	}
	Object *interpreter(Context*ctx)
	{
		//����֧����������������ķ��������Ҳ����ݹ����
		//if(typeid().name() != "TerminalExpression")
		//�ݹ����
		//�ķ�����
		while (!_st.empty())
		{
			Expression* tp = _st.top();
			_st.pop();
			cout << "NoterminalExpression::interpreter" << endl;
			tp->interpreter(ctx);
		}
		return NULL;
	}
private:
	stack <Expression*> _st;
};
class Context{
};

class Client
{
public:
	void operator()()
	{
		Context *ctx = new Context();
		stack<Expression*> st;
		for (int i = 0; i < 5; ++i)
		{
			//�����﷨�жϣ����Ҳ����ݹ����
			st.push(new TerminalExpression());
			st.push(new NonterminalExpression(new TerminalExpression()));
		}
		//for (int i = 0; i < 5; ++i)
		//{
		//	//�����﷨�жϣ����Ҳ����ݹ����
		//	st.push(new NonterminalExpression(new TerminalExpression()));
		//	st.push(new TerminalExpression());
		//}
		//����һ���������﷨�����ɸ���������﷨�������н���
		Expression *exp = st.top();
		exp->interpreter(ctx);
	}
};
//
//#include<string>
//#include<iostream>
//using namespace std;
//class Context
//{};
//
//class AbstractExpression
//{
//public:
//	virtual ~AbstractExpression(){}
//	virtual void Interpret(const Context& c){}
//protected:
//	AbstractExpression(){}
//private:
//};
//
//class TerminalExpression :public AbstractExpression
//{
//public:
//	TerminalExpression(const string& statement);
//	~TerminalExpression(){}
//	void Interpret(const Context& c);
//protected:
//private:
//	string _statement;
//};
//class NonterminalExpression :public AbstractExpression
//{
//public:
//	NonterminalExpression(AbstractExpression* expression, int times);
//	~NonterminalExpression(){}
//	void Interpret(const Context& c);
//protected:
//private:
//	AbstractExpression* _expression;
//	int _times;
//};
//
//TerminalExpression::TerminalExpression(const string& statement)
//{
//	this->_statement = statement;
//}
//void TerminalExpression::Interpret(const Context& c)
//{
//	cout << this->_statement << " TerminalExpression" << endl;
//}
//NonterminalExpression::NonterminalExpression(AbstractExpression*
//	expression, int times)
//{
//	this->_expression = expression;
//	this->_times = times;
//}
//void NonterminalExpression::Interpret(const Context& c)
//{
//	for (int i = 0; i < _times; i++)
//	{
//		this->_expression->Interpret(c);
//	}
//}
//
//
//int TestInterpreter()
//{
//	Context* c = new Context();
//	AbstractExpression* te = new TerminalExpression("hello");
//	AbstractExpression* nte = new NonterminalExpression(te, 2);
//	nte->Interpret(*c);
//	return 0;
//}