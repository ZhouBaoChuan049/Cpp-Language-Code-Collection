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

