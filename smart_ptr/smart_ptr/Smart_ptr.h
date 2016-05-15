#ifndef _SMART_PTR_H
#define _SMART_PTR_H
#include"stdafx.h"
/*
	Auto_ptr:自动释放
	Scoped_ptr:守卫指针->专一对待
	Shared_ptr:共享类型
*/

template<class T>
class AutoPtr
{
public:
	AutoPtr(T*ptr = NULL)
		:_ptr(ptr)
	{}

	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	~AutoPtr()
	{
		delete _ptr;
	}

	AutoPtr<T>& operator=(AutoPtr<T>&ap)
	{
		if (this != &ap)
		{
			delete _ptr;
			_ptr = NULL;
			::swap(_ptr, ap._ptr);
		}
		return *this;
	}

	T& operator	*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}	

	operator bool()
	{
		return _ptr != NULL;
	}
	//实现资源所有权释放
	T* release()
	{
		T* ret = _ptr;
		_ptr = NULL;
		return ret;
	}
private:
	T*_ptr;
};

class TestC{
public:
	int a;
	void f()
	{
		cout << "TestC::f()" << endl;
	}
};

void TestAuto_ptr()
{
	AutoPtr<int> auP1 = new int(10);
	if (auP1)
	{
		cout << "test" << endl;
	}

	cout << *auP1 << endl;

	AutoPtr<int> auP2 = auP1;
	AutoPtr<int> auP3;
	auP3 = auP2;
	//cout << *auP1 << endl;
	//cout << *auP2 << endl;
	cout << *auP3 << endl;

	AutoPtr<TestC> auT(new TestC);
	auT->a = 4;
	cout << auT->a << endl;
	auT->f();
}

template<class T>
class ScopedPtr
{
public:
	explicit ScopedPtr(T*ptr = NULL)
		:_ptr(ptr)
	{}

	explicit ScopedPtr(AutoPtr<T> p)
		:_ptr(p.release())
	{}

	T& operator*()const
	{
		return *_ptr;
	}
	T* operator->()const
	{
		return _ptr;
	}
	~ScopedPtr()
	{
		delete _ptr;
	}

	T* Get()
	{
		return _ptr;
	}

	void Swap(ScopedPtr &b)
	{
		::swap(_ptr, b._ptr);
	}

	operator bool()
	{
		return _ptr != NULL;
	}

	void reset();	//删除就得空间，重新设置指向
private:
	ScopedPtr(const ScopedPtr&);
	ScopedPtr&operator=(const ScopedPtr&);
	bool operator==(const ScopedPtr)const;
	bool operator!=(const ScopedPtr)const;
	T*_ptr;
};



template<class T>
class ScopedPtr<T[]>
{
public:
	explicit ScopedPtr(T*ptr = NULL)
		:_ptr(ptr)
	{}

	explicit ScopedPtr(AutoPtr<T> p)
		:_ptr(p.release())
	{}

	T& operator*()const
	{
		return *_ptr;
	}
	T* operator->()const
	{
		return _ptr;
	}
	~ScopedPtr()
	{
		delete []_ptr;
	}

	T* Get()
	{
		return _ptr;
	}

	void Swap(ScopedPtr &b)
	{
		::swap(_ptr, b._ptr);
	}

	operator bool()
	{
		return _ptr != NULL;
	}

	void reset();	//删除就得空间，重新设置指向
private:
	ScopedPtr(const ScopedPtr&);
	ScopedPtr&operator=(const ScopedPtr&);
	bool operator==(const ScopedPtr)const;
	bool operator!=(const ScopedPtr)const;
	T*_ptr;
};

void Testt()
{
	ScopedPtr<int[]> sp(new int[10]);

}

void TestScopedPtr()
{
	//不能使用Sp1 = new int；因为没有拷贝构造函数可用，且构造函数声明为明确指定的  explicit
	ScopedPtr<int> Sp1(new int(10));
	ScopedPtr<int> Sp2(new int(20));
	ScopedPtr<TestC>Sp3(new TestC);

	cout << *Sp1 << endl;
	Sp3->a = 4;
	Sp3->f();
	
	AutoPtr<int> AuP(new int(4));
	ScopedPtr<int> Sp(AuP);

	cout << *Sp << endl;
}

#endif