//#include<iostream>
//using namespace std;
//
//template<class T>
//struct BinaryTreeNode
//{
//
//	BinaryTreeNode(const T& x)
//		:m_data(x)
//		, m_left(NULL)
//		, m_right(NULL)
//	{}
//	bool operator=(const BinaryTreeNode &x)const
//	{
//		return x.m_data == m_data;
//	}
//	T m_data;
//	BinaryTreeNode* m_left;
//	BinaryTreeNode* m_right;
//};
//
//
//template<class T>
//class BinaryTree
//{
//public:
//
//	BinaryTreeNode<T> *Find(const T& x)
//	{
//		return _Find(m_phead,x);
//	}
//	//BinaryTreeNode<T> *_Find(BinaryTreeNode<T> *root, const T& x)
//	//{
//	//	if (root == NULL)
//	//	{
//	//		return NULL;
//	//	}
//	//	if (root->m_data == x)
//	//	{
//	//		return root;
//	//	}
//	//	else
//	//	{
//	//		if (root->m_left)
//	//		{
//	//			return _Find(root->m_left, x);
//	//		}
//	//		if (root->m_right)
//	//		{
//	//			return _Find(root->m_right, x);
//	//		}
//	//	}
//	//}
//	BinaryTreeNode<T> *_Find(BinaryTreeNode<T> *root, const T &x)
//	{
//		if (root == NULL)
//		{
//			return NULL;
//		}
//		if (root->m_data == x)
//		{
//			return root;
//		}
//		else if (root->m_left)
//		{
//			return _Find(root->m_left, x);
//		}
//		else if (root->m_right)
//		{
//			return _Find(root->m_right, x);
//		}
//		return NULL;
//	}
//	BinaryTree()
//		:m_phead(NULL)
//	{}
//	BinaryTree(const T* arr,size_t size)
//		:m_phead(NULL)
//	{
//		int index = 0;
//		m_phead = _CreatBinaryTree(arr, size,index);
//	}
//	void Print()
//	{
//		_Print(m_phead);
//		cout << endl;
//	}
//protected:
//	void _Print(BinaryTreeNode<T> *m_phead)
//	{
//		if (m_phead == NULL)
//		{
//			cout << "#";
//			return;
//		}
//		else
//		{
//			cout << m_phead->m_data;
//			_Print(m_phead->m_left);
//			_Print(m_phead->m_right);
//		}
//	}
//
//	//根据前序生成
//	
//	BinaryTreeNode<T>* _CreatBinaryTree(const T *a, size_t size, int& index)
//	{
//		BinaryTreeNode<T> *root = NULL;
//		if (a[index] != '#' &&a[index] != '\0' && index < size)
//		{
//			root = new BinaryTreeNode<T>(a[index]);
//			root->m_left = _CreatBinaryTree(a, size, ++index);
//			root->m_right = _CreatBinaryTree(a, size, ++index);
//		}
//		return root;
//	}
//
//protected:
//	BinaryTreeNode<T>* m_phead;
//};
//void Test()
//{
//	char tr[] = "123##4##56";
//	BinaryTree<char> myTree(tr,sizeof(tr)/sizeof(tr[0]));
//	BinaryTreeNode<char>* p;
//	p = myTree.Find(1);
//	cout << p->m_data << endl;
//	p = myTree.Find(2);
//	cout << p->m_data << endl;
//	p = myTree.Find(3);
//	cout << p->m_data << endl;
//	p = myTree.Find(4);
//	cout << p->m_data << endl;
//	p = myTree.Find(5);
//	cout << p->m_data << endl;
//	p = myTree.Find(6);
//	cout << p->m_data << endl;
//	myTree.Print();
//	system("pause");
//}
//#include"xiannv.h"
#include"BinaryTree.h"
#include<iostream>
#include<list>

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_singletonList.size() == 0)
		{
			//此处设置函数进行初始化list
			_singletonList.push_back(new Singleton());
			_singletonList.push_back(new Singleton());
			_singletonList.push_back(new Singleton());
		}
		else
		{
			//对于多例模式，选择例子，返回
			Singleton* tmp = _singletonList.back();
			_singletonList.pop_back();
			return tmp;

		}

	}
protected:
	Singleton()
	{}
private:
	static list<Singleton*> _singletonList;
};
list<Singleton*> Singleton::_singletonList(NULL);

class T
{
public:
	virtual void Fun()
	{
		cout << "仙女" << endl;
	}
};
void(__thiscall T::*f)() = &T::Fun;
void Test()
{

	T x;
	char * p = NULL;
	strlen(p);
	int * A = new int[10];
	Singleton* a = Singleton::GetInstance();
	Singleton* b = Singleton::GetInstance();

	
	int aa = [=]{return 1;}();
	test();
	system("pause");
}
int fib(int a,int b,int n)
{
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	return fib(b, a+b,--n);
}

void main()
{
	int a = 0,b = 1;
	int ret;
	ret = fib(a,b,8);
	cout << ret << endl;
	cout << "Over!" << endl;
}