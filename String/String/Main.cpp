#include"String.h"

void TestOperator()
{
	String s1 = "helloS";
	String s2 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	String s3 = "worldS3 ";
	String s4 = "";
	cout << s3 << endl;
	cout << (s3 < s2) << endl;
	cout << (s3 > s2) << endl;
	cout << (s3 == s2) << endl;
	cout << (s3 != s2) << endl;
	cout << (s3 >= s2) << endl;
	cout << (s3 <= s2) << endl;
	cout << s2.size() << endl;
	cout << s3.size() << endl;
	cout << s4.empty() << endl;
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i] << "\t";
	}
	cout << endl;

	s3[4] = 'G';
	cout << s3 << endl;
}

void TestGlobFunc()
{
	String s1 = "helloS";
	String s2;
	String s3 = "worldS3 ";
	String s5("S5");
	cout << s5 << endl;
	
	s5 += (s3 + s2);
	char* st = "TestChar* ";
	cout << (s5 += st) << endl;

	getline(std::cin, s1);
	cout << s1.size() << endl;
	cout << s1 << endl;

	Swap(s1, s3);
	cout << s1 << endl;
	cout << s3 << endl;
}
void TestFind()
{
	String s1 = "this is a test in Hello world and Change world";
	int i = s1.Find("a");
	cout << s1[i+1] << endl;
	String s2 = s1.substr(i, 8);
	//cout << s1[i + 2];
	cout << i << endl;
	cout << s2 << endl;

	i = s1.rFind("a");
	cout << s1[i + 1] << endl;

}
void TestReplace()
{
	String base = "this is a test string.";
	String str2 = "n example";
	base.replace(4,5 , str2);
	cout << base << endl;
	base.front() = 'T';
	cout << base << endl;
	char buff[10];
	base.copy(buff, 6, 5);
	cout << buff << endl;
}

class a
{
public:
	a(int a,double b = 4.4)
	{}
private:
	double bb;
	int aa;
};
void main()
{
	a aa = 4;
	//TestOperator();
	//TestGlobFunc();

	//TestFind();
	TestReplace();
}