#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Date{
public:
	Date(){
		_year = 2025;
		_month = 12;
		_day = 19;
	}

	void print(int year,int month,int day){
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
}d2;
int main(){
	Date d1;

	return 0;
}