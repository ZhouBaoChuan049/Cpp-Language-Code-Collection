#include<iostream>
using namespace std;
int main()
{
	static int count = 0;
	while (1)
	{
		void* pa = new char[1024*1024];
		count++;
		cout <<"µÚ"<<count<<"´Î¿ª±Ù"<< " " << pa << "->" << endl;

	}
	return 0;
}