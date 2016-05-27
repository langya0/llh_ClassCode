
#include"Menue.h"
enum {UP = 0x48 ,PD = 0x49,L = 0x4b,R = 0x4d, D = 0x50,PU = 0x51,C = 0x63,S = 0x73};
int tmpW = 1;	//星期
int tmpSum = 0;// 累计
int N = 1000; //间隔

CDateTime Localdt;
CDateTime tmpdt;

void a(int a){for(int i = 0; i < 39; ++i)printf("%c",a);printf("\n");}
void Menue1()
{	

	int choise = 1;
	do
	{
		system("cls");
		a(3);
		printf("*[1]显示当前日期     [2]显示当前时间  *\n");
		printf("*[3]显示日期时间     [4]动态显示时间  *\n");
		printf("*[5]显示本月日历表   [6]显示当年日历  *\n");
		printf("*[0]返回主菜单                        *\n");
		a(4);
		printf("请选择:>");
		scanf("%d",&choise);
		switch(choise)
		{
		case 1:
			ShowDate(&Localdt);
			system("pause");
			break;
		case 2:
			ShowTime(&Localdt);
			system("pause");
			break;
		case 3:
			ShowLocalTime(&Localdt);
			system("pause");
			break;
		case 4:
			DynShowTime(&Localdt);
			break;
		case 5:
			ShowMonth(Localdt.m_year,Localdt.m_month);
			system("pause");
			break;
		case 6:
			ShowYear(Localdt.m_year,2);
			system("pause");
			break;
		case 0:
			choise = 0;
			break;
		}

	}while(choise);
}

