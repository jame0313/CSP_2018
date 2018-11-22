#include "shapes.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	double tw, th, rw, rh;
	cin >> tw >> th;
	cin >> rw >> rh;
	vector<Shape*> shapes;
	shapes.push_back(new Triangle(tw, th));
	shapes.push_back(new Rectangle(rw, rh));
	for (vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
		cout << (*it)->getArea() << endl;
		delete *it;
	}
	shapes.clear();

}