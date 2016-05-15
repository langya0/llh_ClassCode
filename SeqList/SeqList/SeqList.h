/*
��Ȩ��Ϣ����
�ļ����ƣ�SeqList.h
�ļ���ʶ��
ժ    Ҫ��C++ʵ�ֻ���˳�����

��ǰ�汾��1.1
��    �ߣ���
���ʱ�䣺2015-12-13

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