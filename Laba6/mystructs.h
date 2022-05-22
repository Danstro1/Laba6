#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* next;

	string name;
	string count;
	string volume;

	Node(string _name, string _count, string _volume) : name(_name), count(_count), volume(_volume), next(nullptr) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			if (p != nullptr) {
				cout << p->name << " " << p->count << " " << p->volume << endl;
				p = p->next;
			}
			else {
				p = p->next;
			}
		}
		cout << endl;
	}

	void add_item(string _name, string _count, string _volume) {
		Node* p = new Node(_name, _count, _volume);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	list fileInput()
	{
		list data{};
		string _name{}, _count{}, _volume{};
		ifstream fileInput("data.txt");
		while (fileInput >> _name, fileInput >> _count, fileInput >> _volume)
		{
			data.add_item(_name, _count, _volume);
		}
		return data;
	}

	void fileOutput() {
		ofstream fileOutput("data.txt", ios_base::trunc);
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			fileOutput << p->name << " " << p->count << " " << p->volume << " " << endl;
			p = p->next;
		}
		cout << endl;
		fileOutput.close();
	}
	void remove_first() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}
	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		Node* p = first;
		while (p->next != last) {
			p = p->next;
		}
		p->next = nullptr;
		delete last;
		last = p;
	}
	void remove1(string _val) {
		if (is_empty()) return;
		if (first->name == _val) {
			remove_first();
			return remove1(_val);
		}
		if (last->name == _val) {
			remove_last();
			return remove1(_val);
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->name != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			return;
		}
		slow->next = fast->next;
		delete fast;
		return remove1(_val);
	}
	void remove2(string _val) {
		if (is_empty()) return;
		if (first->count == _val) {
			remove_first();
			return remove2(_val);
		}
		if (last->count == _val) {
			remove_last();
			return remove2(_val);
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->count != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			return;
		}
		slow->next = fast->next;
		delete fast;
		return remove2(_val);

	}
	void remove3(string _val) {
		if (is_empty()) return;
		if (first->volume == _val) {
			remove_first();
			return remove3(_val);
		}
		if (last->volume == _val) {
			remove_last();
			return remove3(_val);
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->volume != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			return;
		}
		slow->next = fast->next;
		delete fast;
		return remove3(_val);
	}
};

#endif 