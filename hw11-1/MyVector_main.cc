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
		else if (cmd == "a") {
			string op, target;
			cin >> op >> target;
			if (target == "a") {
				*a + *a;
			}
			else if (target == "b") {
				*a + *b;
			}
			else {
				*a + stoi(target);
			}
			cout << *a << endl;		
		}
		else if (cmd == "b") {
			string op, target;
			cin >> op >> target;
			if (target == "a") {
				*b + *a;
			}
			else if (target == "b") {
				*b + *b;
			}
			else {
				*b + stoi(target);
			}
			cout << *b << endl;
		}
	}
}
