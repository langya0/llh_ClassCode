#pragma once
#include <string>
enum Status
{
	EXITS,
	DELETE,
	EMPTY,
};
static size_t BKDRHash(const char * str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313����
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

template<class K>
struct HashFuner
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template <>
struct HashFuner<string>
{
	size_t operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}
};
class inI
{
public:
	size_t operator()(size_t i)
	{
		return i;
	}
};

class inII
{
public:
	size_t operator()(size_t i)
	{
		return i*i;
	}
};

template<class K, class V, class HashFun = HashFuner<K>>
struct KeyValueNode
{
	KeyValueNode(const K& key, const V& Value)
	:_key(key)
	, _value(Value)
	{}	
	KeyValueNode()
	{}
	K _key;
	V _value;
};
template<class K, class V, class INMethod = inI>
class HashTable
{
	typedef KeyValueNode<K, V> KVnode;
public:
	HashTable()
		:_tables(NULL)
		, _size(0)
		, _capacity(0)
		, _status(NULL)
	{}
	HashTable(size_t capacity)
		:_tables(new KVnode[capacity])
		, _size(0)
		, _capacity(capacity)
		, _status(new Status[capacity])
	{
		for (size_t i = 0; i < capacity; ++i)
		{
			_status[i] = EMPTY;
		}
	}
	~HashTable()
	{
		if (_tables)
		delete[] _tables;
		_size = _capacity = 0;
		if (_status)
		delete[] _status;
	}
	bool Insert(const K&k, const V& v)
	{
		_checkCapacity();
		size_t index = HashKey(k);
		int i = 1;
		//���Ǵ���״̬�ɲ���
		//��Ϊ�����������ƱȽ�С���ԣ�һ�����ҵ�λ��
		while (_status[index] == EXITS)
		{
			if (_tables[index]._key == k)
				return false;
			index = Collision(index,i++);
		}
		_tables[index]._key = k;
		_tables[index]._value = v;
		_status[index] = EXITS;
		_size++;
		return true;
	}
	void Print()
	{
		for (int i = 0; i < _capacity; ++i)
		{
			if (_status[i] == EXITS)
			{
				cout << '[' << _tables[i]._key << "��" << _tables[i]._value << ']' << "   ";
			}
			else
				cout << "[]" << "   ";
		}
		cout << endl;
	}
protected:
	void _checkCapacity()
	{
		if (_size * 10 >= _capacity * 7)
		{
			HashTable<K, V> newH(_capacity*2);
			for (int i = 0; i < _capacity; ++i)
			{
				if (_status[i] == EXITS)
				{
					newH.Insert(_tables[i]._key, _tables[i]._value);
				}
			}
			Swap(newH);
			Print();
		}
	}
	void Swap(HashTable<K, V> &x)
	{
		swap(_tables, x._tables);
		swap(_size, x._size);
		swap(_status, x._status);
		swap(_capacity, x._capacity);
	}
	size_t HashKey(const K& key)
	{
		return HashFuner<K>()(key) % _capacity;
	}
	size_t Collision(size_t index, int i) //�����ͻ
	{
		return (index + (INMethod() (i) )) % _capacity; //���ÿ��ŵ�ַ���������̽��  
	}
protected:
	KVnode* _tables;
	size_t _size;
	size_t _capacity;
	Status* _status;
};