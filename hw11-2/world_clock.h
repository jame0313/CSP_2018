#pragma once
#include <iostream>
using namespace std;
class WorldClock {
public:
	void Tick(int seconds = 1);
	bool SetTime(int hour, int minute, int second);
	// 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.

	int hour() const;
	int minute() const;
	int second() const;

private:
	int time;
};

// hh:mm:ss 형식으로 입출력
ostream& operator<<(ostream& os, const WorldClock& c);

// hh:mm:ss 로 입력받음.
istream& operator>>(istream& is, WorldClock& c);
