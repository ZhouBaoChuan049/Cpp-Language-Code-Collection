#include<iostream>
using namespace std;
class Person {
public:
	virtual void BuyTicket() {
		cout << "买票全价" << endl; }
	virtual void BuyTicket01() {
		cout << "买票" << endl;
	}
	virtual void BuyTicket02() {
		cout << "买票" << endl;
	}
	virtual void BuyTicket03() {
		cout << "买票" << endl;
	}
private:
	string _name;
	};
class Student : public Person {
public:
	virtual void BuyTicket() {
		cout << "买票打折" << endl;
	}
private:
	string _id;
};
class Soldier : public Person {
public:
	virtual void BuyTicket() {
		cout << "买票优先" << endl;
	}
private:
	string _codename;
};
void Func(Person* ptr) { ptr->BuyTicket(); }
int main()
{
	Person ps;
	Student st;
	Soldier sr;
	Func(&ps);
	Func(&st);
	Func(&sr);
	return 0;
}
	