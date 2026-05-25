#include<iostream>
using namespace std;
class Person
{
public:
	Person(const string& name = "Mr.J")
		:_name(name)
	{}
	virtual void buyticket(){
		cout << "¹ºÂòÈ«Æ±" << endl;
	}
	~Person(){
		_name = "\0";
	}
protected:
	string _name;
};
class Student:public Person
{
public:
	Student(int id = 01101)
		:_id(id)
		,Person("ming")
	{}
	virtual void buyticket(){
		cout << "¹ºÂòÑ§ÉúÆ±" << endl;
	}
	~Student(){
		_id = 0;
	}
protected:
	int _id;
};
class Teacher :public Person
{
public:
	Teacher(int work = 01101)
		:_work(work)
		, Person("Ms.Wang")
	{}
	virtual void buyticket() {
		cout << "¹ºÂò½ÌÊ¦Æ±" << endl;
	}
	~Teacher() {
		_work = 0;
	}
protected:
	int _work;
};
void test(Person* ptr)
{
	ptr->buyticket();
}
int main()
{
	Person per;
	Student Stu;
	Teacher Tea;
	test(&per);
	test(&Stu);
	test(&Tea);
	return 0;
}
class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(){
	B* p = new B;
	p->test();
	return 0;
}
