/*
版权信息：狼
文件名称：Slist.h
文件标识：
文件概要：
	利用C++实现基本的链表操作，包括增，删，查，改。

当前版本：1.1
作    者：狼
完成时间：2015-12-13
*/

#ifndef _SLIST_H
#define _SLIST_H

#include"afxstd.h"

namespace SLIST
{
	typedef int DataType;
	class SlistNode
	{
		friend class Slist;
		SlistNode(const DataType &x) :
			_data(x)
			, _next(NULL)
		{}

		void Swap(SlistNode&s)
		{
			::swap(_data, s._data);
		}

		DataType _data;
		SlistNode* _next;
	};

	//链表类
	class  Slist
	{
	public:
		Slist();
		Slist(DataType*array, size_t n = 0);
		~Slist();
		Slist(const Slist& S);
		Slist &operator=(const Slist& s);

	public:
		void Destory();
		void Print()const;

		void PushBack(const DataType& x);
		void PushFront(const DataType& x);
		void PopBack();
		void PopFront();

		SlistNode* Find(DataType x);
		void Insert(SlistNode* pos, DataType x);	//在位置pos插入x
		void Erase(SlistNode *pos);//删除指针指向的节点
		void UpdateNode(SlistNode* s,DataType &x); //更新结点内容
		void Remove(DataType x);	//找到x并删除
		void Reverse();			//翻转

		void unique(); //去除重复。。。

	private:
		SlistNode* _head;
		SlistNode* _tail;
	};

}


using namespace SLIST;

 Slist::Slist(DataType* array,size_t n)
	 : _head(NULL)
	 , _tail(NULL)	
{
	 while (n--)
	 {
		 PushBack(array[n]);
	 }
}

 Slist::Slist()
	 : _head(NULL)
	 , _tail(NULL)
{}

 Slist::Slist(const Slist& s)
	 : _head(NULL)
	 , _tail(NULL)
 {
	 SlistNode *cur = s._head;
	 while (cur)
	 {
		 PushBack(cur->_data);

		 cur = cur->_next;
	 }
 }

 Slist::~ Slist()
{
	 Destory();
 }

 void Slist::Destory()
 {
	 SlistNode* begin = _head;
	 while (begin)
	 {
		 SlistNode* del = begin;
		 begin = begin->_next;
		 delete del;
	 }
	 _tail  = _head = NULL;
 }

 void Slist::Print()const 
 {
	 SlistNode*cur = _head;
	 while (cur!=NULL)
	 {
		 cout << cur->_data << " -> ";
		 cur = cur->_next;
	 }
	 cout <<" Over! "<< endl;
 }

 ////////////////////////////////////////
 void Slist::PushBack(const DataType &x)
 {
	 if (_head == NULL)
	 {
		 _tail = new SlistNode(x);
		 _head = _tail;
	 }
	 else
	 {
		 _tail->_next = new SlistNode(x);
		 _tail = _tail->_next;
	 }
 }

 void Slist::PopBack()
 {
	 SlistNode*cur = _head;

	 while (cur&&cur->_next)
	 {
		 if (cur->_next == _tail)
		 {
			 _tail = cur;

			 delete _tail->_next;
			 _tail->_next = NULL;
			 return;
		 }
		 cur = cur->_next;
	 }

	 delete _tail;
	 _head = _tail = NULL;
 }

 void Slist::PushFront(const DataType& x)
 {
	 if (_head == NULL)
	 {
		 _tail = new SlistNode(x);
		 _head = _tail;
	 }
	 else
	 {
		 SlistNode* tmp = new SlistNode(x);
		 tmp->_next = _head;
		 _head = tmp;
	 }
 }

 void Slist::PopFront()
 {
	 if (_head == NULL)
		 return;
	 else if (_tail == _head)
	 {
		 delete _tail;
		 _head = _tail = NULL;
	 }
	 else
	 {
		 SlistNode* cur = _head;
		 
		 _head = _head->_next;
		 delete	cur;
	 }
 }

 SlistNode* Slist::Find(DataType x)
 {
	 SlistNode *tmp = _head;
	 while (tmp)
	 {
		 if (tmp->_data == x)
			 return tmp;

		 tmp = tmp->_next;
	 }
	 return NULL;
 }

 void Slist::Insert(SlistNode* pos, DataType x)//在位置之前插入x
 {
	 assert(pos);

	 SlistNode* newNode = new SlistNode(pos->_data);

	 newNode->_next = pos->_next;
	 pos->_next = newNode;

	 pos->_data = x;
 }	

 void Slist::Erase(SlistNode *pos)//删除指针指向的节点
 {
	 assert(pos);
	 if (_head == NULL)
		 return;
	 else if (_head->_next == NULL && _head == pos)
	 {
		 //只有一个，且==
		 delete _head;
		 _head = NULL;
	 }
	 else
	 {
		 SlistNode* cur = _head;
		 while (cur && cur->_next)
		 {
			 if (cur->_next == pos)
			 {
				 cur->_next = pos->_next;
				 delete pos;
				 pos = NULL;
			 }
			 cur = cur->_next;
		 }
	 }
 }

 void Slist::Remove(DataType x)//找到x并删除
 {
	 SlistNode* re = Find(x);
	 Erase(re);
 }	 

 void Slist::Reverse()//翻转
 {
	 //如果为空或者1个时  直接返回。
	 if (_head == _tail)
		 return;

	 SlistNode *cur = _tail = _head, *tmp = NULL, *newHead = NULL;
	 //assert(_head);
	 while (cur != NULL)
	 {
		 //摘节点
		 tmp = cur;
		 cur = cur->_next;

		 //头插
		 tmp->_next = newHead;
		 newHead = tmp;
	 }
	 _head = newHead;
 }			


  //更新结点内容
 void Slist::UpdateNode(SlistNode*s, DataType &x)
 {
	 s->_data = x;
 }

 void Slist::unique() //去除重复。。。
 {
	 SlistNode * arr[100] = {NULL};
	 int Narr = 0;
	 assert(_head);

	 SlistNode *cur = _head;
	 while (cur)
	 {
		 int flag = 0;
		 for (int i = 0; i < Narr; ++i)
		 {
			 if (cur->_data == arr[i]->_data)
			 {		
				 flag = 1;
				 break;
			 }
		 }

		 //删除重复
		 if (flag)
		 {			
			SlistNode *tmp = cur;
			cur = cur->_next;

			Erase(tmp);
			continue;
		 }

		 //记录未重复结点
		 arr[Narr++] = cur;
		 cur = cur->_next;
	 }
 }

 Slist &Slist::operator=(const Slist& s)
 {
	 Destory();
	 SlistNode* cur = s._head;
	 while (cur)
	 {
		 PushBack(cur->_data);
		 cur = cur->_next;
	 }
	 return *this;
 }

#endif