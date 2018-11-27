#include "clock_time.h"
#include <iostream>
#include <vector>
using namespace std;
class Clock {
protected:
	ClockTime _clockTime;
	double _driftPerSecond;
	double _totalDrift;
public:
	Clock(int hour, int minute, int second, double driftPerSecond) {
		_clockTime.setTime(hour, minute, second, 1);
		_driftPerSecond = driftPerSecond;
	};
	void reset() {
		_clockTime.reset();
		_totalDrift = 0;
	}
	void tick() {
		_clockTime.increment();
		_totalDrift += _driftPerSecond;
	};
	virtual void displayTime() = 0;
};

class NaturalClock :public Clock {
public:
	NaturalClock(int hour, int minute, int second, double driftPerSecond) :Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class MechanicalClock :public Clock {
public:
	MechanicalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class DigitalClock :public Clock {
public:
	DigitalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class QuantumClock :public Clock {
public:
	QuantumClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class SundialClock : public NaturalClock {
public:
	SundialClock(int hour, int minute, int second) : NaturalClock(hour, minute, second, 0) {}
	virtual void displayTime() {
		cout << "SundialClock ";
		_clockTime.display();
		cout << ", total drift: " << (int)(_totalDrift + 0.5) << endl;
	}
};

class CuckooClock : public MechanicalClock {
public:
	CuckooClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0) {}
	virtual void displayTime() {
		cout << "CuckooClock ";
		_clockTime.display();
		cout << ", total drift: " << (int)(_totalDrift + 0.5) << endl;
	}
};

class GrandFatherClock : public MechanicalClock {
public:
	GrandFatherClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0.000694444) {}
	virtual void displayTime() {
		cout << "GrandFatherClock ";
		_clockTime.display();
		cout << ", total drift: " << (int)(_totalDrift+0.5) << endl;
	}
};

class WristClock : public DigitalClock {
public:
	WristClock(int hour, int minute, int second) : DigitalClock(hour, minute, second, 0.000347222) {}
	virtual void displayTime() {
		cout << "WristClock ";
		_clockTime.display();
		cout << ", total drift: " << (int)(_totalDrift + 0.5) << endl;
	}
};

class AtomicClock : public QuantumClock {
public:
	AtomicClock(int hour, int minute, int second) : QuantumClock(hour, minute, second, 0.000034722) {}
	virtual void displayTime() {
		cout << "AtomicClock ";
		_clockTime.display();
		cout << ", total drift: " << (int)(_totalDrift + 0.5) << endl;
	}
};
typedef vector<Clock*>::iterator clit;

int main() {
	int del_time;
	cin >> del_time;
	vector<Clock*> clocks;
	clocks.push_back(new SundialClock(0, 0, 0));
	clocks.push_back(new CuckooClock(0, 0, 0));
	clocks.push_back(new GrandFatherClock(0, 0, 0));
	clocks.push_back(new WristClock(0, 0, 0));
	clocks.push_back(new AtomicClock(0, 0, 0));
	for (clit it = clocks.begin(); it != clocks.end(); it++) {
		(*it)->reset();
	}
	cout << "Reported clock times after resetting:" << endl;
	for (clit it = clocks.begin(); it != clocks.end(); it++) {
		(*it)->displayTime();
	}
	cout << endl << "Running the clocks..." << endl<<endl;
	for (clit it = clocks.begin(); it != clocks.end(); it++) {
		for (int i=0;i<del_time;i++) (*it)->tick();
	}
	cout << "Reported clock times after running:" << endl;
	for (clit it = clocks.begin(); it != clocks.end(); it++) {
		(*it)->displayTime();
		delete *it;
	}
	clocks.clear();
}