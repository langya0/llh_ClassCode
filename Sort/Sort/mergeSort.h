
#include"stdafx.h"
//[)[)
template<class T,template<class>class Cmp = Great>
void MerGe(T * arr, int start, int cir, int end)
{
	assert(arr);
	int newLen = end - cir;
	int * newArr = new int[newLen];
	//保存后半部分值
	for (int i = cir; i < end; ++i)
	{
		newArr[i-cir] = arr[i];
	}
	//将后半部分并入元数组
	while (newLen&&cir-start)
	{
		//if (newArr[newLen - 1]>arr[cir - 1])
		if (Cmp<T>()(newArr[newLen - 1], arr[cir - 1]))
		{
			arr[--end] = newArr[newLen - 1];
			newLen--;
		}
		else
		{
			arr[--end] = arr[cir - 1];
			cir--;
		}
	}
	//如果后半部分有剩余，那么直接加入前半部分
	//否则就不处理，因为本身就是在原数组中处理的
	if (newLen)
	{
		for (int i = 0; i < newLen; ++i)
		{
			arr[start] = newArr[i];
		}
	}
	delete[]newArr;
}
// 归并排序
template<class T,template<class> class Cmp = Great>
void MergeSort(T array[], int start, int end)
{
	if (start < end)
	{
		int i;
		i = (end + start) / 2;
		// 对前半部分进行排序
		MergeSort<T>(array, start, i);
		// 对后半部分进行排序
		MergeSort<T>(array, i + 1, end);
		// 合并前后两部分
		MerGe<T>(array, start, i, end);
	}
}

//归并算法的非递归实现方案
//①

//②
template<class T, template<class> class Cmp = Great>
void MergeSort2(T array[],size_t n)
{
	assert(array);
	int step = 2;
	while (step < n*2)
	{
		int start = 0;
		while (start+step/2 <n)
		{
			int end = start + step;
			if (end > n)
				end = n;
			MerGe<T>(array, start, start+step/2, end);
			start = end;
		}
		step *= 2;
	}
}

void TestMerge()
{
	//	MergeSort<int>(arr, 0, 10);
	int arr[10] = { 1, 4, 7, 5, 2, 3, 6, 8, 9, 0 };
		MergeSort2<int>(arr, 10);
		PrintArr<int>(arr, 10);
}