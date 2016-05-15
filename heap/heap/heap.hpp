#pragma once 
#include<iostream>
#include<vector>

using namespace std;

template<class T>
struct Big
{
	bool operator()(T x, T y)
	{
		return x > y;
	}
};
template<class T>
struct Sma
{
	bool operator()(T x, T y)
	{
		return x < y;
	}
};

template<class T,class Cmp>
class Heap
{
public:
	Heap()
	{}
	Heap(const T* arr, size_t size)
	{
		for (int i = 0; i < size; ++i)
		{
			_heap.push_back(arr[i]);
		}
		int root = (_heap.size() - 2) / 2;//找到第一个非叶子结点
		while (root>=0)
			//向下调整
			AdjustDown(root--);
	}

	void Push(T & t)
	{
		_heap.push_back(t);
		AdjustUp(_heap.size() - 1);
	}
	void pop()
	{
		if (_heap.size() == 0)
			return;
		if (_heap.size() <= 2)
		{
			swap(_heap[0], _heap[_heap.size() - 1]);
			_heap.pop_back();
		}
		else
		{
			swap(_heap[0], _heap[_heap.size() - 1]);
			_heap.pop_back();
			AdjustDown(0);
		}
	}
	bool IsEmpty()const
	{
		return _heap.size() == 0;
	}
	const T & top() const
	{
		if (_heap.size() != 0)
			return _heap[0];
		else
			throw exception("this is a bug");
	}
protected:
	void AdjustDown(int root)
	{
		//int child = root * 2 + 2 >= _heap.size() ? root * 2 + 1 : Cmp(_heap[root * 2 + 1], _heap[root * 2 + 2]) ? root * 2 + 1 : root * 2 + 2;
		while (root <= (_heap.size() - 2) / 2)
		{
			int child = root * 2 + 2 >= _heap.size() ? root * 2 + 1 : Cmp()(_heap[root * 2 + 1], _heap[root * 2 + 2]) ? root * 2 + 1 : root * 2 + 2;
			if (!Cmp()(_heap[root], _heap[child]))
			{
				swap(_heap[root], _heap[child]);
			}
			else
			{
				break;
			}
			root = child;
		}
	}

	void AdjustUp(int child)
	{
		while (child >= 1)
		{
			int root = (child - 1) / 2;
			if (!Cmp()(_heap[root], _heap[child]))
			{
				swap(_heap[root], _heap[child]);
			}
			child = root;
		}
	}
protected:
	vector<T> _heap;
};

//建堆的向下调整过程
template<class T, template<class> class Cmp>
void AdjustDown(T* arr, size_t end, int root)
{
	if (end <= 1)
		return;
	while (root <= (end - 2) / 2)
	{
		int child = root * 2 + 1;
		//找到
		if (child + 1 < end && Cmp<T>()(arr[child] ,arr[child+1]))
		{
			child++;
		}

		Cmp<T>()(arr[root] ,arr[child]) ? swap(arr[root], arr[child]):(1);
		root = child;
	}
}

//堆排定义，template<class> class  typeName 定义类模板依赖。调用处就不用传入类型
template<class T,template<class> class Cmp = Big>
void HeapSort(T *arr,size_t size)
{
	//建堆
	int root = (size - 2) / 2;
	while (root >= 0)
	{
		AdjustDown<T,Cmp>(arr, size, root);
		root--;
	}
	//排序
	int end = size - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown<T,Cmp>(arr, end, 0);
		end--;
	}
}

void TestHeapSort()
{
	int arr[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int arr1[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	HeapSort<int, Sma>(arr, 10);
	HeapSort<int, Big>(arr1, 10);
}

void test_heap()
{
	int arr[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	Heap<int, Sma<int> >hp1(arr, 10);
	int b = 3;
	hp1.Push(b);
	cout << "Over!" << endl;
	while (!hp1.IsEmpty())
	{
		cout << hp1.top() << " ";
		hp1.pop();
	}
	system("pause");
}

//求数组中的众数(众数个数大于总数的一半)
void Test(int *arr,size_t N)
{
	//
	int *left = arr;
	int *right = arr+1;
	//int arr[] = { 1, 2, 1, 3, 1, 2, 1, 1, 2, 2 };

//	int arr[] = { 2, 2, 3, 3, 3, 2, 2, 2, 5, 4 };
	while (right <= arr + N - 1)
	{
		if (*left == *right)
			right++;
		else
		{
			//right!= left
			//找到下一个left项
			if ((left + 1) != right)
			{
				int tmp = *left;
				++left;
				while (*left != tmp)
					++left;
				
				++right;
			}
			if (left-arr==right-left)
			//else//区间内排出干净了则
			{
				if (right == arr + N - 1)
				{
					break;
				}
					left = right + 1;
					right = left + 1;
			}
		}
	}
	cout << *left << endl;
}





#include<iostream>
using namespace std;



void Find(int *a, size_t size)
{
	int count = 0;
	int tmp;
	tmp = a[0];
	count++;
	for (int i = 1; i < size; ++i)
	{
		if (a[i] == tmp)
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count == 0)
		{
			tmp = a[i];
			count = 1;
		}
	}
	cout << tmp;
}

void test()
{
	int arr1[] = { 1, 2, 3, 5, 1, 2, 1, 1, 1, 5, 7, 1, 1 };
	Find(arr1, 13);
}

void TestForTest()
{
	int arr1[] = { 1, 1, 1, 3, 2, 2, 2, 2, 1, 1 };
	int arr2[] = { 1, 2, 1, 2, 1, 2, 1, 1, 2, 2 };
	//int arr[] = { 2, 2, 3, 2, 2, 2, 5, 4 };
		int arr[] = { 2, 2, 3, 3, 3, 2, 2, 2, 5,2, 4 };
	Test(arr, 11);
}

int result[2048] = { 0 };
void Mul(string num1, string num2)
{
	const char* str1 = num1.c_str();
	const char* str2 = num2.c_str();
	int len1 = num1.size();
	int len2 = num2.size();
	int rol = 0;		//进位偏差
	int resultLen = 0;	//保存最终结果长度，翻转的正确结果
	for (int i = len1 - 1; i >= 0;--i)
	{
		int begin = rol;
		for (int j = len2 - 1; j >= 0; --j)
		{
			int res = (str1[i] - '0') * (str2[j] - '0')+result[begin];
			result[begin] = res % 10;
			result[begin + 1] += res / 10;
			begin++;
			resultLen = begin-1;
		}
		rol++;
	}
	for (int i = 0; i <= resultLen / 2;++i)
	{
		swap(result[i], result[resultLen - i]);
	}
}
void TestMul()
{
	string s1("123123");
	string s2("456");
	Mul(s1, s2);
}

void GrayCode(int &x,const int Max,const int N)
{
	int tmp = x;
	if (x > Max)
	{
		return;
	}
	for (int i = N - 1; i >= 0; --i)
	{
		cout << ((x >> i)&1);
	}
	cout << endl;
	GrayCode(++x, Max,N);
}
void TestGray()
{
	int x = 0;
	int max = 31;
	int n = 5;
	GrayCode(x, max, n);
}