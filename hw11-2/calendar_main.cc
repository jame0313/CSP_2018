#include "calendar.h"
#include <string>
using namespace std;

int main() {
	string cmd;
	Date c;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "set") {
			cin >> c;
		}
		else if (cmd == "next_day") {
			c.NextDay();
			cout << c << endl;
		}
		else if (cmd == "next") {
			int t;
			cin >> t;
			c.NextDay(t);
			cout << c << endl;
		}
	}
}