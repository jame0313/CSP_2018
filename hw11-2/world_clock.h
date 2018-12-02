#pragma once
#include <iostream>
using namespace std;
class WorldClock {
public:
	void Tick(int seconds = 1);
	bool SetTime(int hour, int minute, int second);
	// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.

	int hour() const;
	int minute() const;
	int second() const;

private:
	int time;
};

// hh:mm:ss �������� �����
ostream& operator<<(ostream& os, const WorldClock& c);

// hh:mm:ss �� �Է¹���.
istream& operator>>(istream& is, WorldClock& c);
