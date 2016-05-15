#include<iostream>
using namespace std;

template<class T>
class SymmetricMatrix  //Ñ¹Ëõ¾ØÕó£¨¶Ô³Æ£©
{
public:
	SymmetricMatrix(T * array, const size_t size)
		:m_array(new T[size*(size + 1) / 2])
		, m_size(size)
	{
		int ind = 0;
		for (int i = 0; i < size;++i)
		for (int j = 0; j < size; ++j)
		{
			if (i >= j)
			{
				m_array[ind++] = array[i*size + j];
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < m_size; ++i)
		{
			for (int j = 0; j < m_size; ++j)
			{
				if (i >= j)
				{
					cout << m_array[i*(i + 1) / 2 + j] << " ";
				}
				else
				{
					cout << m_array[j*(j + 1) / 2 + i] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	~SymmetricMatrix()
	{
		delete[]m_array;
	}

private:
	T* m_array;
	size_t m_size;
};




//
//void main()
//{
//	int arr[3][3] = { 
//		{1,0,1},
//		{0,1,0},
//		{ 1, 0, 1 },
//	};
//	SymmetricMatrix<int> m((int*)arr,3);
//	m.Print();
//
//	system("pause");
//}

#include"Test.h"

void main()
{
	int arr[3][3] = { 
		{ 1, 2, 3 },
		{ 4, 5, 6 }, 
		{ 7, 8, 9 },
	};	
	int inval = 0;
	::SparseMatrix<int> sp((int*)arr,3,3,inval);
	sp.Print();
	SparseMatrix<int> s = sp.Transpose();
	SparseMatrix<int> s1 = sp.FastTranspose();
	s.Print();
	s1.Print();
	system("pause");
}