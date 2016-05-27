#ifndef _CLIENTREQUEST_H_
#define _CLIENTREQUEST_H_


#include"CDateTime.h"







void ShowLocalTime(CDateTime *dt);	
int TransitionYTW(int y,int m,int d); 
bool IsRunNian(int y);
void ShowMonth(int y,int m, int f = 0);
void ShowMonthNext(int &y,int &m,int flag);
void ShowMonthByNextD(int &y,int &m,int &d,int flag);
void ShowYear(int y,int flag = 1);
void BeforeNDis(int &y,int &m,int &d, int n);
void AfterNDis(int &y,int &m,int &d, int n);
int DayToDay(int y,int m,int d,int y1,int m1,int d1);

void DynShowTime(CDateTime *Localdt);
bool IsRunNian(int y);



#endif