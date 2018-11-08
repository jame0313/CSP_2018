#pragma once
#include <iostream>
using namespace std;
class Rectangle {
public:
	Rectangle(int width, int height);	// �ʿ��� �����͸� ��������� �����ϵ��� �ҽ� ���Ͽ� ����
	int getArea();	// �簢���� ���̸� ���ϵ��� �ҽ� ���Ͽ� ����
	int getPerimeter();	// �簢���� �ѷ��� ���ϵ��� �ҽ� ���Ͽ� ����
protected:
	int _width;
	int _height;
	// �ʿ��� ��������� ����
};

class Square : public Rectangle {
public:
	Square(int width);	// �θ� Ŭ������ �����ڸ� ������ ȣ���ϵ��� �ҽ� ���Ͽ� ����
	void print();	// Square��ü�� ������ ��� (�Ʒ� ���� �� ����)
};

class NonSquare : public Rectangle {
public:
	NonSquare(int width, int height);	// �θ� Ŭ������ �����ڸ� ������ ȣ���ϵ��� �ҽ� //���Ͽ� ����
	void print();	// NonSquare ��ü�� ������ ��� (�Ʒ� ���� �� ����)
};