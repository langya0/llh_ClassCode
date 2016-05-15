#include"String.h"
using namespace COW;

void Test_COPY_EPU()
{

	String S1("hellow     world!");
	String S2("hellow world");
	String S3;
	S3 = S2;
	String S4;
	S4 = S1;
	//少对多，少对少
	cout << "小内存赋值" << S3 << endl;
	cout << "小内存赋值" << S4 << endl;

	//多对多，多对少
	String S5("change             world");
	S5 = S1;
	cout << S5 << endl;
	S5 = S2;
	cout << S5 << endl;
	//多多且等
	String S6 = S1;
	S6 = S1;
	cout << S6 << endl;
}
void Test_Find_Erase()
{
	String S1("hellow     world!");
	String S2("hellow world");
	cout << S1.Find('l') << endl;
	cout << S2.Find('z') << endl;
	cout << S1.Find("low") << endl;
	char*p = NULL;
	cout << S2.Find(p) << endl;

	S2.Erase(4);
	S2.Erase(4, 3);
	cout << S2 << endl;
}

void Test_Push_Insert()
{
	String S1("hellow     world!");
	String S2("hellow   world");
	//S1.PushBack('l');
	//S1.PushBack('v');
	//S2.PushBack('l');
	//S2.PushBack('v');
	int pos = S1.Find('l');
	S1.Insert(pos,'v');
	S1.Insert(100, "lv");
	cout << S1 << endl;
	cout << S2 << endl;
	cout << S1[3] << endl;
	S1[3] = 'X';
	cout << S1 << endl;

}
void main()
{
	//Test_COPY_EPU();
	//Test_Find_Erase();
	Test_Push_Insert();
}