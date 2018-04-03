/*
 * Data Structures : Doubly Linked List
 * Author : Sachin Singh
 * Date :01-04-2018
 * Description : Linked List is a dynamic list which uses a node to store a data item
 * and each node is connected to other nodes in the same list via pointers (links).
 *
 * */

#include<iostream>
using namespace std;


/*
 * LinkedListException : this class defines different types of exceptions that can occurs in
 * various operations on linked list. handle these exceptions to prevent error and unexpected
 * program failure.
 *
 * */


/*
 * Base class for all linked list exceptions
 * */

class LinkedListExceptions {
protected:
	string cause_details;

public:
	LinkedListExceptions() {
		cause_details = "An Unknown Exception has occured during the operation.";
	}
	LinkedListExceptions(string str) {
		this->cause_details = str;
	}

	// displays the exception details
	void displayException() {
		cout<<cause_details<<endl;
	}

	string getCause() {
		return cause_details;
	}
};

/*
 * InvalidIndexException : this exception occurs when user performs a operation with an invalid index
 *
 * */
class InvalidIndexException : public LinkedListExceptions {
	int index;
public:
	InvalidIndexException(string str , int index) : LinkedListExceptions(str) {
		this->index = index;
	}

	void displayException() {
		cout<<"Given Index "<<to_string(index)<<" is Invalid"<<endl;
	}
};

/*
 *EndOfListException : this exception occurs when user reaches end of list while navigating the list.
 * */
class EndOfListException : public LinkedListExceptions {
	int where;
public:
	EndOfListException(string str , int where) : LinkedListExceptions (str) {
		/*
		 * when where = 0 ; thats mean current node pointer pointing to first node
		 * and no previous node is available
		 * where = 1 indicate pointer  is pointing to end of list and no successive node available
		 * Apropriate msg will displayed by exception object with location of node pointer.
		 * */
		this->where = where;

	}

	void displayException() {
		if (where==0) {
			cout<<"Reached Beginning of the list."<<endl;
		}

		else {
			cout<<"Reached End of the list."<<endl;
		}
	}
};

/*
 * LinkedList : Creates a dynamic sequential list in which we can add and remove items.
 * * We can traverse the entire list through the next() and previous() methods
 *
 * */
class LinkedList {
private:

	/*
	 * Node structure of the linkedlist. it has one
	 * next points to next node in the list
	 * and prev points to previous node in the list
	 *
	 * head and last are pointers that points to first and last node in the list respectively
	 * declared along with class Node definition.
	 * */
	class Node {
	private:
		int data;
	public:
		Node *next , *prev;
		Node() {
			data = 0;
			next = prev = nullptr;
		}
		Node(int item) {
			data = item;
			next = prev = nullptr;
		}

		int getItem() {
			return this->data;
		}
	} *head , *last;

	int totalSize; // current no of nodes in the list . 0 means a empty list.
	Node *iterator;  // a pointer that helps to navigate the list in from next() and previous() method
	bool i_flag; // iteration flag . false indicates end of list.
	/*
	 * checks the user given index , if index is valid for perform any action it returns true
	 * otherwise returns false;
	 * */
	bool isValidIndex(int index) {
		if (index >= 0 && index < totalSize)
			return true;
		else
			return false;
	}

	// returns the middle index value of the list.
	int midIndex() {
		return (int) totalSize / 2;
	}

	/*
	 * returns a copy of node in the list specified by the index.
	 * */
	Node getNode(int index) {
		if (isValidIndex(index)) {
			if (index < midIndex()) {
				Node *temp  = head;
				for (int i = 0 ; i < index ;i++ ) {
					temp = temp->next;
				}
				return *temp;
			}

			else {
				Node *temp = last;
				for (int i = (totalSize - 1); i>index ;i--) {
					temp = temp->prev;
				}
				return *temp;
			}
		}
		else {
			throw(InvalidIndexException("Given Index is Invalid.",index));
		}
	}
public:
	//--------------Constructor-----------------------
	LinkedList() {
		head = last = nullptr;
		totalSize = 0;
		iterator = head;
		i_flag = true;
	}

