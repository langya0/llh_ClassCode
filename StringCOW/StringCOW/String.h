/*
��Ȩ��Ϣ����
�ļ����ƣ�String.h
�ļ���ʶ��
ժ    Ҫ�������ϰ汾���׵�String�����Ż�������
		�Ľ�
		1.����С���ڴ���������ֱ�Դ���С�ڴ��ÿ�������У����ڴ�������ڶ����Сʱ���ö�̬����
		2.ʵ�ִ���ڴ��дʱ�������ܣ����Ч�ʣ��Ż��ռ�����
		3.����new[]ʵ�ֻ��ƣ�����̬�ڴ���С��Ϣ����Ϊ���ء�ͷ��
		4.���ڴ���ڴ��ȡ��̬�����͡�����ʱ����Ϊ��ǰ��С��2��

��ǰ�汾��1.2
�� �� �ߣ���
������ڣ�2015-12-12

ȡ���汾��1.1
ԭ �� �ߣ���
������ڣ�2015-12-11
*/
#ifndef _STRING_H
#define _STRING_H
#include<iostream>
using namespace ::std;

namespace COW
{
	class String
	{
	friend 	void Check_Interface(String &S);
	friend ostream& operator << (ostream&os, String &Str);


	public:
		String(const char* str = "");
		String(String& Str);
		String& operator=(const String& Str);
		~String();

	public:
		int Find(char ch)const;
		int Find(const char* str)const;
		void PushBack(char ch);
		void Insert(size_t pos, char ch);
		void Insert(size_t pos, const char* str);
		bool Erase(size_t pos);
		bool Erase(size_t pos, size_t n);
		size_t Strlen()const;

		const char& String::operator[](size_t n)const;
		char& String::operator[](size_t n);
	private:
		void InitInfo(size_t inUse);	//��ʼ��capacity and inUse
		void CheckMem(size_t add = 1);	//�����ڴ����ʱ��������
		char* GetAdd(); //��ȡ��ǰ�ַ�������λ��
		size_t capacity()const;		//��ȡͷ�������Ч��������
		int inCount()const;		//��ȡ���ü���
		void decrease();//�������ü�����
		void increase();//�������ü�����

	private:
		enum{BufSize = 16};		//����ö�ٽ��������ʼ��
		char *_str;				//���ݿ飬��ͷ������capacity
		char _buff[BufSize];	// С�ڴ�鴦��
	};
	ostream& operator << (ostream&os, String &Str);
}
#endif