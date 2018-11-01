#include "integer_set.h"

void IntegerSet::AddNumber(int num) {
	for (vector<int>::iterator it = this->numbers_.begin(); it != this->numbers_.end(); it++) {
		if (*it == num) return;
	}
	this->numbers_.push_back(num);
	sort(this->numbers_.begin(), this->numbers_.end());
	return;
}

void IntegerSet::DeleteNumber(int num) {
	for (vector<int>::iterator it = this->numbers_.begin(); it != this->numbers_.end(); it++) {
		if (*it == num) {
			this->numbers_.erase(it);
			sort(this->numbers_.begin(), this->numbers_.end());
			return;
		}
	}
	return;
}

int IntegerSet::GetItem(int pos) const {
	if(0<= pos && pos <=this->numbers_.size()) return this->numbers_[pos];
	else return -1;
}

vector<int> IntegerSet::GetAll() const {
	return this->numbers_;
}