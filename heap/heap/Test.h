////Heap.h
//#pragma once
//#include<vector>
//using namespace std;
//
//
////һ��С����
//template<class T>
//class Heap
//{
//public:
//	//Ĭ�Ϲ���  ����һ���յĶ�  С����
//	Heap()
//	{}
//	//�����鹹��һ����
//	Heap(const T *  arr, size_t size)
//	{
//		for (int i = 0; i < size; ++i)
//		{
//			_array.push_back(arr[i]);
//		}
//		int root = (_array.size() - 2) / 2;
//		while (root >= 0)
//		{
//			AdjustDown(root--);
//		}
//
//	}
//
//	void Pop()   //ɾ���Ѷ�
//	{
//		if (_array.size() == 0)
//		{
//			return;
//		}
//		if (_array.size() == 1)
//		{
//			_array.pop_back();
//		}
//		else
//		{
//			swap(_array[0], _array[_array.size() - 1]);
//			_array.pop_back();
//			AdjustDown(0);
//		}
//	}
//
//	const T & Top() throw(exception &)  // ȡ�Ѷ�����С�ģ�
//	{
//		if (_array.size() > 0)
//			return _array[0];
//		else
//			throw exception ex("ȡ�Ѷ�ʧ�� �Ѷ�Ϊ��");
//	}
//
//	void Push(T & t)
//	{
//		_array.push_back(t);
//		AdjustUp(_array.size() - 1);
//	}
//
//
//
//protected:
//	void AdjustDown(int root)
//	{
//		while (root <= (_array.size() - 2) / 2)  //ֻҪroot��֤Ϊ���ն˽��
//		{
//			int child = root * 2 + 1;  //���ӿ϶����� �ж����Һ���
//			if (child + 1 < _array.size())  //�����Һ���
//			{
//				child = _array[child] > _array[child + 1] ? child + 1 : child;  //�Ǹ�С������һ��
//			}
//			if (_array[child] < _array[root])
//			{
//				swap(_array[child], _array[root]); //����
//			}
//			root = child;
//		}
//	}
//
//	void AdjustUp(int child)
//	{
//		//��ȷ��ǰ����child�ǺϷ��ģ��ǵ����ߵ�����
//		int root;
//		while (child > 0)
//		{
//			root = (child - 1) / 2;
//			if (_array[root] > _array[child])
//			{
//				swap(_array[root], _array[child]);
//			}
//			child = root;
//		}
//
//	}
//
//protected:
//	vector<T> _array;
//};
//
////Main.cpp  ��������
//
//#include"Heap.h"
//#include<iostream>
//
//void Test1()
//{
//	//int a[] = { 1, 2, 3, 4, 9, 8, 7, 6, 5 };
//	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//
//	Heap<int> h(a, 9);
//	int b = 0;
//	h.Push(b);
//
//	h.Pop();
//
//}
//
//int Test()
//{
//	Test1();
//	system("pause");
//	return 0;
//}
#pragma once

#include <iostream>
using namespace std;
#include <cassert>
#include <vector>

template<class T>
class Heap
{
public:
	Heap()
	{}
	Heap(const int *a, size_t size)
	{
		for (int i = 0; i < size; ++i)
		{
			_array.push_back(a[i]);
		}
		int root = (_array.size() - 2) / 2;//�ҵ�һ����Ҷ�ӽ��
		while (root >= 0)
			AdjustDown(root--);
	}
	bool IsEmpty()const
	{
		return _array.size() == 0;
	}
	T& top()
	{
		if (_array.size() != 0)
			return _array[0];
	}
	void pop()
	{
		if (_array.size() == 0)
		{
			return;
		}

		swap(_array[0], _array[_array.size() - 1]);
		_array.pop_back();
		if (_array.size()>1)
		AdjustDown(0);

	}
protected:
	void AdjustDown(int root)
	{
		assert(root >= 0);
		while (root <= (_array.size() - 2) / 2)
		{
			int child;
			if (root * 2 + 2 < _array.size())
			{
				child = _array[root * 2 + 1] > _array[root * 2 + 2] ? root * 2 + 2 : root * 2 + 1;
			}
			else
			{
				child = root * 2 + 1;
			}
			if (_array[root] > _array[child])
			{
				swap(_array[root], _array[child]);
			}
			root = child;
		}
	}
protected:
	vector<T> _array;
};