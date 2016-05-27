//链表
//不带头结点   头指针为空
//filename:   ---------------------SList.h---------------
#ifndef _SLIST_H
#define _SLIST_H
#include <stdio.h>
#include <memory.h>
#include <windows.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode
{
    DataType _data;
    struct ListNode* _next;
}ListNode;

void InitList(ListNode *&head);
void ShowList( ListNode * head);
ListNode* BuyNode(DataType  x);
void PushBack(ListNode * &pHead, DataType x);
void PushFront(ListNode *&head,DataType x);
void PopBack(ListNode *& head);
void PopFront(ListNode * &head);
//插入元素后边
ListNode* Find(ListNode*head,DataType x);
void Insert(ListNode *pos,DataType x);
//删除指针指向的节点
void Erase(ListNode*&head, ListNode *pos);
//找到x并删除
void Remove(ListNode*& head,DataType x);
//翻转
void Reverse(ListNode*&head);

#endif

