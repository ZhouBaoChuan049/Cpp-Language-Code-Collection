#include"Date.h"
void test01()
{
	////测试项目表：
	////构造函数//打印
	//Date d1(2024,6, 13);
	//d1.print();
	//Date d2(2025, 9, 30);
	//d2.print();
	//// 日期-日期 返回天数
	//int dcd = d2 - d1;
	//cout << dcd << endl;
	//// 拷贝构造函数
	//Date d3(d1);
	//d3.print();
	//// 前置--
	//Date d4 = --d3;
	//d4.print();
 //   // 前置++
	//Date d5 = ++d4;
	//d5.print();
	//// 后置--
	//d5--.print();
	//d5.print();
 //   //后置++
	//d4--.print();
	//d4.print();
	//// 日期-天数
	//// 赋值运算符重载
	Date dx(2025,12, 23);
	//Date dy(2025,12,5);
	//
	//// 日期-=天数
	//
	//// 日期+天数
	//// 日期+=天数
	//// !=运算符重载
	//if (dx != dy)
	//{
	//	printf("猪");
	//}
	//// <=运算符重载
	//if (dx <= dy)
	//{
	//	cout << " is a pig" << endl;
	//}
	//// <运算符重载
	//if (dx >= dy)
	//{
	//	cout << " is a pig" << endl;
	//}
	// >=运算符重载
	// ==运算符重载
	// >运算符重载
	//新增测试列表：
	//<<ceshi .
	Date dz(dx);
	cin >> dz;
	cout << dz << endl;

}
int main()
{
	test01();
	return 0;
}