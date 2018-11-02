#include "message_book.h"
#include <iostream>

void MessageBook::AddMessage(int number, const string& message) {
	//cout << "in class addmessage function: |" << message << "|" << endl;
    string ret = message;
	this->messages_[number] = ret;
}

void MessageBook::DeleteMessage(int number) {
	map<int, string>::iterator pos = this->messages_.find(number);
	if(pos!=this->messages_.end()) this->messages_.erase(number);
}
vector<int> MessageBook::GetNumbers() const {
	vector<int> v;
	map<int, string> m = this->messages_;
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
		v.push_back(it->first);
	return v;
}
const string& MessageBook::GetMessage(int number) const {
	map<int, string> m = this->messages_;
	if (m.find(number) != m.end()) {
		const string& ret= m.find(number)->second;
		cout << "in class getmessage function: |" << ret << "|" << endl;
		return ret;
	}
	else { 
		const string& ret = ""; 
		return ret;
	}
}
void MessageBook::printstring(const string& s){
    cout << s << endl;
}
