#include "draw_shape.h"
#include <iostream>
using namespace std;

Canvas::Canvas(size_t row, size_t col)
{
	canvas.resize(col);
	for (int i = 0; i < col; i++) canvas[i].resize(row);
	Clear();
}

Canvas::~Canvas()
{
	for (int i = 0; i < canvas.size(); i++) canvas[i].clear();
	canvas.clear();
}

void Canvas::Resize(size_t w, size_t h)
{
	canvas.resize(h);
	for (int i = 0; i < h; i++) canvas[i].resize(w);
	Clear();
}

bool Canvas::DrawPixel(int x, int y, char brush)
{
	if (0 <= y && y <= canvas.size() && 0 <= x && x <= canvas[y].size()) {
		canvas[y][x] = brush;
		return true;
	}
	return false;
}

void Canvas::Print()
{
	cout << ' ';
	for (int i = 0; i < canvas[0].size(); i++) cout << i % 10;
	cout << endl;
	for (int i = 0; i < canvas.size(); i++) {
		cout << i % 10;
		for (int j = 0; j < canvas[i].size(); j++) {
			cout << canvas[i][j];
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < canvas.size(); i++) {
		for (int j = 0; j < canvas[i].size(); j++) {
			canvas[i][j] = '.';
		}
	}
}

Shape::Shape(int _xpos, int _ypos, char _brush)
{
	xpos = _xpos;
	ypos = _ypos;
	brush = _brush;
}

Rectangle::Rectangle(int _xpos, int _ypos, int _width, int _height, char _brush): Shape(_xpos,_ypos,_brush)
{
	width = _width;
	height = _height;
}

void Rectangle::Draw(Canvas * canvas)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			canvas->DrawPixel(xpos + j, ypos + i, brush);
		}
	}
}

void Rectangle::Print()
{
	cout << "rect" << xpos << ' ' << ypos << ' ' << width << ' ' << height << ' ' << brush;
}

UpTriangle::UpTriangle(int _xpos, int _ypos, int _height, char _brush): Shape(_xpos,_ypos,_brush)
{
	height = _height;
}

void UpTriangle::Draw(Canvas * canvas)
{
	for (int i = 0; i < height; i++) {
		for (int j = -i; j <= i; j++) {
			canvas->DrawPixel(xpos + j, ypos + i, brush);
		}
	}
}

void UpTriangle::Print()
{
	cout << "tri_up" << xpos << ' ' << ypos << ' ' << height << ' ' << brush;
}

DownTriangle::DownTriangle(int _xpos, int _ypos, int _height, char _brush): Shape(_xpos,_ypos,_brush)
{
	height = _height;
}

void DownTriangle::Draw(Canvas * canvas)
{
	for (int i = 0; i < height; i++) {
		for (int j = -i; j <= i; j++) {
			canvas->DrawPixel(xpos + j, ypos - i, brush);
		}
	}
}

void DownTriangle::Print()
{
	cout << "tri_down" << xpos << ' ' << ypos << ' ' << height << ' ' << brush;
}

Diamond::Diamond(int _xpos, int _ypos, int _radius, char _brush): Shape(_xpos,_ypos,_brush)
{
	radius = _radius;
}

void Diamond::Draw(Canvas * canvas)
{
	for (int i = 0; i < radius; i++) {
		for (int j = -i; j <= i; j++) {
			canvas->DrawPixel(xpos + j, ypos + i, brush);
		}
	}
	for (int j = -radius; j <= radius; j++) canvas->DrawPixel(xpos + j, ypos + radius, brush);
	for (int i = 0; i < radius; i++) {
		for (int j = -i; j <= i; j++) {
			canvas->DrawPixel(xpos + j, ypos +2*radius- i, brush);
		}
	}
}

void Diamond::Print()
{
	cout << "diamond" << xpos << ' ' << ypos << ' ' << radius << ' ' << brush;
}
