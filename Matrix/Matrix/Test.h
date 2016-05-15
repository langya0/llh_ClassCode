//ϡ�����
#pragma once
#include <vector>
template<class T>
class Trituple
{
public:
	Trituple(int row, int col, T& n)
		:_row(row)
		, _col(col)
		, _value(n)
	{}
	int _row;
	int _col;
	T _value;
};

template<class T>
class SparseMatrix//ϡ�����
{
public:
	SparseMatrix(T*a, const int m, const int n, T& invalid)///��������
		:_rowSize(m)
		, _colSize(n)
		, _invalid(invalid)
	{
		size_t index = 0;
		for (int i = 0; i < _rowSize; ++i)
		{
			for (int j = 0; j < _colSize; ++j)
			{
				if (a[i*n + j] != _invalid)
				{
					_array.push_back(*(new Trituple<T>(i, j, a[i*n + j])));
					//_array[index++] = (new Trituple<T>(i,j,a[i*n+j]));
				}
			}
		}
	}

	void Print()
	{
		size_t index = 0;
		for (int i = 0; i < _rowSize; ++i)
		{
			for (int j = 0; j < _colSize; ++j)
			{
				//if (_array[i*_colSize + j]._value != _invalid)
				if ((_array[index]._row == i)&&(_array[index]._col == j))
				{
					cout << _array[index++]._value << "->";
				}
				else
				{
					cout << _invalid<<" ->";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	//ת�÷������������д�С ֵ������Ԫ���ڲ�����ֵ. ��������vector��
	SparseMatrix<T> Transpose()
	{
		SparseMatrix<T> x(*this);
		::swap(x._rowSize, x._colSize);
		x._array.clear();
		int i = 0;
		for (int j = 0; j < _colSize; ++j)
		{
			i = 0;
			while (i < _array.size())
			{
				if (j == _array[i]._col)
				{
					//////////////////////////////////////////////////////////////////
					//Trituple<T> t(_array[i]._row, _array[i]._col, _array[i]._value);
					Trituple<T> t(_array[i]._col, _array[i]._row, _array[i]._value);
					x._array.push_back(t);
				}
				++i;
			}
		}
		return x;
	}
	SparseMatrix<T> FastTranspose()
	{
		//�٣����㲢����ÿһ���з�0Ԫ�ĸ�����
		//�ڣ���col���е�һ����0Ԫ�ھ����е���λ�á�
		//�ۣ��������ϣ����в�����������Ҹ���cpot�е�ֵ
		SparseMatrix<T> x(*this);
		x._colSize = _rowSize;
		x._rowSize = _colSize;
		x._invalid = _invalid;
		if (_array.size())
		{
			int* RowCount = new int[_colSize];    //����Ԫ����
			int* RowStart = new int[_colSize];    //����Ԫ����ʼλ��
			memset(RowCount, 0, sizeof(int)*_colSize);
			memset(RowStart, 0, sizeof(int)*_colSize);
			int index = 0;
			while (index < _array.size())  //һ�ε���O(n)
			{
				++RowCount[_array[index++]._col];
			}
			index = 1;
			while (index < _colSize)      //O(n)
			{
				RowStart[index] = RowStart[index - 1] + RowCount[index - 1];
				++index;
			}
			//ִ�п���ת��
			int i = 0;
			while (i < _array.size())  //���ε��� O(n)
			{
				int col = _array[i]._col;
				int start = RowStart[col];
				x._array[start]._row = _array[i]._col;
				x._array[start]._col = _array[i]._row;
				x._array[start]._value = _array[i]._value;
				++RowStart[col];
				i++;
			}
			delete[]RowCount;
			delete[]RowStart;
		}//if
		return x;
	}
	~SparseMatrix()
	{
	}
private:
	vector<Trituple<T> >  _array;
	size_t _rowSize;
	size_t _colSize;
	T _invalid;
};


class T :public SparseMatrix<int>
{

};