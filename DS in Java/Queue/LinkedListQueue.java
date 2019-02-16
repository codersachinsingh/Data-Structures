package dsa.queue;

public class LinkedListQueue {
    private Node rear;
    private Node front;
    private int length;
    public void insert(int item) {
        Node node = new Node();
        node.data = item;
        node.next = null;

        if (front == null) {
            front = rear = node;
        }
        else {
            rear.next = node;
            rear = node;
        }
        length++;
    }

    public int delete() {
        if (front != null) {
            int val = front.data;
            front = front.next;
            length--;
            return val;
        }
        return -1;
    }

    public int peek() {
        if (front != null) {
            return front.data;
        }
        return -1;
    }
    public int size() {
        return length;
    }
}
