#include "draw_shape.h"
Shape::Shape() {}
Shape::Shape(int xpos, int ypos, char brush) {
	_xpos = xpos;
	_ypos = ypos;
	_brush = brush;
}

Rectangle::Rectangle() {}
Rectangle::Rectangle(int xpos, int ypos, int height, int width, char brush) :
	Shape(xpos, ypos, brush)
{
	_height = height;
	_width = width;
}

Square::Square() {}
Square::Square(int xpos, int ypos, int width, char brush):
	Rectangle(xpos,ypos,width, width, brush)
{}

Diamond::Diamond() {}
Diamond::Diamond(int xpos, int ypos, int radius,char brush) :
	Shape(xpos, ypos, brush)
{
	_radius = radius;
}

double Rectangle::GetArea() {
	return _height * _width;
}
int Rectangle::GetPerimeter() {
	return 2 * (_height + _width);
}

double Diamond::GetArea() {
	return ((double)(2*_radius+1)*(2*_radius+1))/2;
}
int Diamond::GetPerimeter() {
	return (2*_radius + 1) * 4;
}

void Rectangle::Draw(int canvas_width, int canvas_height) {
	vector<vector<bool> >map;
	map.resize(canvas_width);
	for (int i = 0; i < canvas_width; i++) map[i].resize(canvas_height);
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			int x = _xpos + j, y = _ypos + i;
			if (0 <= x && x < canvas_width && 0 <= y && y <= canvas_height) {
				map[x][y] = true;
			}
		}
	}
	cout << ' ';
	for (int i = 0; i < canvas_width; i++)cout << i;
	cout << endl;
	for (int i = 0; i < canvas_height; i++) {
		cout << i;
		for (int j = 0; j < canvas_width; j++) cout << (map[j][i] ? _brush : '.');
		cout << endl;
	}
}

void Diamond::Draw(int canvas_width, int canvas_height) {
	vector<vector<bool> >map;
	map.resize(canvas_width);
	for (int i = 0; i < canvas_width; i++) map[i].resize(canvas_height);
	for (int i = 0; i < _radius; i++) {
		for (int j = -i; j <= i; j++) {
			int x = _xpos + j, y = _ypos + i;
			if (0 <= x && x < canvas_width && 0 <= y && y <= canvas_height) {
				map[x][y] = true;
			}
		}
	}
	for (int j = -_radius; j <= _radius; j++) {
		int x = _xpos + j, y = _ypos + _radius;
		if (0 <= x && x < canvas_width && 0 <= y && y <= canvas_height) {
			map[x][y] = true;
		}
	}
	for (int i = _radius+1; i < 2*_radius+1; i++) {
		int k = 2 * _radius- i;
		for (int j = -k; j <= k; j++) {
			int x = _xpos + j, y = _ypos + i;
			if (0 <= x && x < canvas_width && 0 <= y && y <= canvas_height) {
				map[x][y] = true;
			}
		}
	}
	cout << ' ';
	for (int i = 0; i < canvas_width; i++)cout << i;
	cout << endl;
	for (int i = 0; i < canvas_height; i++) {
		cout << i;
		for (int j = 0; j < canvas_width; j++) cout << (map[j][i] ? _brush : '.');
		cout << endl;
	}
	map.clear();
}