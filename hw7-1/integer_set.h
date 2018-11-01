#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class IntegerSet {
public:
	IntegerSet() {};
	~IntegerSet() {
		numbers_.clear();
	};

	void AddNumber(int num);
	void DeleteNumber(int num);

	int GetItem(int pos) const;
	vector<int> GetAll() const;

private:
	vector<int> numbers_;
};