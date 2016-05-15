#include<iostream>
using namespace std;

template<class K,class V>
struct BST_Node
{
	BST_Node(const K&key)
	:_left(NULL)
	, _right(NULL)
	, _key(key)
	, _value(key)
	{}
	BST_Node* _left;
	BST_Node* _right;
	K _key;
	V _value;
};

template<class K,class V>
class BSTree
{
	typedef BST_Node<K, V> Node;
public:
	bool Remove(const K& key)
	{
		Node* prev = NULL;
		Node* cur = _root;
		if (cur == NULL)
		{
			return false;
		}
		while (cur)
		{
			prev = cur;
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
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
				else
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
	}
public:
	BSTree()
		:_root(NULL)
	{}

	Node* _root;
};