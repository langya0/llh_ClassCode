
#include"Menue.h"
enum {UP = 0x48 ,PD = 0x49,L = 0x4b,R = 0x4d, D = 0x50,PU = 0x51,C = 0x63,S = 0x73};
int tmpW = 1;	//����
int tmpSum = 0;// �ۼ�
int N = 1000; //���

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
		printf("*[1]��ʾ��ǰ����     [2]��ʾ��ǰʱ��  *\n");
		printf("*[3]��ʾ����ʱ��     [4]��̬��ʾʱ��  *\n");
		printf("*[5]��ʾ����������   [6]��ʾ��������  *\n");
		printf("*[0]�������˵�                        *\n");
		a(4);
		printf("��ѡ��:>");
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

//////////////////////�����8��
void Menue2()
{	int choise = 1;
	do
	{
		system("cls");
		a(3);
		printf("*[1]��ѯ��ǰ����         [2]��ѯ��ǰʱ��  *\n");
		printf("*[3]��ѯ����ʱ��         [4]��ѯ����      *\n");
		printf("*[5]��ѯN�������        [6]��ѯN��ǰ���� *\n");
		printf("*[7]��ѯ����ĳ���ڵ����� [8]��ѯ����֮���*\n");
		printf("*[9]����ʱ��             [0]�������˵�    *\n");
		a(4);
		//////////////////////////////
		tmpdt = Localdt;
		printf("��ѡ��:>");
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
			printf("[4]%d��%d��%d��",tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			printf("������%d\n", tmpW);
			system("pause");
			break;
		case 5:
#ifndef Debug
			printf("������N���в�ѯ����\n");
			scanf("%d",&N);
#endif
			AfterNDis(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,N);
			printf("[5]%d�����%d��%d��%d�� \n",N,tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			system("pause");
			break;
		case 6:
#ifndef Debug
			printf("������N���в�ѯ����\n");
			scanf("%d",&N);
#endif
			BeforeNDis(tmpdt.m_year,tmpdt.m_month,tmpdt.m_day,N);
			printf("[6]%d��ǰ��%d��%d��%d�� \n",N,tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			system("pause");
			break;
		case 7:
#ifndef Debug
			EditTime(&tmpdt);
#endif
			tmpSum = DayToDay(Localdt.m_year,Localdt.m_month,Localdt.m_day,
				tmpdt.m_year,tmpdt.m_month,tmpdt.m_day);
			printf("[7]����%d��%d��%d����%d��\n",tmpdt.m_year,tmpdt.m_month,tmpdt.m_day, tmpSum);
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
			printf("[8]%d��%d��%d�� �� %d��%d��%d�� ��� %d �� \n",
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
		printf("��:��һ��             ��:��һ��\n");
		printf("��:��һ��             ��:��һ��\n");
		printf("PageUp:����           PageDown:����\n");
		printf("S:����                c:ȡ��\n");

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
		printf("*[1]�鿴����¼           [2]���ӱ�����Ϣ  *\n");
		printf("*[3]ɾ��������Ϣ         [4]��������¼    *\n");
		printf("*[0]�������˵�                            *\n");
		a(4);
		printf("��ѡ��:>");
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
	printf("�������¼����������ֿ�ͷ  \n");
	printf("ʱ�������ʽ�����ϸ�����ʵ��\n");
	printf("�����ɹ���������ʾ          \n");
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
		printf("*[1]������ʾ����      [2]������ѯ����    *\n");
		printf("*[3]������ʾ����      [4]����¼��Ӱ���  *\n");
		printf("*[0]�����ϲ�                             *\n");
		
		a(4);
		printf("��ѡ��:>");
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
		printf("*            �� �� ��                 *\n");
		printf("*      [1]�� �� �� ʾ->               *\n");
		printf("*      [2]�� �� �� ѯ->               *\n");
		printf("*      [3]�� �� �� ��->               *\n");
		printf("*      [4]�� �� �� �� ¼->            *\n");
		printf("*      [5]�� Ϣ �� ��                 *\n");
		printf("*      [0]�� �� ϵ ͳ                 *\n");
		a(4);
		printf("��ѡ��:>");
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
