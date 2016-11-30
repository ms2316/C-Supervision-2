
template<class T> T Stack<T>::pop() {
	T value = head->val;
	Item* tmp = head;
	head = head->next;
	delete tmp;
	return value;
}

template<class T> Stack<T>::~Stack() {
	while (head) {
		Item* tmp = head->next;
		delete head;
		head = tmp;
	}
}

Stack(const Stack& other) {
	if (!other.head)
			return;

	head = new Item((other.head)->value);

	Item* tmp = (other.head)->next;
	Item* prev = head;

	while (tmp) {
		prev->next = new Item(tmp->value);
		prev = prev->next;
		tmp = tmp->next;
	}
}

Stack& operator=(const Stack& other) {
	if (this == &other)
		return *this;

	while (head) {
		Item* tmp = head->next;
		delete head;
		head = tmp;
	}

	if (!other.head)
		return *this;

	head = new Item((other.head)->value);

	Item* tmp = (other.head)->next;
	Item* prev = head;

	while (tmp) {
		prev->next = new Item(tmp->value);
		prev = prev->next;
		tmp = tmp->next;
	}	

	return *this;
}