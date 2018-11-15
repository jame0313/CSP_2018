#include "print_info.h"
#include <iostream>
using namespace std;
string A::getTypeInfo()
{
	return string("This is an instance of class A");
}

string B::getTypeInfo()
{
	return string("This is an instance of class B");
}

string C::getTypeInfo()
{
	return string("This is an instance of class C");
}

void printObjectTypeInfo1(A * object)
{
	cout << object->getTypeInfo() << endl;
}

void printObjectTypeInfo2(A & object)
{
	cout << object.getTypeInfo() << endl;
}