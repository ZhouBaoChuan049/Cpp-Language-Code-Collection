#pragma once
#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;
//链表结点构造√
//链表迭代器构造√
//operator++√
//operator*√
//operator--√
//operator！=√
//begin/end√
//链表构造√
//pushback√
//push_front√
//insert√
//popback√
//popfront√
//erase√
//size（）√
//empty（）√
//以上全部测试一遍
//2.4新任务：
//operator->√
//三个模板参数实现const和非const合并√
//初始化链表构造√
//const_iterator√
//拷贝构造√
//复制重载√
//swap√
//clear√
//empty_init()升级构造函数√
//按需实例化打印AA类（双成员变量）√
namespace mylist
{
	template <class T>
	struct list_node
	{
		T date;
		list_node<T>* next;
		list_node<T>* prev;

		list_node(const T& x = T())
		{
			date=x;
			next = nullptr;
			prev = nullptr;
		}
	};


	template <class T,class Ptr,class Ref>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ptr, Ref> Self;

		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{}
		Ref operator*()
		{
			return _node->date;
		}
		
		Self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}
		bool operator!=(const Self& iter) const 
		{
			return _node != iter._node;
		}
		bool operator==(const Self& iter) const
		{
			return _node == iter._node;
		}
		Ptr operator->()
		{
			return &(_node->date);
		}
	};


	template <class T>
	class list
	{
	private:
		typedef list_node<T> Node;
		Node* head;
		size_t _size;
	public:
		typedef list_iterator<T,T*,T&> iterator;
		typedef list_iterator<T, const T*, const T&> const_iterator;
		void empty_init()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list<T>& operator=( list<T> lt)
		{
			swap(lt);
			return *this;
		}
		list(initializer_list<T> lt)
		{
			empty_init();
			for (const auto& e : lt)
				push_back(e);

		}
		void clear()
		{
			if (!empty())
			{
				iterator it = begin();
				while (it != end())
				{
					it = erase(it);
				}
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(head, lt.head);
			std::swap(_size, lt._size);
		}
		list(list<T>& lt)
		{
			empty_init();
			iterator it = lt.begin();
			while (it != lt.end())
			{
				push_end(*it);
			}
		}
		size_t size()
		{
			return _size;
		}
		bool empty()
		{
			return _size == 0;
		}
		iterator begin()
		{
			return head->next;
		}
		iterator end()
		{
			return head;
		}
		const_iterator begin() const
		{
			return head->next;
		}
		const_iterator end() const
		{
			return head;
		}
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* _prev = cur->prev;
			Node* newnode =new Node(x);

			newnode->next = cur;
			newnode->prev = _prev;
			_prev->next = newnode;
			cur->prev = newnode;
			_size++;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* _prev = pos._node->prev;
			Node* _next = pos._node->next;
			Node* cur = pos._node;
			cur->next = _next;
			cur->prev = _prev;
			delete pos._node;
			--_size;
			return _next;
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void push_end(const T& x)
		{
			insert(end(), x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}

	};

	template <class continer>
	void print_continer(const continer& con )
	{
		typename continer::const_iterator it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
		}
	}
	void test_of_mylist1()
	{
		list<int> l1;
		l1.push_end(1);
		l1.push_front(2);
		l1.push_end(3);
		l1.push_front(4);
		l1.push_end(5);
		l1.push_front(6);
		auto it = l1.begin();
		auto it1 = l1.begin();
		while (it != l1.end())
		{
			cout << *it << endl;
			++it;
		}
		++++it1;
		l1.erase(it1);
		it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << endl;
			++it;
		}
	}
	class AA
	{
	public:
		AA(int a = 0,int b=0)
			:_a(a)
			,_b(b)
		{}
		int _a;
		int _b;
	};
	void test_of_mylist2()
	{
		list<AA> l2;
		list<AA>::iterator it = l2.begin();
		cout << it->_b << " ";
		cout << endl;
	}
	void test_of_mylist3()
	{
		list<int> l2;
		l2.push_end(1);
		l2.push_end(2);
		l2.push_end(3);
		l2.push_end(4);
		l2.push_end(5);
		l2.push_end(6);
		print_continer(l2);
		cout << endl;
	}
}



