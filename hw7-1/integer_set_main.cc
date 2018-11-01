#include "integer_set.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
	string cmd;
	IntegerSet set;
	while (cin >> cmd) {
		if (cmd == "quit") {
			return 0;
		}
		else if (cmd == "add") {
			int x;
			cin >> x;
			set.AddNumber(x);
			vector<int> v = set.GetAll();
			for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
				cout << *it << ' ';
			}
			cout << endl;
			
		}
		else if (cmd == "del") {
			int x;
			cin >> x;
			set.DeleteNumber(x);
			vector<int> v = set.GetAll();
			for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
				cout << *it << ' ';
			}
			cout << endl;
		}
		else if (cmd == "get") {
			int x;
			cin >> x;
			int ret = set.GetItem(x);
			cout << ret << endl;
		}
	}
}