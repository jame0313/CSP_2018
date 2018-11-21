#pragma once
#include <vector>
using namespace std;

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();

	// Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
	void Resize(size_t w, size_t h);

	// (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
	bool DrawPixel(int x, int y, char brush);

	//캔버스의 내용을 화면에 출력한다.
	void Print();

	// 그려진 내용을 모두 지운다 ('.'으로 초기화)
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
	// 도형의 공통 속성을 정의.
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
