/*
版权信息：狼
文件名称：String.cpp
文件标识：
摘    要：对于上版本简易的String进行优化跟进。
	改进
	1.（将小块内存问题与大块分别对待）小内存块每个对象都有，当内存需求大于定义大小时利用动态分配
	2.实现大块内存的写时拷贝功能，提高效率，优化空间利用
	3.类似new[]实现机制：将动态内存块大小信息保存为隐藏“头”
	当前版本：1.2

修 改 者：狼
完成日期：2015-12-12

取代版本：1.1
原 作 者：狼
完成日期：2015-12-11
*/
#include"String.h"
#pragma warning (disable:4351 4996)

using namespace COW;

String::String(const char *Str)
	:_str(NULL)
	, _buff()
{
	//采用动态分配
	if (strlen(Str) >= BufSize)
	{
		//1.记录引用计数，2.记录当前有效大小   strlen（）+1
		_str = new char[strlen(Str) + 5+4];
		
		InitInfo(strlen(Str)+1);

		char *cur = const_cast<char*>(GetAdd());
		strcpy(cur, Str);	//有效位置
	}
	else//静态存储
	{
		strcpy(_buff, Str);
	}
}
String::String(String& Str)
	:_str(NULL)
	, _buff()
{
	//	1.如果是小块内存。浅拷贝
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
	//都是动态 且指向一处
	if (_str == Str._str&&_str != NULL)
		return *this;

	//两个都是小内存时
	if (Str._str == NULL&&_str==NULL)
	{
		strcpy(_buff, Str._buff);
	}
	//如果*this 是小内存（不存在内存变更，不用处理buff）,Str 动态。
	else if (_str==NULL&&Str._str!=NULL)
	{
		_str = Str._str;
		this->increase();
	}
		
	//*this 动态，Str小内存。减少*this._str计数。。.更改buff
	else if(_str!=NULL&&Str._str==NULL)
	{
		this->decrease();
		_str = NULL;
		strcpy(_buff,Str._buff);
	}

	//两个都是动态分配 但不同
	else
	{
		this->decrease();
		_str = Str._str;
		this->increase();
	}
	return *this;
}
///////问题1...命名空间冲突时
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

		//////问题2，，每次decrease之后必须变更_str..为NULL或者指向新块
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

///获取字符串的核心地址
 char *String::GetAdd()
{
	//忘记给对正确起始点
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

//设置头 信息
void String::InitInfo(size_t inUse)
{
	*((int*)_str) = 1;
	*((int*)_str + 1) = inUse;
}

void String::CheckMem(size_t add)
{
	if (_str == NULL)
	{
		//小内存，且变动后不越界。
		if (strlen(_buff) + add < 16)
			return;
		//小内存，变动后越界
		else
		{
			_str = new char[strlen(_buff) + add + 9];

			InitInfo(strlen(_buff) + add+1);
		}
	}
	else
	{
		//容量足够,且引用计数为1；
		if (strlen(_str + 8) + add < capacity()&& inCount()==1)
		{
			//,但是写时拷贝，需要更新空间，所以顺带增加宽度
			//if (inCount() != 1)
			//{
			//	int new_mem = (strlen(_str + 8) + add) * 2 + 9;
			//	this->decrease();
			//	
			//	_str = new char[new_mem];
			//	//少了+1  会造成后续始终有一个字节浪费问题
			//	InitInfo((strlen(_str + 8) + add) * 2 + 1);
			//}
			return;
		}
		else
		{
			//扩容后，容量为当前串长的2倍。  匹配使用，，用realloc 会出现问题
			//realloc(_str, (strlen(_str+8) + add) * 2 + 8);
		
			//不能delete，，写时拷贝忘记了。。引用计数问题忘记了？
			//delete[] _str;、
			//先计算所需，再decrease()，因为可能赋值为NULL,不得求Strlen
			int new_mem = (strlen(_str + 8) + add) * 2 + 9;
			this->decrease();
			_str = new char[new_mem];
			
			//少了+1  会造成后续始终有一个字节浪费问题
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
//	//首先保存内容。然后判断空间，然后存储。
//	char p[100];
//	char *st = const_cast<char*>(GetAdd());
//
//	strcpy(p, st);
//
//	CheckMem(0);	//默认为1；
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
		///简直，，if 后边有个；bug
		if (strncmp(cur, str, len) == 0)
			return pos;
		cur++;
	}
	return -1;
}
void String::PushBack(char ch)
{
	//首先保存内容。然后判断空间，然后存储。
	char p[100];
	char *st = const_cast<char*>(GetAdd());
	
	strcpy(p, st);

	CheckMem();	//默认为1；
	
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
	//越界有效化。。。
	if (pos >= Strlen())
	{
		pos = Strlen()-1;
	}
	//首先保存内容。然后判断空间，然后存储。
	char p[100];
	char *st = const_cast<char*>(GetAdd());

	strcpy(p, st);

	CheckMem();	//默认为1；

	st = const_cast<char*>(GetAdd());
	strncpy(st, p, pos);

	st[pos] = ch;
	
	//不能用strcat,前边字符串不存在'\0'
	strcpy(st + pos + 1, p + pos);
}

void String::Insert(size_t pos, const char* str)
{
	//越界有效化。。。
	if (pos >= Strlen())
	{
		pos = Strlen();
	}
	//首先保存内容。然后判断空间，然后存储。
	char p[100];
	char *st = const_cast<char*>(GetAdd());

	strcpy(p, st);

	int len = strlen(str);
	CheckMem(len);	//默认为1；

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
//////friend 友员函数不能跨越命名空间访问私有成员？？？？？？？？？？？？
//void Check_Interface(COW::String &S)
//{
//	char  *ch = S._str;
//	const char *ch1 = S._str;
//	cout << endl;
//}