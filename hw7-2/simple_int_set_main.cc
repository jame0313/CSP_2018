#include "simple_int_set.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
string op[] = { "+" ,"*","-" };
int main() {
	string cmd;
	while (getline(cin, cmd)) {
		int sw = -1;
		for (int i = 0; i < 3; i++) {
			if (cmd.find(op[i]) != cmd.npos) {
				sw = i;
				break;
			}
		}
		if (sw == -1) return 0;
		if (cmd.find('{') == cmd.npos || cmd.find('}') == cmd.npos) return 0;
		set<int> left, right;
		stringstream stream;
		stream.str(cmd);
		string c;
		while (stream >> c && c != op[sw]) {
			if (c != "{"&&c != "}") left.insert(atoi(c.c_str()));
		}
		while (stream >> c) {
			if (c != "{"&&c != "}") right.insert(atoi(c.c_str()));
		}
		set<int> ret;
		if (sw == 0) {
			ret = SetUnion(left, right);
		}
		else if (sw == 1) {
			ret = SetIntersection(left, right);
		}
		else {
			ret = SetDifference(left, right);
		}
		cout << "{" << ' ';
		for (set<int>::iterator it = ret.begin(); it != ret.end(); it++) {
			cout << *it << ' ';
		}
		cout << "}" << endl;
	}
}