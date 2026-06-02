#include "ModernString.h"
namespace mystring
{
	//尾插
	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	//重载+=
	string& string::operator+= (char c)
	{
		push_back(c);
		return *this;
	}
	string& string::operator+= (const char* str)
	{
		append(str);
		return *this;
	}

	//尾插一个字符串
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	//清空字符串
	void string::clear()
	{
		_size = 0;
		_str[0] = '\0';
	}
	//空了吗
	bool string::empty()const
	{
		if (_size == 0)
			return true;
		else
			return false;
	}


	//留多少
	char* string::reserve(size_t n)
	{
		assert(n > _capacity);
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
		return _str;
	}

	//拿
	char& string::operator[](size_t index)
	{
		assert(index < _size);
		assert(index > 0);
		return *(_str + index);
	}
	const char& string::operator[](size_t index)const
	{
		assert(index < _size);
		assert(index > 0);
		return *(_str + index);
	}

	//大小判断
	bool string::operator<(const string& s)
	{
		if (strlen(_str) < strlen(s._str))
		{
			return true;
		}
		else
			return false;
	}
	bool string::operator<=(const string& s)
	{
		if (strlen(_str) <= strlen(s._str))
		{
			return true;
		}
		else
			return false;
	}
	bool string::operator>(const string& s)
	{
		if (strlen(_str) > strlen(s._str))
		{
			return true;
		}
		else
			return false;
	}
	bool string::operator>=(const string& s)
	{
		if (strlen(_str) >= strlen(s._str))
		{
			return true;
		}
		else
			return false;
	}
	bool string::operator==(const string& s)
	{
		if (strlen(_str) == strlen(s._str))
		{
			return true;
		}
		else
			return false;
	}
	bool string::operator!=(const string& s)
	{
		if (strlen(_str) == strlen(s._str))
		{
			return false;
		}
		else
			return true;
	}

	// 返回c在string中第一次出现的位置
	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);
		for (int i = pos; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}
		return npos;
	}

	// 返回子串s在string中第一次出现的位置
	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);
		char* tmp = strstr(_str + pos, s);
		if (tmp == nullptr)
		{
			return npos;
		}
		else
		{
			return tmp - _str;
		}
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& string::insert(size_t pos, char c)
	{
		assert(pos < _size);
		if (_size = _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		for (int i = _size - 1; i >= pos; i--)
		{
			_str[i + 1] = _str[i];
		}
		_str[pos] = c;
		_size++;
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		if (_size = _capacity)
		{
			reserve(_size + strlen(str) < _capacity * 2 ? _capacity * 2 : _size + strlen(str));
		}
		for (int i = _size - 1; i >= pos; i--)
		{
			_str[i + strlen(str)] = _str[i];
		}
		for (int j = pos; j < _size; j++)
		{
			_str[j] = str[j];
		}
		_size -= strlen(str);
		return *this;
	}
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string substr;
		for (int i = pos; i <= pos + len; i++)
		{
			substr.push_back(_str[i]);
		}
		return substr;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		for (int i = pos; i < pos + len; i++)
		{
			_str[pos] = _str[pos + 1];
		}
		_size -= len;
	}

	//流操作
	ostream& operator<<(ostream& _cout, const string& s)
	{
		for (int i = 0; i < s._size; i++)
		{
			_cout << s._str[i] << " ";
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, string& s)
	{
		s.clear();
		char buff[258];
		int i = 0;
		char ch = 0;
		ch = _cin.get();
		while (ch != ' ' && ch != '\n')
		{
			ch = _cin.get();
			buff[i++] = ch;
			if (i >= 257)
			{
				buff[i++] = '\0';
				s += buff;
				i = 0;
			}
		}
		if (i != 0)
		{
			buff[i++] = '\0';
			s += buff;
		}
		return _cin;
	}
}