#include"BinaryTree.h"
//寻求两个节点的最近公共祖先


//方案①遍历，找到两个节点到root的路径。然后找出第一个交点（相当于链表相交问题）
#include<stack>



//对前序遍历过程进行改进
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

	//获取两条路径
	GetPaths(root, x1, path1);
	GetPaths(root, x2, path2);

	//处理得到最近的公共祖先
	//---对长的栈pop，当两个size相同时同步pop找到第一个相同的

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


