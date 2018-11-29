#include "MyVector.h"

MyVector::MyVector(int _max_num)
{
	max_num = _max_num;
	a = new double[max_num];
	for (int i = 0; i < max_num; i++) a[i] = 0;
}

MyVector::MyVector(int _max_num, double *a): max_num(_max_num)
{
	this->a = new double[max_num];
	for (int i = 0; i < max_num; i++) this->a[i] = a[i];

}

MyVector::MyVector(const MyVector & v):max_num(v.max_num) {
	a = new double[max_num];
	for (int i = 0; i < max_num; i++) a[i] = v.a[i];
}

MyVector::~MyVector()
{
	if(a!=NULL) delete[] a;
}

MyVector MyVector::operator+(const MyVector & a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] += a.a[i];
	}
	return MyVector(max_num,this->a);
}

MyVector MyVector::operator-(const MyVector & a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] -= a.a[i];
	}
	return MyVector(max_num, this->a);
}

MyVector MyVector::operator+(const int a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] += a;
	}
	return MyVector(max_num, this->a);
}

MyVector MyVector::operator-(const int a)
{
	for (int i = 0; i < max_num; i++) {
		this->a[i] -= a;
	}
	return MyVector(max_num, this->a);
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
