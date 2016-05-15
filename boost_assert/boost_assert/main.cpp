//#include<iostream>
//using namespace std;
//
//#define BOOST_ENABLE_ASSERT_HANDLER
//#include<boost\assert.hpp>
//#include<assert.h>
//#include<boost\static_assert.hpp>
//namespace boost
//{
//	void assertion_failed(char const * expr, char const * funcion, char const * file, long line)
//	{
//		cout << "this is a test while assertion_failed()" << endl;
//		assert(true == 1);
//	}
//}
//
//namespace Test
//{
//	class Test
//	{
//		BOOST_STATIC_ASSERT(sizeof(int) == 4);	//����int��СΪ4   ������
//	public:
//		void f()
//		{
//			assert(true == 1);
//		}
//	};
//	BOOST_STATIC_ASSERT(sizeof(Test) == 1);	//�������СΪ1		�����ռ���
//}
//
//
//#include<boost\test\minimal.hpp>
//#include<boost\format.hpp> 
//int test_main(int argc, char* argv[])
//{
//	using namespace boost;
//	format fmt("%d-%d");
//
//	BOOST_CHECK(fmt.size() == 0);
//	fmt % 12 % 34;
//	BOOST_REQUIRE(fmt.str() == "12-34");
//
//	BOOST_ERROR("��ʾһ��������Ϣ");
//	fmt.clear();
//	fmt % 12;
//	try
//	{
//		cout << fmt;
//	}
//	catch (...)
//	{
//		BOOST_FAIL("�������󣬲�����ֹ");
//	}
//	return 0;
//}
//
//void t()
//{
//	BOOST_ASSERT(true == 1&&"true  is not 1");
//	BOOST_STATIC_ASSERT(true == 1);
//	true != 1;
//}


//#include<boost\test\unit_test.hpp>
#include<stdio.h>
#include<iostream>
using namespace std;
void Swap(int &a, int &b)
{
	b = a^b;
	a = a^b;
	b = a^b;
}
#define Uint 4u
#include<typeinfo>
int All = 0;
int add(int a, int b)
{
	int aa[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 100000000; ++i)
		cout << aa[i];
		
	return 1;
	
}
class Singleton
{
protected:
	Singleton(){}
public:
	static Singleton *Instance()
	{
		//ͬ������ʵ�ֶ��߳�û����
		{
			if (_instance == NULL)
			{
				_instance = new Singleton;
				return _instance;
			}
			else
			{
				cout << "Already has Instance!" << endl;
				return _instance;
			}
		}
	}
protected:
	static Singleton* _instance;
};
Singleton* Singleton::_instance = NULL;
void Test()
{
	Singleton *S1 = Singleton::Instance();
	Singleton *S2 = Singleton::Instance();

}

/*length Ϊ�ַ������������*/
void ReplaceBlank(char str[], int length)
{
	//1��ڼ��
	if (str == NULL || length <= 0)
	{
		return;
	}
	int originalLength = 0;
	int numberBlank = 0;
	int i = 0;
	while (*(str + i) != '\0')
	{
		++originalLength;
		if (*(str + i) == ' ')
		{
			++numberBlank;
		}
		++i;
	}

	//�滻��ĳ���
	int newLength = originalLength + numberBlank * 2;
	if (newLength > length)
	{
		return;
	}
	int indexOfNew = newLength;
	int indexOfOrig = originalLength;
	while (indexOfOrig >= 0 && indexOfNew > indexOfOrig)
	{
		if (str[indexOfOrig] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOrig];
		}
		--indexOfOrig;
	}
}
#include<assert.h>
void Testtt()
{
	char str[100] = "hello world lang";
	ReplaceBlank(str, 100);
	cout << str << endl;
	char newstr[] = "hello%20world%20lang";
	assert(!strcmp(str, newstr));


	char str2[100] = "helloworldlang";
	ReplaceBlank(str2, 100);
	cout << str << endl;
	char newstr2[] = "helloworldlang";
	assert(!strcmp(str2, newstr2));

	char str3[100] = "hello  world lang";
	ReplaceBlank(str3, 100);
	cout << str3 << endl;
	char newstr3[] = "hello%20%20world%20lang";
	assert(!strcmp(str3, newstr3));

	char str1[10] = "";
	ReplaceBlank(str1, 10);
	assert(!strcmp(str1, ""));
}

struct BinaryTreeNode
{
	BinaryTreeNode(int Value=0)
	: m_nValue(Value)
	, m_pLeft(0)
	, m_pRight(0)
	{

	}
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode*ConstructCore(int *startPreorder, int * endPreorder,
	int *startInorder, int *endInorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length < 0)
		return NULL;
	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

BinaryTreeNode*ConstructCore(int *startPreorder, int * endPreorder,
	int *startInorder, int *endInorder)
{
	//ȷ��������
	int rootVlaue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootVlaue;

	//���ǰ��ֻ��һ����
	if (startPreorder == endPreorder)
	{
		//��������Ҳֻ��һ����������ǰ�е�ֵ���
		if (startInorder == endInorder&& *startInorder == *startPreorder)
			return root;
		else
			throw std::exception("Invalid Index");
	}

	//������������Ҹ��ڵ��ֵ
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder&&(*rootInorder) != rootVlaue)
		++rootInorder;

	//�������ĸ��������β��˵���������һ����Ҷ�ӽ�㣬ֵ����ȷ�˳�
	if (rootInorder==endInorder&&*rootInorder!=rootVlaue)
		throw std::exception("Invalid Index.");

	//��������Χ
	int leftLength = rootInorder - startInorder;
	int*leftPreOrderEnd = startPreorder + leftLength;

	cout << leftLength << endl;
	cout << startInorder<< endl;
	cout << rootInorder<< endl;
	if (leftLength > 0)
	{
		//����������
		cout << "����������" << endl;
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreOrderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength<endPreorder-startPreorder)
	{
		cout << "����������"<<endl;
		root->m_pRight = ConstructCore(leftPreOrderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

void Show(BinaryTreeNode*root)
{
	if (root == NULL)
		return;
	Show(root->m_pLeft);
	cout << "-->" <<root->m_nValue << endl;
	Show(root->m_pRight);
}

void Print(BinaryTreeNode*start, int n)
{
	if (start == NULL){
		for (int i = 0; i<n; i++){
			cout << "   ";
		}
		cout << "NULL" << endl;
		return;
	}
	Print(start->m_pRight, n + 1); //print the right subtree

	for (int i = 0; i<n; i++){ //print blanks with the height of the node
		cout << "   ";
	}
	if (n >= 0){
		cout << start->m_nValue << "-->" << endl;//print the node
	}
	Print(start->m_pLeft, n + 1); //print the left subtree
}
void main()
{
	int preTree[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inTree[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode* root = Construct(preTree, inTree, 8);
	Print(root, 3);
}

int test()
{
	int a = 44, b = 32;
	Swap(a,b);
	cout << a << endl << b << endl;
	int aa = 44;
	cout << Uint << endl;
	int aaa = 4;
	cout << typeid(Uint).name() << endl;
	cout << typeid(aaa).name() << endl;
	char c = -4;
	cout << int((unsigned char(c))) << endl;
	return 0;
}
