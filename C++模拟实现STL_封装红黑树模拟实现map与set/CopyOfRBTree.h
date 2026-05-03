#pragma once
#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
enum Color 
{
	RED,
	BLACK
};
template <class T>
class RBTreeNode
{
public:
	T _Date;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Color _col;
	RBTreeNode(const T& pir)
		: _Date(pir)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};
template<class T,class Ptr ,class Ref>
class RBTreeIterator
{
public:
	using Node = RBTreeNode<T>;
	using Self = RBTreeIterator<T, Ptr, Ref>;
	RBTreeIterator(Node* node,Node* root)
		:_node(node)
		,_root(root)
	{}
	Ref operator*(){ return _node->_Date;}
	Ptr operator->(){ return &(_node->_Date);}
	bool operator==(const Self& s) { return _node == s._node; }//有时候想不出来的时候想想这玩意儿怎么用，谁和谁比较
	bool operator!=(const Self& s) { return _node != s._node; }
	Self operator++(){
		if (_node->_right){
			Node* cur = _node->_right;
			while (cur->_left)//这里可以不需要cur，是因为原则上：_node->_right让这棵树不可能为空。
				cur = cur->_left;
			_node = cur;
		}
		else if (_node->_right == nullptr){
			Node* Ancestor = _node->_parent;
			while (Ancestor && Ancestor->_right == _node){
				_node = Ancestor;
				Ancestor = _node->_parent;
			}
			_node = Ancestor;
		}
		return *this;//传递*this返回还是传递++后的指针返回？
	}
	Self operator--(){
		if (_node == nullptr){
			Node* cur = _root;
			while (cur&&cur->_right)
				cur = cur->_right;
			_node = cur;
		}
		else if(_node){
			if (_node->_left){
				Node* cur = _node->_left;
				while (cur->_right)
					cur = cur->_right;
				_node = cur;
			}
			else if (_node->_left == nullptr){
				Node* Ancestor = _node->_parent;
				while (Ancestor && Ancestor->_right == _node){
					_node = Ancestor;
					Ancestor = _node->_parent;
				}
				_node = Ancestor;//是否需要提前标记一下_node再找？
			}
		}
		return *this;//传递指针还是*this？
	}
private:
	Node* _node;
	Node* _root;
};
template <class K, class T,class Compare>
class RBTree
{
	using  Node = RBTreeNode<T>;
public:
	using Iterator = RBTreeIterator<T, T*, T&>;
	using ConstIterator = RBTreeIterator<T, const T*, const T&>;
	Iterator Begin()
	{
	    Node* cur = _root;
		while (cur&&cur->_left)//这里是容器为空的时候进行的工程防御
			cur = cur->_left;
		return Iterator(cur, _root);
	}
	Iterator End(){ return Iterator(nullptr, _root);}
	ConstIterator CBegin() const//忘记了这个const什么用
	{
		Node* cur = _root;
		while (cur&&cur->_left)
			cur = cur->_left;
		return ConstIterator(cur, _root);
	}
	ConstIterator CEnd() const{ return ConstIterator(nullptr,_root);}
	void RotateR(Node* cur) {
		Node* SubL = cur->_left;
		Node* SubLR = cur->_left->_right;
		Node* pParent = cur->_parent;
		if (cur == _root)
			_root = SubL;
		SubL->_right = cur;
		cur->_parent = SubL;
		if (SubLR)
			SubLR->_parent = cur;
		cur->_left = SubLR;
		SubL->_parent = pParent;
		if (pParent) {
			if (pParent->_left == cur)
				pParent->_left = SubL;
			else if (pParent->_right == cur)
				pParent->_right = SubL;
		}
	}
	void RotateL(Node* cur) {
		Node* SubR = cur->_right;
		Node* SubRL = cur->_right->_left;
		Node* pParent = cur->_parent;
		if (cur == _root)
			_root = SubR;
		SubR->_left = cur;
		cur->_parent = SubR;
		cur->_right = SubRL;
		if (SubRL)
			SubRL->_parent = cur;
		SubR->_parent = pParent;
		if (pParent) {
			if (pParent->_left == cur)
				pParent->_left = SubR;
			else if (pParent->_right == cur)
				pParent->_right = SubR;
		}
	}
	void RotateRL(Node* cur) {
		Node* SubR = cur->_right;
		Node* SubRL = cur->_right->_left;
		RotateR(SubR);
		RotateL(cur);
	}
	void RotateLR(Node* cur) {
		Node* SubL = cur->_left;
		Node* SubLR = cur->_left->_right;
		RotateL(SubL);
		RotateR(cur);
	}
	
