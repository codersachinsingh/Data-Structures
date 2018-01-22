/**Data Structures : Arrays
 *Filename : arrays.cpp
 *Author : Sachin Singh (7982858206)
 *Author's Email : sachinsingh.sk13@gmail.com
 *Date : 20-01-2018
 *Description : I implemented various data structure concepts related to Arrays in C++ language.
 */

#include <iostream>
#define MAX 50     // size of the integer array
using namespace std;

class Array {
private:
	int *list;
	int upperBound;
	int list_capacity;
	void increase_list_capacity(int persentage  = 50) {
		if (persentage>20 && persentage <= 100) {
			list_capacity = list_capacity + ((list_capacity*persentage)/100);
		}

			//default increasment 50%
		else {
			list_capacity = list_capacity + list_capacity/2;
		}
		int *temp = new int[list_capacity];
		for (int i = 0 ;i<upperBound;i++) {
				*(temp + i) = *(list + i);
			}
		delete[] list;
		list = temp;
	}

	void swap(int *a ,int *b) {
		int temp = *a;
			*a = *b;
			*b = temp;
	}
	void bubble_sort() {
		for (int i = 0;i<upperBound;i++) {
			for (int j = 0;j<upperBound-1-i;j++) {
				if (*(list + j) > *(list + j + 1)) {
					int temp = *(list + j);
					*(list + j) = *(list + j + 1);
					*(list + j + 1) = temp;
				}
			}
		}
	}
public:

				/********************Constructors***************/

	//Default Construtor : allocate memory for array with initial capacity 10.
	Array() {
		upperBound = 0;
		list = new int[10];
		list_capacity =10;
	}

	//Specified Capacity Constructor : allocate memory for array with specified capacity.
	Array(int initial_capacity) {
		upperBound =0;
		 if (initial_capacity>0) {
			 list = new int[initial_capacity];
			 list_capacity = initial_capacity;
		 }
		 else {
			 list = new int[10];
			 list_capacity = 10;
		 }
	}

	//Copy Constructor : Creates a Array Object by another object.
	Array(Array &arr) {
		this->upperBound = arr.upperBound;
		this->list_capacity = arr.capacity();
		this->list = new int[arr.capacity()];
		for (int i = 0;i<arr.upperBound;i++) {
			*(list + i) = *(arr.list + i);
		}
	}

	Array(int arr[] , int size) {
		list = new int[size+10];
		upperBound = size;
		list_capacity = size + 10;
		for (int i = 0; i < size ;i++) {
			*(list + i) = arr[i];
		}
	}

	//inserts item at last position
	int add(int item) {
		if (upperBound==list_capacity) {
			increase_list_capacity(30);
		}
		*(list + upperBound++)  = item;
		return 0;
	}

	int add(int item,int index) {
		if (index>=0 && index <=upperBound) {
			if (upperBound==list_capacity) {
				increase_list_capacity(30);
			}

			int k = upperBound++;
			while(k>=index) {
				*(list + k) = *(list + k - 1);
				k--;
			}

			*(list + index) = item;
			return 0;
		}
		else {
			cout<<"Invalid index"<<endl;
			return -1;
		}
	}

	int add(int arr[] , int size) {
		for (int i = 0;i<size;i++) {
			add(arr[i]);
		}
		return 0;
	}

	int remove() {
		upperBound--;
		return 1;
	}
	int remove(int index) {
		if(index>= 0 && index <upperBound) {
			int k = index;
			while(k<=upperBound) {
				*(list + k) = *(list + k + 1);
				k++;
			}
			upperBound--;
			return 1;
		}
		return-1;
	}

	int get(int index) {
		if (index >= 0 && index < upperBound) {
			return *(list + index);
		}
		return -1;
	}
	// Returns total number of elements.
	int size() {
		return upperBound;
	}

	// Returns current capacity of Array
	int capacity() {
		return list_capacity;
	}

	//Method for displaying all Array elements.
	void view() {
		cout<<"{";
		for (int i =0 ;i<upperBound;i++) {
			cout<<*(list + i);
			if (i!=upperBound-1) cout<<", ";
		}
		cout<<"}"<<endl;
	}

	int search(int item) {
		for (int i = 0;i<upperBound;i++) {
			if (*(list + i) == item)
				return i;
		}
		return -1;
	}
	void sort() {
		bubble_sort();
	}

	void flip() {
		int m = 0 , n = upperBound;
		if (upperBound%2==0) {
			while(m<(upperBound/2)) {
				swap((list + m),(list + n-m-1));
				m++;
			}
		}
		else {
			while(m<((upperBound-1)/2)) {
				swap((list + m),(list + n-m-1));
				m++;
			}

		}
	}

	Array merge(Array &arr) {
		Array temp(size()+arr.size());
		for (int i = 0 ;i<size();i++) {
			temp.add(*(list + i));
		}
		for (int i = 0;i<arr.size();i++) {
			temp.add(arr.get(i));
		}
		return temp;

	}

};

int main() {
	Array obj;
	int a[] = {1,2,3,4,5};
	obj.add(a,5);
	obj.view();
	return 0;

}


