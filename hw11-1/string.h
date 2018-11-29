#pragma once
#include <iostream>
using namespace std;
class MyString
{
private:
	int len;
	char* a;
public:
	MyString();
	MyString(char* _a, int _len);
	MyString(const MyString& str);
	~MyString();
	MyString operator+(const MyString& a);
	MyString operator*(const int a);
	friend ostream& operator << (ostream& out, MyString& b);
	friend istream& operator >> (istream& in, MyString& b);
};
