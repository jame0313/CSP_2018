#include "dynamic_cast.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<B*> objects;
int main() {
	string cmd;
	while (cin >> cmd, cmd != "0") {
		if (cmd == "B") objects.push_back(new B);
		else if (cmd == "C") objects.push_back(new C);
		else if (cmd == "D") objects.push_back(new D);
	}
	for (vector<B*>::iterator it = objects.begin(); it != objects.end(); it++) {
		C* c = dynamic_cast<C*>(*it);
		if (c) c->test_C();
		D* d = dynamic_cast<D*>(*it);
		if (d) d->test_D();
		delete *it;
	}
	objects.clear();
}