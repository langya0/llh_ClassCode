#include"JinRiToutiao.h"

int main()
{
	Test5();
	return 0;
}


////////#include<iostream>
////////using namespace std;
////////#include<assert.h>
////////#include<string>
////////class Transform {
////////public:
////////	string trans(string s, int n) {
////////		// write code here
////////		assert(n >= 1 && n <= 500);
////////		string ret;
////////		int finish = n;
////////		while (finish)
////////		{
////////			finish--;
////////			if (s[finish] >= 'A'&& s[finish] <= 'Z')
////////			{
////////				s[finish] = s[finish] - 'A' + 'a';
////////			}
////////			else if (s[finish] >= 'a'&& s[finish] <= 'z')
////////			{
////////				s[finish] = s[finish] - 'a' + 'A';
////////			}
////////
////////			if (s[finish] == ' ')
////////			{
////////				s[finish] = '\0';
////////				const char *str = s.c_str() + finish + 1;
////////				ret += str;
////////				ret += ' ';
////////			}
////////		}
////////		const char *str = s.c_str();
////////		ret += str;
////////		return ret;
////////	}
////////};
////////
////////int main()
////////{
////////	string s = "This is a sample";
////////	int a = 16;
////////	Transform ts;
////////	string ret = ts.trans(s, a);
////////	cout << ret << endl;
////////	system("pause");
////////	return 0;
////////}
//////
//////
//////
//////
////#include<iostream>
////#include<hash_map>
////#include<string>
////using namespace std;
////void main()
////{
////	//hash_map<int, string> Num;
////	char *Num[12] = 
////	{"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi","bai"};
////
////	int N;
////	while (cin >> N&& N>0 && N < 1000)
////	{
////		if (N>99)
////		{
////			//jibaijishiji
////			cout << Num[N / 100] << Num[11];	//百位一定存在
////			if (N % 100 != 0)
////			{
////				if ((N % 100) / 10 != 0)		//十位存在
////				{
////					cout << Num[(N % 100) / 10] << Num[10];
////					if ((N % 10) != 0)
////					{
////						cout << Num[N % 10] ;
////					}
////				}
////				else if (N % 10 != 0)
////				{
////					cout <<Num[0]<< Num[N % 10] ;
////				}
////			}
////			else
////				cout << endl;
////		}
////		else if (N > 9)
////		{
////			//jishiji
////			cout << Num[N / 10] << Num[10];
////			if (N % 10 != 0)
////			{
////				cout << Num[N % 10] ;
////			}
////		}
////		else
////		{
////			cout << Num[N];
////		}
////		cout << endl;
////	}
////}
////
////
//////
////////一个背包一旦不往里装东西，小萌就会缝上口不再用……
//////一个物品不装进去就扔掉
////
//////第一行：三个正整数N、T、M。N是物品的个数(1 <= N <= 20)，T是每个背包的容量体积(1 <= T <= 20)，M是背包个数(1 <= M <= 20)。
//////第二行：N个数，a1……an表示每个物品的体积，同时，小萌也是按这个顺序拿物品的。
//////
//////#include<iostream>
//////using namespace std;
//////int main()
//////{
//////	int N = 0;
//////	int T = 0;
//////	int M = 0;
//////	while (cin >> N >> T >> M
//////		&& 1 <= N&&N <= 20
//////		&& 1 <= T&&T <= 20
//////		&& 1 <= M&&M <= 20
//////		)
//////	{
//////		//5 5 2
//////		//4 3 4 2 1
//////		int * V = new int[N];
//////		for (int i = 0; i < N; ++i)
//////		{
//////			cin >> V[i];
//////		}
//////
//////		int ret = 0;//返回拿走个数
//////		//背包遍历
//////		int cur = 0;//当物品遍历位置
//////		int curV = 0;//
//////
//////		while (cur < N&&M) //物品有剩余
//////		{
//////			if (V[cur] + curV < T)//可放入
//////			{
//////				curV += V[cur];
//////				ret++;
//////			}
//////			else  //换包、更新当前包容量
//////			{
//////				M--;
//////				curV = 0;
//////			}
//////			cur++;
//////		}
//////		cout << ret << endl;
//////	}
//////	return 0;
//////}
//
//#pragma once
//#include<vector>
//#include<iostream>
//using namespace std;
//class Partition {
//public:
//	vector<int> getPartition(const vector<vector<int> >&land, int n, int m)
//	{
//		vector<int> result;
//		if (land.size() > 0)
//		{
//			int *cols = new int[land[0].size() + 1];
//			for (int i = 0; i <= land[0].size(); i++)
//			{
//				int left = 0;
//				for (int j = 0; j < i; j++)
//				{
//					for (int k = 0; k < land.size(); k++)
//					{
//						if (land[k][j] == 1)
//						{
//							left++;
//						}
//					}
//				}
//				int right = 0;
//				for (int j = i; j < land[0].size(); j++)
//				{
//					for (int k = 0; k < land.size(); k++)
//					{
//						if (land[k][j] == 0)
//						{
//							left++;
//						}
//					}
//				}
//				cols[i] = (left + right);
//			}
//
//			int Target = INT_MAX;
//			for (int i = 0; i <= land[0].size(); i++)
//			{
//				cout << cols[i] << "  ";
//				if (Target > cols[i])
//				{
//					Target = cols[i];
//					result.clear();
//					result.push_back(i);
//					result.push_back(i + 1);
//				}
//			}
//			cout << endl;
//
//		}
//		cout << "result = " << endl;
//		for (int i = 0; i < result.size(); i++)
//		{
//			cout << result[i] << "  ";
//		}
//		return result;
//	}
//};
///**
//vector<vector<int>> TestData = { {1,1,1,1},{0,0,0,0},{1,0,1,1} };
//Test.getPartition(TestData, 4, 3);
//*/
//
//#pragma once
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class LongestPath {
//	struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//
//public:
//	void Path(vector<int> &result, TreeNode * root, int & zeros, int & ones)
//	{
//		if (root == NULL)
//		{
//			zeros = 0;
//			ones = 0;
//			result.push_back(0);
//		}
//		else
//		{
//			int leftOnes = 0, leftZeros = 0;
//			Path(result, root->left, leftZeros, leftOnes);
//			int rightOnes = 0, rightZeros = 0;
//			Path(result, root->right, rightZeros, rightOnes);
//			if (root->val == 1)
//			{
//				ones = leftOnes > rightOnes ? leftOnes + 1 : rightOnes + 1;
//				zeros = 0;
//				result.push_back(leftOnes + rightOnes + 1);
//
//			}
//			else if (root->val == 0)
//			{
//				ones = 0;
//				zeros = leftZeros > rightZeros ? leftZeros + 1 : rightZeros + 1;
//				result.push_back(leftZeros + rightZeros + 1);
//			}
//		}
//	}
//	int findPath(TreeNode * root)
//	{
//		int ones = 0;
//		int zeros = 0;
//		vector<int> result;
//		Path(result, root, zeros, ones);
//		int maxD = -1;
//		for (int i = 0; i < result.size(); i++)
//		{
//			cout << result[i] << "  ";
//			if (maxD < result[i])
//				maxD = result[i];
//		}
//		return maxD;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> TestData = { { 1, 1, 1, 1 }, { 0, 0, 0, 0 }, { 1, 0, 1, 1 } };
//	Partition Test;
//	Test.getPartition(TestData, 4, 3);
//	getchar();
//}
//
