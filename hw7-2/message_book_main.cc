#include "message_book.h"
#include <iostream>
#include <sstream>
int main() {
	string cmd;
	MessageBook mb;
	while (cin >> cmd, cmd!="quit") {
		if (cmd == "add") {
			int number;
			string raw,word,s;
			cin >> number;
			getline(cin, raw);
			cout << "raw: |" << raw << '|' << endl;
			stringstream ss;
			ss.str(raw);
			while (ss >> word) {
				//cout << "word: |" << word << '|' << endl;
				s+=word+" ";
			}
			//cout << "sentence: |" << s << '|' << endl;
			if (cin.fail()) return -1;
			mb.AddMessage(number, raw);
		}
		else if (cmd == "delete") {
			int number;
			cin >> number;
			if (cin.fail()) return -1;
			mb.DeleteMessage(number);
		}
		else if (cmd == "print") {
			int number;
			cin >> number;
			if (cin.fail()) return -1;
			const string& ret = mb.GetMessage(number);
			cout << ret << endl << endl;
		}
		else if(cmd == "list") {
			vector<int> v = mb.GetNumbers();
			for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
				cout << *it << ": " << mb.GetMessage(*it) << endl;
			}
		}
	}
}