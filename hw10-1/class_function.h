#pragma once
#include <iostream>
using namespace std;
class A {
public:
	virtual void test1();
	virtual void test2() = 0;
	virtual ~A() { };
};

class B : public A {
	virtual void test2();
};


class C : public A {
	virtual void test1();
	virtual void test2();
};

class BB : public B {
	virtual void test1();
};