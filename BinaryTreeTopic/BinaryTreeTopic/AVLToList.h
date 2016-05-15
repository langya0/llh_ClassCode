#include"BinaryTree.h"

//将搜索二叉树转换为双向链表
template<class T>
TreeNode<T>* ToList(TreeNode<T>* root)
{
	TreeNode<T>* prev = NULL:
	return _ToList(root, prev);
}

//其实就是线索化的过程
template<class T>
TreeNode<T>* _ToList(TreeNode<T>*root, TreeNode<T>*prev)
{
	_ToList(root->_left, prev);

	root->_left = prev;
	if (prev)
		prev->_right = root;

	prev = root;

	_ToList(root->_left, prev);

	TreeNode<T>* head = root;
	while (head&&head->_left)	//找到最左结点，作为链表头结点返回
		head = head->_left;

	return head;
}