#pragma once
#include<iostream>
#include<cassert>
#include<vector>
#include<ctime>
using namespace std;
//需要完成的接口：
//AVL树的结点类和AVL树类√
//插入函数√
//四种旋转函数√
//中序遍历，高度，查找，结点数量√
//判定是否是AVL树√
template <class K,class V>
struct AVLTreeNode
{
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	int _bf;//Balance Factor
	K _key;
	V _value;

	AVLTreeNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_bf(0)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};
template <class K,class V>
class AVLTree
{
	using Node = AVLTreeNode<K, V>;
public:
	void RotateL(Node* parent){
		Node* pParent = parent->_parent;
		Node* cur = parent->_right;
		Node* nodeC = cur->_left;
		cur->_left = parent;
		parent->_parent = cur;
		parent->_right = nodeC;
		if (nodeC)
			nodeC->_parent = parent;
		cur->_parent = pParent;
		if (parent == _root) {
			_root = cur;
			cur->_parent = nullptr;
		}
		if (pParent){
			if (pParent->_key < cur->_key)
				pParent->_right = cur;
			else if (pParent->_key > cur->_key)
				pParent->_left = cur;
		}
		cur->_bf = 0;
		parent->_bf = 0;
	}
	void RotateR(Node* parent) {
		Node* pParent = parent->_parent;
		Node* cur = parent->_left;
		Node* nodeC = cur->_right;
		cur->_right = parent;
		parent->_left = nodeC;
		parent->_parent = cur;
		cur->_parent = pParent;
		if (nodeC)
			nodeC->_parent = parent;
		if (parent == _root){
			_root = cur;
			cur->_parent = nullptr;
		}
		if (pParent){
			if (pParent->_key > cur->_key)
				pParent->_left = cur;
			else if (pParent->_key < cur->_key)
				pParent->_right = cur;
		}
		cur->_bf = 0;
		parent->_bf = 0;
	}
	void RotateLR(Node* parent){
		Node* cur = parent->_left;
		Node* SubL = cur;
		Node* SubLR = cur->_right;
		int bf = SubLR->_bf;
		RotateL(SubL);
		RotateR(parent);
		if (bf == 1) {
			parent->_bf = 0;
			SubLR->_bf = 0;
			SubL->_bf = -1;
		}
		else if (bf == -1) {
			parent->_bf = 1;
			SubL->_bf = 0;
			SubLR->_bf = 0;
		}
		else if (bf == 0){
			SubLR->_bf = 0;
			SubL->_bf = 0;
			parent->_bf = 0;
		}
		else
			assert(false);
	}
	void RotateRL(Node* parent) {
		Node* cur = parent->_right;
		Node* SubR = cur;
		Node* SubRL = cur->_left;
		int bf = SubRL->_bf;
		RotateR(SubR);
		RotateL(parent);
		if (bf == 1) {
			SubRL->_bf = 0;
			SubR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1) {
			SubRL->_bf = 0;
			SubR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0) {
			SubR->_bf = 0;
			SubRL->_bf = 0;
			parent->_bf = 0;
		}
		else
			assert(false);
	}
	bool Insert(const K& key,const V& value){
		if (_root == nullptr){
			_root = new Node(key, value);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_key > key){
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key){
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key == key)
				return false;
		}
		cur=new Node(key, value);
		if (parent->_key > cur->_key)
			parent->_left = cur;
		else if (parent->_key < cur->_key)
			parent->_right = cur;
		cur->_parent = parent;
		while (parent){
			if (parent->_left == cur)
				parent->_bf--;
			else if (parent->_right == cur)
				parent->_bf++;
			else
				assert(false);
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2){
				if (parent->_bf == 2 && cur->_bf == 1)//左单
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == -1)//右单
					RotateR(parent);
				else if (parent->_bf == -2 && cur->_bf == 1)//左右
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1)//右左
					RotateRL(parent);
				else
					assert(false);
				break;
			}
			else
				assert(false);
		}
		return true;
	}
	
	Node* Find(const K& key){
		Node* cur = _root;
		while (cur){
			if (cur->_key > key)
				cur = cur->_left;
			else if (cur->_key < key)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}
	int Size() { return size(_root); }
	int Height(){return height(_root);}
	void Inorder(){inorder(_root); cout << endl;}
	bool IsBalanceTree(){return JudgeAVLTree(_root);}
private:
	bool JudgeAVLTree(Node* root) {
		if (root == nullptr)
			return true;
		int leftheight = height(root->_left);
		int rightheight = height(root->_right);
		int Bf = rightheight - leftheight;
		if (abs(Bf) >= 2)
		{
			cout << root->_key << " height error" << endl;
			return false;
		}

		if (root->_bf != Bf)
		{
			cout << root->_key << "balance factor error" << endl;
			return false;
		}
		return JudgeAVLTree(root->_left) && JudgeAVLTree(root->_right);
	}
	int size(Node* root){
		if (root == nullptr)
			return 0;
		int leftsize = size(root->_left);
		int rightsize = size(root->_right);
		return leftsize + rightsize + 1;
	}
	int height(Node* root){
		if (root == nullptr)
			return 0;
		int leftheight=height(root->_left);
		int rightheight=height(root->_right);
		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}
	void inorder(Node* root){
		if (root == nullptr)
			return;
		inorder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		inorder(root->_right);
	}
private:
	Node* _root=nullptr;
};
