#include<iostream>
using namespace std;
int ExceptionofDivision(int x,int y)
{
	//try
	//{
		if (y == 0)
		{
			const string error_div = "Divisor cannot be zero";
			throw error_div;
		}
	//}
	/*catch (const string& errormessage)
	{
		cout << errormessage << endl;
	}*/
		cout << "common runing" << endl;
	return x / y;
}
void Test()
{
	//no error
	int x = 10;
	int y = 20;
	cout<<ExceptionofDivision(10, 20)<<endl;
	//error
	int z = 0;
	cout << ExceptionofDivision(x, 0) << endl;
}
int main()
{
	try
	{
		Test();
	}
	catch (int& errormessage)
	{
		cout << errormessage << endl;
	}
	catch (...)
	{
		cout << "Unknown Exception" << endl;
	}
	return 0;
}