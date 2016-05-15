/*
版权信息：狼
文件名称：String.h
文件标识：
摘    要：对于上版本简易的String进行优化跟进。
		改进
		1.（将小块内存问题与大块分别对待）小内存块每个对象都有，当内存需求大于定义大小时利用动态分配
		2.实现大块内存的写时拷贝功能，提高效率，优化空间利用
		3.类似new[]实现机制：将动态内存块大小信息保存为隐藏“头”
		4.对于大块内存采取动态增长型。不够时扩容为当前大小的2倍

当前版本：1.2
修 改 者：狼
完成日期：2015-12-12

取代版本：1.1
原 作 者：狼
完成日期：2015-12-11
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
		void InitInfo(size_t inUse);	//初始化capacity and inUse
		void CheckMem(size_t add = 1);	//对于内存操作时的增否处理
		char* GetAdd(); //获取当前字符串所在位置
		size_t capacity()const;		//读取头，获得有效容量长度
		int inCount()const;		//获取引用计数
		void decrease();//减少引用计数。
		void increase();//增加引用计数。

	private:
		enum{BufSize = 16};		//利用枚举进行数组初始化
		char *_str;				//内容块，“头”代替capacity
		char _buff[BufSize];	// 小内存块处理。
	};
	ostream& operator << (ostream&os, String &Str);
}
#endif