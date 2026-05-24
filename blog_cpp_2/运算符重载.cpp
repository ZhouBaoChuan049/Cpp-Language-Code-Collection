#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
class Date
{
public:
	bool operator==(Date x2)
	{
		if (_year == x2._year && _month == x2._month && _day == x2._day)
			return true;
		else
			return false;
	}
	Date (int year ,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int getyear(int year)
	{
		return year;
	}
//private:
	int _year;
	int _month;
	int _day;
};
//ÔËËã·ûÖØÔØ
//int main()
//{
//	Date d1(2024,6,26);
//	Date d2(2024,2,26);
//	bool result=(d1.operator==(d2));
//	cout << result << endl;
//	cout << (d1.operator==(d2))<< endl;
//	return 0;
//}