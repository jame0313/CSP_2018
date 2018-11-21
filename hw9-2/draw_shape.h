#pragma once
#include <vector>
using namespace std;

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();

	// Canvas ũ�⸦ w x h �� �����Ѵ�. �׷��� ������ �����Ѵ�.
	void Resize(size_t w, size_t h);

	// (x,y) ��ġ�� ch ���ڸ� �׸���. ���� ���� x,y �� �����Ѵ�.
	bool DrawPixel(int x, int y, char brush);

	//ĵ������ ������ ȭ�鿡 ����Ѵ�.
	void Print();

	// �׷��� ������ ��� ����� ('.'���� �ʱ�ȭ)
	void Clear();
public:
	vector<vector<char> > canvas;
};
class Shape {
public:
	Shape(int _xpos, int _ypos, char _brush );
	virtual ~Shape() {};
	virtual void Print() {};
	virtual void Draw(Canvas* canvas) {};
protected:
	int xpos, ypos;
	char brush;
	// ������ ���� �Ӽ��� ����.
};

class Rectangle : public Shape {
private:
	int width, height;
public:
	Rectangle(int _xpos, int _ypos, int _width, int _height, char _brush);
	virtual void Draw(Canvas* canvas);
	virtual void Print();
};
class UpTriangle : public Shape {
private:
	int height;
public:
	UpTriangle(int _xpos, int _ypos, int _height, char _brush);
	virtual void Draw(Canvas* canvas);
	virtual void Print();
};
class DownTriangle : public Shape {
private:
	int height;
public:
	DownTriangle(int _xpos, int _ypos, int _height, char _brush);
	virtual void Draw(Canvas* canvas);
	virtual void Print();
};
class Diamond : public Shape {
private:
	int radius;
public:
	Diamond(int _xpos, int _ypos, int _radius, char _brush);
	virtual void Draw(Canvas* canvas);
	virtual void Print();
};
