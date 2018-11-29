#include "string.h"
#include <string>
using namespace std;

int main() {
	string cmd;
	MyString *a = NULL, *b = NULL;
	char *k;
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
		else if (cmd == "a") {
			string op, target;
			cin >> op >> target;
			if (op == "*") {
				MyString tmp = ((*a)*stoi(target));
				cout << tmp << endl;
			}
			else {
				if (target == "a") { 
					MyString tmp = *a + *a;
					cout << tmp << endl;
				}
				else if (target == "b") {
					MyString tmp = *a + *b;
					cout << tmp << endl;
				}
			}
		}
		else if (cmd == "b") {
			string op, target;
			cin >> op >> target;
			if (op == "*") {
				MyString tmp = ((*b)*stoi(target));
				cout << tmp << endl;
			}
			else {
				if (target == "a") {
					MyString tmp = *b + *a;
					cout << tmp << endl;
				}
				else if (target == "b") {
					MyString tmp = *b + *b;
					cout << tmp << endl;
				}
			}
		}
	}
}

