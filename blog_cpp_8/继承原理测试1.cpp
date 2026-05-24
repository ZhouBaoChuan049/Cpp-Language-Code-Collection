#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<array>
#include<iostream>
#define CONTINER deque
using namespace std;
namespace work
{
	using namespace std;
	template<class T>
	class stack :public std::CONTINER<T>
	{
	public:
		void push(const T& x)
		{
			std::CONTINER<T>::push_back(x);
		}
	};
}

int main()
{
	work::stack<int> st;
	st.push(1);
	return 0;
}
//模板继承实现stack，不用写太多接口√
//测试子类给给父类
//父子成员同名隐藏
//重要：子函数的默认成员函数

class Person
{
public:
	Person(const char* name = "xxx")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	Student(int num,string str)
		:_num(num)
		,_addrss(str)
		,Person()
	{}
	Student(const Student& stu)
		:Person(stu)
		,_num(stu._num)
		,_addrss(stu._addrss)
	{}
	void operator=(const Student& stu)
	{
		if (this != &stu)
		{
			this->_num = stu._num;
			this->_addrss = stu._addrss;
			Person::operator=(stu);
		}
	}
	~Student()
	{
	}
protected:
	int _num = 1;
	string _addrss = "湖州市吴兴区";
};

//int main()
//{
//	Student stu;
//	Person per;
//	per = stu;
//	stu = per;
//	return 0;
//}