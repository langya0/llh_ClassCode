#pragma once
//邻接表实现图

template<class V, class E>
struct Edge
{
	Edge(size_t dst,size_t src, const E&e)
		:_wight(e)
        ,_dst(dst)
        ,_src(src)
		, _next(NULL)
	{}
	E _wight;       //权值，边比重
    size_t _dst;    //目的顶点下标
    size_t _src;    //源顶点下标
	struct Edge<V, E>* _next;
};

template<class V,class E>
class GraphList
{
protected:
	V* _vArr;               //顶点存储数组 
	size_t _size;
     
	Edge<V, E>** _eList;    //边存储指针数组

public:
	GraphList(const V* vArray, const size_t size)
		:_size(size)
		, _vArr(new V[size])
	{
		//初始化顶点保存
		for (size_t i = 0; i < size; ++i)
		{
			_vArr[i] = vArray[i];
		}
		//初始化边结构
		_eList = new Edge<V,E>*[size];
		memset(_eList, 0, sizeof(Edge<V, E>)*size);
	}

	int FindIndexV(const V& v) const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_vArr[i] == v)
				return i;
		}
		return -1;
	}

    //添加v1->v2的边
	void AddEdge2(const V& v1, const V&v2, const E& e)
	{
		int ind1 = FindIndexV(v1);

		Edge<V, E>* cur = new Edge<V, E>(v2,v1,e);
		cur->_next = _eList[ind1];
		_eList[ind1] = cur;
  	}

	void Display()const
	{
		cout << "顶点集合" << endl;
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _vArr[i] << " ";
		}
		cout << endl << "边表示" << endl;

		for (size_t i = 0; i < _size; ++i)
		{
			cout << "边"<<_vArr[i] << " ";
			Edge<V, E>* cur = _eList[i];
			while (cur)
			{
				cout << "[" << cur->_dst << "]" << cur->_wight << " ";
				cur = cur->_next;
			}
			cout <<"NULL"<< endl;
		}
		cout << endl;
	}



	~GraphList()
	{
        if (_vArr)
        {
            delete[]_vArr;
            _vArr = NULL;
        }
		if (_eList)
		{
			for (size_t i = 0; i < _size;++i)
			{
				while (_eList[i] != NULL)
				{
					Edge<V, E>* del = _eList[i];
					_eList[i] = del->_next;
					delete del;
                    del = NULL;
				}
			}
		}
	}
};

void testD()
{
	int vArr1[] = { 1,2,3,4,5,6 };
	GraphList<int, int> gh1(vArr1, sizeof(vArr1) / sizeof(vArr1[0]));

	gh1.AddEdge2(1, 2, 11);
	gh1.AddEdge2(3, 2, 33);
	gh1.AddEdge2(5, 2, 44);
	gh1.AddEdge2(1, 6, 55);
	gh1.AddEdge2(4, 6, 66);
	gh1.Display();

	char vArr2[] = { 'A','B','C','D','E','F' };
	GraphList<char, int> gh(vArr2, sizeof(vArr2) / sizeof(vArr2[0]));
	gh.AddEdge2('E', 'D', 11);
	gh.AddEdge2('A', 'B', 33);
	gh.AddEdge2('D', 'B', 44);
	gh.AddEdge2('A', 'C', 55);
	gh.AddEdge2('F','D', 66);
	gh.Display();
}