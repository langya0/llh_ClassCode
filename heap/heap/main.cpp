#include"heap.hpp"
//#include"Test.h"
//
//void test()
//{
//	int arr[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
//	Heap<int>hp1(arr, 9);
//	// 	cout << "Over!" << endl;
//	while (!hp1.IsEmpty())
//	{
//		cout << hp1.top() << " ";
//		hp1.pop();
//	}
//}
int main()
{
	//test();
	//TestHeapSort();
	//TestForTest();
	test();
	//TestMul();
	//TestGray();
	return 0;
}

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		//1,2,3,4
		//5,6,7,8
		//9,10,11,12
		int row = array.size();
		int line = array[0].size();
		for (int i = line - 1; i >= 0; --i)
		{
			for (int j = 0; j<row; ++j)
			{
				if (array[i][j] == target)
					return true;
				else if (array[i][j]> target)
					break;
			}
		}
		return false;
	}
};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		char *cur = str;
		int numSpace = 0;
		while (*cur!= '\0'){
			if (*cur == ' ')
				numSpace++;
			cur++;
		}
		int newLength = length + 2 * numSpace;
		char *ret = new char[newLength];
		cur = str[length - 1];
		while (newLength - 1){
			if (*cur == ' '){
				ret[newLength - 1] = '0';
				ret[newLength - 2] = '2';
				ret[newLength - 3] = '%';
				newLength -= 3;
				continue;
			}
			else{

				ret[newLength - 1] = *cur;
				cur--;
				newLength--;
			}
		}
	}
};