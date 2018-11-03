#include "message_book.h"
#include <iostream>

int main() {
	string cmd;
	MessageBook mb;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "add") {
			int number;
			string s;
			cin >> number;
			char chk = cin.get();
            if(chk!=' ') return -1;
            getline(cin, s);
			if (cin.fail()) return -1;
			mb.AddMessage(number, s);
		}
		else if (cmd == "delete") {
			int number;
			cin >> number;
			if (cin.fail()) return -1;
			mb.DeleteMessage(number);
		}
		else if (cmd == "print") {
			int number;
			cin >> number;
			if (cin.fail()) return -1;
			cout << mb.GetMessage(number) << '\n' << endl;
		}
		else if (cmd == "list") {
			vector<int> v = mb.GetNumbers();
			for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
				cout << *it << ": " << mb.GetMessage(*it) << endl;
			}
		}
	}
}
