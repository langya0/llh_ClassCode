#include<iostream>
using namespace std;

template<class T>
class SeqList
{
public:
	SeqList()
		:_data(0)
		, _size(0)
		, _capacity(0)
	{}
	SeqList(const SeqList<T>&s)
		:_data(0)
		, _size(s._size)
		, _capacity(s._size)
	{}
	~SeqList()
	{
		if (_data)
		{
			delete[] _data;
		}
		_size = 0;
		_capacity = 0;
	}
protected:
	T* _data;
	size_t _size;
	size_t _capacity;
};

class A{
public:
	virtual A& f(){
		cout << "A::f" << endl;
		return A();
	}
};

class B:public A
{
	B& f(){
		cout << "B::f" << endl;
		return B();
	}
};

#include<iostream>
using namespace std;
#include<Windows.h>
struct {
	unsigned char a : 4;
	unsigned char b : 4;
} i;

#include<vector>
class GetT
{
public:
	//目的，最大化自己的得分
	void Get(int &A, int &B, int N, int *e, int *a,int re[])
	{
		//先手
		int *pCurPer = &A;
		int curPer = 1;


		int  cur = 0;
		while (cur<N)
		{
			//有能量且判定下回合的更值钱
			//if (Magic() && NextIsBetter())
			if (*pCurPer && a[cur+1]>a[cur])
			{
				(*pCurPer)--;
				GetNext(pCurPer, curPer, A, B);
				continue;
			}
			else
			{
				//获取能量，获取得分。
				*pCurPer += e[cur];
				re[curPer] += a[cur];

				GetNext(pCurPer, curPer, A, B);
				cur++;
			}
			//取当前位置的石子。
		}
	}
	void GetNext(int *&cur,int &curper,int &p,int &q)
	{
		curper = !curper;
		if (cur == &p)
		{
			cur = &q;
		}
		else
		{
			cur = &p;
		}
	}
};


void main()
{
	int A = 9;
	int B = 0;
	const int s = 7;
	int see[] = { 66, 2, 6, 2, 8, 4, 3 };
	int sea[] = { 7, 12, 65, 7, 4, 40, 15 };

	int re[] = {0,0};
	GetT get;

	get.Get(A, B, s, see, sea,re);
	cout << re[0] << "\t";
	cout << re[1] << endl;
}

#include<string>
class Periods {
public:
	long long getLongest(int n, string s) {
		// write code here
		long long	res = 0;

		//1求所有前缀
		for (int i = 0; i <= n; i++)
		{
			
			string subS = s.substr(0, i);		//前缀

			bool get = false;	//是否获得最长重复词

			//判断是否是重复词。//要求之一是qq 有前缀A所以长度限制
			for (int k = i-1; k >= i / 2; k--)
			{
				//真前缀  i-1 保证
				string subsubS = subS.substr(0, k);
				
				//前缀
				string supS = subsubS + subsubS;
				string tmp = supS.substr(0, subS.length());
				if (subS == tmp)
				{
					get = true;
					//cout << subS << ":::::" << "\t";
					//cout << subsubS << endl;
					res += subsubS.length();
				}
				else if (get == true)break;
			}
		}
		return res;
	}
};


class Test
{
public:
	//1 除2 运算
	unsigned int CountT(unsigned char t)
	{
		int res = 0;
		while (t)
		{
			if (t % 2 == 1)
				res++;
			t /= 2;
		}
		return res;
	}
	//2 位运算
	unsigned int CountTB(unsigned char t)
	{
		int res = 0;
		while (t)
		{
			res += t & 0x01;
			t >>= 1;
		}
		return res;
	}
	unsigned int CountTBQ(unsigned char t)
	{
		int res = 0;
		while (t)
		{
			cout << "Test" << endl;
			//eg t = a;     1010
			//①1010&1001 = 1000
			//②1000&0111 = 0
			//∴res = 2
			t &= (t - 1);
			res++;
		}
		return res;
	}
	unsigned int CountTBQT(int t)
	{
		//对于特定类型直接查表。。也可以利用switch。。。就是效率问题。
		return countTable[t];
	}

	int UnEqual(unsigned char a,unsigned char b)
	{
		return CountTBQ(a^b);
		//func1按位比较
		int res = 0;
		while (a || b)
		{
			if ((a & 0x01) != (b & 0x01))
			{
				res++;
			}
			a >>= 1;
			b >>= 1;
		}
		return res;
	}
private:
	static int countTable[256];


};
int Test::countTable[256]
{
	0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3,
		3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3,
		4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
		3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3,
		4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6,
		6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4,
		5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3,
		4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4,
		4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6,
		7, 6, 7, 7, 8
};

void T()
{
	Periods per;
	string s1 = "babababa";
	cout << per.getLongest(8, s1) << endl;

	s1 = "baaaba";
	cout << per.getLongest(6, s1) << endl;

	s1 = "babababaa";
	cout << per.getLongest(9, s1) << endl;

	s1 = "";
	cout << per.getLongest(0, s1) << endl;
	
	Test t;
	t.CountTBQ(0xa1);

	cout <<"t.UnEqual(4, 5) "<< t.UnEqual(110,7) << endl;

	long long res = 1;
	for (long long i = 1; i <= 20; i++)
	{
		res *= i;
	}
	//求阶乘中最后0的个数
	//1求得阶乘。
	//2记录0个数。就是除10 操作
	cout << "13:::" << res << endl;
	cout << "long :\t\t" << "所占字节数" << sizeof(long long) << "最大值" <<dec<< (numeric_limits<long long>::max) << endl;


	//求阶乘中最后一个一的位置
	//1求阶乘
	//2求该数字
	int result = 1;
	int a = 4;
	for (int i = 1; i < a; i++)
	{
		result *= i;
	}
	unsigned int fl = 0x01;
	int count = 1;
	cout <<"阶乘是："<< result << endl;
	while (1)
	{
		if ( (result & fl))
		{
			cout <<a<<"的阶乘的最后一个1 在"<< count << endl;
			break;
		}
		fl <<= 1;
		count++;
	}


	int ret = 0;
	int i;
	for (i = 1; i <= 125; i++)
	{
		int j = i;
		while (j % 5 == 0)
		{
			ret++;
			j /= 5;
		}
	}

	cout << 125 << "dsfsdfs" << ret << endl;
}   