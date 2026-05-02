#pragma once
#include<iostream>
#include<vector>
using namespace std;
//今日任务清单;
//转整型仿函数和string特化√
//哈希桶的结构
//哈希桶的插入
namespace Separate_Chaining
{
	template<class K,class V>
	class HashBucketNode
	{
		using Node = HashBucketNode<K, V>;
	public:
		pair<K, V> _date;
		Node* _next;
		HashBucketNode(const pair<K,V> date)
			:_next(nullptr)
			,_date(date)
		{}
	};
	template <class K>
	class HashFunc
	{
	public:
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& key)
		{
			size_t sum = 0;
			string::const_iterator it = key.begin();
			while (it != key.end())
			{
				sum += (*it);
				sum *= 131;
				++it;
			}
			return sum;
		}
	};
	template<class K,class V,class Hash = HashFunc<K>>
	class HashBucket
	{
		using Node = HashBucketNode<K, V>;
	public:
		HashBucket()
			:_Table(4)
			,_n(0)
		{}
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
		bool Insert(const pair<K, V> kv)
		{
			if (_n == _Table.size())				//扩容
			{
				vector<Node*> tmp;
				tmp.resize(__stl_next_prime(_Table.size() + 1));
				for (int i=0;i<_Table.size();i++)
				{
					Node* cur=_Table[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = (cur->_date.first) % _Table.size();
						cur->_next = tmp[hashi];
						tmp[hashi] = cur;
						cur = next;
					}
					_Table[i] = nullptr;
				}
				_Table.swap(tmp);
			}
			size_t hashi = kv.first % _Table.size();
			Node* newnode = new Node(kv);
			newnode->_next = _Table[hashi];
			_Table[hashi] = newnode;
			_n++;
			return true;
		}

	private:
		vector<Node*> _Table;
		size_t _n;
	};
}