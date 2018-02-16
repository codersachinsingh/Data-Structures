import java.util.Iterator;

/**
 * Data Structures : Linked List
 * Filename : linkedlist.java
 * @author Sachin Singh
 * Email : sachinsingh.sk13@gmail.com
 * Description : LinkedList class  
 * @version 1.1
 * */

public class LinkedList implements Iterator<Integer> {
	/*Node Structure of Linked List*/
	private static class Node {
		private int data;		//to hold information
		Node next;
		Node(int d) {
			this.data = d;
			next = null;
		}
		
		int getItem() {
			return this.data;
		}
	}
	
	/*Head Pointer*/
	private Node head;
	private int size;
	private int iterator = 0;
	/*Returns a newly created node with given item*/
	private Node getNewNode(int item) {
		return new Node(item);
	}
	
	public LinkedList() {
		head = null;
		size = 0;
	}
	
	/*Inserts an item at end of the list*/
	public void insert(int item) {
		if (head!=null) {
			Node temp = head;
			while(temp.next!=null) {		//goto end of list
				temp = temp.next;
			}
			temp.next = getNewNode(item);
		}
		
		else {
			head = getNewNode(item);
		}
		size++;
	}
	
	/*Inserts given item to specified index*/
	public void insert(int item, int index) {
		if (index < 0 || index > size) {
			System.out.println("Invalid Index");
		}
		else {
			
				if (index == 0) {
					Node node = getNewNode(item);
					node.next = head;
					head = node;
					size++;
				}
				else {
				Node temp = head;
				for (int i = 0;i<(index-1);i++) { // stop at just before where we have to add new node
					temp = temp.next;
				}
				Node node = getNewNode(item);
				node.next = temp.next;
				temp.next = node;
				size++;
				}
		}
	}
	
	/*Returns item when specified index is correct else return -1. */
	public int get(int index) {
		if (size>0 && index>= 0 && index < size) {
			if (index == 0) {
				return head.getItem();
			}
			else {
				Node temp = head;
				for (int i = 0;i<index;i++) { 
					temp = temp.next;
				}
				return temp.getItem();
			}
		}
		else {
			System.out.println("List is Empty");
			return -1;
		}
	}
	/*removes the item at specified index in the list and returns it. returns -1 when index is incorrct*/
	public int remove(int index) {
		if (size > 0 && index >= 0 && index < size) {
			if (index == 0) {
				int temp = head.getItem();
				head = head.next;
				size--;
				return temp;
			}
			else {
				Node temp = head;
				for (int i = 0;i<(index-1);i++) { // stop at just before the target node
					temp = temp.next;
				}
				int tm = temp.next.getItem();
				temp.next = temp.next.next;
				size--;
				return tm;
			}
		}
		else {
			System.out.println("List is Empty");
			return -1;
		}
	}
	
	/*Returns total number of items in list*/
	public int listSize() {
		return size;
	}
	
	/*Display all items of list*/
	public void traverse() {
		Node temp = head;
		while(temp!=null) {
			System.out.println("Data is : " + temp.getItem());
			temp = temp.next;
		}
	}
	
	@Override
	public boolean hasNext() {
		
		return iterator<size;
		
	}

	@Override
	public Integer next() {
		
		return this.get(iterator++);
	}
	
	public void resetIterator() {
		iterator = 0;
	}
	
}
