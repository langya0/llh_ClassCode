////Heap.h
//#pragma once
//#include<vector>
//using namespace std;
//
//
////一个小根堆
//template<class T>
//class Heap
//{
//public:
//	//默认构造  构造一个空的堆  小根堆
//	Heap()
//	{}
//	//用数组构造一个堆
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
//	void Pop()   //删除堆顶
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
//	const T & Top() throw(exception &)  // 取堆顶（最小的）
//	{
//		if (_array.size() > 0)
//			return _array[0];
//		else
//			throw exception ex("取堆顶失败 堆顶为空");
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
//		while (root <= (_array.size() - 2) / 2)  //只要root保证为非终端结点
//		{
//			int child = root * 2 + 1;  //左孩子肯定存在 判断下右孩子
//			if (child + 1 < _array.size())  //存在右孩子
//			{
//				child = _array[child] > _array[child + 1] ? child + 1 : child;  //那个小返回那一个
//			}
//			if (_array[child] < _array[root])
//			{
//				swap(_array[child], _array[root]); //交换
//			}
//			root = child;
//		}
//	}
//
//	void AdjustUp(int child)
//	{
//		//正确的前提是child是合法的，是调用者的责任
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
////Main.cpp  测试用例
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
		int root = (_array.size() - 2) / 2;//找第一个非叶子结点
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