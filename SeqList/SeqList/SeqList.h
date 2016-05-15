/*
版权信息：狼
文件名称：SeqList.h
文件标识：
摘    要：C++实现基本顺序表功能

当前版本：1.1
作    者：狼
完成时间：2015-12-13

*/
#ifndef _SEQLIST_H
#define _SEQLIST_H

#include"afxstd.h"

namespace LIST
{
	typedef int DataType;

	class SeqList
	{
	public:
		SeqList(DataType * array, const size_t size=0);
		SeqList();

		SeqList(const SeqList& s);
		SeqList& operator=(const SeqList& s);
		~SeqList();

	public:
		void PushBack();
		void Print();
		void PushFront(DataType x);
	

	private:
		DataType* _array;
		size_t _size;
		size_t _capacity;
	};

}

using namespace LIST;

SeqList::SeqList(DataType * array, const size_t size)
	: _array(new DataType[size])
	, _size(size)
	, _capacity(size)
{
	memcpy(_array, array, sizeof(DataType)*size);
}

SeqList::SeqList():
	_array(NULL)
	, _size(0)
	, _capacity(0)
{}

SeqList::~SeqList()
{
	if (_array)
		delete[] _array;
}

void SeqList::Print()
{
	for (size_t i = 0; i < _size; ++i)
	{
		cout << _array[i] << " -> ";
	}
	cout << " Over! " << endl;
}
#endif