#pragma once

template<class V,class E>
class Graph
{
protected:
	V* _vArray;		//顶点数组
	size_t _size;	//顶点个数

	E** _eArray;	//二维数组

public:
	Graph(const V* vArray,const size_t size)
		:_size(size)
		, _vArray(new V[size])
	{
		//初始化顶点保存
		for (size_t i = 0; i < size; ++i)
		{
			_vArray[i] = vArray[i];
		}
		//初始化边结构
		_eArray = new E*[size];
		for (size_t i = 0; i < size; ++i)
		{
			_eArray[i] = new E[size]();
			memset(_eArray[i], 0, sizeof(E)*size);
		}
	}

	int FindIndexV(const V& v) const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_vArray[i] == v)
				return i;
		}
		return -1;
	}

	bool AddEdge1(const V& v1, const V&v2, const E& e)
	{
		int ind1 = FindIndexV(v1);
		int ind2 = FindIndexV(v2);

		if (ind1 != ind2&& ind1 != -1 && ind2 != -1)
		{
			_eArray[ind1][ind2] = e;
			return true;
		}
		return false;
	}

	bool AddEdge2(const V& v1, const V&v2, const E& e)
	{
		int ind1 = FindIndexV(v1);
		int ind2 = FindIndexV(v2);

		if (ind1 != ind2&& ind1 != -1 && ind2 != -1)
		{
			_eArray[ind1][ind2] = e;
			_eArray[ind2][ind1] = e;
			return true;
		}
		return false;
	}
	
	~Graph()
	{
		if (_vArray)
			delete[]_vArray;
		if (_eArray)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_eArray[i])
					delete[]_eArray[i];
			}
			delete[] _eArray;
		}
	}

	void Display()
	{
		cout << "顶点列表" << endl;
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _vArray[i] << " ";
		}
		cout << endl << "边显示" << endl;
		for (size_t i = 0; i < _size; ++i)
		{
			for (size_t j = 0; j < _size; ++j)
			{
				printf("%2d ", _eArray[i][j]);
			}
			cout << endl;
		}
	}
};

void test()
{
	int vArr[] = { 1,2,3,4,5,6 };
	Graph<int, int> gh(vArr, sizeof(vArr) / sizeof(vArr[0]));
	gh.AddEdge2(1, 2, 11);
	gh.AddEdge2(3, 2, 33);
	gh.AddEdge2(5, 2, 44);
	gh.AddEdge2(1, 6, 55);
	gh.AddEdge2(4, 6, 66);
	gh.Display();
}