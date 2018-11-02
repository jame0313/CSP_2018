#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

class MessageBook {
public:
	MessageBook() {}
	~MessageBook() {
		messages_.clear();
	}
	void AddMessage(int number, const string& message);
	void DeleteMessage(int number);
    void printstring(const string& s);
	vector<int> GetNumbers() const;
	const string& GetMessage(int number) const;

private:
	map<int, string> messages_;
};