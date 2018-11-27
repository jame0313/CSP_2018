#include "print_shape.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string cmd;
	vector<Shape*> shapes;
	cout.precision(15);
	while (cin >> cmd, cmd != "0") {
		if (cmd == "c") {
			double radius;
			cin >> radius;
			shapes.push_back(new Circle(radius));
		}
		else if (cmd == "r") {
			double width, height;
			cin >> width >> height;
			shapes.push_back(new Rectangle(width,height));
		}
	}
	for (vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
		cout << (*it)->getTypeString() << ", " << (*it)->getArea() << ", " << (*it)->getPerimeter() << endl;
		delete *it;
	}
	shapes.clear();
}