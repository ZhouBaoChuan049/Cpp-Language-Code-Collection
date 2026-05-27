#pragma once
#include"BitMap.h"
//布隆过滤器的设置set接口，
//布隆过滤器的test查看有没有存在接口
namespace BloomFilter
{
	struct HashFuncBKDR
	{
		// @detail 本 算法由于在Brian Kernighan与Dennis Ritchie的《The CProgramming Language》
		// 一书被展示而得 名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法累乘因子为31。
		size_t operator()(const std::string& s)
		{
			size_t hash = 0;
			for (auto ch : s)
			{
				hash *= 31;
				hash += ch;
			}
			return hash;
		}
	};


	struct HashFuncAP
	{
		// 由Arash Partow发明的一种hash算法。  
		size_t operator()(const std::string& s)
		{
			size_t hash = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0) // 偶数位字符
				{
					hash ^= ((hash << 7) ^ (s[i]) ^ (hash >> 3));
				}
				else              // 奇数位字符
				{
					hash ^= (~((hash << 11) ^ (s[i]) ^ (hash >> 5)));
				}
			}

			return hash;
		}
	};

	struct HashFuncDJB
	{
		// 由Daniel J. Bernstein教授发明的一种hash算法。 
		size_t operator()(const std::string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash = hash * 33 ^ ch;
			}

			return hash;
		}
	};

	template <class T = string,
		size_t N=50, 
		size_t K = 20,
		class Func01 = HashFuncDJB,
		class Func02 = HashFuncAP,
		class Func03 = HashFuncBKDR>
	class BloomFilter
	{
	public:
		void set( T& key)
		{
			Func01 func01;
			size_t key01 = func01(key);
			_bitmap.Set(key01 % (N * K));
			Func02 func02;
			size_t key02 = func02(key);
			_bitmap.Set(key02 % (N * K));
			Func03 func03;
			size_t key03 = func03(key);
			_bitmap.Set(key03 % (N * K));
		}
		bool Test( T& key)
		{
			Func01 func01;
			size_t key01 = func01(key)%(N*K);
			if (!_bitmap.Test(key01))
				return false;
			Func02 func02;
			size_t key02 = func02(key)%(N*K);
			if (!_bitmap.Test(key02))
				return false;
			Func03 func03;
			size_t key03 = func03(key)%(N*K);
			if (!_bitmap.Test(key03))
				return false;
			return true;
		}
	private:
		//你要存入多少个数据
		//你每一个数据要映射多少个位
		int _m = N * K;
		MyBitMap::BitMap<N* K> _bitmap;
	};
	void test01()
	{
		string str01 = "asj";
		string str02 = "shd";
		string str03 = "chs";
		BloomFilter<string, 20, 5> blf;
		blf.set(str01);
		blf.set(str02);
		blf.set(str03);
		cout << blf.Test(str01) << endl;
		string str04 = "fdsv";
		cout << blf.Test(str04) << endl;
	}
}