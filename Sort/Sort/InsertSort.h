#pragma once
#include"stdafx.h"


template<class T,template <class>class Cmp = Great >
void InsertSort(T *arr, size_t n)
{
	assert(arr);

	///1532685
	for (int beg = 1; beg < n; ++beg)
	{
		int end = beg - 1;
		while (end >= 0 && Cmp<T>()(arr[end], arr[end+1]))
		{
			swap(arr[end], arr[end + 1]);
			end--;
		}
	}
}

void TestInsertSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	//ShellSort<int>(arr, 10);

	InsertSort<int>(arr, 10);
	PrintArr<int>(arr, 10);
}



//Ï£¶ûÅÅÐò
template<class T, template <class>class Cmp = Great >
void ShellSort(T*arr, size_t n)
{
	assert(arr);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int beg = gap; beg < n; ++beg)
		{
			int end = beg-gap;
			while (end >= 0 && Cmp<T>()(arr[end], arr[end + gap]))
			{
				swap(arr[end], arr[end + gap]);
				end-=gap;
			}
		}
	}
}

void TestShellSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	ShellSort<int>(arr, 10);

	//InsertSort<int>(arr, 10);
	PrintArr<int>(arr, 10);
}