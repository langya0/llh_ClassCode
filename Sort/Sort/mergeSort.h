
#include"stdafx.h"
//[)[)
template<class T,template<class>class Cmp = Great>
void MerGe(T * arr, int start, int cir, int end)
{
	assert(arr);
	int newLen = end - cir;
	int * newArr = new int[newLen];
	//�����벿��ֵ
	for (int i = cir; i < end; ++i)
	{
		newArr[i-cir] = arr[i];
	}
	//����벿�ֲ���Ԫ����
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
	//�����벿����ʣ�࣬��ôֱ�Ӽ���ǰ�벿��
	//����Ͳ�������Ϊ���������ԭ�����д����
	if (newLen)
	{
		for (int i = 0; i < newLen; ++i)
		{
			arr[start] = newArr[i];
		}
	}
	delete[]newArr;
}
// �鲢����
template<class T,template<class> class Cmp = Great>
void MergeSort(T array[], int start, int end)
{
	if (start < end)
	{
		int i;
		i = (end + start) / 2;
		// ��ǰ�벿�ֽ�������
		MergeSort<T>(array, start, i);
		// �Ժ�벿�ֽ�������
		MergeSort<T>(array, i + 1, end);
		// �ϲ�ǰ��������
		MerGe<T>(array, start, i, end);
	}
}

//�鲢�㷨�ķǵݹ�ʵ�ַ���
//��

//��
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