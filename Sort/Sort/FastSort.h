//filename: FastSort.h
#pragma once
#include"stdafx.h"

template<class T, template <class>class Cmp = Great >
void BubbSort(T *arr, size_t n)
{
	for (int beg = 0; beg < n; ++beg)
	{
		for (int j = 0; j < n - beg - 1; ++j)
		{
			if (Cmp<T>()(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void TestBubbSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	BubbSort<int>(arr, 10);
	PrintArr<int>(arr, 10);
}

template<class T, template <class>class Cmp = Great >
void BubbSort_B(T *arr, size_t n)
{
	for (int beg = 0; beg < n; ++beg)
	{
		int flag = 0;
		for (int j = 0; j < n - beg - 1; ++j)
		{
			if (Cmp<T>()(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				//交换了那么设置调整开关为1
				flag = 1;
			}
		}
		//如果遍历过程中不曾修改，那么说明序列有序，不在遍历
		if (flag == 0)
			break;
	}
}
void TestBubbSort_B()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	BubbSort_B<int>(arr, 10);
	PrintArr<int>(arr, 10);
}

template<class T, template <class>class Cmp = Great >
void FastSort(T *arr, size_t n, int first, int last)
{
	assert(arr);
	if (first < 0 || last >= n || first>last)
		return;
	int beg = first;
	int end = last;
	while (beg < end)
	{
		while (beg < end&&Cmp<T>()(arr[end], arr[beg]))
		{
			--end;
		}
		swap(arr[beg], arr[end]);
		while (beg < end && (Cmp<T>()(arr[end], arr[beg])))
		{
			++beg;
		}
		swap(arr[beg], arr[end]);
	}
	//beg == end ==  中间元素

	FastSort(arr, n, first, beg - 1);
	FastSort(arr, n, beg + 1, last);
}

template<class T, template <class>class Cmp = Great >
void FastSortPerfect(T *arr, size_t n, int first, int last)
{
	assert(arr);
	if (first < 0 || last >= n || first>last)
		return;
	int beg = first;
	int end = last;
	if (end - beg < 13)
	{
		InsertSort(arr + first, last - first+1);
		return;
	}
	while (beg < end)
	{
		while (beg < end&&Cmp<T>()(arr[end], arr[beg]))
		{
			--end;
		}
		swap(arr[beg], arr[end]);
		while (beg < end && (Cmp<T>()(arr[end], arr[beg])))
		{
			++beg;
		}
		swap(arr[beg], arr[end]);
	}
	//beg == end ==  中间元素

	FastSortPerfect(arr, n, first, beg - 1);
	FastSortPerfect(arr, n, beg + 1, last);
}

void TestFastSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	FastSortPerfect<int>(Arr, 10, 0, 9);
	PrintArr<int>(Arr, 10);
}