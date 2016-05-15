/*
��Ȩ��Ϣ����
�ļ����ƣ�String.cpp
�ļ���ʶ��
ժ    Ҫ�������ϰ汾���׵�String�����Ż�������
	�Ľ�
	1.����С���ڴ���������ֱ�Դ���С�ڴ��ÿ�������У����ڴ�������ڶ����Сʱ���ö�̬����
	2.ʵ�ִ���ڴ��дʱ�������ܣ����Ч�ʣ��Ż��ռ�����
	3.����new[]ʵ�ֻ��ƣ�����̬�ڴ���С��Ϣ����Ϊ���ء�ͷ��
	��ǰ�汾��1.2

�� �� �ߣ���
������ڣ�2015-12-12

ȡ���汾��1.1
ԭ �� �ߣ���
������ڣ�2015-12-11
*/
#include"String.h"
#pragma warning (disable:4351 4996)

using namespace COW;

String::String(const char *Str)
	:_str(NULL)
	, _buff()
{
	//���ö�̬����
	if (strlen(Str) >= BufSize)
	{
		//1.��¼���ü�����2.��¼��ǰ��Ч��С   strlen����+1
		_str = new char[strlen(Str) + 5+4];
		
		InitInfo(strlen(Str)+1);

		char *cur = const_cast<char*>(GetAdd());
		strcpy(cur, Str);	//��Чλ��
	}
	else//��̬�洢
	{
		strcpy(_buff, Str);
	}
}
String::String(String& Str)
	:_str(NULL)
	, _buff()
{
	//	1.�����С���ڴ档ǳ����
	if (Str._str == NULL)
	{
		strcpy(_buff,Str._buff);
	}
	else
	{
		_str = Str._str;
		this->increase();
	}
}
String& String::operator=(const String& Str)
{
	//���Ƕ�̬ ��ָ��һ��
	if (_str == Str._str&&_str != NULL)
		return *this;

	//��������С�ڴ�ʱ
	if (Str._str == NULL&&_str==NULL)
	{
		strcpy(_buff, Str._buff);
	}
	//���*this ��С�ڴ棨�������ڴ��������ô���buff��,Str ��̬��
	else if (_str==NULL&&Str._str!=NULL)
	{
		_str = Str._str;
		this->increase();
	}
		
	//*this ��̬��StrС�ڴ档����*this._str��������.����buff
	else if(_str!=NULL&&Str._str==NULL)
	{
		this->decrease();
		_str = NULL;
		strcpy(_buff,Str._buff);
	}

	//�������Ƕ�̬���� ����ͬ
	else
	{
		this->decrease();
		_str = Str._str;
		this->increase();
	}
	return *this;
}
///////����1...�����ռ��ͻʱ
ostream& COW::operator << (ostream&os, String &Str)
{
	if (Str._str)
	{
		os << (Str._str + 8);
	}
	else
		os << Str._buff;
	return os;
}


////////////////////////core_func
inline void String::increase()
{
	*(int*)_str += 1;
}

inline void String::decrease()
{
	if (_str != NULL)
	{

		//////����2����ÿ��decrease֮�������_str..ΪNULL����ָ���¿�
		if ((*(int*)_str) - 1 != 0)
		{
			(*(int*)_str) -= 1;
		}
		else
		{
			delete[]_str;
			_str = NULL;
		}
	}
}
String::~String()
{
	this->decrease();
	_str = NULL;
}

///��ȡ�ַ����ĺ��ĵ�ַ
 char *String::GetAdd()
{
	//���Ǹ�����ȷ��ʼ��
	return _str ? _str+8 : _buff;
}

size_t String::capacity()const
{
	return *((int*)_str+1);
}
int String::inCount()const 
{
	return *((int*)_str);
}

//����ͷ ��Ϣ
void String::InitInfo(size_t inUse)
{
	*((int*)_str) = 1;
	*((int*)_str + 1) = inUse;
}

