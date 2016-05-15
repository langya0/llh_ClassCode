
/*
��Ȩ��Ϣ����
�ļ����ƣ�BidCirList.h
�ļ���ʶ:
�ļ�ժҪ��
	����C++ʵ�ּ򵥵�˫�������ܡ�����ɾ���飬��
	Ϊ���ٿ��ж����⣬����һ��ͷ��㡣
	swap �ƻ���ľ�����Ǹ������ķ�������just try
��ǰ�汾��1.1
��    �ߣ���
���ʱ�䣺2015-12-13

*/
#ifndef _BIDCIRLIST_H
#define _BIDCIRLIST_H

#include"afxstd.h"

typedef int DataType;
typedef struct ListNode
{
	ListNode(DataType x=0)
	: _data(x)
	//Ĭ�ϳ�ʼ�����Ի�����  NULL
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

	//��տռ�
	void Destoty()
	{
		ListNode*cur = &_head;
		while (cur->_prev != &_head)
		{
			DelPrev();
		}
	}

	//ɾ�����֮ǰ�Ľ�㡣Ĭ��Ϊͷ
	void DelPrev(ListNode *del = NULL)
	{
		if (_head._prev == &_head)
			return;
		if (del == NULL)
		{
			//ɾ��ͷ֮ǰ
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

	//ɾ�����֮��һ������Ĭ��Ϊͷ
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

	//�ڽ��֮ǰ����,Ĭ��Ϊͷ
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

	//�����ӡ
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
	//�����ӡ
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

