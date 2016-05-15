#include"BinaryTree.h"


//方案①层次遍历树，当遍历到某一结点无左或者右子节点时，那么其所有伯父无子
//方案②遍历，如果每一个子树左子树高度=右子树高度（+1）那么这个数就是完全二叉树
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
bool IsCompleteTree(TreeNode<T>* root)
{	
	if (root == NULL)
	{
		return true;
	}
	IsCompleteTree(root->_left);
	IsCompleteTree(root->_right);

	size_t l = depth(root->_left);
	size_t r = depth(root->_right);
	if (l == r || l == r + 1 || r == l + 1)
	{
		return true;
	}
	return false;
}