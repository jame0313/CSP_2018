#include "world_clock.h"
#include <string>
using namespace std;

int main() {
	string cmd;
	WorldClock c;
	c.SetTime(0, 0, 0);
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "set") {
			cin >> c;
		}
		else if (cmd == "tick") {
			int t = 0;
			cin >> t;
			c.Tick(t);
			cout << c << endl;
		}
	}
}