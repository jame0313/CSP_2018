#include "sorted_array.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
	string cmd;
	SortedArray arr;
	while (cin >> cmd) {
		if ('0' <= cmd[0] && cmd[0] <= '9') {
			int x = atoi(cmd.c_str());
			arr.AddNumber(x);
		}
		else {
			if (cmd == "ascend") {
				vector<int> v = arr.GetSortedAscending();
				for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
					cout << *it << ' ';
				}
				cout << endl;
			}
			else if (cmd == "descend") {
				vector<int> v = arr.GetSortedDescending();
				for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
					cout << *it << ' ';
				}
				cout << endl;
			}
			else if (cmd == "max") {
				int x = arr.GetMax();
				cout << x << endl;
			}
			else if (cmd == "min") {
				int x = arr.GetMin();
				cout << x << endl;
			}
			else if (cmd == "quit") {
				return 0;
			}
		}
	}
}