#include "string.h"
#include <string>
using namespace std;

int main() {
	string cmd;
	MyString *a = NULL, *b = NULL;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "new") {
			if (a != NULL) delete a;
			if (b != NULL) delete b;
			a = new MyString();
			b = new MyString();
			cout << "enter a" << endl;
			cin >> *a;
			cout << "enter b" << endl;
			cin >> *b;
		}
		if (cmd == "a" || cmd == "b") {
			string op, target;
			cin >> op >> target;
			MyString tmp = op == "+" ? ((cmd == "a" ? *a : *b) + (target == "a" ? *a : *b)) : ((cmd == "a"? *a : *b) * stoi(target));
			cout << tmp << endl;
		}
	}
}

