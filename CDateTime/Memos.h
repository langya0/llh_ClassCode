
//////////////////////////备忘录//////////////////////////////////////////
#ifndef _MEMOS_H
#define _MEMOS_H
#include"operat.h"

#include<list>
using namespace std;

typedef struct Memos
{
	size_t index;
	CDateTime time;
	//////时间，地点，事件。
	char p[20];
}Memos;

void Init(list <Memos> *);
void Destroy(list <Memos> *);
void Look(list <Memos> *);
void Add(list <Memos> *);
void Delet(list <Memos> *);
void Output(list <Memos> *);
#endif