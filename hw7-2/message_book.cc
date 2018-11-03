#include "message_book.h"
#include <iostream>
string blank = "";

void MessageBook::AddMessage(int number, const string& message) {
	string ret = message;
	this->messages_[number] = ret;
}

void MessageBook::DeleteMessage(int number) {
	if (this->messages_.find(number) != this->messages_.end())
		this->messages_.erase(number);
}
vector<int> MessageBook::GetNumbers() const {
	vector<int> v;
	for (map<int, string>::const_iterator it = this->messages_.begin(); it != this->messages_.end(); it++)
		v.push_back(it->first);
	return v;
}
const string& MessageBook::GetMessage(int number) const {
	if (this->messages_.find(number) != this->messages_.end()) {
		return this->messages_.find(number)->second;
	}
	else {
		const string& ret = blank;
		return ret;
	}
}