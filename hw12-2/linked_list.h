#pragma once
#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class List {
private:
	Node<T> *head;
public:
	List() : head(NULL) {};
	~List() {
		while (head != NULL) pop_back();
	}
	List(T * arr, int n_nodes) : head(NULL)
	{
		Node<T>* pre = head;
		for (int i = 0; i < n_nodes; i++) {
			Node<T>* tmp = new Node<T>;
			tmp->data = arr[i];
			tmp->next = NULL;
			if (pre == NULL) head = tmp;
			else pre->next = tmp;
			pre = tmp;
		}
	}
	void insert_at(int idx, T data)
	{
		Node<T>* target = head;
		Node<T>* pre = NULL;
		for (int i = 0; i < idx; i++) {
			pre = target;
			target = target->next;
			if (pre == NULL) return;
		}
		Node<T>* tmp = new Node<T>;
		tmp->data = data;
		tmp->next = target;
		if (pre != NULL) pre->next = tmp;
		else head = tmp;
	}
	void remove_at(int idx)
	{
		Node<T>* target = head;
		Node<T>* pre = NULL;
		for (int i = 0; i < idx; i++) {
			pre = target;
			target = target->next;
			if (target == NULL) return;
		}
		if (pre != NULL) pre->next = target->next;
		else head = target->next;
		delete target;
	}
	void pop_back()
	{
		if (head == NULL) return;
		int idx = 0;
		Node<T>* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next, idx++;
		remove_at(idx);
	}
	void push_back(T val)
	{
		if (head == NULL) return insert_at(0, val);
		int idx = 0;
		Node<T>* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next, idx++;
		insert_at(idx + 1, val);
	}
	void pop_front() {
		remove_at(0);
	}
	void push_front(T val) {
		insert_at(0, val);
	}
	friend ostream& operator<<(ostream& out, List<T>& rhs) {
		Node<T>* tmp = rhs.head;
		while (tmp != NULL) {
			if (tmp != rhs.head) out << ',';
			out << tmp->data;
			tmp = tmp->next;
		}
		out << endl;
		return out;
	}
};