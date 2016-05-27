#include"CDateTime.h"

void InitDateTime(CDateTime *dt)
{
	dt->m_year = 1;
	dt->m_month = 1;
	dt->m_day = 1;
	dt->m_hour = 0;
	dt->m_minute = 0;
	dt->m_second = 0;
}
//////////////////////////////////////////////
void ShowDate(CDateTime *dt)
{
	printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
}
void ShowTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
}
void ShowDateTime(CDateTime *dt)
{
	GetNowDateTime(dt);
	printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
	printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
}
void EditTime(CDateTime *dt)
{
	printf("请输入年月日进行操作(2015-11-9)\n");
	int y,m,d;
	scanf("%d-%d-%d",&y,&m,&d);
	dt->m_year = y;
	dt->m_month = m;
	dt->m_day = d;
}
void GetNowDateTime(CDateTime *dt)
{
	time_t te;
	time(&te);
	tm *ptm = localtime(&te);
	dt->m_year = ptm->tm_year+1900;
	dt->m_month = ptm->tm_mon+1;
	dt->m_day = ptm->tm_mday;
	dt->m_hour = ptm->tm_hour;
	dt->m_minute = ptm->tm_min;
	dt->m_second = ptm->tm_sec;
}