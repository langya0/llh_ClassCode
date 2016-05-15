//////分析
//////首先研究对象是ascill字母和"."组成。即输入合法性为[a-z][A-Z][.]
//////2改变行为：将两个连续的"."，替换为一个.统计最终替换次数
//////那么只需要统计连续多少个"."相邻，结果-1即可
////
////#include<iostream>
////using namespace std;
////#include<assert.h>
////
////int f(char *s, int index, char ch) //使得串中不出现连续两个"."的最小置换次数
////{
////	assert(s);
////	assert(index >= 0);
////	s[index - 1] = ch;	//替换
////	int ret = 0;
////	char* beg = s;
////	while (*beg != '\0')
////	{
////		if (*beg == '.' && (*(beg + 1) != '\0'))
////		{
////			if (*(beg + 1) == '.')
////			{
////				ret++;
////			}
////		}
////		beg++;
////	}
////	return ret;
////}
////int main()
////{
////	int n = 0;//个数
////	int m = 0;//次数
////
////	char buff[100];
////	//1 <= n, m <= 300000
////	while (cin >> n >> m)
////	{
////		while (n<1 || n>300000 || m<1 || m>300000)
////		{
////			cin >> n >> m;
////		}
////		for (int i = 0; i < n; ++i)
////		{
////			char c = getchar();
////			if (c >= 'a'&&c <= 'z'
////				|| c >= 'A'&&c <= 'Z'
////				|| c == '.')
////			{
////				buff[i] = c;
////			}
////		}
////		buff[n] = '\0';
////		int index = 0;
////		char c;
////		for (int i = 0; i< m; ++i)
////		{
////			cin >> index;
////			cin >> c;
////			cout << f(buff, index, c) << endl;
////		}
////
////	}
////	return 0;
////}
//
////素数确定以及查找
//#include<cmath>
//#include<iostream>
//using namespace std;
//bool IsPrime(const size_t n)
//{
//	//.1最基本的概念方式处理
//	/*1*********************
//	if(n<2)
//	return false;
//	for(int i = 2;i<n;++i)
//	{
//	if (n%i==0)
//	return false;
//	}
//	return true;
//	/***********************/
//	//.2排除偶数&利用平方&
//	/*2*********************
//	if(n < 2)
//	return false;
//	if(n==2)
//	return true;
//	for(int i = 3; i*i<=n;i+=2)
//	{
//		if(n%i==0)
//	{
//	return false;
//	}
//	}
//	return true;
//	/************************/
//	//3.利用素数表排除法     n%Prime!=0
//	if (n < 2)
//		return false;
//	if (n == 2)
//		return true;
//	//size_t ar[n / 2];
//	size_t *ar = new size_t[n / 2];
//	///////////////////////////////////////////
//	//int nMaxLen=static_cast<int> ((n/log(double(n)))*1.5);
//	int nMaxLen = int((n / log(double(n)))*1.5);
//	///////////////////////////////////////////
//	cout << nMaxLen << endl << endl;
//	size_t count = 0;
//	ar[count++] = 2;
//	for (int i = 3; i <= n; i += 2)
//	{
//		int flag = true;
//		for (int j = 0; ar[j] * ar[j] <= i; j++)
//		if (i%ar[j] == 0)
//		{
//			flag = false;
//			break;
//		}
//		if (flag)
//			ar[count++] = i;
//	}
//	cout << endl << n << "内所有素数共有 " << count << "个 :" << endl;;
//	for (int i = 0, _n = 1; i<count; ++i, ++_n)
//	{
//		cout << ar[i] << "  ";
//		if (_n % 10 == 0)
//			cout << endl;
//	}
//	cout << endl;
//	return true;
//}
//int main()
//{
//	IsPrime(100);
//	IsPrime(1000);
//}



