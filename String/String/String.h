/*
	版权：狼2015
	文件名称：String.h
	文件标识：string模仿
	摘    要：模仿stl::string。利用C++实现了基本功能

	当前版本：1.1
	作者：狼
	完成时间：2015-12-11

	（历史版本：NULL
	  原作者：
	  完成日期：)
*/
#include<iostream>
#include<assert.h>
using namespace std;
#pragma warning (disable:4996)
class String
{
private:
	
	char *_str;
	size_t _size;
	size_t _capacity;

public:
	friend ostream& operator<<(ostream&os, const String&s);
	friend istream& getline(istream& is, String& str);
	friend void Swap(String a, String b);

	String(const char * str = "")
		: _str(new char[strlen(str) + 1])
		, _size(strlen(str))	
		, _capacity(strlen(str) + 1)
	{
		strcpy(_str, str);
	}
	String(const String &s)
		:_str(NULL)
	{
		String tmp = s._str;
		swap(tmp, *this);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
		}
	}

	String& operator=(const String&s)
	{
		if (this != &s)
		{
			String tmp(s);
			swap(*this, tmp);
		}
		return *this;
	}
	bool operator >(const String& s)
	{
		int cmp = this->Strcmp(s);
		if (cmp == 1)
			return true;
		return false;
	}
	bool operator <(const String& s)
	{
		int cmp = this->Strcmp(s);
		if (cmp == -1)
			return true;
		return false;
	}
	bool operator <=(const String& s)
	{
		int cmp = this->Strcmp(s);
		if (cmp != 1)
			return true;
		return false;
	}
	bool operator >=(const String& s)
	{
		int cmp = this->Strcmp(s);
		if (cmp != -1)
			return true;
		return false;
	}
	bool operator !=(const String&s)
	{
		return !(*this == s);
	}
	bool operator ==(const String&s)
	{
		int cmp = this->Strcmp(s);
		if (cmp == 0)
			return true;
		return false;
	}

	//String+String
	String operator+(const String& s)
	{
		if (*s._str == 0)
		{
			return *this;
		}
		int len = length();
		char* tmp = new char[_str, s.length() + len + 1];
		strcpy(tmp, _str);
		strcat(tmp + len, s._str);
		return String(tmp);
	}
	//String+char*
	String operator+(const char*& s)
	{
		if (*s == 0)
		{
			return *this;
		}
		int lens = CLength(s);
		int lenString = length();
		char* tmp = new char[_str, lens + lenString + 1];
		strcpy(tmp, _str);
		strcat(tmp + lenString, s);
		return String(tmp);
	}
	//String+=String  -->>有效利用swap
	String operator+=(const String& s)
	{
		String tmp = *this + s;
		swap(*this, tmp);
		return *this;
	}
	String operator+=(const char*& s)
	{
		String tmp = *this + s;
		swap(*this, tmp);
		return *this;
	}

	bool empty()const
	{
		return (*_str == 0);
	}

	const char &operator[](int index)const
	{
		assert(index < length() && index >= 0);
		return *(_str + index);
	}
	char &operator[](int index)
	{
		assert(index < length() && index >= 0);
		return *(_str + index);
	}

	//求开始于pos直到len的子串，-1 表示直到结尾。
	String substr(int pos = 0, int len = -1) const
	{
		assert(len < length()&&pos<=len);
		char *pret = NULL;
		if (len == -1)
		{
			pret = new char[length() - pos+1];
			strcpy(pret, _str + pos);
		}
		else
		{
			pret = new char[len - pos + 1];
			strncpy(pret, _str + pos, len - pos);
			pret[len - pos] = '\0';
		}
		return String(pret);
	}
	//find first str in Str;
	int Find(const char* str)
	{
		char *tmp = _str;
		int len = CLength(str);
		///又一次忘记*
		while (*tmp)
		{
			if (!strncmp(tmp, str,len))
			{
				return tmp - _str;
			}
			tmp++;
		}
		return -1;
	}
	//找到最后一个出现的
	int rFind(const String& s, int pos = -1) const
	{
		int len = s.length();
		int lengThis = length();
		//定位到和str等长未位置
		char *tmp = _str+lengThis-len;
		while (tmp!=_str)
		{
			if (!strncmp(tmp, s._str, len))
			{
				return tmp - _str;
			}
			tmp--;
		}
		return -1;
	}

	//从  pos 位置开始的len个元素被替换为  s。。
	String& replace(int pos, int len, const String& s)
	{
		char *tmp = NULL;
		int le = s.length();
		int leng = length();
		if (len == le)
		{
			strncmp(_str + pos, s._str, len);
			return *this;
		}
		else
		{
			char *tmp = new char[leng - len + le+1];
			strncpy(tmp, _str, pos);
			strncpy(tmp + pos, s._str, le);
			strcpy(tmp + pos + le, _str + pos + len);
			tmp[leng - len + le + 1] = '\0';
			swap(*this, String(tmp));
			return *this;
		}
	}
	int size()const
	{
		return length();
	}
	int capacity()const
	{
		return _capacity;
	}

	char* C_str()const
	{
		return _str;
	}

	char& front()const
	{ 
		return _str[0];
	}
	char &back()const
	{
		return _str[_size - 1];
	}

	void push_back(char x)
	{
		String tmp(*this);
		tmp = (*this) + String(&x);
		swap(*this, tmp);
	}
	void copy(char p[],size_t pos,int n)
	{
		int i = 0;
		while (n--){
			p[i] = _str[pos + i - 1];
			i++;
		}
		p[i] = '\0';
	}
	void pop_back()
	{
		_size--;
		_str[_size - 1] = '\0';
	}
	////////////////////////////////////////////////////////////////////
private:
	int length()const
	{
		int length = 0;
		char *tmp = _str;
		while (*tmp)
		{
			tmp++;
			length++;
		}
		return length;
	}
	//字符串求长度
	int CLength(const char*& s)
	{
		int length = 0;
		char *tmp = const_cast<char*>(s);
		while (*tmp)
		{
			tmp++;
			length++;
		}
		return length;
	}
	//String交换
	void swap(String& a, String& b)
	{
		::swap(a._str, b._str);
		::swap(a._size, b._size);
		::swap(a._capacity, b._capacity);
	}
	//String 比较
	int Strcmp(const String&s)
	{
		int i = 0;
		//////////////very nice    &&改为  ||
		while ((*(s._str + i)) || (*(_str + i)))
		{
			if ((*(_str + i)) > (*(s._str + i)))
			{
				return 1;
			}
			else if ((*(_str + i)) < (*(s._str + i)))
			{
				return -1;
			}
			i++;
		}
		return 0;
	}
	int Strcmp1(const String&s)
	{
		int i = 0;
		while ((*(s._str + i)) == (*(_str + i)) && (*(s._str + i)) != 0)
		{
			i++;
		}
		return (*_str + i) - (*(s._str + i))?((*_str + i) > (*(s._str + i))?1:-1):0;
	}
private:
	char *_str;
	size_t _size;
	size_t _capacity;

};

ostream& operator<<(ostream&os, const String&s)
{
	os << s._str;
	return os;
}
///////////////必须经过buf缓存。否则可能写入越界
istream& getline(istream& is, String& str)
{
	char buf[100];
	is >> buf;
	str.swap(str, String(buf));
	return is;
}
void Swap(String a, String b)
{
	a.swap(a, b);
}
