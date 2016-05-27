#ifndef _CDATETIME_H
#define _CDATETIME_H

#include"stdafx.h"

typedef struct CDateTime
{
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
}CDateTime;

/////////////////////////////////////////
void ShowDate(CDateTime *dt);
void ShowTime(CDateTime *dt);
void EditTime(CDateTime *dt);
void InitDateTime(CDateTime *dt);
void GetNowDateTime(CDateTime *dt);
void ShowDateTime(CDateTime *dt);
#endif