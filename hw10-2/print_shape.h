#pragma once
#include <string>
#define PI 3.141592
using namespace std;

class Shape {
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual string getTypeString() = 0;
	virtual ~Shape() {};
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double _radius);
	virtual double getArea();
	virtual double getPerimeter();
	virtual string getTypeString();
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double _width, double _height);
	virtual double getArea();
	virtual double getPerimeter();
	virtual string getTypeString();
};