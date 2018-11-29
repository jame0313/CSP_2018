#include "MyVector.h"
#include <string>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
	string cmd;
	MyVector *a=NULL, *b=NULL;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "new") {
			int num;
			cin >> num;
			if(a!=NULL) delete a;
			if(b!=NULL) delete b;
			a = new MyVector(num);
			b = new MyVector(num);
			cout << "enter a" << endl;
			cin >> *a;
			cout << "enter b" << endl;
			cin >> *b;
		}
		else if (cmd == "a" || cmd == "b") {
			string op, target;
			cin >> op >> target;
			if (target == "a" || target == "b") {
				MyVector tmp = op=="+" ? ((cmd=="a"?*a:*b) + (target == "a" ? *a : *b)) : ((cmd == "a" ? *a : *b) - (target == "a" ? *a : *b));
				cout << tmp << endl;
			}
			else {
				MyVector tmp = op == "+" ? ((cmd == "a" ? *a : *b) + stoi(target)) : ((cmd == "a" ? *a : *b) - stoi(target));
				cout << tmp << endl;
			}
		}
	}
}
