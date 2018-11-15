#pragma once
#include <string>
#include <iostream>
using namespace std;
class A {
public:
	A(int _memberA);
	virtual ~A();
	virtual void print();
private:
	int *memberA;
};

class B : public A {
public:
	B(double _memberB);
	virtual ~B();
	virtual void print();
public:
	double *memberB;
};

class C : public B {
public:
	C(string _memberC);
	virtual ~C();
	virtual void print();
private:
	string *memberC;
};