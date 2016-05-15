/*
��Ȩ��Ϣ����
�ļ����ƣ�Slist.h
�ļ���ʶ��
�ļ���Ҫ��
	����C++ʵ�ֻ����������������������ɾ���飬�ġ�

��ǰ�汾��1.1
��    �ߣ���
���ʱ�䣺2015-12-13
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

	//������
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
		void Insert(SlistNode* pos, DataType x);	//��λ��pos����x
		void Erase(SlistNode *pos);//ɾ��ָ��ָ��Ľڵ�
		void UpdateNode(SlistNode* s,DataType &x); //���½������
		void Remove(DataType x);	//�ҵ�x��ɾ��
		void Reverse();			//��ת

		void unique(); //ȥ���ظ�������

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

 void Slist::Insert(SlistNode* pos, DataType x)//��λ��֮ǰ����x
 {
	 assert(pos);

	 SlistNode* newNode = new SlistNode(pos->_data);

	 newNode->_next = pos->_next;
	 pos->_next = newNode;

	 pos->_data = x;
 }	

 void Slist::Erase(SlistNode *pos)//ɾ��ָ��ָ��Ľڵ�
 {
	 assert(pos);
	 if (_head == NULL)
		 return;
	 else if (_head->_next == NULL && _head == pos)
	 {
		 //ֻ��һ������==
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

 void Slist::Remove(DataType x)//�ҵ�x��ɾ��
 {
	 SlistNode* re = Find(x);
	 Erase(re);
 }	 

 void Slist::Reverse()//��ת
 {
	 //���Ϊ�ջ���1��ʱ  ֱ�ӷ��ء�
	 if (_head == _tail)
		 return;

	 SlistNode *cur = _tail = _head, *tmp = NULL, *newHead = NULL;
	 //assert(_head);
	 while (cur != NULL)
	 {
		 //ժ�ڵ�
		 tmp = cur;
		 cur = cur->_next;

		 //ͷ��
		 tmp->_next = newHead;
		 newHead = tmp;
	 }
	 _head = newHead;
 }			


  //���½������
 void Slist::UpdateNode(SlistNode*s, DataType &x)
 {
	 s->_data = x;
 }

 void Slist::unique() //ȥ���ظ�������
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

		 //ɾ���ظ�
		 if (flag)
		 {			
			SlistNode *tmp = cur;
			cur = cur->_next;

			Erase(tmp);
			continue;
		 }

		 //��¼δ�ظ����
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