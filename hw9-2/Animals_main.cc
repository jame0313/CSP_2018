#include "Animals.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string cmd;
	vector<Animals*> animals;
	while (cin >> cmd, cmd != "0") {
		if (cmd == "z") {
			string name;
			int age, numStripes;
			cin >> name >> age >> numStripes;
			animals.push_back(new Zebra(name, age, numStripes));
		}
		else if (cmd == "c") {
			string name, favoriteToy;
			int age;
			cin >> name >> age >> favoriteToy;
			animals.push_back(new Cat(name, age, favoriteToy));
		}
	}
	for (vector<Animals*>::iterator it = animals.begin(); it != animals.end(); it++) {
		(*it)->printInfo();
		delete *it;
	}
	animals.clear();
}
