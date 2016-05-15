#include"BinaryTree.h"
//Ѱ�������ڵ�������������


//�����ٱ������ҵ������ڵ㵽root��·����Ȼ���ҳ���һ�����㣨�൱�������ཻ���⣩
#include<stack>



//��ǰ��������̽��иĽ�
template<class T>
bool GetPaths(TreeNode<T>* root, TreeNode<T>* x,stack<TreeNode<T>* > &s)
{
	if (root == NULL)
	{
		return false;
	}

	if (root == x)
	{
		return true;
	}
	s.push(root);

	if (GetPaths(root->_left, x, s)
		|| GetPaths(root->_right, x, s))
		return true;

	s.pop();
	return false;
}

template<class T>
TreeNode<T>* GetAncestor(TreeNode<T>* root, TreeNode<T>*x1, TreeNode<T>*x2)
{
	stack<TreeNode<T>*> path1;
	stack<TreeNode<T>*> path2;

	//��ȡ����·��
	GetPaths(root, x1, path1);
	GetPaths(root, x2, path2);

	//����õ�����Ĺ�������
	//---�Գ���ջpop��������size��ͬʱͬ��pop�ҵ���һ����ͬ��

	stack<TreeNode<T>*> &rPath = path1.size() > path2.size() ? path1 : GetPaths;
	size_t minLen = path1.size() < path2.size() ? path1.size() : path2.size();
	while (rPath.size()>minLen)
	{
		rPath.pop();
	}

	while (path1.top() != path2.top())
	{
		path1.pop();
		path2.pop();
	}

	return path1.top();
}


