#include "print_info.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<A*> objects;
	objects.push_back(new A);
	objects.push_back(new B);
	objects.push_back(new C);
	for (vector<A*>::iterator it = objects.begin(); it != objects.end(); it++) {
		printObjectTypeInfo1(*it);
		printObjectTypeInfo2(**it);
		delete *it;
	}
	objects.clear();
}