
#include"operat.h"


int Month[12] = {31,29,31,30, //������
				31,30,31,31,
				30,31,30,31};

int Nss = 366;
extern CDateTime tmpdt;
//����У��
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
//��Ļ���λ�ÿ���
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
//����fȷ���Ƿ�������������˫�����
void ShowMonth(int y, int m,int f)
{
	int TodayIs = tmpdt.m_day;
	int lo = 1;
	IsRunNian(y);
	int F = TransitionYTW(y,m,1);
	if(!f)
	{
	printf("      < %d��%d�� >       \n",y,m);
	printf(" ��  һ  ��  ��  ��  ��  ��  \n");
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
		printf("      < %d��%d�� >       ",y,m);
		gotoxy(hOut,32,fy+=1);
	 	printf("  ��  һ  ��  ��  ��  ��  �� ");
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
	//////////////////��һ��
	if(flag)
	{
		//�±߽�
		IsRunNian(y);
		if(d == Month[m-1])
		{	//��߽�
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
				//��߽�
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

//��ʾ�����·���Ϣ
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

//��̬��ʾ��ǰʱ��
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

//ʱ�����Ƚ�
bool LateThen(int y1,int m1,int d1,
			 int y2,int m2,int d2)
{
	return ((y1 > y2) || (y1 == y2)&&(m1>m2) || (y1 == y2)&&(m1 == m2)&&(d1>d2));
}

// ���ڶ�Ӧ����
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

//N�������
int DayAfterN(int y, int m, int d,int n)
{
	return (TransitionYTW(y, m, d)+n)%7;
}

//������  ����ڶ�����
int DayIsN(int y,int m,int d)
{
	IsRunNian(y);
	int sum = 0;
	for(int i = 0; i < m-1; ++i)
		sum += Month[i];
	sum += d;
	return sum;
}

//���ڲ����
int DayToDay(int y1,int m1,int d1,
			 int y2,int m2,int d2)
{
	int Res = 0;
	int Y1,Y2;

	//Ϊ�����������ڴ�С����
	y1 >y2?(Y1 = y2,Y2 = y1):(Y1 = y1,Y2 = y2);
	//[]��ʽ����  ����-��+
	for(int i = Y1;i <=Y2;++i)
	{
		IsRunNian(i);
		Res += Nss;
	}

	//���¼�¼�������ʱ��
	int nss1 = 365,nss2 = 365;
	IsRunNian(y1);
	nss1 = Nss;
	IsRunNian(y2);
	nss2 = Nss;
	
	//���ڲ�����ݵ����ڽ��д���
	int nd1 = DayIsN(y1,m1,d1);
	int nd2 = DayIsN(y2,m2,d2);

	if(LateThen(y1,m1,d1,y2,m2,d2))
	{Res = Res + nd1 - nss1 - nd2; Res *=(-1);}
	else
	{Res = Res - nd1 + nd2 - nss2;}

	return Res;
}

//ĳ��ĵڶ������Ǽ��¼���
void AfterNIsNofYear(int &y,int &m,int &d, int n)
{
	IsRunNian(y);
	int f = 0;
	//ȷ�����
	if(n > Nss)
	{
		y++;
		n -= Nss;
		AfterNIsNofYear(y,m,d,n);
	}

	//���ڴ���
	int sum = 0;
	//ȷ���·�
	for(int i = 0; i < 12; ++i)
	{
		//ȷ������
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

//ĳ��� �ĵڶ������Ǽ��¼���
void AfterNDis(int &y,int &m,int &d, int n) 
{
	//1ȷ����ʱ���Ǳ���ڶ�����
	int IsND = DayIsN(y,m,d);
	//2ת��Ϊ��һ������
	AfterNIsNofYear(y,m,d,n+IsND);
}

//ĳ��ǰ �ĵڶ������Ǽ��¼���
void BeforeNDis(int &y,int &m,int &d, int n) 
{
	//1ȷ�������Ǳ����ʱ
	int nDayOfY = DayIsN(y,m,d);
	//������ڱ���
	if(nDayOfY < n)
	{
		y-=1;
		IsRunNian(y);
		int f = 0;
		//ȷ�����
		n -= Nss;
		BeforeNDis(y,m,d,n);
	
	}
	else	
	//����ڱ���֮��	
	{
		AfterNIsNofYear(y,m,d,nDayOfY - n);
	}

}
