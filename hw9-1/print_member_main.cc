#include "print_member.h"
#include <vector>
using namespace std;

int main() {
	int a;
	double b;
	string c;
	cin >> a >> b >> c;
	vector<A*> objects;
	objects.push_back(new A(a));
	objects.push_back(new B(b));
	objects.push_back(new C(c));
	for (vector<A*>::iterator it = objects.begin(); it != objects.end(); it++) {
		(*it)->print();
	}
	for (vector<A*>::iterator it = objects.begin(); it != objects.end(); it++) {
		delete *it;
	}
	objects.clear();
}