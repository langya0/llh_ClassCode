#ifndef _SHAREPTR_H
#define _SHAREPTR_H

template<class T>
class  SharedPtr
{
private:
	T *_ptr;
	long *_useCount;

	void decream()
	{
		if (--(*_useCount) == 0)
		{
			delete _ptr;
			_ptr = NULL;

			delete _useCount;
			_useCount = NULL;
		}
	}

	void incream()
	{
		++(*_useCount);
	}

public:
	explicit SharedPtr(T* p = NULL)
		: _ptr(p)
		, _useCount(new long (1))
	{}

	template<class Y, class D>
	explicit SharedPtr(Y* p, D d);

	~SharedPtr()
	{
		cout << "~SharedPtr();" << endl;
		decream();
	}

	SharedPtr(SharedPtr<T>&r)
		:_ptr(r._ptr)
		, _useCount(r._useCount)
	{
		r.incream();
		//*_useCount = *r._useCount;
	}
	SharedPtr&operator=(SharedPtr&r)
	{
		if (this != &r)
		{
			r.incream();

			this->decream();
			_ptr = r._ptr;
			_useCount = r._useCount;
		}
		return *this;
	}
	template<class Y>SharedPtr& operator=(AutoPtr<Y>&r)
	{
		decream();
		_ptr = r.release();
		_useCount = NULL;
	}

	void reset()
	{
		decream();
		_ptr = NULL;
		_useCount = NULL;
	}
	template<class Y>void reset(Y*p);
	template<class Y, class D>void reset(Y*p, D d);

	T &operator*()const
	{
		return *_ptr;
	}
	T* operator->()const
	{
		return _ptr;
	}
	T* Get()const
	{
		return _ptr;
	}

	bool unique()const
	{
		return _useCount == 1;
	}
	long useCount()const
	{
		return *_useCount;
	}
	operator bool()
	{
		return _ptr != NULL;
	}
	void Swap(SharedPtr &r)
	{
		::swap(_ptr, r._ptr);
		::swap(_useCount, r._useCount);
	}
};

void TestSmartPtr()
{
	cout << "TestSharedPtr()" << endl;

	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(new int(10));
	SharedPtr<int> sp3(sp2);

	cout << *sp1 << endl;

	SharedPtr<int> auP1(new int(10));
	SharedPtr<int> auP2;
	auP1 = auP2;
	SharedPtr<int> auP3;
	auP3 = auP2;

	if (auP3)
	{
		cout << *auP3 << endl;
	}
	SharedPtr<TestC> auT(new TestC);
	auT->a = 4;
	cout << auT->a << endl;
	auT->f();
}
#endif