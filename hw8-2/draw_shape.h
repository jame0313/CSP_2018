#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Shape {
public:
	Shape();
	Shape(int xpos,int ypos, char brush);

	double GetArea() {};
	int GetPerimeter() {};
	void Draw(int canvas_width, int canvas_height) {};

protected:
	// 모든 도형에 공통적인 속성 정의
	int _xpos, _ypos;
	char _brush;
};

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(int xpos, int ypos, int height, int width, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);

protected:
	int _width, _height;
};

class Square : public Rectangle {
public:
	Square();
	Square(int xpos, int ypos, int width, char brush);
};

class Diamond : public Shape {
public:
	Diamond();
	Diamond(int xpos, int ypos, int radius, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);

protected:
	int _radius;
};