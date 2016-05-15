//#include"hash.h"
//void main()
//{
//	Test();
//}
#include <iostream>
using namespace std;
#include "TestForXiannv.h"

void main()
{
	HashTable<string, string>ht1(3);
	ht1.Insert("a", "a");
	ht1.Insert("b", "a");
	ht1.Insert("c", "a");
	ht1.Insert("d", "a");
	ht1.Insert("d", "a");
	ht1.Print();

}
