
//////////////////////////备忘录//////////////////////////////////////////
#include"Memos.h"
size_t Length = 0;
void Init(list<Memos> * plist)
{
	FILE *fp = 	fopen("Memos.txt","r");
	if(NULL == fp)
		return;
	int i = 0;
	int ind = 1;
	while(!feof(fp))
	{
		Memos tmp;
		tmp.index = ind ++;
		fscanf(fp,"%d-%d-%d,%d:%d",&tmp.time.m_year,&tmp.time.m_month,&tmp.time.m_day,
									&tmp.time.m_hour,&tmp.time.m_minute);
		fscanf(fp,"%s",tmp.p); 
		fgetc(fp);
		plist->push_back(tmp);
	}
	Length = ind;
	system("pause");
	fclose(fp);  
}

void Destroy(list <Memos> *plist)
{  
	Output(plist);
	plist->clear();
}
void Look(list<Memos> * plist)
{
	list<Memos>::iterator it = plist->begin();
	while(it!=plist->end())
	{
		printf("序号:%d",it->index);
		printf("时间:%d-%d-%-d,%d:%d\n",it->time.m_year,it->time.m_month,it->time.m_day,
									it->time.m_hour,it->time.m_minute);
		printf("事件: %s\n",it->p);
		it++;
	}
}
void Add(list<Memos> * plist)
{
	printf("输入时间%%d-%%d-%%d,%%d:%%d\n");
	Memos tmp;
	scanf("%d-%d-%d,%d:%d",&tmp.time.m_year,&tmp.time.m_month,&tmp.time.m_day,
		&tmp.time.m_hour,&tmp.time.m_minute);
	printf("输入事件\n");
	scanf("%s",tmp.p);

	tmp.index = Length++;
	plist->push_back(tmp);
}
void Delet(list<Memos> * plist)
{
	size_t ind = 0;
	printf("输入序号进行删除\n");
	scanf("%d",&ind);

	list<Memos>::iterator it = plist->begin();
	while(it!=plist->end())
	{
		if(it->index == ind)
			break;
		it++;
	}
	Length--;
	plist->erase(it);
}
void Output(list<Memos> * plist)
{
	FILE *fp = 	fopen("Memos.txt","w");
	if(NULL == fp)
		return;
	list<Memos>::iterator it = plist->begin();

	fprintf(fp,"%d-%d-%d,%d:%d",it->time.m_year,it->time.m_month,it->time.m_day,
								it->time.m_hour,it->time.m_minute);
	fprintf(fp,"%s",it->p);
	it++;
	while(it!=plist->end())
	{
		fprintf(fp,"\n%d-%d-%d,%d:%d",it->time.m_year,it->time.m_month,it->time.m_day,
									it->time.m_hour,it->time.m_minute);
		fprintf(fp,"%s",it->p);
		it++;
	}
	fclose(fp);
}

