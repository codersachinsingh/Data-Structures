#include<iostream>
using namespace std;

class Point {
	int x;
	int y;
public:
	Point() {
		x = y = 0;
	}
	Point(int m , int n) {
		this->x = m;
		this->y = n;
	}
	void show() {
		cout<<"Point  : ("<<x<<","<<y<<")"<<endl;
	}
};

template <class T>
class Stack {
private:
	T *stack;
	int top;
	int list_capacity;
	/*Method for increasing the list capacity*/
	void increase_capacity(int amount) {
		if (amount < 0) {
			amount = 5;
		}
		T *temp = new T[list_capacity = list_capacity + amount];
		for (int i = 0;i < (top + 1) ; i++) {
			*(temp + i) = *(stack + i);
		}
		delete[] stack;
		stack = temp;
	}
public:

	/* Constructors for Stack */
	Stack() {
		stack = new T[list_capacity = 10];
		top = -1;
	}

	Stack(int init_capacity) {
		if (init_capacity < 2) {
			stack = new T[list_capacity = 10];
			top = -1;
		}
		else {
			stack = new T[list_capacity = init_capacity];
			top = -1;
		}
	}

	/* Utility Methods for Stack*/
	void push(T item) {
		if (top != list_capacity -1) {
			*(stack + ++top) = item;
		}
		else {
			increase_capacity(10);
			*(stack + ++top) = item;
		}
	}

	T pop() {
		if (top != -1) {
			return *(stack + top--);
		}
		else {
			cout<<"Stack is Empty"<<endl;
		}
	}

	int size() {
		return top + 1;
	}

	T peek() {
		if (top!=-1) {
			return *(stack + top);
		}
		else {
			cout<<"Stack is empty"<<endl;
		}
	}

	void empty() {
		top = -1;
	}
};
int main() {
	Point a(3,4) , b(4,5) , c(6,7);
	a.show();
	b.show();
	c.show();
	Stack <Point> obj;
	obj.push(a);
	obj.push(b);
	obj.push(c);
	Point temp;
	for (int i = 0; i< 3;i++) {
	temp = obj.pop();
	temp.show();
	}


	return 0;
}
