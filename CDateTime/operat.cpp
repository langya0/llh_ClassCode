
#include"operat.h"


int Month[12] = {31,29,31,30, //闰年月
				31,30,31,31,
				30,31,30,31};

int Nss = 366;
extern CDateTime tmpdt;
//闰年校验
bool IsRunNian(int y)
{
	bool Is = (y%4==0&&y%100!=0||y%400==0);
	if(Is)
	{
		Month[1] = 29;
		Nss = 366;
	}
	else
	{
		Month[1] = 28;
		Nss = 365;
	}
	return Is;
}

void ShowLocalTime(CDateTime *dt)
{
	ShowDateTime(dt);
}

///////////////////////////////////////////////
//屏幕光标位置控制
void gotoxy(HANDLE hOut, int x, int y)
{
COORD pos;
pos.X = x;
pos.Y = y;
SetConsoleCursorPosition(hOut, pos);
}

void getxy(HANDLE hOut, int &x, int &y)
{
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hOut, &screen_buffer_info);

x = screen_buffer_info.dwCursorPosition.X;
y = screen_buffer_info.dwCursorPosition.Y;
}
//根据f确定是否局左输出，否则双排输出
void ShowMonth(int y, int m,int f)
{
	int TodayIs = tmpdt.m_day;
	int lo = 1;
	IsRunNian(y);
	int F = TransitionYTW(y,m,1);
	if(!f)
	{
	printf("      < %d年%d月 >       \n",y,m);
	printf(" 日  一  二  三  四  五  六  \n");
	for(int j = 0; j< F; ++j)
		printf("    ");
	for(int k = 1; k <= Month[m-1]; ++k)
	{
		if(F++ %7 == 0)
		{	lo++;
			printf("\n");
		}
		if(k == TodayIs)
		{
			printf("[%2d]",k);
		}
		else
			printf(" %2d ",k);
	}
	while(lo++ < 6)
		printf("\n");
	printf("\n");
	}
	else
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		int fx = 0,fy = 0;
		getxy(hOut,fx,fy);
		gotoxy(hOut,32,fy-=8);
		printf("      < %d年%d月 >       ",y,m);
		gotoxy(hOut,32,fy+=1);
	 	printf("  日  一  二  三  四  五  六 ");
		gotoxy(hOut,32,fy+=1);
		for(int j = 0; j< F; ++j)
			printf("    ");
		for(int k = 1; k <= Month[m-1]; ++k)
		{
			if(F++ %7 == 0)
			{
				lo++;
				gotoxy(hOut,32,fy+=1);
			}
			if(k == TodayIs)
			{
				printf("[%2d]",k);
			}
			else
				printf(" %2d ",k);
		}
		while(lo++ < 6)
			gotoxy(hOut,32,fy+=1);
		printf("\n");
	}
}

void ShowMonthByNextD(int &y,int &m,int &d,int flag)
{
	//////////////////后一天
	if(flag)
	{
		//月边界
		IsRunNian(y);
		if(d == Month[m-1])
		{	//年边界
			if(m == 12)
			{
				y ++;
				IsRunNian(y);
				m = 1;
			}
			else
				m++;
			d = 1;
		}
		else
		{
			d++;
		}
	}
	else
	{
		IsRunNian(y);
			if(d == 1)
			{
				//年边界
				if(m == 1)
				{
					y --;
					IsRunNian(y);
					m = 12;
					d = 31;
				}
				else
				{
					m--;
					d = Month[m-1];
				}
			}
			else d--;
	}
	ShowMonth(y,m);
}

//显示相邻月份信息
void ShowMonthNext(int &y,int &m,int k)
{
	if(k)
	{
		y = y+ m/12;
		m = m %12+1;
	}
	else
	{
		if( m == 1)
		{
			y = y -1;
			m = 12;
		}else
		m--;
	}
	ShowMonth(y,m);
}

