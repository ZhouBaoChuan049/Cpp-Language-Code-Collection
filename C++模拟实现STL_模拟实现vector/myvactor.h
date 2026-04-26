#pragma once
#include<assert.h>
#include<list>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		//resize
		void resize(int n,const T& val=T())
		{
			if (n > size())
			{
				reserve(n);
				num=n - size();
				while (num)
				{
					push_back(val);
					num--;
				}
				_finish = _start + n;
			}
			else
			{
				_finish = _start + n;
			}
		}
		//insert
		void insert(int pos,const T& x)
		{
			assert(pos > 0);
			assert(pos < size());
			if (_finish == _end_of_storage)
			{
				int len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			int end = _finish - _start;
			for (int i = end-1; i >=pos; i--)
			{
				_start[i + 1] = _start[i];
			}
			_start[pos] = x;
			_finish++;
		}
		//erase
		void erase(int pos)
		{
			assert(pos > 0);
			assert(pos < size());
			for (int i = pos+1; i < size(); i++)
			{
				_start[i - 1] = _start[i];
			}
			_finish--;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
	
	//Ä£°åprint_vector
	template <class T>
	void print_vector(const vector<T>& x)
	{
		for (auto e : x)
		{
			cout << e << endl;
		}
	}
	//Ä£°åprint_container
	template <class T>
	void print_continer(const T& x)
	{
		typename vector::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << endl;
		}
	}
}
