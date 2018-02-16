/**
 * Data Structures : Linked List
 * Author : Sachin Singh
 * Email : sachinsingh.sk13@gmail.com
 *
 * */


#include<iostream>   // for standard output
using namespace std;

/*Linked List Class*/
class LinkedList {
private:

	/*Node structure*/
	class Node {
	private:
		int data;
	public:
		Node *next;  // pointer to next node
		Node() {
			data = 0;
			next = nullptr;
		}

		Node(int item) {
			this->data = item;
			next = nullptr;
		}

		int getItem() {
			return this->data;
		}
	};

	Node *head;
	int size;
public:

	/*Constructor*/
	LinkedList() {
		head = nullptr;
		size = 0;
	}

	/*returns pointer to new created node*/
	Node *getNewNode(int item) {
		Node *node = new Node(item);
		return node;
	}

	/*Insert item at last*/
	void insert(int item) {
		if (head!=nullptr) {
			Node *temp = head;
			while(temp->next!=nullptr) {
				temp = temp->next;
			}
			Node *node = getNewNode(item);
			temp->next = node;
			size++;
		}
		else {
			head = getNewNode(item);
			size++;
		}
	}

	/*Insert item at specified index*/
	void insert(int item , int index) {
		if (index >= 0 && index <= size) {
			if (index!=0) {
				Node *temp = head;
				for (int i = 0;i<(index-1);i++) {
					temp = temp->next;
				}
				Node *node = getNewNode(item);
				node->next = temp->next;
				temp->next = node;
				size++;
			}

			else {
				Node *node = getNewNode(item);
				node->next = head;
				head = node;
				size++;
			}
		}

		else {
			cout<<"Invalid Index"<<endl;
		}
	}
	/*Returns item at given index*/
	int get(int index) {
		if (index >= 0 && index < size) {
			if (index!=0) {
			Node *temp = head;
			for (int i = 0;i<index;i++) {
				temp = temp->next;
			}
			return temp->getItem();
			}
			else {
				return head->getItem();
			}
		}
		else {
			cout<<"Invalid Index"<<endl;
			return -1;
		}
	}

	/*Removes an item from list at specified index*/
	int remove(int index) {
		if (index >= 0 && index < size) {
			if (index!=0) {
				Node *temp = head;
				for (int i = 0;i<(index-1);i++) {
				temp = temp->next;
				}
				int tm = temp->next->getItem();
				Node *del = temp->next;
				temp->next = temp->next->next;
				delete del; //free memory
				size--;
				return tm;
			}
			else {
				int tm = head->getItem();
				Node *del = head;
				head = head->next;
				delete del; // free memory
				size--;
				return tm;
			}

		}

		else {
			cout<<"Invalid Index"<<endl;
			return -1;
		}

	}

	/*Returns total number of items in the list*/
	int getSize() {
		return this->size;
	}

	/*Displays each item*/
	void traverse() {
		Node *temp = head;
		while(temp!=nullptr) {
			cout<<"Value : "<<temp->getItem()<<endl;
			temp = temp->next;
		}
	}
};
