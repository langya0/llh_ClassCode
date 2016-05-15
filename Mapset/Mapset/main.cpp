#include<iostream>
using namespace std;
#include"BitMap.h"
void main()
{
	BitMap s(13);
	BitMap s1(13);
	cout << "s==s1:" << (s == s1) << endl;
	cout << "s.size():" << s.size() << endl;
	cout << "s.set(1):" << s.set(1) << endl;
	cout << "s.set(4):" << s.set(4) << endl;
	cout << "s==s1:" << (s == s1) << endl;
	cout << "s.set(13):" << s.set(13) << endl;
	cout << "s.set(13):" << s.set(13) << endl;
	cout << "s.reset(1):" << s.reset(1) << endl;
	//s.set(10);
	//s.set(1);
	cout << "s.PrintHex:";
	s.PrintHex();
	cout << "s.PrintByte:";
	s.PrintByte();
	cout << "s.test(3):" << s.test(3) << endl;
	cout << "s.test(4):" << s.test(4) << endl;
	s.clear();
	s.PrintByte();
}