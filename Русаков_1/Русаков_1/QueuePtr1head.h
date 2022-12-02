#pragma once
using namespace std;
#include <iostream>
class QueuePtr1head
{
	int csize;
	int* nop;
	struct list
	{
		int data; // ���� ������
		struct list* next; // ��������� �� ��������� �������
	};
	list* head;
public:
	QueuePtr1head() {
		csize = 0;
		head = nullptr;
	}
	void setNOP(int* _nop) {
		nop = _nop;
	}
	int* getNOP() {
		return nop;
	}
	void push(int element) { // 6
		list* l = new list(); *nop += 1; // 1
		if (csize == 0) { // 4
			l->next = nullptr;
			l->data = element;
			head = l;
			*nop += 3; 
		}
		else
		{
			l->next = head;
			l->data = element;
			head = l;
			*nop += 3;
		}
		*nop += 2;
		csize++; // 1
	}
	int front() { // 3 + 3n
		list* l = head;
		list* prev = nullptr;
		while (l->next != nullptr) {
			prev = l;
			l = l->next;
			*nop += 3;
		}
		*nop += 3;
		return l->data;
	}
	int size() {
		return csize;
	}
	void pop() {
		if (csize == 1) {
			delete(head);
			csize = 0;
			head = nullptr;
		}
		else
		{
			list* l = head;
			list* prev = nullptr;
			while (l->next != nullptr) {
				prev = l;
				l = l->next;
			}
			csize--;
			delete(l);
			prev->next = nullptr;
		}
	}
	void display() {
		QueuePtr1head* queTmp1 = new QueuePtr1head();
		queTmp1->setNOP(nop);
		int c_size = size();
		for (int i = 0; i < c_size; i++) {
			queTmp1->push(front());
			cout << " " << front();
			pop();
		}
		for (int i = 0; i < c_size; i++) {
			push(queTmp1->front());
			queTmp1->pop();
		}
	}
};