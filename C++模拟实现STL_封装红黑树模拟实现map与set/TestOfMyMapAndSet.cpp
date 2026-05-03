//今日任务清单；
//给红黑树加一个迭代器类。√
//迭代器类内部要实现的接口：√
//1.经典老样：构造迭代器，2.解引用3.箭头。4.等号和不等√
//1.新东西：1.operator++。2.operator--。√
//包装两套迭代器到红黑树类。√
//const/一般版本的begin（）和end（）√
//调整插入函数的返回值为了适配operator[]。返回值要改好几个地方√
//整个模板参数大修，为了适配set和map两种不同容器的特性。√
//Insert中仿函数的植入√
//从红黑树类里面取到包装的迭代器，再包装一遍给set和map√
//从红黑树类里面取到插入函数包装一层给set和map，注意返回值。√
//组合包装一颗红黑树到set和map。我们的这两个容器是用组合完成的。√
// //注意键值不可修改，map 的value必须可以修改
//问题：能不能再封装迭代器给这个map和set的时候我们去封装一个迭代器类的。而不是去红黑树类里面取得？
//operator[]基于insert实现 
#include"Myset.h"
#include"Mymap.h"
#include<string>
#include<iostream>
using namespace std;
void Print(MySet::Set<int>& s)
{
	MySet::Set<int>::iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	MySet::Set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	MySet::Set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//Print(s);


	MyMap::Map<string, string> dict;
	dict.insert({ "sort", "1" });
	dict.insert({ "left", "1" });
	dict.insert({ "right", "1" });

	dict["left"] = "2";
	dict["insert"] = "3";
	dict["string"];

    MyMap::Map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}

