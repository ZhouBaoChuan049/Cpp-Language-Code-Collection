#include<iostream>
using namespace std;
void print(int* p)
{
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << endl;
	}
}
int main()
{
	//CÓïÑÔ
	int* pa = (int*)malloc(sizeof(int) * 10);
	if (pa == nullptr){
		perror("malloc::fail");
	}
	for (int i = 0; i < 10; i++)
	{
		*(pa + i) = i + 1;
	}

	//C++
	int* pb = new int[10]{1,2,3,4,5,6,7,8,9,10};

	//´òÓ¡
	print(pa);
	print(pb);
	return 0;
}