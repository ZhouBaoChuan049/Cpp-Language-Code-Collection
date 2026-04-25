#include"mystring.h"
namespace mystring
{
	void test_of_mystring()
	{
		string str1("asdasjfhjkd");
		cout << str1 << endl;
	}
	void test_string01()
	{
		//常用接口
		string str0("asdfghj");
		string str1("klpoiuy");
		cout << str0 << endl;
		cout << str0 << endl;
	}
	void test_string02()
	{
		//不常用接口
		string str2("0123456789");
		string str3("abcdefghij");
		cout << str2 << endl;
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
		cout << str3 << endl;
	}
	void test_string04()
	{
		string str4("123454321");
		size_t pos = str4.find('3');
		cout << str4 << endl;
	}
	void test_string05()
	{
		string str5("0123456789");
		cout << str5 << endl;
	}
	void test_string06()
	{
		string str5("abcdefg");
		cin >> str5;
		cout << str5;
	}
	void test_modern_string()
	{
		string str1("123456");//构造
		string st2 = str1;//赋值重载
		string str3(str1);//拷贝构造
		cout << "**********************" << endl;
		string str4(string("123456"));//移动构造
		string str5 = string("123456");////移动赋值
	}
}
int main()
{
	mystring::test_modern_string();
	return 0;
}