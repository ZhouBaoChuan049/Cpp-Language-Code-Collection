#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stdbool.h>
using namespace std;
class Date
{
public:
	friend ostream& operator<<(ostream& out, const Date d);
	friend istream& operator>>(istream& in, Date& d);
	//检查
	bool check_Date()
	{
		if (_day== GetMonthDay(_year,_month))
		{
			return false;
		}
		if (_month > 12)
		{
			return false;
		}
		return true;
	}
	//构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int arrey[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0 && year % 100 != 0 && month == 2)
		{
			return 29;
		}
		else
		{
			return arrey[month];
		}
	}
	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	// 日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		while ( _day> GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		*this += day;
		return *this;
	}
	// 日期-=天数
	Date operator-=(int day)
	{
		_day -= day;
		while ( _day< 0)
		{
			if (_month == 1)
			{
				_year--;
				_month += 12;
			}
			_day += GetMonthDay(_year, _month-1);
			_month--;
		}
		return *this;
	}
	// 日期-天数
	Date& operator-(int day)
	{
		*this -= day;
		return *this;
	}
	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	// 后置++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// 后置--
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year < d._year)
		{
			return false;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return false;
			}
			else if (_month == d._month)
			{
				if (_day <= d._day)
				{
					return false;
				}
			}
		}
		return true;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		if (_year == d._year
			&& _month == d._month
			&& _day == d._day)
			return true;
		else
			return false;
	}
	// >=运算符重载
	bool operator >= (const Date& d)
	{
		if (*this == d)
		{
			return true;
		}
		else if (*this > d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// <运算符重载
	bool operator < (const Date& d)
	{
		if (*this >= d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		if (*this > d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		int count = 0;
		Date dmax = *this;
		Date dmin = d;
		if (dmax < dmin)
		{
			dmax = d;
			dmin = *this;
			flag = -1;
		}
		while (1)
		{
			count++;
			dmin++;
			if (dmin == dmax)
			{
				break;
			}
		}
		return flag * count;
	}
	//打印
	void print()
	{
		cout << _year <<"年"<< _month <<"月" << _day <<"日" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//重载<<
ostream& operator<<(ostream& out, const Date d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
//重载>>
istream& operator>>(istream& in, Date& d)
{
	cout << "请输入" << endl;
	while (1)
	{
		in >> d._year >> d._month >> d._day;
		if (d.check_Date() == false)
		{
			cout << "日期非法，请重新输入" << endl;
		}
		else if (d.check_Date() == true)
		{
			break;
		}
	}
	return in;
}
