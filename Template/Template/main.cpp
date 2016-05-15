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
	//Ŀ�ģ�����Լ��ĵ÷�
	void Get(int &A, int &B, int N, int *e, int *a,int re[])
	{
		//����
		int *pCurPer = &A;
		int curPer = 1;


		int  cur = 0;
		while (cur<N)
		{
			//���������ж��»غϵĸ�ֵǮ
			//if (Magic() && NextIsBetter())
			if (*pCurPer && a[cur+1]>a[cur])
			{
				(*pCurPer)--;
				GetNext(pCurPer, curPer, A, B);
				continue;
			}
			else
			{
				//��ȡ��������ȡ�÷֡�
				*pCurPer += e[cur];
				re[curPer] += a[cur];

				GetNext(pCurPer, curPer, A, B);
				cur++;
			}
			//ȡ��ǰλ�õ�ʯ�ӡ�
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

		//1������ǰ׺
		for (int i = 0; i <= n; i++)
		{
			
			string subS = s.substr(0, i);		//ǰ׺

			bool get = false;	//�Ƿ�����ظ���

			//�ж��Ƿ����ظ��ʡ�//Ҫ��֮һ��qq ��ǰ׺A���Գ�������
			for (int k = i-1; k >= i / 2; k--)
			{
				//��ǰ׺  i-1 ��֤
				string subsubS = subS.substr(0, k);
				
				//ǰ׺
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
	//1 ��2 ����
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
	//2 λ����
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
			//��1010&1001 = 1000
			//��1000&0111 = 0
			//��res = 2
			t &= (t - 1);
			res++;
		}
		return res;
	}
	unsigned int CountTBQT(int t)
	{
		//�����ض�����ֱ�Ӳ����Ҳ��������switch����������Ч�����⡣
		return countTable[t];
	}

	int UnEqual(unsigned char a,unsigned char b)
	{
		return CountTBQ(a^b);
		//func1��λ�Ƚ�
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
	//��׳������0�ĸ���
	//1��ý׳ˡ�
	//2��¼0���������ǳ�10 ����
	cout << "13:::" << res << endl;
	cout << "long :\t\t" << "��ռ�ֽ���" << sizeof(long long) << "���ֵ" <<dec<< (numeric_limits<long long>::max) << endl;


	//��׳������һ��һ��λ��
	//1��׳�
	//2�������
	int result = 1;
	int a = 4;
	for (int i = 1; i < a; i++)
	{
		result *= i;
	}
	unsigned int fl = 0x01;
	int count = 1;
	cout <<"�׳��ǣ�"<< result << endl;
	while (1)
	{
		if ( (result & fl))
		{
			cout <<a<<"�Ľ׳˵����һ��1 ��"<< count << endl;
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