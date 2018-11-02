#include "simple_int_set.h"
set<int> SetIntersection(const set<int>& set0, const set<int>& set1) {
	set<int> s;
	for (set<int>::iterator it = set0.begin(); it!=set0.end(); it++){
		if (set1.find(*it) != set1.end()) {
			s.insert(*it);
		}
	}
	return s;
}

set<int> SetUnion(const set<int>& set0, const set<int>& set1) {
	set<int> s;
	for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
		if (s.find(*it) == s.end()) {
			s.insert(*it);
		}
	}
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		if (s.find(*it) == s.end()) {
			s.insert(*it);
		}
	}
	return s;
}

set<int> SetDifference(const set<int>& set0, const set<int>& set1) {
	set<int> s = set0;
	set<int> intersection = SetIntersection(set0, set1);
	for (set<int>::iterator it = intersection.begin(); it != intersection.end(); it++) {
		if (s.find(*it) != s.end()) {
			s.erase(*it);
		}
	}
	return s;
}