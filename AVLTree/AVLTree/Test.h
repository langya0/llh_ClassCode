#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct BSTNode
{

	BSTNode(const K& key, const V& v)
	:_key(key)
	, _value(v)
	, _left(NULL)
	, _right(NULL)
	{}
	BSTNode()
		:_key()
		, _value()
		, _left(NULL)
		, _right(NULL)
	{}
	K _key;
	V _value;
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
};

template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		:_root(NULL)
	{}

	~BSTree()
	{
		Destroy(_root);
	}
	bool Remove(const K& key)
	{
		Node* head = new Node();
		head->_left = head->_right = _root;

		Node* prev = head;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				prev = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				prev = cur;
				cur = cur->_left;
			}
			else
			{
				//当前节点为所要删除的结点
				//删除结点是父的左
				if (cur = prev->_left)
				{
					if (cur->_left == NULL)
						prev->_left = cur->_right;
					else if (cur->_right == NULL)
						prev->_left = cur->_left;
					else
					{
						//左右都不空
						Node* tmp = cur;
						prev = cur;
						cur = cur->_right;
						while (cur->_left)
						{
							prev = cur;
							cur = cur->_left;
						}
						swap(tmp->_key, cur->_key);
						swap(tmp->_value, cur->_value);
						prev->_left = cur->_right;
						delete cur;
						cur = NULL;
					}
				}

				if (cur = prev->_right)
				{
					if (cur->_left == NULL)
						prev->_left = cur->_right;
					else if (cur->_right == NULL)
						prev->_left = cur->_left;
					else
					{//左右都不空
						Node* tmp = cur;
						prev = cur;
						cur = cur->_right;
						while (cur->_left)
						{
							prev = cur;
							cur = cur->_left;
						}
						swap(tmp->_key, cur->_key);
						swap(tmp->_value, cur->_value);
						prev->_left = cur->_right;
						delete cur;
						cur = NULL;
					}
				}

			}
		}
		return false;
	}


	void Destroy(BSTNode<K, V>* root)
	{
		if (root == NULL)
		{
			return;
		}
		Destroy(root->_left);
		Destroy(root->_right);
		if (root->_left == NULL&&root->_right == NULL)
		{
			delete root;
		}
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	//void Remove(const K& key)
	//{
	//	//Remove1(key);
	//	_Remove_R(_root,key);
	//}
public:
	BSTNode<K, V>*& GetTreeRoot()
	{
		return _root;
	}
	bool Insert(BSTNode<K, V>*& root, const K& key, const V& v)
	{
		if (root == NULL)
		{
			root = new Node(key, v);
			return true;
		}
		else
		{
			if (key < root->_key)
			{
				Insert(root->_left, key, v);
			}
			if (key > root->_key)
			{
				Insert(root->_right, key, v);
			}
			else
			{
				return false;
			}
		}
	}
	bool Find_R(BSTNode<K, V>*& root, const K& key)//递归实现
	{
		if (root == NULL)
		{
			return false;
		}
		else
		{
			if (key == root->_key)
			{
				return true;
			}
			else if (key > root->_key)
			{
				Find_R(root->_right, key);
			}
			else
			{
				Find_R(root->_left, key);
			}
		}
	}
	bool Find(BSTNode<K, V>*& root, const K& key)//非递归实现
	{
		if (root == NULL)
		{
			return false;
		}
		Node *cur = root;
		while (cur)
		{
			if (key == cur->_key)
			{
				return true;
			}
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		return false;
	}
	void _Remove(const K& key)//非递归
	{
		if (_root == NULL)
		{
			return;
		}
		if (_root->_left == NULL &&_root->_right == NULL&&_root->_key==key)
		{
			delete _root;
			_root = NULL;
		}

		//>=1个结点且根不是删除的结点
		else
		{
			Node*parent = _root;
			Node* del = parent;

			//前边是为了保证parent
			while (del && del->_key != key)
			{
				parent = del;
				if (del->_key > key)
				{
					del = del->_left;
				}
				else if (del->_key < key)
				{
					del = del->_right;
				}
			}

			if (del->_key != key)
				return;
			else if (del->_key == key)
			{
				//无左
				if (del->_left == NULL)
				{
					if (del == parent->_left)
						parent->_left = del->_right;
					else if (del == parent->_right)
						parent->_right = del->_right;
					delete del;
					del = NULL;
					return;
				}
				//无右
				else if (del->_right == NULL)
				{
					if (del== parent->_left)
						parent->_left = del->_left;
					else if (del == parent->_right)
						parent->_right = del->_left;
					delete del;
					del = NULL;
					return;
				}
				else
				{
					//del 为删除的结点
					parent = del;
					Node* d = del->_right;
					//parent 一阵跟着走，找到中序遍历第一个结点的父
					while (d->_left)
					{
						parent = d;
						d = d->_left;
					}
					swap(del->_key, d->_key);
					swap(del->_value, d->_value);

					if (d == parent->_left)
						parent->_left = d->_right;
					else if (d == parent->_right)
						parent->_right = d->_right;
					delete d;
					d = NULL;
				}
			}
		}
	}

	bool Remove1(const K& key)//非递归
	{
		if (_root == NULL)
		{
			return false;
		}
		Node *del = _root;
		Node *parent = _root;
		while (del && del->_key != key)
		{
			parent = del;
			if (del->_key > key)
			{
				del = del->_left;
			}
			else if (del->_key < key)
			{
				del = del->_right;
			}
		}
		if (del)
		{
			if (del->_left == NULL)
			{
				if (parent->_left == del)
				{
					parent->_left = del->_right;
				}
				else
				{
					parent->_right = del->_right;
				}
				delete del;
				return true;
			}
			if (del->_right == NULL)
			{
				if (parent->_left == del)
				{
					parent->_left = del->_left;
				}
				else
				{
					parent->_right = del->_left;
				}
				delete del;
				return true;
			}
			else
			{
				Node *InOrderfirst = del->_right;
				while (InOrderfirst->_left)
				{
					parent = InOrderfirst;
					InOrderfirst = InOrderfirst->_left;
				}
				swap(del->_key, InOrderfirst->_key);
				swap(del->_value, InOrderfirst->_value);
				delete InOrderfirst;
				return true;
			}
		}
		return false;
	}

	void _Remove_R(BSTNode<K, V>*& root, const K& key)//递归
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_key == key)
		{
			if (root->_left&&root->_right)
			{
				Node* del = root->_right;
				while (del->_left)
				{
					del = del->_left;
				}
				swap(del->_key, root->_key);
				swap(del->_value, root->_value);
				delete del;
			}
			else
			{
				Node*del = root;
				if (del->_left == NULL)
				{
					root = root->_right;
				}
				if (del->_right == NULL)
				{
					root = root->_left;
				}
				delete del;
			}
		}
		else if (key < root->_key)
		{
			_Remove_R(root->_left, key);
		}
		else
		{
			_Remove_R(root->_right, key);
		}

	}
	void _InOrder(BSTNode<K, V>* root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ":"<< root->_value << " ";
		_InOrder(root->_right);
	}
protected:
	BSTNode<K, V> *_root;
};

void test()
{
	BSTree<int, int> t;
	t.Insert(t.GetTreeRoot(), 4, 1);
	t.Insert(t.GetTreeRoot(), 1, 1);
	t.Insert(t.GetTreeRoot(), 3, 1);
	t.Insert(t.GetTreeRoot(), 2, 1);
	t.Insert(t.GetTreeRoot(), 5, 1);
	t.Insert(t.GetTreeRoot(), 6, 1);
	t.Insert(t.GetTreeRoot(), 9, 1);
	t.Insert(t.GetTreeRoot(), 8, 1);
	t.Insert(t.GetTreeRoot(), 7, 1);

	t.InOrder();
	cout << endl;

	cout << t.Find(t.GetTreeRoot(), 9) << endl;
	cout << t.Find(t.GetTreeRoot(), 0) << endl;

	for (int i = 1; i < 9; ++i)
	{
		t.Remove(i);
		t.InOrder();
	}
	system("pause");
}