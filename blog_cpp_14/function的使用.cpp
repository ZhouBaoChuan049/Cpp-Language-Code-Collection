//#include<iostream>
//#include<functional>
//using namespace std;
//int func(int x,int y){
//	return x + y;
//}
//struct Struct{
//	bool operator()(int x, int y){
//		return x + y;
//	}
//};
//class Test
//{
//public:
//	Test(int n=0)
//		:_n(n)
//	{ }
//	const int func01(int x, int y, int z) const
//	{
//		return x * y * z*_n ;
//	}
//	static int func02(int x, int y)
//	{
//		return x * y;
//	}
//	int func03(int x, int y)
//	{
//		return x * _n * y;
//	}
//private:
//	const int _n;
//};
//void Test00(int x,int y,int z)
//{
//	//static member function:
//	function<int(int, int)>f2 = Test::func02;
//	cout << f2(x, y) << endl;
//
//	//common member function:
//	function<int(Test*,int, int)>f1 = &Test::func03;
//	function<const int(Test*,int, int, int)> f3 = &Test::func01;
//	Test test01(123);
//	cout << f1(&test01, x, y) << endl;
//	Test test02(456);
//	cout << f3(&test02, x, y, z) << endl;
//}
//int main()
//{
//	Test00(1, 2, 3);
//	return 0;
//}