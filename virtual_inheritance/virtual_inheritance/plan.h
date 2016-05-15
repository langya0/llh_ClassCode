
#include <iostream>
using namespace std;
//
// 1.实现以下几个类的成员函数
// 2.实现一个虚函数的覆盖及调用
// 3.处理菱形继承问题。
//

// 植物
class Botany
{
public:
	Botany(string & name)
		:_name(name)
	{
		++_sCount;
	}

	virtual void Display()
	{
		cout << "Botany::Display()" << endl;
	}
	static const int TotalBotany()
	{
		return _sCount;
	}
protected:
	string _name;//名字
	static int _sCount;
};
int Botany::_sCount = 0;

class Tree :virtual public Botany
{
public:
	//...实现默认的成员函数
	Tree(string &name,const int &hight)
		:Botany(name)
		, _hight(hight)
	{}
	void Display()
	{
		cout << "Tree::Display()" << endl;
	}
protected:
	int _hight;		// 高度
};

class Flower :virtual public Botany
{
public:
	//...实现默认的成员函数
	Flower(string & name,const int &colour)
		:Botany(name)
		, _colour(_colour)
	{}
	void Display()
	{
		cout << "Flower::Display()" << endl;
	}
protected:
	int _colour;	// 颜色
};

// 白兰花，即是树有时花。
class MicheliaAlba : public Flower, public Tree
{
public:
	MicheliaAlba(string &name,const int &hight, const int colour,const int haha)
		:Botany(name)
		, Tree(name, hight)
		, Flower(name, colour)
		, _haha(haha)
	{}
	virtual void Display()
	{
		cout << "MicheliaAlba::Display()" << endl;
	}
protected:
	int _haha;
};
void PrintInfo(Botany* b)
{
	b->Display();
}

#include<string>
int Test()
{
	string l("lang");
	Botany b(l);
	Tree t(l, 6);
	Flower f(l, 4);
	MicheliaAlba m(l, 4, 5, 6);
	
	Botany *pbarr[4];
	pbarr[0] = &b;
	pbarr[1] = &t;
	pbarr[2] = &f;
	pbarr[3] = &m;

	for (int i = 0; i < 4; i++)
	{
		pbarr[i]->Display();
		//PrintInfo(pbarr[i]);
		cout << endl;
	}
	cout << Botany::TotalBotany() << endl;
	return 0;
}

