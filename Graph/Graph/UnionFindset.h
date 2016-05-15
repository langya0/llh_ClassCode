#pragma once

class UnionFindSet
{
public:
    UnionFindSet(size_t size)
        :_arr(new int[size])
        ,_size(size)
    {
        memset(_arr, 0xff, size*sizeof(int));
    }

    int FindRoot(size_t index)
    {
        while (_arr[index]>=0)
        {
            index = _arr[index];
        }
        return index;
    }

    //合并root2到root1
    void Combine(int root1, int root2)
    {
        //找到两个根节点，将树由根进行合并
        root1 = FindRoot(root1);
        root2 = FindRoot(root2);
        if (root1 != root2)
        {
            _arr[root1] += _arr[root2];
            _arr[root2] = root1;
        }
    }

    void Display()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
    void DisplayUnion()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_arr[i] < 0)
            {
                cout << "根：i"   ;
                for (size_t j = i; j < _size; ++j)
                {
                    if (_arr[j]==i)
                    { 
                        cout << _arr[j] << " ";
                    }
                }
            }
        }
    }
    ~UnionFindSet()
    {
        if (_arr)
            delete[] _arr;
    }
protected:
    int *_arr;
    size_t _size;
};

void testU()
{
    UnionFindSet us(10);
    us.Combine(1, 2);
    us.Combine(1, 2);
    us.Combine(3, 2);
    us.Combine(1, 2);
    us.Combine(4, 2);
    us.Combine(1, 6);
    us.Display();
}