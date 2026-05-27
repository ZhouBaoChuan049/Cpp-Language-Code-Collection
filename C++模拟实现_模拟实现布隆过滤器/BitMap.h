#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
namespace MyBitMap
{
	template <size_t N>
	class BitMap;
	template<size_t N>
	class DoubleBitMap
	{
	public:
		void Set(size_t n)
		{
			if (!bitmap01.Test(n) && !bitmap10.Test(n))
			{
				bitmap01.Set(n);
			}
			else if (bitmap01.Test(n) && !bitmap10.Test(n))
			{
				bitmap10.Set(n);
				bitmap01.Reset(n);
			}
			else if(!bitmap01.Test(n) && bitmap10.Test(n))
			{
				bitmap01.Set(n);
			}
		}
		size_t GetCount(size_t n)
		{
			if (!bitmap01.Test(n) && !bitmap10.Test(n))
			{
				return 0;
			}
			else if (bitmap01.Test(n) && !bitmap10.Test(n))
			{
				return 1;
			}
			else if (!bitmap01.Test(n) && bitmap10.Test(n))
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	private:
		BitMap<N> bitmap01;
		BitMap<N> bitmap10;
	};
	template <size_t N>
	class BitMap
	{
	public:
		BitMap() { _Table.resize(N / 32 + 1); }
		void Set(size_t n)
		{
			size_t x = n / 32;
			size_t y = n % 32;
			_Table[x] |= (1 << y);
		}
		void Reset(size_t n)
		{
			size_t x = n / 32;
			size_t y = n % 32;
			_Table[x] &= (~(1 << y));
		}
		bool Test(size_t n)
		{
			size_t x = n / 32;
			size_t y = n % 32;
			return (1 << y) & _Table[x];
		}
	private:
		vector<int> _Table;
	};
}
void test02()
{
	MyBitMap::DoubleBitMap<100> dbmp;
	vector<int> test = {
	5, 12, 7, 7, 23,
	45, 12, 89, 34, 56,
	78, 90, 100, 0, 3,
	45, 67, 23, 88, 92,
	11, 11, 50, 60, 70,
	80, 90, 20, 30, 40
	};
	for (auto e : test)
	{
		dbmp.Set(e);
	}
	for (int i=0;i<100;i++)
	{
		cout << i<<" :" << dbmp.GetCount(i) << endl;
	}
}
void test01()
{
	MyBitMap::BitMap<100> bitmap;
	vector<int> test = {
	5, 12, 7, 7, 23,
	45, 12, 89, 34, 56,
	78, 90, 100, 0, 3,
	45, 67, 23, 88, 92,
	11, 11, 50, 60, 70,
	80, 90, 20, 30, 40
	};
	for (auto e : test)
	{
		bitmap.Set(e);
	}
	cout << bitmap.Test(89) << endl;
	bitmap.Reset(89);
	cout << bitmap.Test(89) << endl;
	cout << bitmap.Test(2) << endl;
	cout << bitmap.Test(99) << endl;
	cout << bitmap.Test(7) << endl;
}