void ShowYear(int y,int flag)
{
	if (flag == 1)
	{
	
		for(int i = 1; i <= 12;++i)
			ShowMonth(y,i);
	}
	else
	{
		for(int i = 1;i <=12;++i)
		{
		if(i%2)
			ShowMonth(y,i);
		else
			ShowMonth(y,i,2);
		}
	}
}

//动态显示当前时间
void DynShowTime(CDateTime *Localdt)
{
    while(1)
	{
		system("cls");
		ShowDateTime(Localdt);
		Sleep(1000);
		if(kbhit())
			break;
	}
}

//时间迟早比较
bool LateThen(int y1,int m1,int d1,
			 int y2,int m2,int d2)
{
	return ((y1 > y2) || (y1 == y2)&&(m1>m2) || (y1 == y2)&&(m1 == m2)&&(d1>d2));
}

// 日期对应星期
int TransitionYTW(int y, int m, int d)
{
	if(m==1||m==2)
	{
		m+=12;
		y--;
	}
	int iWeek = 0;
	iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return iWeek+1;
}

//N天后星期
int DayAfterN(int y, int m, int d,int n)
{
	return (TransitionYTW(y, m, d)+n)%7;
}

//年月日  该年第多少天
int DayIsN(int y,int m,int d)
{
	IsRunNian(y);
	int sum = 0;
	for(int i = 0; i < m-1; ++i)
		sum += Month[i];
	sum += d;
	return sum;
}

//日期差计算
int DayToDay(int y1,int m1,int d1,
			 int y2,int m2,int d2)
{
	int Res = 0;
	int Y1,Y2;

	//为处理两个日期大小问题
	y1 >y2?(Y1 = y2,Y2 = y1):(Y1 = y1,Y2 = y2);
	//[]方式处理  最后多-少+
	for(int i = Y1;i <=Y2;++i)
	{
		IsRunNian(i);
		Res += Nss;
	}

	//重新记录两端年份时间
	int nss1 = 365,nss2 = 365;
	IsRunNian(y1);
	nss1 = Nss;
	IsRunNian(y2);
	nss2 = Nss;
	
	//对于不满年份的日期进行处理
	int nd1 = DayIsN(y1,m1,d1);
	int nd2 = DayIsN(y2,m2,d2);

	if(LateThen(y1,m1,d1,y2,m2,d2))
	{Res = Res + nd1 - nss1 - nd2; Res *=(-1);}
	else
	{Res = Res - nd1 + nd2 - nss2;}

	return Res;
}

//某年的第多少天是几月几日
void AfterNIsNofYear(int &y,int &m,int &d, int n)
{
	IsRunNian(y);
	int f = 0;
	//确定年份
	if(n > Nss)
	{
		y++;
		n -= Nss;
		AfterNIsNofYear(y,m,d,n);
	}

	//年内处理
	int sum = 0;
	//确定月份
	for(int i = 0; i < 12; ++i)
	{
		//确定日期
		if (n <= sum)
		{
			m = i;
			sum -= Month[i-1];
			d = n - sum;
			break;
		}
		sum += Month[i];
	}
}

//某天后 的第多少天是几月几日
void AfterNDis(int &y,int &m,int &d, int n) 
{
	//1确定该时间是本年第多少天
	int IsND = DayIsN(y,m,d);
	//2转化为上一个问题
	AfterNIsNofYear(y,m,d,n+IsND);
}

//某天前 的第多少天是几月几日
void BeforeNDis(int &y,int &m,int &d, int n) 
{
	//1确定今天是本年何时
	int nDayOfY = DayIsN(y,m,d);
	//如果不在本年
	if(nDayOfY < n)
	{
		y-=1;
		IsRunNian(y);
		int f = 0;
		//确定年份
		n -= Nss;
		BeforeNDis(y,m,d,n);
	
	}
	else	
	//如果在本年之内	
	{
		AfterNIsNofYear(y,m,d,nDayOfY - n);
	}

}
