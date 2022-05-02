#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;
class MyList
{
public:
	MyList()
	{
		size = 0;
		head = nullptr;
	}
	~MyList()
	{
		clear();
	}
	void push_back(int newnumber)
	{
		if (!head) head = new Node(newnumber); // creates a list with newnumber
		else {
			Node* current = head;
			while (current->next) current = current->next; // moves the current list while the next item exists
			current->next = new Node(newnumber); // adds newnumber to the end of the list
		}
		size++;
		savesize = size;
	}
	void push_front(int newnumber)
	{
		if (!head) head = new Node(newnumber); // creates a list with newnumber
		else {
			Node* first = new Node(newnumber); // creates a list with newnumber
			first->next = head; // the next elements of the list are equal to the elements of the old list
			head = first; // the list is updated
		}
		size++;
		savesize = size;
	}
	void pop_back()
	{
		if (head) {
			Node* current = head, * previous = nullptr;
			while (current->next)
			{
				previous = current; // keeps the last element of the list
				current = current->next; // moves the current list while the next item exists
			}
			delete current; // clears memory 
			current = nullptr;
			if (previous) previous->next = current; // updates the pointer
			else head = nullptr;
			size--;
			savesize = size;
		}
	}
	void pop_front()
	{
		if (head) {
			Node* current = head->next;
			delete head;
			head = current;
			size--;
			savesize = size;
		}
	}
	void insert(int newnumber, size_t index)
	{
		if (size >= index + 1) {
			Node* current = head;
			if (!index) push_front(newnumber); // if index = 0 then add newnumber to the beginning
			else
			{
				for (size_t i = 1; i < index; i++, current = current->next); // move the current list item to index
				Node* newelem = new Node(newnumber);  // creates a list with newnumber
				newelem->next = current->next; // insert the list item before index element
				current->next = newelem;
				size++;
				savesize = size;
			}
		}
	}
	bool contains(int number)
	{
		Node* current = head;
		while (current) {
			if (current->number == number)
				return true;
			current = current->next;
		}
		return false;
	}
	int get_elem(size_t index)
	{
		if (size >= index + 1) {
			Node* current = head;
			for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
			return current->number; // returns index number
		}
		else
			throw out_of_range("index is entered incorrectly"); // error message
	}
	void remove(size_t index)
	{
		if (size >= index + 1) {
			if (index == 0) pop_front(); // delete first element
			else if (index + 1 == size) pop_back(); // delete last element
			else {
				Node* current = head, * next;
				for (size_t i = 1; i < index - 1; i++, current = current->next);  // moves the current list to index
				next = current->next;
				current->next = next->next;
				delete next;
				next = nullptr;
				size--;
				savesize = size;
			}
		}
	}
	size_t get_size()
	{
		return size;
	}
	void clear()
	{
		while (size && head) pop_front();
	}
	void set(size_t index, int newnumber)
	{
		if (size >= index + 1) {
			Node* current = head;
			for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
			current->number = newnumber;
		}
	}
	bool isEmpty()
	{
		return head == nullptr;
	}

	void push_front(MyList newlist)
	{
		if (newlist.head) {
			Node* current = newlist.head;
			MyList main;
			while (current) {
				main.push_back(current->number);
				current = current->next;
			}
			current = head;
			while (current) {
				main.push_back(current->number);
				current = current->next;
			}
			clear(); // the head is cleared
			head = main.head;
			size = main.size;
			savesize = size;
			main.size = 0; // since size = 0 the destructor will not delete the memory
			newlist.size = 0; // since size = 0 the destructor will not delete the memory
		}
	}
	void save_list()
	{
		size = 0;
	}
	MyList& operator=(MyList Listnum)
	{
		this->head = Listnum.head;
		Listnum.head = nullptr;
		this->size = Listnum.savesize;
		this->savesize = Listnum.savesize;
		Listnum.size = 0;
		return *this;
	}
	friend ostream& operator<< (ostream& out, const MyList& list)
	{
		MyList current;
		current.head = list.head;
		while (current.head) {
			out << current.head->number;
			if (current.head->next) out << ',';
			current.head = current.head->next;
		}
		current.size = 0;  // since size = 0 the destructor will not delete the memory
		return out;
	}
private:
	class Node {
	public:
		int number;
		class Node* next;
		Node(int newnumber = 0, Node* next = nullptr) {
			this->next = next;
			this->number = newnumber;
		}
		~Node() {};
	};
	Node* head;
	size_t size;
	size_t savesize;

};

class Mymap {
public:
	~Mymap();
	void insert(int key, int value);
	void remove(int key);
	int find(int key);
	MyList get_keys();
	MyList get_values();
	void clear();
	void print();
private:
	class Node {
	public:
		int key;
		int value;
		bool isblack;
		Node* left;
		Node* right;
		Node* parent;
		Node(int newkey, int newvalue, bool newcolor = false, Node* newparent = nullptr, Node* newleft = nullptr, Node* newright = nullptr) {
			this->key = newkey;
			this->value = newvalue;
			this->isblack = newcolor;
			this->left = newleft;
			this->right = newright;
			this->parent = newparent;
		}
	};
	Node* head = nullptr;
	int count = 0;
	Node* nill = new Node(0, 0, true);
	void left_turn(Node* swivel);
	void right_turn(Node* swivel);
	MyList get_keys_or_value(bool iskeys);
};