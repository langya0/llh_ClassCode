#include<iostream>
#include<string>
using namespace std;

//���룺һ������  n��   n�У�ÿ�г��Ȳ�����12.n������50�������ٴ���һ���ַ��������κ��ַ���������ĸ
#include<hash_map>
void Test2()
{
	int n = 0;
	int ret = 0;
	
	while (cin >> n&& n > 0 && n <= 50)
	{
		//897+978 = 1875;
		char buff[13];
		cin >> buff;
		string str = buff;
	}
}
void Test5()
{
	int x = 0;
	int k = 0;
	while (cin >> x >> k
		&&x > 0 && k > 0
		&& x < 2000000000
		&& k < 2000000000)
	{
		//x+y = x|y
		int y = 0;
		while (k)
		{
			++y;
			if (x + y == (x | y))
			{
				k--;
			}
		}
		cout << y << endl;
	}
}
#include<string>
int Test4()
{
	int n = 0;
	int k = 0;
	while (cin >> n >> k
		&&n > 0 && n<9
		&& k>0 && k < 201)
	{
		char buff[21];
		cin >> buff;
		string str = buff;
		for (int i = 0; i < str.size(); ++i)
		{
			if (!(str[i] >= 'A'&&str[i] <= 'Z'))//�������
				return 0;
		}

	}
}