	pair<Iterator,bool> Insert(const T& pir) {
		if (_root == nullptr) {
			_root = new Node(pir);
			_root->_col = BLACK;
			return { Iterator(_root,_root),true };
		}
		Compare _com;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (_com(cur->_Date) > _com(pir)) {//
				parent = cur;
				cur = cur->_left;
			}
			else if (_com(cur->_Date) < _com(pir)) {//
				parent = cur;
				cur = cur->_right;
			}
			else
				return {Iterator(cur,_root), false};
		}
		cur = new Node(pir);
		cur->_col = RED;
		cur->_parent = parent;
		Node* NewNode = cur;
		if (_com(parent->_Date) > _com(cur->_Date))//
			parent->_left = cur;
		else if (_com(parent->_Date) < _com(cur->_Date))//
			parent->_right = cur;
		while (parent && parent->_col == RED) {
			Node* grandpa = parent->_parent;
			if (grandpa->_left == parent) {
				Node* uncle = grandpa->_right;
				if (uncle && uncle->_col == RED) {
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandpa->_col = RED;
					cur = grandpa;
					parent = grandpa->_parent;
				}
				else if (uncle == nullptr || uncle->_col == BLACK) {
					if (parent->_left == cur) {
						RotateR(grandpa);
						grandpa->_col = RED;
						parent->_col = BLACK;
					}
					else if (parent->_right == cur) {
						RotateLR(grandpa);
						grandpa->_col = RED;
						cur->_col = BLACK;
					}
					break;
				}
				else assert(false);
			}
			else if (grandpa->_right == parent) {
				Node* uncle = grandpa->_left;
				if (uncle && uncle->_col == RED) {
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandpa->_col = RED;
					cur = grandpa;
					parent = grandpa->_parent;
				}
				else if (uncle == nullptr || uncle->_col == BLACK) {
					if (parent->_right == cur) {
						RotateL(grandpa);
						grandpa->_col = RED;
						parent->_col = BLACK;
					}
					else if (parent->_left == cur) {
						RotateRL(grandpa);
						grandpa->_col = RED;
						cur->_col = BLACK;
					}
					break;
				}
				else assert(false);
			}
			else assert(false);
		}
		_root->_col = BLACK;
		return { Iterator(NewNode,_root),true };
	}
	/*void Inorder() {
		inorder(_root);
		cout << endl;
	}*/
	int Size() {
		return size(_root);
	}
	int Height() {
		return height(_root);
	}
	/*Node* Find(const pair< K, T > pir) {
		Node* cur = _root;
		while (cur) {
			if (cur->_Date.first > pir.first) {
				cur = cur->_left;
			}
			else if (cur->_Date.first < pir.first) {
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;
	}*/
	/*bool IsBalanceTree() {
		if (_root->_col == RED) return false;
		int Referance = 0;
		Node* cur = _root;
		while (cur) {
			if (cur->_col == BLACK) Referance++;
			cur = cur->_left;
		}
		return check(_root, 0, Referance);
	}*/
private:
	/*bool check(const Node* cur, int BlackNum, int Referance) {
		if (cur == nullptr && BlackNum != Referance) return false;
		else return true;
		if (cur->_col == RED) {
			if (cur->_parent->_col == RED) {
				cout << "NodeArea:" << cur->_parent->_Date.first << "->" << cur->_Date.first << "HaveContinuousRedNode" << endl;
				return false;
			}
		}
		else if (cur->_col == BLACK) BlackNum++;
		return check(cur->_left, BlackNum, Referance) &&
			check(cur->_right, BlackNum, Referance);
	}*/
	int size(const Node* root) {
		if (root == nullptr) return 0;
		return size(root->_left) + size(root->_right) + 1;
	}
	int height(const Node* root) {
		if (root == nullptr) return 0;
		int leftheight = height(root->_left);
		int rightheight = height(root->_right);
		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}
	/*void inorder(const Node* root) {
		if (root == nullptr)
			return;
		inorder(root->_left);
		cout << "key: " << root->_Date.first << "Value: " << root->_Date.second << endl;
		inorder(root->_right);
	}*/
private:
	Node* _root = nullptr;
};