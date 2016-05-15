#pragma once
#include<stack>
#include<iostream>
using namespace std;
class Object;
class Context;
//抽象表达式

//抽象表达式是生成语法集合/语法树的关键，每个语法集合完成指定语法解析任务，通过递归调用方式完成
class Expression
{
public:
	virtual Object* interpreter(Context *ctx) = 0
	{
		cout << "If you Can, you Don't" << endl;
		return NULL;
	};
};
//终结符表达式简单，主要处理场景元素和数据的转换
//终结符表达式
class TerminalExpression :public Expression
{
	Object* interpreter(Context*ctx)
	{
		cout << "TerminalExpression::interpreter" << endl;
		return NULL;
	}
};

//每个非终结符表达式都表示一个文法规则，每个文法规则又只关心周边文法规则的结果，所以就会有递归调用而存在
//非终结符表达式
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
		//核心支出在于这里。。进行文法处理，并且产生递归调用
		//if(typeid().name() != "TerminalExpression")
		//递归调用
		//文法处理
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
			//进行语法判断，并且产生递归调用
			st.push(new TerminalExpression());
			st.push(new NonterminalExpression(new TerminalExpression()));
		}
		//for (int i = 0; i < 5; ++i)
		//{
		//	//进行语法判断，并且产生递归调用
		//	st.push(new NonterminalExpression(new TerminalExpression()));
		//	st.push(new TerminalExpression());
		//}
		//产生一个完整的语法树，由各个具体的语法分析进行解析
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