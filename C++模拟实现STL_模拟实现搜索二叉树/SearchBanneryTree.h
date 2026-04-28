#pragma once
#include<iostream>
using namespace std;
namespace key_value
{
	
	template <class K, class V>
	class SBTnode
	{
	public:
		K _key;
		V _value;
		SBTnode<K, V>* left;
		SBTnode<K, V>* right;
		SBTnode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, left(nullptr)
			, right(nullptr)
		{
		}
	};
	template <class K, class V>
	class SBTree
	{
		using Node = SBTnode<K, V>;
	public:
		void swap(SBTree& other)
		{
			std::swap(_root, other._root);
		}
		void Inorder()
		{
			inorder(_root);
			cout << endl;
		}
		void inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			inorder(root->left);
			cout << root->_key << " " << root->_value << endl;
			inorder(root->right);
		}
		SBTree() = default;
		SBTree(const SBTree& tree)
		{
			_root = Copy(tree._root);
		}
		Node* Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newnode = new Node(root->_key, root->_value);
			newnode->left = Copy(root->left);
			newnode->right = Copy(root->right);
			return newnode;
		}
		
		SBTree& operator= (const SBTree tree)
		{
			swap(tree);
			return *this;
		}
		~SBTree()
		{
			destory(_root);
			_root = nullptr;
		}
		void destory(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			destory(root->left);
			destory(root->right);
			delete(root);
		}
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					cur = cur->left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}
		bool Insert(const K& key, const V& value)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, value);
			if (parent->_key > key)
			{
				parent->left = cur;
			}
			else if (parent->_key < key)
			{
				parent->right = cur;
			}
			return true;
		}
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					if (cur->left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->right;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->right;
							}
							else if (parent->right == cur)
							{
								parent->right = cur->right;
							}
						}
					}
					else if (cur->right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->left;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->left;
							}
							else if (parent->right == cur)
							{
								parent->right = cur->left;
							}
						}
					}
					else
					{
						Node* replaceparent = cur;
						Node* replace = cur->right;
						while (replace->left)
						{
							replaceparent = replace;
							replace = replace->left;
						}
						cur->_key = replace->_key;
						if (replaceparent->left == replace)
						{
							replaceparent->left = replace->right;
						}
						else if (replaceparent->right == replace)
						{
							replaceparent->right = replace->right;
						}
						cur = replace;
					}
					delete (cur);
					return true;
				}
			}
			return false;
		}

	protected:
		Node* _root=nullptr;
	};
}