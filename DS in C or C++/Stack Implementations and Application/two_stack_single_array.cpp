/* Two stacks using one array */
#include<iostream>
#define MAX 20
using namespace std;
int stack_array[MAX];
int top_lower = -1,top_upper = MAX;

void push(int stack , int item) {
	if (stack==1) {
		if (top_lower != top_upper) {
			stack_array[++top_lower] = item;
		}
		else {
			cout<<"Stack 1 is full"<<endl;
		}
	}
	else if (stack==2) {
		if (top_upper != top_lower) {
			stack_array[--top_upper] = item;
		}
		else {
			cout<<"Stack 2 is full"<<endl;
		}
	}
	else {
		cout<<"Invalid Stack"<<endl;
	}
}

int pop(int stack) {
	if (stack == 1) {
		if (top_lower != -1) {
			return stack_array[top_lower--];
		}
		else {
			cout<<"stack 1 is empty"<<endl;
		}
	}
	else if (stack == 2) {
		if (top_upper != MAX) {
			return stack_array[top_upper++];
		}
		else {
			cout<<"stack 2 is empty"<<endl;
		}
	}
	else {
		cout<<"Invalid stack"<<endl;
	}
}

int main() {
	push(1,23);
	push(1,45);
	push(2,13);
	push(2,67);
	cout<<"pop stack 1 : "<<pop(1)<<endl;
	cout<<"pop stack 2 : "<<pop(2)<<endl;
	cout<<"pop stack 1 : "<<pop(1)<<endl;
	cout<<"pop stack 2 : "<<pop(2)<<endl;
}