void String::CheckMem(size_t add)
{
	if (_str == NULL)
	{
		//С�ڴ棬�ұ䶯��Խ�硣
		if (strlen(_buff) + add < 16)
			return;
		//С�ڴ棬�䶯��Խ��
		else
		{
			_str = new char[strlen(_buff) + add + 9];

			InitInfo(strlen(_buff) + add+1);
		}
	}
	else
	{
		//�����㹻,�����ü���Ϊ1��
		if (strlen(_str + 8) + add < capacity()&& inCount()==1)
		{
			//,����дʱ��������Ҫ���¿ռ䣬����˳�����ӿ��
			//if (inCount() != 1)
			//{
			//	int new_mem = (strlen(_str + 8) + add) * 2 + 9;
			//	this->decrease();
			//	
			//	_str = new char[new_mem];
			//	//����+1  ����ɺ���ʼ����һ���ֽ��˷�����
			//	InitInfo((strlen(_str + 8) + add) * 2 + 1);
			//}
			return;
		}
		else
		{
			//���ݺ�����Ϊ��ǰ������2����  ƥ��ʹ�ã�����realloc ���������
			//realloc(_str, (strlen(_str+8) + add) * 2 + 8);
		
			//����delete����дʱ���������ˡ������ü������������ˣ�
			//delete[] _str;��
			//�ȼ������裬��decrease()����Ϊ���ܸ�ֵΪNULL,������Strlen
			int new_mem = (strlen(_str + 8) + add) * 2 + 9;
			this->decrease();
			_str = new char[new_mem];
			
			//����+1  ����ɺ���ʼ����һ���ֽ��˷�����
			InitInfo(new_mem-8);
		}
	}	
}

//////////////////publicFunc
char& String::operator[](size_t n)
{
	return GetAdd()[n];
}

//char& String::operator[](size_t n)
//{
//	//���ȱ������ݡ�Ȼ���жϿռ䣬Ȼ��洢��
//	char p[100];
//	char *st = const_cast<char*>(GetAdd());
//
//	strcpy(p, st);
//
//	CheckMem(0);	//Ĭ��Ϊ1��
//
//	st = const_cast<char*>(GetAdd());
//	strcpy(st, p);
//
//	return st[n];
//}

int String::Find(char ch)
{
	char *cur = GetAdd();
	int pos = -1;
	while (*cur)
	{
		pos++;
		if (*cur == ch)
			return pos;
		cur++;
	}
	return -1;
}

int String::Find(const char* str)const
{
	if (str == NULL)
		return -1;
	char *cur = GetAdd();
	int pos = -1;
	int len = strlen(str);
	while (*(cur + len))
	{
		pos++;
		///��ֱ����if ����и���bug
		if (strncmp(cur, str, len) == 0)
			return pos;
		cur++;
	}
	return -1;
}
void String::PushBack(char ch)
{
	//���ȱ������ݡ�Ȼ���жϿռ䣬Ȼ��洢��
	char p[100];
	char *st = const_cast<char*>(GetAdd());
	
	strcpy(p, st);

	CheckMem();	//Ĭ��Ϊ1��
	
	st = const_cast<char*>(GetAdd());
	strcpy(st, p);

	st[strlen(st)+1] = '\0';
	st[strlen(st)] = ch;

}

size_t String::Strlen()const
{
	return strlen(GetAdd());
}

void String::Insert(size_t pos, char ch)
{
	//Խ����Ч��������
	if (pos >= Strlen())
	{
		pos = Strlen()-1;
	}
	//���ȱ������ݡ�Ȼ���жϿռ䣬Ȼ��洢��
	char p[100];
	char *st = const_cast<char*>(GetAdd());

	strcpy(p, st);

	CheckMem();	//Ĭ��Ϊ1��

	st = const_cast<char*>(GetAdd());
	strncpy(st, p, pos);

	st[pos] = ch;
	
	//������strcat,ǰ���ַ���������'\0'
	strcpy(st + pos + 1, p + pos);
}

void String::Insert(size_t pos, const char* str)
{
	//Խ����Ч��������
	if (pos >= Strlen())
	{
		pos = Strlen();
	}
	//���ȱ������ݡ�Ȼ���жϿռ䣬Ȼ��洢��
	char p[100];
	char *st = const_cast<char*>(GetAdd());

	strcpy(p, st);

	int len = strlen(str);
	CheckMem(len);	//Ĭ��Ϊ1��

	st = const_cast<char*>(GetAdd());
	strncpy(st, p, pos);

	strcpy(st + pos, str);

	strcpy(st + pos + len, p + pos);
}

bool String::Erase(size_t pos)
{
	char *cur = const_cast<char*>(GetAdd());
	size_t len = Strlen();
	if (pos >= len)
		return false;
	memmove(cur+ pos, cur + pos + 1, len + 1);
	return true;
}

bool String::Erase(size_t pos, size_t n)
{
	char *cur = const_cast<char*>(GetAdd());
	size_t len = strlen(cur + pos + 1);
	if (pos >= len)
		return false;
	memmove(cur + pos, cur + pos + n, len + 1);
	return true;
}

using namespace COW;
//////friend ��Ա�������ܿ�Խ�����ռ����˽�г�Ա������������������������
//void Check_Interface(COW::String &S)
//{
//	char  *ch = S._str;
//	const char *ch1 = S._str;
//	cout << endl;
//}