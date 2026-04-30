#pragma once
#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
enum Color{
	RED,
	BLACK
};
template <class K,class V>
class RBTreeNode
{
public:
	pair<K, V> _Date;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _col;
	RBTreeNode(const pair<K,V>& pir)
		:_Date(pir)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
};
template <class K, class V>
class RBTree
{
	using  Node = RBTreeNode<K, V>;
public:
	void RotateR( Node* cur){
		Node* SubL = cur->_left;
		Node* SubLR =cur->_left->_right;
		Node* pParent = cur->_parent;
		if (cur == _root) 
			_root = SubL;
		SubL->_right = cur;
		cur->_parent = SubL;
		if(SubLR)
			SubLR->_parent = cur;
		cur->_left = SubLR;
		SubL->_parent=pParent;
		if (pParent) {
			if (pParent->_Date.first > SubL->_Date.first)
				pParent->_left = SubL;
			else if (pParent->_Date.first < SubL->_Date.first)
				pParent->_right = SubL;
		}
	}
	void RotateL( Node* cur) {
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
			if (pParent->_Date.first > SubR->_Date.first)
				pParent->_left = SubR;
			else if (pParent->_Date.first < SubR->_Date.first)
				pParent->_right = SubR;
		}
	}
	void RotateRL( Node* cur) {
		Node* SubR = cur->_right;
		Node* SubRL = cur->_right->_left;
		RotateR(SubR);
		RotateL(cur);
	}
	void RotateLR( Node* cur) {
		Node* SubL = cur->_left;
		Node* SubLR = cur->_left->_right;
		RotateL(SubL);
		RotateR(cur);
	}
	bool Insert(const pair<K, V> pir){
		if (_root == nullptr){
			_root = new Node(pir);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (cur->_Date.first > pir.first) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_Date.first < pir.first) {
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(pir);
		cur->_col = RED;
		cur->_parent = parent;
		if (parent->_Date.first > cur->_Date.first)
			parent->_left = cur;
		else if (parent->_Date.first < cur->_Date.first) 
			parent->_right = cur;
		while (parent && parent->_col == RED){
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
		return true;
	}
	void Inorder(){
		inorder(_root);
		cout << endl;
	}
	int Size() {
		return size(_root);
	}
	int Height() {
		return height(_root);
	}
	template <class K,class V>
	Node* Find(const pair< K , V > pir) {
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
	}
	bool IsBalanceTree() {
		if (_root->_col == RED) return false;
		int Referance = 0;
		Node* cur = _root;
		while (cur) {
			if (cur->_col == BLACK) Referance++;
			cur = cur->_left;
		}
		return check(_root,0,Referance);
	}
private:
	bool check(const Node* cur,int BlackNum,int Referance) {
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
	}
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
	void inorder(const Node* root) {
		if (root == nullptr)
			return;
		inorder(root->_left);
		cout << "key: " << root->_Date.first << "Value: " << root->_Date.second << endl;
		inorder(root->_right);
	}
private:
	Node* _root = nullptr;
};