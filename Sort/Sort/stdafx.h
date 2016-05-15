//filename£º stdafx.h
#pragma once

#include<iostream>
using namespace std;

#include<assert.h>
template<class T>
struct Great
{
	bool operator()(const T&x, const T&y)
	{
		return x > y;
	}
};

template<class T>
void PrintArr(T *arr, size_t n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

