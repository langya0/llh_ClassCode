#include"stdafx.h"


template<class T>
struct TreeNode
{
	struct TreeNode	* _left;
	struct TreeNode	* _right;
	T _data;

	TreeNode(const T&x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef	TreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T*& arr, size_t size)
		:_root(NULL)
	{
		_Creat
	}

	bool Insert(const T& x)
	{
		if (_root == NULL)
		{
			_root = new Node(x);
			return true;
		}
	}
protected:
	Node * _root;
};

void Test()
{
	BinaryTree<int> bt;
	cout << "Finish" << endl;
}