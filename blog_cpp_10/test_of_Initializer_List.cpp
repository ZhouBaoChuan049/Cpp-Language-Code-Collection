#include<iostream>
#include<vector>
using namespace std;


void test02()
{
	//short s1{ 50000 };     // ❌ 超出short范围 → 编译错误
	//int i1{ 3.14 };        // ❌ 浮点截断 → 编译错误
	//unsigned u1{ -1 };     // ❌ 负数赋给无符号 → 编译错误
}
void test01()
{
	initializer_list<int> v = { 1,2,3,4,5,8,9,7,50,9,5,6 };
	int arrey[10] = { 1,5,9,8,7,4,2 };
}
int main()
{
	test02();
	return 0;
}