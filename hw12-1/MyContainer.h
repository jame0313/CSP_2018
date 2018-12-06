#pragma once
#define max(a,b) ((a)>(b)?(a):(b))
#include <iostream>
using namespace std;
template<class T>
class MyContainer {
public:
	MyContainer() :n_elements(0), obj_arr(new T[0]) {}
	MyContainer(int n) : n_elements(n) {
		obj_arr = new T[n_elements];
	}
	MyContainer(T* arr, int n) : n_elements(n), obj_arr(arr) {}
	~MyContainer() {
		if (n_elements != 0) delete[] obj_arr;
	}
	void clear() {
		if (n_elements != 0) {
			delete[] obj_arr;
			n_elements = 0;
		}
	}
	int size() {
		return n_elements;
	}
protected:
	T* obj_arr = NULL;
	int n_elements;
};

template<class T>
class MyVector : public MyContainer<T> {
public:
	MyVector() : MyContainer<T>(), capacity(0) {}
	MyVector(int n) : MyContainer<T>(n), capacity(n) {}
	MyVector(T* arr, int n): MyContainer<T>(arr, n), capacity(n) {}
	bool empty() {
		return (this->n_elements == 0);
	}
	int size() {
		return this->n_elements;
	}
	int max_size() {
		return capacity;
	}
	void reserve(int new_cap) {
		if (new_cap >= capacity) {
			T* tmp = new T[new_cap];
			for (int i = 0; i < this->n_elements; i++) {
				tmp[i] = (this->obj_arr)[i];
			}
			this->obj_arr = tmp;
			capacity = new_cap;
		}
	}
	void push_back(T obj) {
		if (this->n_elements >= capacity) this->reserve(max(1, 2 * capacity));
		(this->obj_arr)[this->n_elements++] = obj;
	}
	void pop_back() {
		if (this->n_elements > 0) {
			(this->obj_arr)[--this->n_elements] = T();
		}
	}
	T& front() {
		if (this->n_elements > 0) return (this->obj_arr)[0];
	}
	T& back() {
		if (this->n_elements > 0) return (this->obj_arr)[this->n_elements - 1];
	}
	T& at(int idx) {
		if (0 <= idx && idx <this->n_elements) {
			return (this->obj_arr)[idx];
		}
	}
	T& operator[] (const int &i) {
		return this->at(i);
	}
	MyVector<T> operator+(const MyVector<T>& rhs) {
		int Max_elements = this->n_elements+rhs.n_elements;
		T* tmp = new T[Max_elements];
		for (int i = 0; i < this->n_elements; i++) {
			tmp[i] = (this->obj_arr)[i];
		}
		for (int i=this->n_elements; i < Max_elements; i++) {
			tmp[i] = rhs.obj_arr[i-(this->n_elements)];
		}
		return MyVector(tmp, Max_elements);
	}
private:
	int capacity;
};
