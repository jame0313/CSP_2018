#pragma once
class Shape {
protected:
	double width, height;
public:
	Shape(double _width, double _height);
	virtual double getArea() = 0;
};

class Triangle : public Shape {
public:
	Triangle(double _width, double _height);
	virtual double getArea();
};

class Rectangle : public Shape {
public:
	Rectangle(double _width, double _height);
	virtual double getArea();
};