#pragma once
class Number
{
protected:
	int _num;
public:
	void setNumber(int num)
	{
		_num = num;
	}
	int getNumber()
	{
		return _num;
	}
};

class Square : public Number
{
public:
	int getSquare(); // setNumber()�� ������ ������ ������ ���� �ϵ��� �ҽ� ���Ͽ� ����
};

class Cube : public Square
{
public:
	int getCube(); // setNumber()�� ������ ������ �������� �����ϵ��� �ҽ� ���Ͽ� ����
};