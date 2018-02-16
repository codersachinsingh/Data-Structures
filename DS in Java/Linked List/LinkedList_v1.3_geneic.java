/**
 * Data Structures : Linked List
 * Filename : linkedlist_v1.3.java
 * @author Sachin Singh
 * Email : sachinsingh.sk13@gmail.com
 * Description : Generic LinkedList class  
 * @version 1.3
 * */

public class LinkedList<T> {
	/*Node Structure of Linked List*/
	private static class Node <T>{
		private T data;		//to hold information
		Node<T> next;
		Node(T d) {
			this.data = d;
			next = null;
		}
		
		T getItem() {
			return this.data;
		}
	}
	/*Head Pointer*/
	private Node<T> head;
	private int size;
	
	/*Returns a newly created node with given item*/
	private Node<T> getNewNode(T item) {
		return new Node<T>(item);
	}
	
	public LinkedList() {
		head = null;
		size = 0;
	}
	
	/*Inserts an item at end of the list*/
	public void insert(T item) {
		if (head!=null) {
			Node<T> temp = head;
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
	public void insert(T item, int index) {
		if (index < 0 || index > size) {
			System.out.println("Invalid Index");
		}
		else {
			
				if (index == 0) {
					Node<T> node = getNewNode(item);
					node.next = head;
					head = node;
					size++;
				}
				else {
				Node<T> temp = head;
				for (int i = 0;i<(index-1);i++) { // stop at just before where we have to add new node
					temp = temp.next;
				}
				Node<T> node = getNewNode(item);
				node.next = temp.next;
				temp.next = node;
				size++;
				}
		}
	}
	
	/*Returns item when specified index is correct else return -1. */
	public T get(int index) {
		if (size>0 && index>= 0 && index < size) {
			if (index == 0) {
				return head.getItem();
			}
			else {
				Node<T> temp = head;
				for (int i = 0;i<index;i++) { 
					temp = temp.next;
				}
				return (T) temp.getItem();
			}
		}
		else {
			System.out.println("List is Empty");
			return null;
		}
	}
	/*removes the item at specified index in the list and returns it. returns -1 when index is incorrct*/
	public T remove(int index) {
		if (size > 0 && index >= 0 && index < size) {
			if (index == 0) {
				T temp = (T) head.getItem();
				head = head.next;
				size--;
				return  temp;
			}
			else {
				Node<T> temp = head;
				for (int i = 0;i<(index-1);i++) { // stop at just before the target node
					temp = temp.next;
				}
				T tm = (T) temp.next.getItem();
				temp.next = temp.next.next;
				size--;
				return tm;
			}
		}
		else {
			System.out.println("List is Empty");
			return null;
		}
	}
	
	/*Returns total number of items in list*/
	public int listSize() {
		return size;
	}
	
	/*Display all items of list*/
	public void traverse() {
		Node<T> temp = head;
		while(temp!=null) {
			System.out.println("Data is : " + temp.getItem());
			temp = temp.next;
		}
	}
	
}
