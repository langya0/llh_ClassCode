#ifndef _SMART_ARRAY_H
#define _SMART_ARRAY_H

#include"stdafx.h"
#include<boost\smart_ptr\shared_ptr.hpp>
#pragma warning(disable:4996)
template<class T>
class BaseDelet;


template<class T>
class Scoped_array
{
public:
	explicit Scoped_array(T* p = 0)
		:_array(p)
	{}
	~Scoped_array()
	{
		delete[]_array;
		_array = NULL;
	}

	void reset(T* p = 0)
	{
		delete[]_array;
		_array = p;
	}

	T& operator[](int i) 
	{
		return _array[i];
	}
	T* get()const
	{
		return _array;
	}

	operator bool()const
	{
		return _array != NULL;
	}
	template<class Y>
	void Swap(Scoped_array<Y> &b)
	{
		::swap(_array, b._array);
	}
public:
	T * _array;
};


class Test{
public:
	Test(int a = 0) :
		_a(a)
	{}
	int Get()
	{
		return _a;
	}
	int _a;
};

void TestScopedArray()
{
	cout << "\tTestScopedArray()" << endl << endl;
	Scoped_array<int> arP1(new int[10]);
	for (int i = 0; i < 10; i++)
	{
		arP1[i] = i + 1;
	}

	Scoped_array<Test> tp(new Test[10]);
	Test t;
	tp[0] = t;
	
	arP1.reset();
	if (arP1)
		cout << "arP1 not NULL" << endl;
	else
		cout << "arP1 NULL" <<endl;

	Scoped_array<int> sa(new int[10]);
	fill_n(&sa[0], 10, 5);
	sa[9] = sa[2] + sa[3];
	for (int i = 0; i < 10; i++)
	{
		cout << sa[i] << "-->";
	}
	cout << "Over" << endl;

	//sa.Swap(arP1);

	for (int i = 0; i < 10; i++)
	{
		cout << arP1[i] << "-->";
	}
}


template<class T,class D = BaseDelet<int> >
class SharedArray
{
private:
	void decream()
	{
		if (--(*_use_Count) == 0)
		{
			if (!_delet)
			{
				delete[] _ptr;
				delete[] _use_Count;
			}
			else
			{
				(*_delet)(_ptr);
			}
		}
	}

	void incream()
	{
		++(*_use_Count);
	}
public:
	explicit SharedArray(T*p = NULL)
		: _ptr(p)
		, _use_Count(new long(1))
		, _delet()
	{}
	SharedArray(T*p, D &d)
		: _ptr(p)
		, _use_Count(new long(1))
		, _delet(&d)
	{}
	~SharedArray()
	{
		decream();
	}

	SharedArray(SharedArray &r)
		:_ptr(r._ptr)
	{
		r.incream();
		_use_Count = r._use_Count;
	}

	SharedArray &operator = (SharedArray const &r)
	{
		if (this != &r)
		{
			decream();
			r.incream();
			_ptr = r._ptr;
			_use_Count = r._use_Count;
		}
	}

	//void reset(T*p = 0)
	//{
	//	decream();
	//	_ptr = p;
	//	_use_Count = 1;///////////////////////////////////
	//}
	template<class D>void reset(T *p, D d);

	T& operator[](int i)
	{
		return _ptr[i];
	}
	T* get() const
	{
		return _ptr;
	}

	bool unique()const
	{
		return *_use_Count == 1;
	}
	long use_count()const
	{
		return *_use_Count;
	}

	void Swap(SharedArray<T,D>& b)
	{
		::swap(b._ptr, _ptr);
		::swap(b._use_Count, _use_Count);
	}

private:
	T * _ptr;
	long *_use_Count;
//	void(*_delet)();
	D* _delet;
};

template<class T>
class BaseDelet
{
public:
	BaseDelet(T* ptr = NULL,bool use = false)
		:_use(use)
		, _ptr(ptr)
	{}
	virtual void operator()(T *ptr) 
	{
		cout << "BaseDelete()" << endl;
	};
	operator bool()
	{
		return _use;
	}
private:
	bool _use;
	T *_ptr;
};
template<class T>
class Delete:public BaseDelet<T>
{
public:
	Delete(T *ptr = NULL)
		:BaseDelet(ptr,true)
	{}
	void operator()(T *ptr)
	{
		delete ptr;

		cout << "TestDelete" << endl;
	}
};


void TestSharedArray()
{
	//int *p = new int[100];
	//SharedArray<int> sarrP1(p);
	//SharedArray<int> sarrP2 = sarrP1;
	SharedArray<int> sarrP3(new int[10], Delete<int>());
/*
	sarrP1[0] = 10;
	assert(sarrP2[0] == 10);*/
}

#endif
