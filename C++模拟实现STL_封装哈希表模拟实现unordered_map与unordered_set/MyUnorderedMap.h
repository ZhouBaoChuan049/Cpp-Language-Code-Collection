#pragma once
#include"CyOfHash.h"
using namespace Separate_Chaining;
namespace MyUnorderedMap
{
	template<class K,class V>
	class UnorderedMap
	{
	public:
		struct KeyofUnorderedMap
		{
			const K& operator()(const pair<K, V>& pir)
			{
				return pir.first;
			}
		};
		typedef typename HashBucket<K, pair<const K, V>, KeyofUnorderedMap>::Iterator iterator;
		typedef typename HashBucket<K, pair<const K, V>, KeyofUnorderedMap>::ConstIterator const_iterator;
		iterator begin() { return _hb.Begin(); }
		iterator end() { return _hb.End(); }
		const_iterator begin() const { return _hb.Begin(); }
		const_iterator end()const { return _hb.End(); }
		pair<iterator, bool>insert(const pair<K,V>& data) { return _hb.Insert(data); }
		bool erase(const K& key) { return _hb.Erase(key); }
		iterator find(const K& key) { return _hb.Find(); }
	private:
		HashBucket<K, pair<const K, V>, KeyofUnorderedMap> _hb;
	};
	void test_map1()
	{
		UnorderedMap<string, string> dict;
		dict.insert({ "sort", "64" });
		dict.insert({ "99", "string" });

		dict.insert({ "sort", "33" });
		dict.insert({ "left", "22" });
		dict.insert({ "right", "11" });

		for (auto& kv : dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;

		UnorderedMap<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			// 不能修改first，可以修改second
			//it->first += 'x';
			it->second += 'x';
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}