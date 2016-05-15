#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

#include<vector>
class BitMap
{
public:
	BitMap()
	:_size(0)
	{}
	BitMap(int x)
		:_size(x)
	{
		int size = (x >> 5) + 1;
		_setv.resize(size);
		_setv.assign(size, 0);
	}
	//set pos 1
	bool set(int pos)
	{
		assert(pos <= _size&&pos >= 1);

		int index = pos % 32;
		if (_setv[pos / 32] & (0x1 << index - 1))
		{
			return false;
		}

		_setv[pos / 32] |= (0x1 << index - 1);
		return true;
	}
	//set pos 0
	bool reset(int pos)
	{
		assert(pos <= _size&&pos >= 1);

		int index = pos % 32;
		if (!(_setv[pos / 32] & (0x1 << index - 1)))
		{
			return false;
		}
		
		_setv[pos / 32] &= (~(0x1 << index - 1));
		return true;
	}
	bool operator==(const BitMap&s)const
	{
		if (_size != s._size)
			return false;
		for (int i = 0; i < _setv.size(); ++i)
		{
			if (_setv[i] != s._setv[i])
				return false;
		}
		return true;
	}
	size_t size()const 
	{
		return _size;
	}
	void PrintHex()
	{
		int index = _setv.size();
		for (int i = index - 1; i >= 0; --i)
		{
			printf("%0x", _setv[i]);
		}
		cout << endl;
	}
	void clear()
	{
		_setv.assign(_setv.size(), 0);
	}
	void PrintByte()
	{
		for (int i = _size; i > 0; --i)
		{
			if (i % 8 == 0)
				cout << " ";

			cout << (_setv[i / 32] & (1<<(i%32-1)));
		}
		cout << endl;
	}

	bool test(size_t pos)
	{
		assert(pos <= _size&&pos >= 1);
		return _setv[pos / 32] & (1 << ((pos % 32) - 1));
	}
private:
	vector<int> _setv;
	size_t _size;
};