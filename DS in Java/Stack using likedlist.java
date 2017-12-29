/**
 * Integer Stack using Singly Linked List
 * @author Sachin Singh
 * */

class LLStack {  // linked list stack
    class Node {
        int num; // to hold data value
        Node next; // pointer to next node in the list
    }
    private int size=0;
    Node head=null;
    boolean isEmpty() {
        return head==null;
    }
    void push(int item) {
        if (head == null) {
            Node top = new Node();
            top.num = item;
            top.next = null;
            head=top;
            size++;
        }

        else {
             Node top = new Node();
             top.num = item;
             top.next = head;
             head = top;
             size++;
        }
    }

    int pop() {
        if (head==null) {
            return -1;
        }

        else {
            int temp = head.num;
            head = head.next;
            size--;
            return temp;
        }
    }

    int peek() {
        if (head!=null) {
            return head.num;
        }
        return -1;
    }

    int size() {
        return size;
    }

}

public class Main {
    public static void main(String[] args) {
        LLStack stack = new LLStack();
        System.out.println("Size of stack : " + stack.size());
        stack.push(3);
        stack.push(2);
        stack.push(1);
        System.out.println("Size of stack : " + stack.size());
        System.out.println("Pop item : " + stack.pop());
        System.out.println("Pop item : " + stack.pop());
        System.out.println("Pop item : " + stack.pop());
        System.out.println("Size of stack : " + stack.size());

    }
}
