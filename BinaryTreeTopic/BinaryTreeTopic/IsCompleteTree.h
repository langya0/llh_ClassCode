#include"BinaryTree.h"


//�����ٲ�α���������������ĳһ�������������ӽڵ�ʱ����ô�����в�������
//�����ڱ��������ÿһ�������������߶�=�������߶ȣ�+1����ô�����������ȫ������
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