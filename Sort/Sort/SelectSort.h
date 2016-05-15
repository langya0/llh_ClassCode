#include"stdafx.h"

template<class T, template<class> class Cmp = Great>
void SelectSort(T*arr, size_t n)
{
	assert(arr);

	for (int beg = 0; beg < n; ++beg)
	{
		int flag = beg;
		for (int j = beg + 1; j < n; ++j)
		{
			if (Cmp<T>()(arr[flag], arr[j]))
				flag = j;
		}
		swap(arr[beg], arr[flag]);
	}
}
/////////////////////Test
void TestSelectSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	//ShellSort<int>(arr, 10);

	SelectSort<int>(arr, 10);
	PrintArr<int>(arr, 10);
}

template<class T, template<class> class Cmp = Great>
void BetSelectSort(T*arr, size_t n)
{
	assert(arr);

	int beg = 0; 
	int end = n - 1;
	while(beg<end)
	{
		int leftF = beg;
		int rightF = end;

		for (int j = beg; j <=end; ++j)
		{
			if (Cmp<T>()(arr[leftF], arr[j]))
				swap(arr[leftF], arr[j]);
			if (!Cmp<T>()(arr[rightF], arr[j]))
				swap(arr[rightF], arr[j]);
		}
		++beg; --end;
	}
}
//Test
void TestBetSelectSort()
{
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
	//ShellSort<int>(arr, 10);

	BetSelectSort<int>(arr, 10);
	PrintArr<int>(arr, 10);
}



int Arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };

template<class T, template<class> class Cmp = Great>
void AdjustDown(T*arr, int n, int root)
{
	if (n <=1)
		return;
	while (root <= (n - 2) / 2)
	{
		int child= root * 2 + 1;
		child = child + 1 < n ? Cmp<T>()(arr[child + 1], arr[child]) ? child + 1 : child : child;

		if (Cmp<T>()(arr[child], arr[root]))
		{
			swap(arr[child], arr[root]);
		}
		root = child;

	}
}

template<class T, template<class> class Cmp = Great>
void heapSort(T*arr, size_t n)
{
	//½¨¶Ñ
	for (int i = (n - 2) / 2; i >= 0;--i)
	{
		AdjustDown(arr, n, i);
	}
	//ÅÅÐò
	int end = n - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown<T>(arr, end, 0);
		end--;
	}
}

void TestheapSort()
{

	heapSort<int>(Arr, 10);
	PrintArr<int>(Arr, 10);
}