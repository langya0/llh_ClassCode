
//#include"SeqList.h"
//
//void TestSeqList()
//{
//	int array[5] = { 0, 1, 2, 3, 4 };
//	SeqList S1(array, 5);
//	S1.Print();
//	SeqList s2;
//}

#include"Slist.h"

void TestSlist()
{
	int array[5] = { 0, 1, 2, 3, 4 };
	Slist S1(array, 5);
	Slist S2(S1);
	//S2.Print();

	int array1[5] = {  1,3, 2, 3, 3 };
	int array2[5] = { 6, 7, 8, 9, 10};

	Slist S3(array1, 5);
	S3.unique();
	//SlistNode* tmp = S3.Find(3);
	//S3.Erase(tmp);
	S3.Print();

	//Slist S4(array2,3);
	//S3 = S4;
	//S3.Print();


	//S2.Reverse();
	//S2.PopBack();
	//S2.PopFront();
	//
	//S2.PushBack(5);
	//S2.PushFront(6);
	//
	//S2.Print();
}

//#include"BidCirList.h"
//
//void Test_BidCirList()
//{
//	int array[6] = { 0, 1, 2, 3, 4, 5 };
//	BidCirList S1(array, 6);
//	//S1.PrintPrev();
//	//S1.PrintLate();
//
//	ListNode* fd = S1.Find(3);
//	S1.DelLate();
//	S1.DelLate(fd);
//
//	S1.PrintLate();
//
//	int arr[3]{11, 22, 33};
//	BidCirList S2;/*(arr,3);*/
//	//S2.PrintLate();
//	BidCirList S3 = S2 + S1;
//	S3.PrintLate();
//
//	S3 = S2;
//	S3.PrintLate();
//	
//	//S3.Destoty();
//	//S3.PrintLate();
//}

//void main()
//{
//	Test_BidCirList();
//
//	//TestSeqList();
//
//	//TestSlist();
//}


template<class T,class In = int,int Flag = 4>
void Cout(T a, In b = 4)
{
	cout << a << endl;
	cout << b << endl;
}

class base
{
public:
	int b;
};

class base1// :virtual public base
{
public:
	virtual void f()
	{
		cout << "base1:: f()"<< endl;
	}
	int b1;
};
class base2// :virtual public base
{
public:
	virtual void f()
	{
		cout << "base2:: f()" << endl;
	}
	int b2;
};

class D :public base1, public base2
{
public:
	void g()
	{
		cout << "D::g()" << endl;
	}
	int d;
};

//
//void main()
//{
//	D dd;
//
//	//cout << sizeof(dd) << endl;
//}


class b
{
public:
	virtual void f()
	{
		cout << "f" <<endl;
	}
	void d()
	{
		cout << "d" << endl;
	}
};

void main()
{
	cout << sizeof(b) << endl;
	b bb;
	bb.f();
}