//////////////////////多个【8】
void Menue2()
{	int choise = 1;
	do
	{
		system("cls");
		a(3);
		printf("*[1]查询当前日期         [2]查询当前时间  *\n");
		printf("*[3]查询日期时间         [4]查询星期      *\n");
		printf("*[5]查询N天后日期        [6]查询N天前日期 *\n");
		printf("*[7]查询距离某日期的天数 [8]查询两天之间隔*\n");
		printf("*[9]更新时间             [0]返回主菜单    *\n");
		a(4);
		//////////////////////////////
		tmpdt = Localdt;
		printf("请选择:>");
		scanf("%d",&choise);
		switch(choise)
		{
		case 1:
			ShowDate(&Localdt);
			system("pause");
			break;
		case 2:
			ShowTime(&Localdt);
			system("pause");
			break;
		case 3:
			/////////////////////////////////
			ShowLocalTime(&Localdt);
			ShowMonth(tmpdt.m_year,tmpdt.m_month);
			system("pause");
			break;
		case 4:
			////////////////////////////////////////
#ifndef Debug
			EditTime(&tmpdt);
#endif
			tmpW = TransitionYTW(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day); 
			printf("[4]%d年%d月%d日",tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			printf("是星期%d\n", tmpW);
			system("pause");
			break;
		case 5:
#ifndef Debug
			printf("请输入N进行查询操作\n");
			scanf("%d",&N);
#endif
			AfterNDis(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,N);
			printf("[5]%d天后是%d年%d月%d日 \n",N,tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			system("pause");
			break;
		case 6:
#ifndef Debug
			printf("请输入N进行查询操作\n");
			scanf("%d",&N);
#endif
			BeforeNDis(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,N);
			printf("[6]%d天前是%d年%d月%d日 \n",N,tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			system("pause");
			break;
		case 7:
#ifndef Debug
			EditTime(&tmpdt);
#endif
			tmpSum = DayToDay(Localdt.m_year,Localdt.m_month,Localdt.m_day,
				tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			printf("[7]距离%d年%d月%d日有%d天\n",tmpdt.m_year,tmpdt.m_month,tmpdt.m_day, tmpSum);
			system("pause");
			break;
		case 8:
			CDateTime tmpdt1;
			InitDateTime(&tmpdt1);
#ifndef Debug
			EditTime(&tmpdt);
			EditTime(&tmpdt1);
#endif
			tmpSum = 
				DayToDay(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,
						 tmpdt1.m_year,tmpdt1.m_month,tmpdt1.m_day);
			printf("[8]%d年%d月%d日 与 %d年%d月%d日 相差 %d 天 \n",
						tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,
						tmpdt1.m_year,tmpdt1.m_month,tmpdt1.m_day,tmpSum);
			system("pause");
			break;
		case 9:
			GetNowDateTime(&Localdt);
			break;
		case 0:
			choise = 0;
			break;
		}

	}while(choise);
}

void Menue3()
{
	char choise = 0,choise2 = 0;
	char c = 0;
	do
	{
		system("cls");
		printf("↑:上一年             ↓:下一年\n");
		printf("←:上一月             →:下一月\n");
		printf("PageUp:昨天           PageDown:明天\n");
		printf("S:保存                c:取消\n");

		if((c = getch()) != 0xffffffe0)
			choise = c;
		else 
			choise = getch();
		////////void EditTime(CDateTime *dt)
		switch(choise)
		{
		case UP:
			ShowYear(tmpdt.m_year-=1,2);
			system("pause");
			break;
		case D:
			ShowYear(tmpdt.m_year+=1,2);
			system("pause");
			break;
		case L:
			ShowMonthNext(tmpdt.m_year,tmpdt.m_month,0);
			system("pause");
			break;
		case R:
			ShowMonthNext(tmpdt.m_year,tmpdt.m_month,1);
			system("pause");
			break;   
		case PU:
			ShowMonthByNextD(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,0);
			system("pause");
			break;
		case PD:
			ShowMonthByNextD(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,1);

			system("pause");
			break;
		case S:
			Localdt = tmpdt;
			choise = 0;
			break;
		case C:
			choise = 0;
			break;
		}
	}while(choise);
}
extern list<Memos> MemosList;

void Menue4()
{
	list<Memos> MemosList;
	int choise = 1;
	///////////////////////////////////////////////////////
	Init(&MemosList);

	do
	{
		system("cls");
		a(3);
		printf("*[1]查看备忘录           [2]增加备忘信息  *\n");
		printf("*[3]删除备忘信息         [4]导出备忘录    *\n");
		printf("*[0]返回主菜单                            *\n");
		a(4);
		printf("请选择:>");
		scanf("%d",&choise);
		switch(choise)
		{
		case 1:
			Look(&MemosList);
			system("pause");
			break;
		case 2:
			Add(&MemosList);
			system("pause");
			break;
		case 3:
			Delet(&MemosList);
			system("pause");
			break;
		case 4:
			Output(&MemosList);
			system("pause");
			break;
		case 0:
			Destroy(&MemosList);
			choise = 0;
			break;
		}
	}while(choise);

}
void Help1()
{
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
}
void Help2()
{
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
}
void Help3()
{
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
}
void Help4()
{
	printf("添加项的事件不得以数字开头  \n");
	printf("时间输入格式必须严格遵守实例\n");
	printf("导出成功不给于提示          \n");
	printf("");
	printf("");
}
void Menue5()
{	
	
	int choise = 1;
	do
	{
		system("cls");
		a(3);
		printf("*[1]日历显示帮助      [2]日历查询帮助    *\n");
		printf("*[3]日历显示帮助      [4]备忘录添加帮助  *\n");
		printf("*[0]返回上层                             *\n");
		
		a(4);
		printf("请选择:>");
		scanf("%d",&choise);
		switch(choise)
		{
		case 1:
			Help1();
			system("pause");
			break;
		case 2:
			Help1();
			system("pause");
			break;
		case 3:
			Help1();
			system("pause");
			break;
		case 4:
			Help1();
			system("pause");
			break;
		case 0:
			choise = 0;
			break;
		}
	}while(choise);
}


void Menue()
{	
	InitDateTime(&Localdt);
	GetNowDateTime(&Localdt);
	//////////////////////////////////////////////////
	tmpdt = Localdt;

	int choise = 1;
	do
	{
		system("cls");
		a(3);
		printf("*            万 年 历                 *\n");
		printf("*      [1]日 历 显 示->               *\n");
		printf("*      [2]日 历 查 询->               *\n");
		printf("*      [3]修 改 日 期->               *\n");
		printf("*      [4]日 期 备 忘 录->            *\n");
		printf("*      [5]信 息 帮 助                 *\n");
		printf("*      [0]退 出 系 统                 *\n");
		a(4);
		printf("请选择:>");
		scanf("%d",&choise);
		
		switch(choise)
		{
		case 1:
			Menue1();
			break;
		case 2:
			Menue2();
			break;
		case 3:
			Menue3();
			break;
		case 4:
			Menue4();
			break;
		case 5:
			Menue5();
			break;
		default:
			choise = 0;
			break;
		}
	}while(choise);
}
