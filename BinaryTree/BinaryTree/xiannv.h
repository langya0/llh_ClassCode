#pragma once
#include<iostream>
using namespace std;
#include <queue>
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T &data)
	:_data(data)
	, _left(NULL)
	, _right(NULL)
	{}
	T _data;
	BinaryTreeNode<T> *_left;
	BinaryTreeNode<T> *_right;
};
template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size)
	{
		int index = 0;
		_root = _CreatTree(a, size, index);
	}
	BinaryTree(const BinaryTree<T> &t)
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(BinaryTree<T> t)
	{
		swap(t._root, _root);
		return *this;
	}
	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << endl;
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	BinaryTreeNode<T>* Find(const T& x)
	{
		return _Find(_root, x);
	}

	~BinaryTree()
	{
		_Destroy(_root);
	}
private:
	BinaryTreeNode<T>*_CreatTree(const T* a, size_t size, int &index)
	{
		BinaryTreeNode<T> *root = NULL;
		if (index < size && a[index] != '#')
		{
			root = new BinaryTreeNode<int>(a[index]);
			root->_left = _CreatTree(a, size, ++index);
			root->_right = _CreatTree(a, size, ++index);
		}
		return root;
	}
	BinaryTreeNode<T> *_Find(BinaryTreeNode<T> *root, const T& x)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == x)
		{
			return root;
		}
		else
		{ 
			if (root->_left)
			{
				BinaryTreeNode<T>*tmp = _Find(root->_left, x);
				if (tmp)
					return tmp;
				else if(root->_right)
				{
					return _Find(root->_right, x);
				}
			}
			
		}
		return NULL;
	}
	size_t _Size(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return 1 + _Size(root->_left) + _Size(root->_right);
	}
	size_t _Depth(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		size_t left = _Depth(root->_left);
		size_t right = _Depth(root->_right);
		if (left < right)
		{
			return 1 + right;
		}
		return 1 + left;
	}
	void _PrevOrder(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}
	void _LevelOrder(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		queue<BinaryTreeNode<T> *> q;
		q.push(root);
		while (!q.empty())
		{
			BinaryTreeNode<T> *tmp = q.front();
			q.pop();
			cout << tmp->_data << " ";
			if (tmp->_left)
			{
				q.push(tmp->_left);
			}
			if (tmp->_right)
			{
				q.push(tmp->_right);
			}
		}
	}
	BinaryTreeNode<T>* _Copy(BinaryTreeNode<T> *root)
	{
		BinaryTreeNode<T> *Newroot = NULL;
		if (root)
		{
			Newroot = new BinaryTreeNode<T>(root->_data);
			Newroot->_left = _Copy(root->_left);
			Newroot->_right = _Copy(root->_right);
		}
		return Newroot;
	}
	void _Destroy(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
private:
	BinaryTreeNode<T> *_root;
};

void test()
{
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(a, 10);
//	BinaryTree<int> t2;

	//t2 = t1;

	t1.PrevOrder();
	t1.InOrder();
	t1.PostOrder();
	t1.LevelOrder();

	BinaryTreeNode<int>*p = t1.Find(1);
	cout << p->_data << endl;
	p = t1.Find(2);
	cout << p->_data << endl;
	p = t1.Find(3);
	cout << p->_data << endl;
	p = t1.Find(4);
	cout << p->_data << endl;
	p = t1.Find(5);
	cout << p->_data << endl;
	p = t1.Find(6);
	cout << p->_data << endl;
	p = t1.Find(7);
	cout << p->_data << endl;

	//t2.PostOrder();

	//cout << t2.Find(2)->_data << endl;
}