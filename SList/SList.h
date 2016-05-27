//����
//����ͷ���   ͷָ��Ϊ��
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
//����Ԫ�غ��
ListNode* Find(ListNode*head,DataType x);
void Insert(ListNode *pos,DataType x);
//ɾ��ָ��ָ��Ľڵ�
void Erase(ListNode*&head, ListNode *pos);
//�ҵ�x��ɾ��
void Remove(ListNode*& head,DataType x);
//��ת
void Reverse(ListNode*&head);

#endif

