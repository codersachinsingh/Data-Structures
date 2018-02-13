/**
 * Data Structures : Queue
 * Filename : queue.cpp (C++ source file)
 * Author : Sachin Singh (7982858206)
 * Author's Email : sachinsingh.sk13@gmail.com
 * Description : Queue data structure implemented by me.
 * Queue is First in First out (FIFO) sequencial list.
 * */

#include<iostream>
using namespace std;

/*Queue class*/
class Queue {
private:
	int *queue; 		// pointer to a dynamic array
	int rear;
	int front;
	int capacity; 		// capacity of dynamic array
	long size;  		// total number of elements in the queue
	void increase_capacity() { // this method increases list capacity by 50%
		int *temp = new int[capacity + capacity/2];
		for (int i = 0;i<capacity;i++) {
			*(temp + i) = *(queue + i);
		}
		delete[] queue;     // free memory occupied by previous array
		queue = temp; 		// assign new array to queue
		capacity = capacity + capacity/2;
	}
public:
	/* Default constructor creates a Queue object with initial capacity 10 */
	Queue() {
		queue = new int[3];
		rear = front = -1;
		capacity = 3;
		size = 0;
	}

	/*This constructor creates Queue object with specified capacity */
	Queue(int init_capacity) {
		rear = front = -1;
		size = 0;
		if (init_capacity>2) {   // if initial capacity is less than two by default it will 10
			queue = new int[init_capacity];
			capacity = init_capacity;
		}
		else {
			queue = new int[10];
			capacity = 10;
		}
	}

	/* Method for enqueue item in the queue */
	void enqueue(int item) {
		if (rear == -1) {          // putting first element
			front = 0;
			*(queue + ++rear) = item;
			size++;
		}
		else if (rear != capacity - 1) {
			*(queue + ++rear) = item;
			size++;
		}
		else {      // incresing capacity when queue is full
			increase_capacity();
			enqueue(item);
		}
	}

	/*Method for dequeue item from queue . returns -1 if queue is empty */

	int dequeue() {
		if (front < 0 || front > rear) {
			rear = front = -1;    // set queue to initial stage
			cout<<"Queue is empty";
			return -1; // queue is empty
		}

		else {
			size--;
			return *(queue + front++);
		}
	}

	/* Returns the current number of items in queue */
	int queue_size() {
		return size;
	}
	/*Returns the current capacity of queue*/
	int current_capacity() {
		return capacity;
	}
	/* Returns the next dequeuing item without removing it. returns -1 if queue is empty */
	int peek() {
		if (front < 0 || front > rear) {
			return -1;
		}
		else {
			return *(queue + front);
		}
	}
};
int main() {
Queue obj;
obj.enqueue(100);
obj.enqueue(56);
obj.enqueue(89);
cout<<"peek is : "<<obj.peek()<<endl;
return 0;
}
