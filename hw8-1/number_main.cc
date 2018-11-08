#include "number.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	string cmd;
	while (cin >> cmd,cmd!="quit") {
		int num;
		cin >> num;
		if (cmd == "number") {
			Number number;
			number.setNumber(num);
			cout << "getNumber(): " << number.getNumber() << endl;
		}
		else if (cmd == "square") {
			Square square;
			square.setNumber(num);
			cout << "getNumber(): " << square.getNumber() << endl;
			cout << "getSquare(): " << square.getSquare() << endl;
		}
		else if (cmd == "cube") {
			Cube cube;
			cube.setNumber(num);
			cout << "getNumber(): " << cube.getNumber() << endl;
			cout << "getSquare(): " << cube.getSquare() << endl;
			cout << "getCube(): " << cube.getCube() << endl;
		}
	}
}