	LinkedList(LinkedList &list) {
		head = last = nullptr;
		totalSize = list.size();
		iterator = head;
		for (int i = 0 ;i < totalSize ;i++) {
			this->add(list.get(i));
		}
		i_flag = true;
	}
	//--------------------Destructor------------------
	~LinkedList() {
		// deleting all nodes of list;
		for (int i = 0 ; i < totalSize ; i++) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
	//--------------Methods Prototypes----------------

	bool add(int);
	void add(int,int);
	int get(int);
	int remove(int);
	int size();
	void emptyList();
	void swap(int,int);
	bool isEmpty();
	bool hasNext();
	bool hasPrevious();
	int next();
	int previous();
	void show() {
		if (head!=nullptr) {
			Node *temp = head;
			int i= 0;
			while(temp!=nullptr) {
				cout<<"Data : "<<temp->getItem()<<", Index : "<<i++<<endl;
				temp = temp->next;
			}
		}
		else
		{
			cout<<"List is Empty"<<endl;
		}
	}

};
//-------------------Class LinkedList Method Definitions------------------

/*
 *Add's an item to end of the list.
 * */
bool LinkedList::add(int item) {
	// Adding first node of the list.
	if (head==nullptr) {
		head = last =  new Node(item);
		totalSize++;
		iterator = head;
		return true;
	}
	else {
		Node *newNode = new Node(item);
		newNode->prev = last;
		last->next = newNode;
		last = newNode;
		totalSize++;
		return true;
	}
}


/*
 * Add's an item to specified index number.
 * Any Number between 0 and (total number of node) - 1 is a valid index number to add element.
 * this method first checks given index number , if index is valid it follows three different procedures for add item in
 * three types of index locations. these index locations are 0 , all between 1 and (totalSize - 2)  and last index which is (totalSize -1)
 * these locations required different procedure for insertion item.
 * if index is not valid it return false.
 * */


void LinkedList::add(int item , int index) {
	if(isValidIndex(index) && head!=nullptr) {   // checking validity of index

		/*
		 * 	PROCEDURE for all index between 1 and (totalSize - 2)
		 **/
		if (index!=0 && index != (totalSize-1)) {
			Node *newNode = new Node(item);
			Node *temp = nullptr;

			/* This procedure divide the linked list into two half list and reach the target by either binging or end
			 * 	of the list as which requires less steps.
			 **/

			// adding element from end of list.
			if (index > midIndex()) {
				temp = last;
				for (int i = totalSize-2 ;i >= index;i-- ) {
					temp = temp->prev;
				}
				temp->prev->next = newNode;
				newNode->prev = temp->prev;
				temp->prev = newNode;
				newNode->next = temp;
				totalSize++;
			}

			//adding item from binging of the list
			else {
				temp = head;
				for (int i = 0;i<index - 1;i++) {
					temp  = temp->next;
				}
				temp->next->prev = newNode;
				newNode->next = temp->next;
				temp->next = newNode;
				newNode->prev = temp;
				totalSize++;
			}
		}

		// Procedure for add when given index is 0
		else if (index==0 && head!=nullptr) {
			Node *newNode = new Node(item);
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
			totalSize++;
		}

		// Procedure for add when given index is last (totalSize-1)
		else {
			Node *newNode = new Node(item);
			last->prev->next = newNode;
			newNode->prev = last->prev;
			last->prev = newNode;
			newNode->next = last;
			totalSize++;
		}
	}


	else if (index==0 && head==nullptr) {
		add(item);
	}
	// Return false if index is invalid.
	else {
		throw(InvalidIndexException("Given Index is Invalid.",index));
	}
}

/*
 * returns the item which is specified by the index. throws InvalidIndexException if given index is invalid
 *
 * */
int LinkedList::get(int index) {
	if (isValidIndex(index)) {
		if (index < midIndex()) {
			Node *temp  = head;
			for (int i = 0 ; i < index ;i++ ) {
				temp = temp->next;
			}
			return temp->getItem();
		}

		else {
			Node *temp = last;
			for (int i = (totalSize - 1); i>index ;i--) {
				temp = temp->prev;
			}
			return temp->getItem();
		}
	}
	else {
		throw(InvalidIndexException("Given Index is Invalid.",index));
	}
}

/*
 * Removes an item in the list specified by the index . throws InvalidIndexException
 *
 * */
int LinkedList::remove(int index) {
	if (isValidIndex(index)) {
		if (index !=0 && index!=(totalSize-1)) {
			if (index < midIndex()) {
				Node *temp = head;
				for (int i = 1 ; i <= index ; i++) {
				temp = temp->next;
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				int val = temp->getItem();
				delete temp;
				totalSize--;
				return val;
			}

			else {
				Node *temp = last;
				for (int i = totalSize-2 ; i >= index ; i--) {
					temp = temp->prev;
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				int val = temp->getItem();
				delete temp;
				totalSize--;
				return val;
			}
		}
		else if (index == 0) {
			Node *del = head;
			head->next->prev = nullptr;
			head = head->next;
			int val = head->getItem();
			delete del;
			totalSize--;
			return val;
		}

		else {
			Node *del = last;
			last->prev->next = nullptr;
			last = last->prev;
			int val = last->getItem();
			delete del;
			totalSize--;
			return val;
		}
	}
	else {
		throw InvalidIndexException("Given Index is Invlid",index);
	}
}

/* returns the current total number of nodes or items in the list*/
int LinkedList::size() {
	return totalSize;
}

/*Deletes all items in the list*/
void LinkedList::emptyList() {
	for (int i = 0 ; i < totalSize ; i++) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	totalSize = 0;
}

/*
 * Swaps the items between two index locations
 * */
void LinkedList::swap(int index1 , int index2) {
	//check given index first
	if (index1!=index2 && isValidIndex(index1) && isValidIndex(index2) ) {
		int lowIndex  = -1, highIndex = -1;

		// resolve high index and low index values
		if (index1>index2) {
			highIndex = index1;
			lowIndex = index2;
		}
		else {
			highIndex = index2;
			lowIndex = index1;
		}
		//get a copy of nodes in the list
		Node first = getNode(lowIndex);
		Node second = getNode(highIndex);

		// remove  the lower index node
		remove(lowIndex);

		// add there item of high index node
		add(second.getItem(),lowIndex);

		// remove high index node
		remove(highIndex);

		// add there low index node item
		add(first.getItem(),highIndex);


	}

	// do nothing if both indexes are same
	else {
		return;
	}
}

// returns true if a next item available in the list else returns false
bool LinkedList::hasNext() {
	if (iterator != nullptr && i_flag == true)
		return true;
	else
		return false;
}
// returns true if a previous item available in the list else returns false
bool LinkedList::hasPrevious() {
	if (iterator != nullptr) {
		if (iterator->prev != nullptr && i_flag == true)
			return true;
		else if (iterator->prev != nullptr && i_flag == false)
			return true;
		else if (iterator->prev == nullptr && i_flag == false)
			return true;
		else
			return false;
	}
	else
		return false;
}

// returns the next item in the list else throws Exception
int LinkedList::next() {
	if (iterator!=nullptr && i_flag == true) {
		int val = iterator->getItem();
		if (iterator->next != nullptr) {
			iterator = iterator->next;
		}
		else {
			i_flag = false;
		}
		return val;
	}
	else {
		throw EndOfListException("Reached End of List or List is Empty",1);
	}
}
// returns the previous item in the list else throws Exception
int LinkedList::previous() {

	if (iterator != nullptr) {
		if (iterator->prev != nullptr && i_flag == true) {
			iterator = iterator->prev;
			return iterator->getItem();
		}

		else if (iterator->prev != nullptr && i_flag == false) {
			i_flag = true;
			return iterator->getItem();
		}
		else if (iterator->prev == nullptr && i_flag == true)
			throw EndOfListException("Reached End of List or List is Empty",0);
		else
			return false;
	}
	else {
		throw EndOfListException("Reached End of List or List is Empty",0);
	}

}

// returns true if linked list is Empty
bool LinkedList::isEmpty() {
	if (totalSize ==0) return true;
	else return false;
}



// Driver function to test linked list
int main() {
	LinkedList obj;
	try {
		for (int i = 1;i<=10;i++) {
			obj.add(i*10);
		}
		int i;
		do {
			cout<<"1 next"<<endl;
			cout<<"2 prev"<<endl;

			cin>>i;
			switch(i) {
			case 1:
				cout<<obj.next()<<endl;
				break;
			case 2:
				cout<<obj.previous()<<endl;
				break;
			}
		}while(i!=3);


	}
	catch(EndOfListException &e) {
		e.displayException();
	}

	return 0;
}
