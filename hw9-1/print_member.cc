#include "print_member.h"
A::A(int _memberA)
{
	memberA = new int(_memberA);
	cout << "new memberA" << endl;
}

B::B(double _memberB): A(1)
{
	memberB = new double(_memberB);
	cout << "new memberB" << endl;
}

C::C(string _memberC): B(1.1)
{
	memberC = new string(_memberC);
	cout << "new memberC" << endl;
}

A::~A()
{
	delete memberA;
	cout << "delete memberA" << endl;
}

B::~B()
{
	delete memberB;
	cout << "delete memberB" << endl;
}

C::~C()
{
	delete memberC;
	cout << "delete memberC" << endl;
}

void A::print()
{
	cout << "*memberA " << *memberA << endl;
}

void B::print()
{
	A::print();
	cout << "*memberB " << *memberB << endl;
}

void C::print()
{
	B::print();
	cout << "*memberC " << *memberC << endl;
}