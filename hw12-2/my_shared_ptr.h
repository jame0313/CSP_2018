#pragma once
#include <iostream>
using namespace std;

template <class T>
class My_shared_ptr
{
private:
	T* m_obj = NULL;
	int* count = NULL;
public:
	My_shared_ptr():m_obj(NULL), count(NULL) {}
	My_shared_ptr(T* obj):m_obj(obj), count(new int(1)) {}
	My_shared_ptr(const My_shared_ptr& rhs):m_obj(rhs.m_obj), count(rhs.count) {
		increase();
	}
	~My_shared_ptr() {
		decrease();
		if (getCount() == 0) {
			delete count;
			delete m_obj;
			cout << "everything destroyed";
		}
	}

	My_shared_ptr<T>& operator=(const My_shared_ptr<T>& rhs)
	{
		if (count != NULL) {
			decrease();
			if (getCount() == 0) {
				delete count;
				delete m_obj;
			}
		}
		this->count = rhs.count;
		this->m_obj = rhs.m_obj;
		increase();
		return *this;
	}
	const T* get_m_obj() { return m_obj; }

	int getCount() {
		if (count == NULL) return 0;
		return *count;
	}
	void increase() {
		if(count!=NULL) (*count)++;
	}
	void decrease() {
		if (count != NULL) (*count)--;
	}
};
