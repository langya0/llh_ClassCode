#pragma once
#include<iostream>
using namespace std;
#include<vector>

template<class K>
class Hash
{
public:
	size_t operator()(K k)
	{
		return size_t(k);
	}
};

static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
	5, 97, 193, 389, 769,
	1543, 3079, 6151, 12289, 24593,
	49157, 98317, 196613, 393241, 786433,
	1572869, 3145739, 6291469, 12582917, 25165843,
	50331653, 100663319, 201326611, 402653189, 805306457,
	1610612741, 3221225473ul, 4294967291ul
};
inline unsigned long __stl_next_prime(unsigned long n)
{
	unsigned const long* first = __stl_prime_list;
	unsigned const long* last = __stl_prime_list + __stl_num_primes;
	while (first < last && *first <=
		n)
	{
		++first;
	}
	return first == last ? *(last - 1) : *first;
}
template<class K,class V>
struct __hashTableNode
{
	K _key;
	V _value;
	__hashTableNode<K, V> *_next;
	__hashTableNode(K &key, V& value, __hashTableNode<K, V>*next = NULL)
		:_key(key)
		, _value(value)
		, _next(next)
	{}
};
//template<class K, class V, class hashFunc >
//class hashTable;
//template<class K,class V,class hashFunc>
//class __hashTableIterator
//{
//public:
//	typedef __hashTableIterator<K, V, hashFunc> iterator;
//	typedef __hashTableNode<K, V> node;
//	typedef V value_type;
//	typedef V& reference;
//	typedef V* pointer;
//	typedef size_t size_type;
//
//	__hashTableIterator(node* c, hashTable *h)
//		:_cur(c)
//		, _ht(h)
//	{}
//	__hashTableIterator()
//	{}
//
//	reference operator*() const { return cur->val; }
//	pointer operator->() const { return &(operator*()); }
//	iterator& operator++();
//	iterator operator++(int);
//	bool operator==(const iterator& it) const { return cur == it.cur; }
//	bool operator!=(const iterator& it) const { return cur != it.cur; }
//protected:
//	node *_cur;
//	hashTable *_ht;
//};

template<class K, class V, class hashFunc = Hash<K> >
class hashTable
{
public:
	typedef V value_type;
	typedef V& reference;
	typedef V* pointer;
	typedef size_t size_type;
	//typedef __hashTableIterator<K, V, hashFunc> iterator;
	typedef __hashTableNode<K, V> node;
private:
	vector<__hashTableNode<K,V>*> _buckets;
	size_type _size;
public:
	hashTable()
		:_size(0)
	{}
	hashTable(const hashTable& ht)
	{
		_size = ht._size;
		for (size_t i = 0; i < ht._buckets.size(); ++i)
		{
			node* cur = ht._buckets[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
			}
		}
	}
	~hashTable()
	{
		clear();
	}
	bool Insert(K k, V v)
	{
		return _Insert(new node(k, v));
	}
	void Print()
	{
		for (int i = 0; i < _size; ++i)
		{
			node* cur = _buckets[i];
			while (cur)
			{
				cout << cur->_key << "->";
				cur = cur->_next;
			}
			cout <<"nul"<< endl;
		}
		cout << "Over!" << endl << endl;;
	}
	void clear()
	{
		for (size_type i = 0; i < _buckets.size(); ++i)
		{
			while (_buckets[i] != NULL)
			{
				node* tmp = _buckets[i];
				_buckets[i] = tmp->_next;
				delete tmp;
			}
		}
	}
	size_type size()
	{
		return _size;
	}
	size_type max_size()const
	{
		return _buckets.size();
	}
	bool IsEmpty()const
	{
		return _size == 0;
	}
	bool remove(const K& k)
	{
		size_type index = hash(k);
		node* cur = _buckets[index];
		while (cur)
		{
			if (cur->_key == k)
				break;
			cur = cur->_next;
		}
		if (cur == NULL)
			return false;
		//和第一个交换，然后删除第一个。
		swap(cur->_key, _buckets[index]->_key);
		swap(cur->_value, _buckets[index]->_value);
		node* rem = _buckets[index];
		_buckets[index] = rem->_next;
		delete rem;
		return true;
	}
	void Swap(hashTable& ht)
	{
		swap(_size, ht._size);
		_buckets.swap(ht._buckets);
	}
protected:
	size_type hash(K k)
	{
		return hashFunc()(k) % _buckets.size();
	}
	bool _Insert(node* newNode)
	{
		_checkCapacity();
		size_type index = hash(newNode->_key);
		node *cur = _buckets[index];
		while (cur)
		{
			if ((cur)->_key == newNode->_key)
				return false;
			cur=cur->_next;
		}
		newNode->_next = _buckets[index];
		_buckets[index] = newNode;
		++_size;
		return true;
	}
	void _checkCapacity()
	{
		if (_size == _buckets.size())
		{
			size_t oldSize = _size;
			size_type newCapacity = ::__stl_next_prime(oldSize);
			_buckets.resize(newCapacity);//直接原地进行原地扩容

			typedef node* NF;
			node** tmparr = new NF[oldSize];
			for (int i = 0; i < oldSize; ++i)
			{
				tmparr[i] = _buckets[i];
				_buckets[i] = NULL;
			}

			for (size_t i = 0; i < oldSize; ++i)
			{
				node *cur = tmparr[i];	//作为临时串，插入_buckets
				while (cur)
				{
					node * pre = cur;
					cur = cur->_next;
					_Insert(pre);
				}
			}
		}
	}
};
void Test()
{
	hashTable<int, int> ht;
	ht.Insert(1, 6);
	ht.Insert(6, 6);
	ht.Insert(11, 6);
	ht.Insert(2, 6);
	ht.Insert(7, 6);
	ht.remove(2);
	ht.Print();
	ht.Insert(6, 6);
	ht.Insert(7, 7);
	ht.Print();
}
