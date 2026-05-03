#pragma once
#include"CopyOfRBTree.h"
namespace MyMap
{
	template <class K,class V>
	class Map
	{
		struct Compare
		{
			const K& operator()(const pair<K,V>& node){ return node.first;}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, Compare>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, Compare>::ConstIterator const_iterator;
		iterator begin(){ return tree.Begin();}
		iterator end() { return tree.End(); }
		const_iterator cbegin()const { return tree.CBegin(); }
		const_iterator cend()const { return tree.CEnd(); }//为什么航哥这里的const迭代器要重载而不是写一个新的
		pair<iterator, bool> insert(const pair<K, V>& pir){ return tree.Insert(pir);}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert({ key,V() });
			return ret.first->second;//为什么？
		}
	private:
		RBTree< K, pair<const K, V>, Compare > tree;
	};
}