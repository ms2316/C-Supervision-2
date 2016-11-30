#include <iostream>


class LinkList {

private:

	struct node {
		int value;
		node* next;
		node(int value, node* next = nullptr) : value(value), next(next) {}
	};

	node* head = nullptr;

public:

	LinkList(int* start=nullptr, int len=0) {
		if (len <= 0)
			return;

		head = new node(*(start+len-1), nullptr);
		while (--len)
			head = new node(*(start+len-1), head);
	}

	LinkList(const LinkList& other) {
		if (!other.head)
			return;

		head = new node((other.head)->value);

		node* tmp = (other.head)->next;
		node* prev = head;

		while (tmp) {
			prev->next = new node(tmp->value);
			prev = prev->next;
			tmp = tmp->next;
		}
	}

	LinkList& operator=(const LinkList& other) {
		if (this == &other)
			return *this;

		while (head) {
			node* tmp = head->next;
			delete head;
			head = tmp;
		}

		if (!other.head)
			return *this;

		head = new node((other.head)->value);

		node* tmp = (other.head)->next;
		node* prev = head;

		while (tmp) {
			prev->next = new node(tmp->value);
			prev = prev->next;
			tmp = tmp->next;
		}

		return *this;
	}

	~LinkList() {
		while (head) {
			node* tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	int pop() {
		if (!head)
			return -1;

		node* tmp = head;
		head = head->next;

		int value = tmp->value;
		delete tmp;

		return value;
	}

};

int main() {
	int a[] {11, 22, 33};
	LinkList t(a,3);
	LinkList l2(t), l3 = l2;

	std::cout << t.pop() << '\n';
	std::cout << t.pop() << '\n';
	std::cout << t.pop() << '\n';
	std::cout << t.pop() << '\n';

	std::cout << l2.pop() << '\n';
	std::cout << l2.pop() << '\n';
	std::cout << l2.pop() << '\n';
	std::cout << l2.pop() << '\n';	

	std::cout << l3.pop() << '\n';
	std::cout << l3.pop() << '\n';
	std::cout << l3.pop() << '\n';
	std::cout << l3.pop() << '\n';	
}
