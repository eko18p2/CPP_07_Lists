#include <iostream>

using namespace std;


template<typename T> class OldList {
	struct Elem{
		T data;
		Elem* next = nullptr;
		Elem(const T& data):data(data){}
	};

	Elem* head = nullptr;

public:

	void push_back(const T& data) {
		Elem* e = new Elem(data);
		if (head == nullptr) head = e;
		else {
			Elem* tail = head;
			while(tail->next != nullptr) tail = tail->next;
			tail->next = e;
		}
	}

	void forEach(void(*f)(const T&)) {
		for (Elem* cur = head; cur != nullptr; cur = cur->next) {
			f(cur->data);
		}
	}



};

template<typename T> class List {
	struct Elem {
		T data;
		Elem* next = nullptr;
		Elem(const T& data) :data(data) {}
	};

	Elem* head = nullptr;
	Elem* tail = nullptr;

public:

	void push_back(const T& data) {
		Elem* e = new Elem(data);
		if (head == nullptr) tail=head=e;
		else tail = tail->next = e;
	}

	void forEach(void(*f)(const T&)) {
		for (Elem* cur = head; cur != nullptr; cur = cur->next) {
			f(cur->data);
		}
	}



};



void printInt(const int& a) {
	cout << a << endl;
}



int main() {

	List<int> lst;

	lst.push_back(2);
	lst.push_back(8);
	lst.push_back(10);

	lst.forEach(printInt);
	getchar();

	return 0;
}