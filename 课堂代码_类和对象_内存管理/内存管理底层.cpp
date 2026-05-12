#include<iostream>
using namespace std;
class Asser
{
public:
	Asser(int x = 0, int y = 1)
		:_x(x)
		,_y(y)
	{
		cout << "构造函数被调用" << endl;
	}
	~Asser()
	{
		_x = 0;
		_y = 0;
		cout << "析构函数被调用" << endl;
	}
private:
	int _x;
	int _y;
};
int main()
{
	int* str = new int[10];
	delete str;
	return 0;
}