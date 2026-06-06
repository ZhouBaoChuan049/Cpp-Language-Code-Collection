#include<iostream>
#include<functional>
using namespace std;
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;
using placeholders::_4;
int Sub(int x, int y)
{
	return x - y;
}
int SubX(int a, int b, int c, int x)
{
	return a * b * c - x;
}

void conmmonTest()
{
	auto Handle01 = bind(Sub, _1, _2);
	cout << Handle01(100, 52) << endl;
	auto Handle02 = bind(Sub, 100, _1);
	cout << Handle02(60) << endl;

	auto Handle03 = bind(SubX, _1, _2, _3,_4);
	cout << Handle03(54, 95, 55,1)<<endl;
	auto Handle04 = bind(SubX, _1, 200, _2, _3);
	cout << Handle04(1, 2, 5);

}
class MemberTest
{
public:
	MemberTest(int n=1)
		:_n(n)
	{}
	int Func(int a, int b, int c)
	{
		return _n*a * b * c;
	}
	static int Func01(int a, int b, int c)
	{
		return a * b * c;
	}
private:
	const int _n;
};
void memberTest()
{
	function<int(int, int)> f = bind(&MemberTest::Func, MemberTest(), _1, 200, _2);
	cout << f(5, 20) << endl;
}
int main()
{
	memberTest();
	return 0;
}