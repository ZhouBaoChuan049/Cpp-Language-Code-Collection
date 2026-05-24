#include<iostream>
using namespace std;
namespace myswap
{
	template <typename T>
	void swap( T& x,  T& y)
	{
		cout << x << " " << y << endl;
		T swa = x;
		x = y;
		y = swa;
	}
}
//int main()
//{
//	int a = 10, b = 20;
//	double c = 12.3, d = 45.2;
//	myswap::swap<double>((double)a, (double)b);
//	myswap::swap<int>(c, d);
//	cout << a <<" "<< b << endl;
//	cout << c <<" "<< d << endl;
//	return 0;
//}