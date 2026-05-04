#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
namespace Separate_Chaining
{
	template<class T>
	class HashBucketNode
	{
		using Node = HashBucketNode;
	public:
		T _data;
		Node* _next;
		HashBucketNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};
	template <class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& str)
		{
			size_t sum = 0;
			for (auto e : str)
			{
				sum += e;
			}
			return sum;
		}
	};
	template<class K, class T, class KeyofT, class Hash>
	class HashBucket;
	template <class K, class T ,class Ptr,class Ref,class KeyofT,class Hash = HashFunc<K> >
	class HashBucketIterator
	{ 
		using _HB = HashBucket<K, T, KeyofT, Hash>;
		using _Node = HashBucketNode<T>;
		using _Self = HashBucketIterator<K, T, Ptr, Ref, KeyofT, Hash>;
	public:
		const _HB* _hb;
		_Node* _node;
		HashBucketIterator( _Node* node, _HB* hb )
			:_node(node)
			, _hb(hb)
		{}
		_Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				Hash hash;
				KeyofT kot;
				size_t hashi = (hash(kot(_node->_data))) % _hb->_Table.size();//告诉我现在我再哪个桶
				hashi++;
				while (hashi<_hb->_Table.size())
				{
					_node = _hb->_Table[hashi];
					if (_node)
						break;
					else hashi++;
				}
				if (hashi == _hb->_Table.size())
					_node = nullptr;//走到最后一格，设置成空 == end（）
			}
			return *this;
		}
		bool operator!=(const _Self& s){ return _node != s._node;}
		Ref operator* (){ return _node->_data;}
		Ptr operator->(){ return &(_node->_data);}
	};
	template<class K,class T,class KeyofT ,class Hash = HashFunc<K>>
	class HashBucket
	{
	public:
		template <class K, class T, class Ptr, class Ref, class KeyofT, class Hash >
		friend class HashBucketIterator;
		using Node = HashBucketNode<T>;
		using Iterator = HashBucketIterator<K, T, T*, T&, KeyofT, Hash>;
		using ConstIterator = HashBucketIterator<K, T, const T*, const T&, KeyofT, Hash>;
		HashBucket()
			:_Table(__stl_next_prime(0))
			,_N(0)
		{}
		~HashBucket()
		{
			//遍历删除所有的槽位上的结点，并把槽位置空
			for (int i = 0;i < _Table.size();i++)
			{
				Node* cur = _Table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_Table[i] = nullptr;
			}
		}
		inline unsigned long __stl_next_prime(unsigned long n)
		{
			// Note: assumes long is at least 32 bits.
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] = {
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};
			const unsigned long* first = __stl_prime_list;
			const unsigned long* last = __stl_prime_list + __stl_num_primes;
			const unsigned long* pos = lower_bound(first, last, n);
			return pos == last ? *(last - 1) : *pos;
		}
		Iterator Begin()
		{
			if (_N == 0)
				return End();
			//找到第一个有数据的桶，返回的应该是这个桶的第一个结点的迭代器
			for (int i = 0;i < _Table.size();i++)
			{
				Node* cur = _Table[i];
				if (cur) return {cur,this};
			}
			return End();
		}
		Iterator End() { return { nullptr,this }; }
		ConstIterator Begin()const
		{
			if (_N == 0)
				return End();
			//找到第一个有数据的桶，返回的应该是这个桶的第一个结点的迭代器
			for (int i = 0;i < _Table.size();i++)
			{
				Node* cur = _Table[i];
				if (cur) return { cur,this };
			}
			return End();
		}
		ConstIterator End()const { return { nullptr,this }; }
		pair<Iterator, bool> Insert(const T& data)
		{
			KeyofT kot;
			Hash hash;
			Iterator it = Find(kot(data));
			if (it!= End())
				return { it,false};
			if (_N == _Table.size())
			{
				vector<Node*> newtable;
				for (int i=0;i<_Table.size();i++)
				{
					Node* cur = _Table[i];
					while (cur)
					{
						Node* next = cur->_next;
						// 头插到新表
						size_t hashi = hash(kot(cur->_data)) % newtable.size();
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
					_Table[i] = nullptr;
				}
				_Table.swap(newtable);
			}
			size_t hashk = hash(kot(data)) % _Table.size();
			Node* newnode = new Node(data);
			newnode->_next = _Table[hashk];
			_Table[hashk] = newnode;
			++_N;
			return { Iterator(newnode,this),true };
		}//这儿肯定还有问题
		Iterator Find(const K& key)
		{
			//知道我要在哪个桶里面找。
			Hash hash;
			KeyofT kot;
			size_t hashi = hash(key) % _Table.size();
			Node* cur = _Table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)//找到了
				{
					return{ cur,this };
				}
				else cur = cur->_next;
			}
			return End();
		}
		bool Erase(const K& key)
		{
			Hash hash;
			KeyofT kot;
			size_t hashi = hash(key) % _Table.size();
			Node* cur = _Table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev==nullptr)
					{
						_Table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_N;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
	private:
		vector<Node*> _Table;
		size_t _N;
	};
}
