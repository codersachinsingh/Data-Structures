#include<iostream>
using namespace std;
class Stack {
private:
	int *stack;
	int top;
	int list_capacity;
	/*Method for increasing the list capacity*/
	void increase_capacity(int amount) {
		if (amount < 0) {
			amount = 5;
		}
		int *temp = new int[list_capacity = list_capacity + amount];
		for (int i = 0;i < (top + 1) ; i++) {
			*(temp + i) = *(stack + i);
		}
		delete[] stack;
		stack = temp;
	}
public:

	/* Constructors for Stack */
	Stack() {
		stack = new int[list_capacity = 10];
		top = -1;
	}

	Stack(int init_capacity) {
		if (init_capacity < 2) {
			stack = new int[list_capacity = 10];
			top = -1;
		}
		else {
			stack = new int[list_capacity = init_capacity];
			top = -1;
		}
	}

	/* Utility Methods for Stack*/
	void push(int item) {
		if (top != list_capacity -1) {
			*(stack + ++top) = item;
		}
		else {
			increase_capacity(10);
			*(stack + ++top) = item;
		}
	}

	int pop() {
		if (top != -1) {
			return *(stack + top--);
		}
		else {
			cout<<"Stack is Empty"<<endl;
			return -1;
		}
	}

	int size() {
		return top + 1;
	}

	int peek() {
		if (top!=-1) {
			return *(stack + top);
		}
		else {
			cout<<"Stack is empty"<<endl;
			return -1;
		}
	}

	void empty() {
		top = -1;
	}
};
int main() {
	Stack obj(45);
	obj.push(44);
	obj.push(3);
	cout<<"size of stack is : "<<obj.size();
	cout<<"Pop : "<<obj.pop()<<endl;
	cout<<"size of stack is : "<<obj.size();
	obj.empty();
	cout<<"size of stack is : "<<obj.size();
	return 0;
}
