//TestFor SList
//filename ---------------TestForSList.cpp
#include "SList.h"

void Test1()
{
	ListNode *list;
	InitList(list);
	ShowList(list);
	PushBack(list,4);
	PushBack(list,6);
	PushBack(list,1);
	PushBack(list,3);
	ShowList(list);
	PushFront(list,8);
	ShowList(list);
	PopFront(list);
	ListNode *ears = Find(list,11);
	Erase(list,ears);
	for(int i = 0;i < 5;++i)
	{
		PopBack(list);
	}
	PushBack(list,1);
	PushBack(list,3);
	ShowList(list);
	PushFront(list,8);
	ListNode *f = Find(list,3);
	Insert(f,10);
	ShowList(list);
	Reverse(list);
	ShowList(list);
	//system("pause");
}
int main()
{
	Test1();
	//system("pause");

	return 0;
}


