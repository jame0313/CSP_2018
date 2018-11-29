#include "MyVector.h"

MyVector::MyVector(int _max_num)
{
	max_num = _max_num;
	a = new double[max_num];
}

MyVector::~MyVector()
{
	delete[] a;
}

MyVector MyVector::operator+(const MyVector & a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] += a.a[i];
	}
	return *this;
}

MyVector MyVector::operator-(const MyVector & a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] -= a.a[i];
	}
	return *this;
}

MyVector MyVector::operator+(const int a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] += a;
	}
	return *this;
}

MyVector MyVector::operator-(const int a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] -= a;
	}
	return *this;
}

ostream & operator<<(ostream & out, MyVector & b)
{
	for (int i = 0; i < b.max_num; i++) {
		out << b.a[i]<<" ";
	}
	return out;
}

istream & operator>>(istream & in, MyVector & b)
{
	for (int i = 0; i < b.max_num; i++) {
		in >> b.a[i];
	}
	return in;
}
