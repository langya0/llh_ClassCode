#include"BinaryTree.h"

//������������ת��Ϊ˫������
template<class T>
TreeNode<T>* ToList(TreeNode<T>* root)
{
	TreeNode<T>* prev = NULL:
	return _ToList(root, prev);
}

//��ʵ�����������Ĺ���
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
	while (head&&head->_left)	//�ҵ������㣬��Ϊ����ͷ��㷵��
		head = head->_left;

	return head;
}