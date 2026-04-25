#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define npos -1
using namespace std;
namespace mystring
{
    class string
    {
    public:
        friend ostream& operator<<(ostream& _cout, const mystring::string& s);
        friend istream& operator>>(istream& _cin, mystring::string& s);
        //迭代器和迭代器组件
        typedef char* iterator;
        typedef const char* const_iterator;
        const_iterator begin() const//√
        {
            const char* str = _str;
            return str;
        }
        iterator begin()//√
        {
            return _str;
        }
        iterator end()//√
        {
            return _str + _size;
        }
        const_iterator end()const //√
        {
            const char* str = _str;
            return str;
        }
    


        //构造函数
        string(const char* str = "")
        {
            cout << "gouzao" << endl;
            _capacity = strlen(str)*2;
            _size = strlen(str);
            _str = new char[_capacity];
            strcpy(_str, str);
        }

        //拷贝构造
        string(const string& s)
        {
            cout << "kaobeigouzao" << endl;
            /*_capacity = s._capacity;
            _size = s._size;
            _str = reserve(s._capacity);
            strcpy(_str, s._str);*/
            string tmp(s._str);
            swap(tmp);
        }
        //赋值运算符重载
        string& operator=(const string& s)
        {
            cout << "fuzhichongzai" << endl;
            /*     if (this != &s)
                 {
                     clear();
                     if (_capacity < s._capacity)
                     {
                         _str = reserve(s._capacity);
                     }
                     _size = s._size;
                     strcpy(_str, s._str);
                 }
                 */
            string tmp(s._str);
            swap(tmp);
        }
        void swap(string& s)
        {
            std::swap(s._str,_str);
            std::swap(s._size, _size);
            std::swap(s._capacity, _capacity);
        }
        //移动构造
        string(string&& Ref)
        {
            cout << "yidonggouzao" << endl;
            swap(Ref);
        }
        //移动赋值
        string& operator=(string&& Ref)
        {
            cout << "yidong fuzhi" << endl;
            swap(Ref);
            return *this;
        }

        //析构函数
        ~string()
        {
            cout << "xigouhanshu" << endl;
            if (_str)
            {
                delete[](_str);
                _str = nullptr;
                _capacity = _size = 0;
            }
        }
        //尾插
        void push_back(char c);

        //重载+=
        string& operator+=(char c);
        string& operator+=(const char* str);

        //尾插一个字符串
        void append(const char* str);

        //清空字符串
        void clear();

        //返回C_string类型的字符串
        const char* c_str()const
        {
            return _str;
        }
        //有多少个
        size_t size()const
        {
            return _size;
        }

        //有多大
        size_t capacity()const
        {
            return _capacity;
        }
        //空了吗
        bool empty()const;

        //留多少
        char* reserve(size_t n);

        //拿
        char& operator[](size_t index);
        const char& operator[](size_t index)const;

        //大小判断
        bool operator<(const string& s);
        bool operator<=(const string& s);
        bool operator>(const string& s);
        bool operator>=(const string& s);
        bool operator==(const string& s);
        bool operator!=(const string& s);

        // 删除pos位置上的元素，并返回该元素的下一个位置
        void erase(size_t pos, size_t len = npos);

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const;//meixie !!!!!!

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);

       //字串
        string substr(size_t pos, size_t len);
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };
    ostream& operator<<(ostream& _cout, const string& s);
    istream& operator>>(istream& _cin, string& s);
}
