#include<iostream>
using namespace std;
class DA{
public:
	DA(int a)
		:_a(a){
		cout << "DA" << endl;
	}
private:
	int _a = 0;
};
class Date{
public:
	Date(int a=0)
		:_day(a)
		,da(1)
	{
	}
private :
	int _day;
	DA da;
};
int main(){
	Date d1;
	return 0;
}