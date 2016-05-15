//稀疏矩阵
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
class SparseMatrix//稀疏矩阵
{
public:
	SparseMatrix(T*a, const int m, const int n, T& invalid)///行序排列
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

	//转置方案：交换行列大小 值，交换元祖内部行列值. 重新排序vector；
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
		//①：计算并保存每一列中非0元的个数；
		//②：求col列中第一个非0元在矩阵中的行位置。
		//③：依据以上，进行插入操作，并且更新cpot中的值
		SparseMatrix<T> x(*this);
		x._colSize = _rowSize;
		x._rowSize = _colSize;
		x._invalid = _invalid;
		if (_array.size())
		{
			int* RowCount = new int[_colSize];    //列中元素数
			int* RowStart = new int[_colSize];    //列中元素起始位置
			memset(RowCount, 0, sizeof(int)*_colSize);
			memset(RowStart, 0, sizeof(int)*_colSize);
			int index = 0;
			while (index < _array.size())  //一次迭代O(n)
			{
				++RowCount[_array[index++]._col];
			}
			index = 1;
			while (index < _colSize)      //O(n)
			{
				RowStart[index] = RowStart[index - 1] + RowCount[index - 1];
				++index;
			}
			//执行快速转置
			int i = 0;
			while (i < _array.size())  //两次迭代 O(n)
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