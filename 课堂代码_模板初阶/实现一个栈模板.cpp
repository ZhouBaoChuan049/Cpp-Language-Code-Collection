#include<iostream>
#include<cstring>
using namespace std;
template <class T>
class stack
{
public:
	stack(int n=4)
		:_capacity(n)
		, _str(new T[n])
		, _size(0)
	{}
	~stack()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	void stack_pushback(T x)
	{
		if (_size == _capacity)
		{
			T* tmp = new T[_capacity*2];
			memcpy(tmp,_str,sizeof(T)*_size);
			delete[](_str);
			_str = tmp;
			_capacity *= 2;
		}
		_str[_size++] = x;
	}
private:
	T* _str;
	size_t _size;
	size_t _capacity;
};
//int main()
//{
//	stack<char>stack1;
//	stack1.stack_pushback('a');
//	stack1.stack_pushback('b');
//	stack1.stack_pushback('c');
//	stack1.stack_pushback('d');
//	stack1.stack_pushback('e');
//	stack1.stack_pushback('f');
//	stack1.stack_pushback('g');
//	return 0;
//}
int main()
{
    string s;
    const int N = 256;
    char arr[N] = { 0 };
    char ch;
    cin >> ch;  
    while (ch != ' ' && ch != '\n')  
    {
        s += ch;
        cin >> ch;
    }
   // s += ch;
    cout << s;
	return 0;
}