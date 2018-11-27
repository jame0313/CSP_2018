#include "print_shape.h"

Circle::Circle(double _radius)
{
	radius = _radius;
}

double Circle::getArea()
{
	return PI*radius*radius;
}

double Circle::getPerimeter()
{
	return 2*PI*radius;
}

string Circle::getTypeString()
{
	return "Circle";
}

Rectangle::Rectangle(double _width, double _height)
{
	width = _width;
	height = _height;
}

double Rectangle::getArea()
{
	return width*height;
}

double Rectangle::getPerimeter()
{
	return 2*(width+height);
}

string Rectangle::getTypeString()
{
	return "Rectangle";
}
