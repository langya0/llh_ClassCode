#pragma once
#include<iostream>
using namespace std;
enum PointerTag{ THREAD, LINK };

template<class T>
struct BinaryTreeNode_Thd
{
	BinaryTreeNode_Thd(const T& data)
	:_data(data)
	, _left(NULL)
	, _right(NULL)
	, _leftTag(LINK)
	, _rightTag(LINK)
	{}
	T _data;
	BinaryTreeNode_Thd<T> *_left;
	BinaryTreeNode_Thd<T> *_right;
	PointerTag _leftTag;
	PointerTag _rightTag;

};
template<class T>
class BinaryTree_Thd
{
public:
	BinaryTree_Thd()
		:_root(NULL)
	{}
	BinaryTree_Thd(const T *a, const size_t size)
	{
		int index = 0;
		_root = _CreatTree(a, size, index);
	}
	// 	void PrevOrder_Threading()
	// 	{
	// 		_PrevOrder_Threading(_root);
	// 	}
	void InOrder_Threading()
	{
		_InOrder_Threading(_root);
	}
	void InOrder_Thd()
	{
		_InOrder_Thd(_root);
	}
	~BinaryTree_Thd()
	{
		_Destroy(_root);
	}
protected:
	BinaryTreeNode_Thd<T>* _CreatTree(const int *a, size_t size, int &index)
	{
		BinaryTreeNode_Thd<T> *root = NULL;
		if (index < size && a[index] != '#')
		{
			root = new BinaryTreeNode_Thd<T>(a[index]);
			root->_left = _CreatTree(a, size, ++index);
			root->_right = _CreatTree(a, size, ++index);
		}
		return root;
	}
public:
	void Destroy()
	{
		_Destroy(_root);
	}
	//	void _Destroy(BinaryTreeNode_Thd<T> *&root)
	//{
	//		static int i = 1;

	//	if (root == NULL)
	//	{
	//		return;
	//	}
	//	if (root->_left != NULL || root->_right != NULL)
	//	{
	//		_Destroy(root->_left);
	//		_Destroy(root->_right);
	//		delete root;
	//		cout << i++;
	//	}
	//	else
	//	{
	//		delete root;
	//		cout << i++;
	//		root = NULL;
	//	}
	//}

	void _Destroy(BinaryTreeNode_Thd<T> *root)
	{
		static int i = 1;
		if (root == NULL)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
		cout << i++ << endl;
	}

	// 	void _PrevOrder_Threading(BinaryTreeNode_Thd<T> *root)
	// 	{
	// 		
	// 	}
	void _InOrder_Threading(BinaryTreeNode_Thd<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		BinaryTreeNode_Thd<T> *cur = root, *prev = NULL;
		while (cur&& cur->_left)
		{
			cur = cur->_left;
		}
		if (!cur->_left)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && !prev->_right)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		_InOrder_Threading(cur->_right);
	}
	void _InOrder_Thd(BinaryTreeNode_Thd<T> *root)
	{
		if (root == NULL)
		{
			return;
		}
		BinaryTreeNode_Thd<T> *cur = root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		cout << cur->_data << " ";
		if (cur->_rightTag == THREAD)
		{
			cur = cur->_right;
		}
		if (cur->_rightTag == LINK)
		{
		}
	}
protected:
	BinaryTreeNode_Thd<T> *_root;
};

using namespace std;

void test()
{
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree_Thd<int> t1(a, 10);
	t1.Destroy();
	cout << "test" << endl;
	//t1.InOrder_Threading();
	//t1.InOrder_Thd();
}
