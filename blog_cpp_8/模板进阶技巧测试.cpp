#include<iostream>
using namespace std;
//以Date类为背景：写非类型模板参数
//模板特化：全特化，偏特化，全指针偏特化，全引用偏特化，指针引用偏特化。
//写100000个随机数的vector和list——>vector排序比较
template <class T1,class T2>
class Date
{
public:
	Date()
	{
		cout << "class T1,class T2,int x" << endl;
	}
};
template<>
class Date<int ,char>
{
public:
	Date()
	{
		cout << "Date(int x,char y)" << endl;
	}
};


template <class T1>
class Date<T1,int*>
{
public:
	Date()
	{
		cout << "Date(T1 x, int* y)" << endl;
	}
};
template <class T1,class T2>
class Date<T1*, T2*>
{
public:
	Date()
	{
		cout << "Date(T1* x, T2* y)" << endl;
	}
};
template <class T1, class T2>
class Date<T1&, T2&>
{
public:
	Date()
	{
		cout << "Date(T1& x, T2& y)" << endl;
	}
};
//函数特化与函数参数列表的const关系。
template <class T1,class T2>
void func(const T1& x,const T2& y )
{
	cout << "func(const T1& x,const T2& y )" << endl;
}

template<>
void func<int*>(int* const& x, int* const& y)
{
	cout << "func<int*, int*>( int* const& x, int* const& y)" << endl;
}
	
//int main()
//{
//	int* a = (int*)1;
//	int* b = (int*)2;
//	func(a, b);
//	return 0;
//}