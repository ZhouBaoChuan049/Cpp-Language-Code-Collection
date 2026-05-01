#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//今日任务清单：
//枚举状态
//哈希储值结构√
//构造函数√
//插入查找和删除
//线性探测和二次探测
//inline unsigned long __stl_next_prime(unsigned long n)把这个CV过来装上
template<class K>
struct HashFunc
{
	size_t operator()(const K& key) { return (size_t)key; }
};
template<>
struct HashFunc<string>
{
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
namespace OpenAddress
{
	enum State { EXIST, EMPTY, DELETE };
	template <class K, class V>
	struct HashDate
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};
	template <class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_table(__stl_next_prime(0))
			, _n(0)
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
			if (Find(kv.first)!=INT_MAX)
				return false;
			Hash hash;
			if (_n * 10 / _table.size() >= 7)
			{
				HashTable<K, V> newtable;
				newtable._table.resize(__stl_next_prime(_table.size() + 1));
				for (auto& e : _table)
				{
					if (e._state == EXIST)
						newtable.Insert(e._kv);
				}
				_table.swap(newtable._table);
			}
			int hash0 = hash(kv.first) % _table.size();
			int hashi = hash0;
			int i = 1;
			int flag = 1;
			while (_table[hashi]._state == EXIST)
			{
				hashi = (hash0 + (i * i * flag)) % _table.size();
				if (hashi < 0)
					hashi += _table.size();
				if (flag == 1)
					flag = -1;
				else{
					++i;
					flag = 1;
				}
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			_n++;
			return true;
		}
		size_t Find(const K& key){
			Hash hash;
			size_t hash0 = hash(key) % _table.size();
			size_t hashi = hash0;
			int i = 1;
			int k = 0;
			int flag = 1;
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST &&
					_table[hashi]._kv.first == key)
				{
					cout << "Find" << endl;
					return hashi;
				}
				else{
					hashi = (hash0 + (i * i * flag)) % _table.size();
					if (hashi < 0)
						hashi += _table.size();
					if (flag == 1)
						flag = -1;
					else {
						++i;
						flag = 1;
					}
				}
				i++;
			}
			cout << "NoFind" << endl;
			return INT_MAX;
		}
		bool Erase(const K& key)
		{
			size_t hashi = Find(key);
			if (hashi == INT_MAX)
				return false;
			else
			{
				_table[hashi]._state = DELETE;
				return true;
			}
		}
	private:
		vector<HashDate<K, V>> _table;
		size_t _n = 0;
	};
}