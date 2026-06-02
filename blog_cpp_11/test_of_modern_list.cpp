#include"modern_list.h"

int main()
{
    mylist::list<mystring::string> lt;
    cout << "***********************" << endl;

    mystring::string s1("11111111111111111111");
    lt.push_back(s1);
    cout << "***********************" << endl;

    lt.push_back(mystring::string("2222222222222222222222222222"));
    cout << "***********************" << endl;

    lt.push_back("33333333333333333333333333");
    cout << "***********************" << endl;

    lt.push_back(move(s1));
    cout << "***********************" << endl;

    return 0;
}