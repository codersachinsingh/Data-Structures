/**
 * Data Structures : Queue
 * Filename : staticqueue.cpp
 * Author : Sachin Singh (7982858206)
 * Author's Email : sachinsingh.sk13@gmail.com
 * Description : Queue is a first in first out list.
 * this static queue has fixed capacity so it can't grow dynamically
 * so "queue is full" message arises when queue gets full.
 *
 * */


#include<iostream>
using namespace std;

/* StaticQueue class*/
class StaticQueue {
	int *queue;
	const int capacity;			// for make capacity unchangeable
	int rear , front;			// pointers to maintain queue
	int _size;
public:
	StaticQueue() : capacity(10) {     // default capacity is 10
		queue = new int[capacity];
		rear = front = -1;
		_size = 0;
	}

	/*Constructor for specifeid capacity Queue
	 * if required capacity is less than two then it sets its capacity to 10
	 * otherwise sets the specified capacity.
	 * */
	StaticQueue(int c) : capacity((c>=2)?c:10) {   // specified capacity
		rear = front = -1;
		queue = new int[capacity];
		_size = 0;
	}

	/*Method for enqueue item in the queue*/
	void enqueue(int item) {
		if (rear >= 0 && (rear != (capacity-1))) {
			*(queue + (++rear)) = item;
			_size++;
		}

		else if (rear == -1) {     // for first element
			*(queue + (++rear)) = item;
			front = 0;    // set front to zero
			_size++;
		}

		else {
			cout<<"Queue is Full"<<endl;
		}
	}


	/*Method for dequeue item from queue*/
	int dequeue() {
		if (front > -1 && front <= rear) {
			_size--;
			return *(queue + (front++));
		}
		else {
			cout<<"Queue is Empty"<<endl;
			rear = front = -1;  	// re-initialize queue pointers
			return -1;
		}
	}

	/*Returns next item to dequeued from queue without removing it*/
	int peek() {
		if (front > -1 && front <= rear) {
			return *(queue + (front++));
		}
		else {
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
	}


	int size() {
		return _size;
	}
};
/*Performing some operatios : Testing*/
int main() {
	StaticQueue obj(4);
	obj.enqueue(45);
	obj.enqueue(89);
	obj.enqueue(34);
	obj.enqueue(100);
	obj.enqueue(10000);
	cout<<"size : "<<obj.size()<<endl;
	for(int i = 0;i<5;i++) {
		cout<<"size : "<<obj.size()<<endl;
		cout<<"Value : "<<obj.dequeue()<<endl;
	}


	return 0;
}
