#include<iostream>
using namespace std;
class A
{
public:
	A()
		:_a(1)
		, _b(1)
		, pa((int*)malloc(4))
	{
		cout << "A:A()" << endl;
	}
	~A()
	{
		_a = 0;
		_b = 0;
		free(pa);
		cout << "A:~A()" << endl;
	}
	private:
	int _a;
	int _b;
	int* pa;
};
int main()
{
	A* po = new  A[10];
	delete[]po;
	return 0;
}