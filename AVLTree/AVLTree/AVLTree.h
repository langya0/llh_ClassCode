#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;
	K _key;
	V _value;

	AVLTreeNode(const K& key = 0, const V& value = 0)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
		, _key(key)
		, _value(value)
	{}
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
	AVLTree()
		:_pRoot()
	{}
	~AVLTree()
	{}
	bool Insert(const K& key, const V& value)
	{
		if (_pRoot._left == NULL)
		{
			_pRoot._left = _pRoot._right = new Node(key, value);
			_pRoot._left->_parent = &_pRoot;
			return true;
		}
		else
		{
			return _Insert(_pRoot._left, key, value);
		}
	}
	bool Remove(const K&key)
	{
		return true;
	}
	void InOrder()
	{
		_InOrder(_pRoot._left);
		cout << endl;
	}
	bool IsBalanceTree()
	{
		return true;
	}
protected:
	void _InOrder(Node * root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << " ";
		_InOrder(root->_left);
		cout << root->_key << endl;
		cout << " ";
		_InOrder(root->_right);
	}
	bool _Insert(Node* root, const K& key, const V& value)
	{
		Node *cur = root;
		Node* parent = cur->_parent;

		while (cur)
		{
			parent = cur;
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else //已经存在
			{
				return false;
			}
		}
		//插入节点的父节点权值更新
		Node *newNode = new Node(key, value);
		if (parent->_key>key)
		{
			parent->_left = newNode;
			parent->_left->_parent = parent;
		}
		else
		{
			parent->_right = newNode;
			parent->_right->_parent = parent;
		}
		//插入点的祖父
		Node * pparent = parent->_parent;
		//祖父节点更新。。。。如果插入节点之后，父节点的权值为0说明本来就不平衡，插入之后不影响祖父。否则，左-右+
		while (pparent != &_pRoot)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else //2  -2
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						_RotateL(parent);
					}
					else
					{
						_RotateRL(parent);
					}
				}
				else
				{
					if (cur->_bf == 1)
					{
						_RotateR(parent);
					}
					else
					{
						_RotateLR(parent);
					}
				}
			}

			//if (parent->_bf != 0 && parent == pparent->_left)
			//{
			//	//-2
			//	if ((--pparent->_bf) < -1)
			//	{
			//		Node *&rPParent = pparent == pparent->_parent->_left ? pparent->_parent->_left : pparent->_parent->_right;
			//		if (parent->_bf == -1)
			//		{
			//			_RotateR(rPParent);
			//		}
			//		else  //1
			//			_RotateLR(rPParent);
			//	}
			//}
			//else if (parent->_bf != 0 && parent == pparent->_right)
			//{
			//	//2
			//	if (pparent == &_pRoot)
			//		return true;
			//	if (++pparent->_bf > 1)
			//	{
			//		Node *&rPParent = pparent == pparent->_parent->_left ? pparent->_parent->_left : pparent->_parent->_right;
			//		if (parent->_bf == 1)
			//			_RotateL(rPParent);
			//		else  //-1
			//			_RotateRL(rPParent);
			//	}
			//}
			//else  //插入之后依旧是平衡树
			//{
			//	return true;
			//}
		}
		_pRoot._right = NULL;
	}
protected:
	bool _RotateLR(Node * &pparent)
	{
		_RotateL(pparent->_left);
		_RotateR(pparent);
		return true;
	}
	bool _RotateRL(Node * &pparent)
	{
		_RotateL(pparent->_right);
		_RotateR(pparent);
		return true;
	}
	bool _RotateL(Node * &pparent)
	{
		Node * parent = pparent->_right;
		Node * pR = parent->_left;

		//pR换位
		if (pR)
		{
			pR->_parent = pparent;
		}
		pparent->_right = pR;
		parent->_left = pparent;

		parent->_parent = pparent->_parent;
		pparent->_parent = parent;
		pparent = parent;

		pparent->_bf = parent->_left->_bf = 0;

		return true;
	}
	bool _RotateR(Node * &pparent)
	{
		Node * parent = pparent->_left;
		Node * pR = parent->_right;
		
		//pR换位
		if (pR)
		{
			pR->_parent = pparent;
		}
		pparent->_left = pR;
		parent->_right = pparent;

		parent->_parent = pparent->_parent;
		pparent->_parent = parent;
		pparent = parent;

		pparent->_bf = parent->_right->_bf = 0;

		return true;
	}
protected:
	//root'Parent
	Node _pRoot;
};

void TestAVLTree()
{
	AVLTree<int, int> tr;
	tr.Insert(22, 1);
	tr.Insert(33, 1);
	tr.Insert(44, 1);
	tr.Insert(55, 1);
	tr.Insert(66, 1);
	tr.Insert(42, 1);

	tr.InOrder();
	system("pause");
}