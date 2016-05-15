/*
	��Ȩ����2015
	�ļ����ƣ�String.h
	�ļ���ʶ��stringģ��
	ժ    Ҫ��ģ��stl::string������C++ʵ���˻�������

	��ǰ�汾��1.1
	���ߣ���
	���ʱ�䣺2015-12-11

	����ʷ�汾��NULL
	  ԭ���ߣ�
	  ������ڣ�)
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
	//String+=String  -->>��Ч����swap
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

	//��ʼ��posֱ��len���Ӵ���-1 ��ʾֱ����β��
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
		///��һ������*
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
	//�ҵ����һ�����ֵ�
	int rFind(const String& s, int pos = -1) const
	{
		int len = s.length();
		int lengThis = length();
		//��λ����str�ȳ�δλ��
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

	//��  pos λ�ÿ�ʼ��len��Ԫ�ر��滻Ϊ  s����
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
	//�ַ����󳤶�
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
	//String����
	void swap(String& a, String& b)
	{
		::swap(a._str, b._str);
		::swap(a._size, b._size);
		::swap(a._capacity, b._capacity);
	}
	//String �Ƚ�
	int Strcmp(const String&s)
	{
		int i = 0;
		//////////////very nice    &&��Ϊ  ||
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
///////////////���뾭��buf���档�������д��Խ��
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
