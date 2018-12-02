#include "world_clock.h"

void WorldClock::Tick(int seconds)
{
	int _time = time + seconds;
	while (_time < 0) _time += 86400;
	_time %= 86400;
	time = _time;
}

bool WorldClock::SetTime(int hour, int minute, int second)
{
	if (0 <= hour && hour <24) {
		if (0 <= minute && minute < 60) {
			if (0 <= second && second < 60) {
				time = hour * 3600 + minute * 60 + second;
				return true;
			}
		}
	}
	return false;
}

int WorldClock::hour() const
{
	return time/3600;
}

int WorldClock::minute() const
{
	return (time/60)%60;
}

int WorldClock::second() const
{
	return time%60;
}

ostream & operator<<(ostream & os, const WorldClock & c)
{
	os << c.hour() << ':' << c.minute() << ':' << c.second();
	return os;
}

istream & operator>>(istream & is, WorldClock & c)
{
	int t[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		char cstr[10001] = { 0, };
		is.getline(cstr, 10001, i!=2?':':'\n');
		t[i] = atoi(cstr);
	}
	if (c.SetTime(t[0], t[1], t[2]) == false) {
		cout << "Invalid time: " << t[0] << ':' << t[1] << ':' << t[2] << endl;
	}
	else cout << c << endl;
	return is;
}
