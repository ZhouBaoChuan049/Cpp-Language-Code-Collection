#pragma once
#include"CopyOfRBTree.h"
namespace MySet
{
	template <class K>
	class Set
	{
		struct Compare
		{
			const K& operator()(const K& key){ return key;}
		};
	public:
		typedef typename RBTree<K, const K, Compare>::Iterator iterator;
		typedef typename RBTree<K, const K, Compare>::ConstIterator const_iterator;
		iterator begin() { return tree.Begin(); }
		iterator end() { return tree.End(); }
		const_iterator begin() const { return tree.CBegin(); }
		const_iterator end() const { return tree.CEnd(); }
		pair<iterator, bool> insert(const K& key) { return tree.Insert(key); }
	private:
		RBTree< K, const K, Compare > tree;
	};
}