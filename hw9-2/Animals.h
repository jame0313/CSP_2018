#pragma once
#include <string>
using namespace std;

class Animals {
protected:
	string name;
	int age;
public:
	Animals(string _name, int _age);
	virtual void printInfo() { };
};

class Zebra : public Animals {
private:
	int numStripes;
public:
	Zebra(string _name, int _age, int _numStripes);
	virtual void printInfo();
};

class Cat : public Animals {
private:
	string favoriteToy;
public:
	Cat(string _name, int _age, string _favoriteToy);
	virtual void printInfo();
};

