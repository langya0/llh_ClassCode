//链表
//不带头结点   头指针为空
//filename --------SList.cppS-------------
#include "SList.h"
void InitList(ListNode *&head)
{
	head = NULL;
}
void ShowList( ListNode *const head)
{
	ListNode *tmp = head;
	while(tmp)
	{
		printf("%d -> ",tmp->_data);
		tmp = tmp->_next;
	}
	printf("NULL\n");
}

ListNode* BuyNode(DataType  x)
{
	ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
	assert(tmp);
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void PushBack(ListNode * &pHead, DataType x)
{
	//assert(pHead);
	//空或者不空
	if(pHead == NULL)
	{
		pHead = BuyNode(x);
	}
	else
	{
		ListNode *tail = pHead;
		while(tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = BuyNode(x);
	}
}
void PushFront(ListNode *&head,DataType x)
{
	if(head == NULL)
	{
		head = BuyNode(x);
	}
	else
	{
		ListNode *tmp = BuyNode(x);
		tmp->_next = head;

		head = tmp;
	}
}

void PopBack(ListNode *& head)
{
	//1空
	//2一个节点
	//多个
	if(head == NULL)
	{
		printf("SList is Empty!\n");
	}
	else if(head->_next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		ListNode *tmp = head;
		while(tmp->_next->_next)
		{
			tmp = tmp->_next;
		}
		free(tmp->_next);
		tmp->_next = NULL;
	}
}

void PopFront(ListNode * &head)
{
	assert(head);
	ListNode* re = head;
	head = re->_next;
	free(re);
}

//插入元素后边
ListNode* Find(ListNode*head,DataType x)
{
	ListNode* cur = head;
	while(cur)
	{
		if(cur->_data == x)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}
void Insert(ListNode *pos,DataType x)
{
	assert(pos);
	ListNode* tmp = BuyNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
}
//删除指针指向的节点
void Erase(ListNode*&head, ListNode *pos)
{
	///Find失败，返回
	if(pos == NULL)
	{
		printf("要删除的位置不存在\n");
		return;
	}
	//头为删除
	ListNode *cur = head;
	if(head == pos)
	{
		ListNode* rem = head;
		head = head->_next;
		free(rem);
		return;
	}
	//其他位置
	while(cur->_next!=pos)
	{
		cur = cur->_next;
	}
	ListNode* rem = cur->_next;
	cur->_next = rem->_next;
	free(rem);
}
//找到x并删除
void Remove(ListNode*& head,DataType x)
{
	ListNode* front = head;
	if(head->_data == x)
	{
		ListNode* rem = head;
		head = head->_next;
		free(rem);
		return;
	}
	while(front->_next != NULL && front->_next->_data!= x)
	{
		front = front->_next;	
	}
	if(front->_next == NULL)
	{
		printf("没找到\n");
		return;
	}
	ListNode* rem = front->_next;
	front->_next = rem->_next;
	free(rem);
	
}

//翻转
void Reverse(ListNode*&head)
{
	ListNode *cur = head,*tmp = NULL,*newHead = NULL;
	assert(head);
	while(cur != NULL)
	{
		tmp = cur;
		cur = cur->_next;
		tmp->_next = newHead;
		newHead = tmp;
	}
	head = newHead;
}
