#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;
void test_string01()
{
	//常用接口
	string str0("asdfghj");
	string str1("klpoiuy");
	cout << str0 << endl;
	str0.insert(1, str1);
	cout << str0 << endl;
	str0.insert(1, "zxcvbnm");
	cout << str0 << endl;
	str0.insert(0, 1, 'q');
	cout << str0 << endl;
}
void test_string02()
{
	//不常用接口
	string str2("0123456789");
	string str3("abcdefghij");
	cout << str2 << endl;
	str2.insert(0, str3, 1, 5);
	cout << str2 << endl;
	str2.insert(1, str3, 3);
	cout << str2 << endl;
}
void test_string03()
{
	string str3("123456789");
	cout << str3 << endl;
	//str3.erase();
	//cout << str3 << endl;
 //   str3.erase(str3.begin(), str3.end());
	//cout << str3 << endl;
	str3.erase(str3.begin() + 3);
	cout << str3 << endl;
}
void test_string04()
{
	string str4("123454321");
	size_t pos=str4.rfind('3');
	str4.replace(pos,1,1,'a');
	cout << str4 << endl;
}
void test_string05()
{
	string str5("0123456789");
	size_t pos = str5.find_first_of("6889");
	str5.replace(pos, 1, 1, 'a');
	cout << str5 << endl;
}
void test_string06()
{
	string str6;
	getline(cin, str6, '*');
	cout << str6 <<endl;
}
void test_string07()
{
	string str1;
	getline(cin, str1);
	size_t pos = str1.rfind(' ');
	string substr1 = str1.substr(pos);
	size_t n = substr1.size()-1;
	cout << n << endl;
}

int main()
{
	test_string07();
	return 0;
}
