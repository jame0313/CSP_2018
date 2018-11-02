#include "message_book.h"
#include <iostream>
int main() {
	string cmd;
	MessageBook mb;
	while (cin >> cmd, cmd!="quit") {
		if (cmd == "add") {
			int number;
			string raw,word,s;
			cin >> number;
            //cin.get();
            cin >> raw;
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
		    mb.printstring(ret);
            cout<<endl;
        }
		else if(cmd == "list") {
			vector<int> v = mb.GetNumbers();
			for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
				cout << *it << ": ";
                mb.printstring(mb.GetMessage(*it));
			}
		}
	}
}
