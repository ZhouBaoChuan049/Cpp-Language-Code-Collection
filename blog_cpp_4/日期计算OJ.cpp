//#include <climits>
//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//    friend  ostream & operator<< (ostream& _cout, Date date);
//    friend istream& operator>> (istream& _cin, Date date);
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    int getmonthday(int month,int year)
//    {
//        int tian[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2 && year % 4 == 0 && year % 100 != 0)
//            return 29;
//        else
//            return tian[month];
//    }
//    Date operator+=(int num)
//    {
//        _day += num;
//        while (_day >= getmonthday(_month, _year))
//        {
//            _day -= getmonthday(_month, _year);
//            _month++;
//            if (_month == 12)
//            {
//                _month = 1;
//                _year += 1;
//            }
//        }
//        return *this;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    int n = 0;
//    cin >> n;
//    while (n >= 0)
//    {
//        int year, month, day;
//        cin >> year >> month >> day;
//        Date d(year, month, day);
//        int num;
//        cin >> num;
//        d += num;
//        cout << d;
//        n--;
//    }
//}
//ostream& operator<< ( ostream& _cout , Date date)
//{
//    _cout << date._year <<"-" << date._month <<"-" << date._day << endl;
//    return _cout;
//}
//istream& operator>> (istream& _cin , Date date)
//{
//    _cin >> date._year >> date._month >> date._day;
//    return _cin;
//}
#include <climits>
#include <iostream>
using namespace std;
class Date
{
public:
    friend  ostream& operator<< (ostream& _cout, Date date);
    Date(int year, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    int getmonthday(int month, int year)
    {
        int tian[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return tian[month];
    }
    Date operator+=(int num)
    {
        _day += num;
        while (_day > getmonthday(_month, _year))
        {
            _day -= getmonthday(_month, _year);
            _month++;
            if (_month == 13)
            {
                _month = 1;
                _year += 1;
            }
        }
        return *this;
    }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    int n, y;
    cin >> y >> n;
    Date d(y);
    d += n;
    cout << d << endl;
}
ostream& operator<< (ostream& _cout, Date date)
{
    _cout << date._year << "-";

    if (date._month < 10) _cout << "0";
    _cout << date._month << "-";

    if (date._day < 10) _cout << "0";
    _cout << date._day << endl;   // ¡û ¼Ó»Ø»»ÐÐ

    return _cout;
}