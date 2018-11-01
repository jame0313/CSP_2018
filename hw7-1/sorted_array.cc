#include "sorted_array.h"

void SortedArray::AddNumber(int num) {
	this->numbers_.push_back(num);
	sort(this->numbers_.begin(), this->numbers_.end());
}

vector<int> SortedArray::GetSortedAscending() const {
	vector<int> v = this->numbers_;
	sort(v.begin(), v.end());
	return v;
}

vector<int> SortedArray::GetSortedDescending() const {
	vector<int> v = this->numbers_;
	sort(v.begin(), v.end(), greater<int>());
	return v;
}

int SortedArray::GetMax() const {
	if (this->numbers_.size() == 0) return -1;
	vector<int> v = this->numbers_;
	sort(v.begin(), v.end());
	return v[v.size() - 1];
}

int SortedArray::GetMin() const {
	if (this->numbers_.size() == 0) return -1;
	vector<int> v = this->numbers_;
	sort(v.begin(), v.end());
	return v[0];
}