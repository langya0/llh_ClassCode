
#include"Smart_ptr.h"
#include"SharePtr.h"
#include"Smart_array.h"
#include<boost\shared_ptr.hpp>

#include<boost\shared_array.hpp>

#include<boost\weak_ptr.hpp>

#include<assert.h>

class A
{
public:
	A()
		:_this(this)
	{}
	weak_ptr<A> _prev;
	weak_ptr<A> _next;
	weak_ptr<A> _this;
};
void main()
{
	shared_ptr<A>p1(new A);
	shared_ptr<A>p2(new A);
	assert(p1.use_count() == 1);
	assert(p2.use_count() == 1);

	p1->_next = p2;
	p2->_prev = p1;

	assert(p1.use_count() == 2);
	assert(p2.use_count() == 2);

	//TestShare();

	//Testt();
	//boost::shared_array<int> sp(new int);

	
	//int *p = new int[10];
	//delete[]p;
	//TestAuto_ptr();
	//TestScopedPtr();
	//TestSmartPtr();
	//TestScopedArray();
//	TestSharedArray();
	//f(Tb());
}

void TestWeak()
{
	shared_ptr<int >sp(new int(10));
	assert(sp.use_count() == 1);
	weak_ptr<int> wp(sp);
	assert(wp.use_count() == 1);

	if (!wp.expired())
	{
		shared_ptr<int> sp2 = wp.lock();
		*sp2 = 100;
		assert(wp.use_count() == 2);
	}
	cout << *sp << endl;
	assert(wp.use_count() == 1);
	sp.reset();
	assert(wp.expired());
	assert(!wp.lock());

}