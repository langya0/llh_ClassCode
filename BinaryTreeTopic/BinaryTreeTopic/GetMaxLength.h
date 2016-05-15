#include"BinaryTree.h"


template<class T>
struct Node
{
	TreeNode<T> node;
	size_t depth;
	size_t maxlen;
	Node(const T& x)
		:node(x)
		, depth(0)
		, maxlen(0)
	{}
};

template<class T>
size_t depth(TreeNode<T>*root)
{
	if (root == NULL)
		return 0;

	size_t l = depth(root->_left);
	size_t r = depth(root->_right);

	return l > r ? l + 1 : r + 1;
}

template<class T>
size_t GetMaxlen(TreeNode<T>* root)
{
	size_t len = 0;
	_GetMax(root, len);
	return len;
}

template<class T>
void _GetMax(TreeNode<T>* root, size_t &len)
{
	if (root == NUUL)
	{
		return ;
	}
	else
	{
		size_t l = depth(root->_left);
		size_t r = depth(root->_right);

		if (l + r > len)
			len = l + r;
		_GetMax(root->_left,len);
		_GetMax(root->_right,len);
	}
}