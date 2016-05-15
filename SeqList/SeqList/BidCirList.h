
/*
版权信息：狼
文件名称：BidCirList.h
文件标识:
文件摘要：
	利用C++实现简单的双向链表功能。增，删，查，改
	为减少空判断问题，增添一个头结点。
	swap 移花接木依旧是个给力的方法。。just try
当前版本：1.1
作    者：狼
完成时间：2015-12-13

*/
#ifndef _BIDCIRLIST_H
#define _BIDCIRLIST_H

#include"afxstd.h"

typedef int DataType;
typedef struct ListNode
{
	ListNode(DataType x=0)
	: _data(x)
	//默认初始化是自环而非  NULL
	, _prev(this)
	, _late(this)
	{}

	DataType _data;
	struct ListNode* _prev;
	struct ListNode* _late;
}ListNode;

class BidCirList
{
public:
	BidCirList()
		:_head(0)
	{}

	BidCirList(DataType *array, size_t n = 0)
		:_head(0)
	{
		size_t i = 0;
		while (n--)
		{
			InsertAter(array[i++]);
		}
	}

	BidCirList(BidCirList & list)
		:_head()
	{
		ListNode* cur = list._head._prev;
		while (cur)
		{
			InsertAter(cur->_data);
			cur = cur->_prev;
			if (cur == &list._head)
				break;
		}
	}

	~BidCirList()
	{
		Destoty();
	}
	
	BidCirList operator+(BidCirList& list)
	{
		BidCirList tmp(*this);
		ListNode* cur = list._head._prev;

		while (cur != &list._head)
		{
			tmp.InsertAter(cur->_data);
			cur = cur->_prev;
		}
		return tmp;
	}

	BidCirList& operator = (BidCirList& list)
	{
		if (this != &list)
		{
			BidCirList S(list);

			Swap(S);
		}
		return *this;
	}

	//清空空间
	void Destoty()
	{
		ListNode*cur = &_head;
		while (cur->_prev != &_head)
		{
			DelPrev();
		}
	}

	//删除结点之前的结点。默认为头
	void DelPrev(ListNode *del = NULL)
	{
		if (_head._prev == &_head)
			return;
		if (del == NULL)
		{
			//删除头之前
			_head._prev = _head._prev->_prev;
			delete _head._prev->_late;

			_head._prev->_late = &_head;
		}
		else
		{
			del->_prev = del->_prev->_prev;
			delete del->_prev->_late;

			del->_prev->_late = del;
		}
	}

	//删除结点之后一个，，默认为头
	void DelLate(ListNode *del = NULL)
	{
		if (_head._prev == &_head)
			return;
		if (del == NULL)
		{
			_head._late = _head._late->_late;
			delete _head._late->_prev;

			_head._late->_prev = &_head;
		}
		else
		{
			del->_late = del->_late->_late;
			delete del->_late->_prev;

			del->_late->_prev = del;
		}
	}

	//在结点之前插入,默认为头
	void InsertAter(DataType x ,ListNode* ins= NULL)
	{
		ListNode* tmp = new ListNode(x);

		if (ins == NULL)
		{
			tmp->_prev = &_head;
			tmp->_late = _head._late;

			tmp->_late->_prev = tmp;
			tmp->_prev->_late = tmp;
		}
		else
		{
			tmp->_prev = ins;
			tmp->_late = ins->_late;

			tmp->_late->_prev = tmp;
			tmp->_prev->_late = tmp;
		}
	}

	ListNode* Find(DataType x)
	{
		ListNode* cur = _head._prev;
		while (cur)
		{
			if (cur == &_head)
				return NULL;
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_prev;
		}
	}

	void Erase(ListNode * node)
	{
		if (node == &_head)
		{
			return;
		}
		else
		{
			ListNode* tmp = node;
			node->_prev->_late = node->_late;
			node->_late->_prev = node->_prev;
			delete tmp;
			tmp = NULL;
		}
	}

	//反向打印
	void PrintPrev()
	{
		ListNode* cur = _head._prev;
		while (cur)
		{
			if (cur == &_head)
				break;
			cout << cur->_data << " -> ";
			cur = cur->_prev;
		}
		cout << " Over! " << endl;
	}
	//正向打印
	void PrintLate()
	{
		ListNode* cur = _head._late;

		while (cur)
		{
			if (cur == &_head)
				break;
			cout << cur->_data << " -> ";
			cur = cur->_late;
		}
		cout << " Over! " << endl;
	}

	void Swap(BidCirList &list)
	{
		::swap(_head._prev->_late, list._head._prev->_late);
		::swap(_head._prev, list._head._prev);

		::swap(_head._late->_prev, list._head._late->_prev);
		::swap(_head._late, list._head._late);

	}
	
private:
	ListNode _head;
};

#endif

