#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	//constructer
	string str1("abcdef");
	cout << str1 << endl;
	cout << str1.c_str() << endl;
	string str11;
	cout << str11 << endl;
	string str111(str1);
	cout << str111 << endl;
	string str2("ghijkl");
	////operator=
	string str3("qwerty");
	str3 = str1;
	cout << str3 << endl;
	str3 = "qwedhiwdji";
	cout << str3 << endl;
	str3 = 'k';
	cout << str3 << endl;
	//iterator
	cout << "²âÊÔµü´úÆ÷½á¹û£º"<<" ";
	string::iterator sit = str3.begin();
	while (sit != str3.end())
	{
		cout <<  *sit << " ";
		sit++;
	}
	cout << endl;
	reverse_iterator&&const_reverse_iterator
	cout << "²âÊÔ·´Ïòµü´úÆ÷½á¹û£º" << endl;
	string::const_reverse_iterator crsit = str3.crbegin();
	while (crsit != str3.crend())
	{
		cout << * crsit << " ";
		crsit++;
	}
	cout << endl;
	cout << typeid(crsit).name() << endl;
	cout << endl;
	//·¶Î§for
	cout << "²âÊÔ·¶Î§for½á¹û£º" << " ";
	for (auto chi : str1)
	{
		cout << chi << " ";
	}
	auto=string::const_reverse_iterator//Ç°ÌáÊÇ±àÒëÆ÷¿ÉÒÔÍÆµ¼³öÀ´¡£
	auto crsit = str3.crbegin();
	while (crsit != str3.crend())
	{
		cout << *crsit << " ";
		crsit++;
	}
	cout << endl;
	//operator[]&&size()
	cout << "²âÊÔoperator[]½á¹û£º" << " ";
	string str99("asghjdafhs");
	for (int i = 0; i < strlen(str99.c_str()); i++)
	{
		cout << str99[i] << " ";
	}
	//size(),capacity(),max_size()£¬length()
	cout << endl;
	cout << "str2's size: " << str2.size() << endl;
	cout << "str2's length: " << str2.length() << endl;
	cout << "str2's capacity :"<<str2.capacity() << endl;
	cout << "str2's max_size in x86/x64 :"<<str2.max_size() << endl;
	resize()
	cout << "resize²âÊÔ1Ç°str2.size£¨£©£º" << str2.size() << endl;
	str2.resize(2);
	cout << "resize²âÊÔ1ºóstr2.size£¨£©£º" << str2.size() << endl;
	cout << "resize²âÊÔ1£º" << " ";
	for (auto ch : str2)
	{
		cout << ch << " ";
	}
	cout << endl;
	cout << "resize²âÊÔ2Ç°str2.size£¨£©£º" << str2.size() << endl;
	str2.resize(6, 'x');
	cout << "resize²âÊÔ2ºóstr2.size£¨£©£º" << str2.size() << endl;
	cout << "resize²âÊÔ2£º" << " ";
	for (auto ch1 : str2)
	{
		cout << ch1 << " ";
	}
	//cout << endl;
	//reserve(n)
	str1.reserve(100);
	cout << "²âÊÔreserveÔ¤Áô100×Ö½Ú¿Õ¼ä: " << str1.capacity() ;
	cout << endl;
	//clear()
	string str4("123456");
	cout << "str4: " << endl;
	str4.clear();
	cout << "²âÊÔstr4.clear(): " << str4.size();
	cout << endl;
	//empty
	cout << "²âÊÔempty(): ";
	if (str4.empty() == true)
	{
		cout << "str4 is empty" << endl;
	}
	else
	{
		cout << "str4 isn't empty" << endl;
	}
	//strink_to_fit
	cout << "²âÊÔstrink_to_fit: ";
	string str5("asdfghjkl");
	cout << str5.capacity() << " ";
	str5.reserve(100);
	cout << str5.capacity() << " ";
	str5.shrink_to_fit();
	cout << str5.capacity() << " ";
	cout << endl;
	at,back,front
	string str6("987654321");
	str6.at(5) = 'x';
	cout << "²âÊÔat,back,front£º" << str6 << " ";
	str6.back() = 'y';
	cout  << str6 << " ";
	str6.front() = 'z';
	cout << str6 << " ";
	//cout << endl;












	//append&operator+=&push_back
    string str6("Ô­ÉñÅ£±Æ");
	string str7("Ãù³±Å£±Æ");

	str7 += 'x';
	cout << str7 << endl;


	str7 += "yyyyyy";
	cout << str7 << endl;


	str7 += str6;
	cout << str7 << endl;


	cout << endl;


	str7.append("qwe");
	cout << str7 << " ";
	str7.append(8, 'r');
	cout << str7 << " ";




	str7.push_back('z');
	cout << str7 << " ";
	cout << endl;
	//assign
	string str8("Hello world");
	str8.assign("Ciallo world");
	cout <<"²âÊÔassign: "<< str8 << endl;
	str8.assign(5, 'c');
	cout << str8 << endl;
	str8.assign("rewwwwwww", 3, 5);
	cout << str8 << endl;
	str8.assign("ssssss", 4);
	cout << str8 << endl;
	string str9("qwjfhakvio");
	string::iterator it2 = str9.begin();
	str8.assign(it2, it2 + str9.size());
	cout << str9 << endl;
	str8.assign(str9.begin(),str9.end());
	cout << str9 << endl;
}