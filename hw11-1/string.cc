#include "string.h"

MyString::MyString()
{
	a = NULL;
	len = 0;
}

MyString::MyString(char * _a, int _len): a(_a), len(_len) {}

MyString::~MyString()
{
	if(a!=NULL) delete[] a;
}

MyString MyString::operator+(const MyString & a)
{
	int nlen = this->len + a.len;
	char* na = new char[nlen+1];
	for (int i = 0; i <= nlen; i++) na[i] = 0;
	for (int i = 0; i < this->len; i++) {
		na[i] = this->a[i];
	}
	for (int i = 0; i < a.len; i++) {
		na[(this->len) + i] = a.a[i];
	}
	return MyString(na, nlen);
}

MyString MyString::operator*(const int a)
{
	int nlen = (this->len )*a;
	char* na = new char[nlen + 1];
	na[nlen] = 0;
	for (int t = 0; t < a; t++) {
		for (int i = 0; i < this->len; i++) {
			na[t*(this->len)+i] = this->a[i];
		}
	}
	return MyString(na, nlen);
}

ostream & operator<<(ostream & out, MyString & b)
{
	out << b.a;
	return out;
}

istream & operator>>(istream & in, MyString & b)
{
	char *tmp=new char [10001];
	in >> tmp;
	int cnt = 0;
	for (int i = 0; tmp[i] != 0; i++) cnt++;
	b.len = cnt;
	b.a = new char[b.len + 1];
	for (int i = 0; i < b.len; i++) b.a[i] = tmp[i];
	delete[] tmp;
	return in;
}
