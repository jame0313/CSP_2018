#include "class_function.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<A*> objects;
int main() {
	string cmd;
	while (cin >> cmd, cmd != "0") {
		if (cmd == "B") objects.push_back(new B);
		else if(cmd == "C") objects.push_back(new C);
		else if(cmd == "BB") objects.push_back(new BB);
	}
	for (vector<A*>::iterator it = objects.begin(); it != objects.end(); it++) {
		(*it)->test1();
		(*it)->test2();
		delete *it;
	}
	objects.clear();
}