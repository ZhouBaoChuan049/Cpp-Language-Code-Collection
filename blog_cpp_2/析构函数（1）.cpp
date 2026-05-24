#include<iostream>
using namespace std;
typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//				return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	~Stack()
//	{
//		free(_a);
//		_capacity = 0;
//		_top = 0;
//	}
//private:
//STDataType* _a;
//size_t _capacity;
//size_t _top;
//};
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	~MyQueue()
//	{
//		free(ptr);
//		ptr = nullptr;
//	}
//private:
//	Stack pushst;
//	Stack popst;
//	int* ptr;
//};
//int main()
//{
//	///MyQueue mq;
//	int* ptr = nullptr;
//	int*& rb = *ptr; // 注意：这里是 rb 绑定到 ptr 本身
//	rb++;
//	return 0;
//}