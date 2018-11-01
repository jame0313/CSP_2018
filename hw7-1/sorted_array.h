#pragma once
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class SortedArray {
public:
	SortedArray() {};
	~SortedArray() {
		numbers_.clear();
	};

	void AddNumber(int num);

	vector<int> GetSortedAscending() const;
	vector<int> GetSortedDescending() const;
	int GetMax() const;
	int GetMin() const;

private:
	vector<int> numbers_;
};