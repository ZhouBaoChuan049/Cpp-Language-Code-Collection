#pragma once
#include"CyOfHash.h"
using namespace Separate_Chaining;
namespace MyUnorderedSet
{
	template<class K>
	class UnorderedSet
	{
	public:
		struct KeyofUnorderedSet
		{
			const K& operator()(const K& pir)
			{
				return pir;
			}
		};
		typedef typename HashBucket<K, const K, KeyofUnorderedSet>::Iterator iterator;
		typedef typename HashBucket<K, const K, KeyofUnorderedSet>::ConstIterator const_iterator;
		iterator begin() { return _hb.Begin(); }
		iterator end() { return _hb.End(); }
		const_iterator begin() const { return _hb.Begin(); }
		const_iterator end()const { return _hb.End(); }
		pair<iterator, bool>insert(const K& data) { return _hb.Insert(data); }
		bool erase(const K& key) { return _hb.Erase(key); }
		iterator find(const K& key) { return _hb.Find(); }
	private:
		HashBucket<K, pair<const K, V>, KeyofUnorderedSet> _hb;
	};
}