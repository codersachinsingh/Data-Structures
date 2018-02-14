/**
 * Data Structures : Queue
 * Filename : queue.java
 * @author Sachin Singh
 * Email : sachinsingh.sk13@gmail.com
 * Description : Queue is a First in first out list.
 * */

public class Queue<T> {
    private Object[] queue;
    private int rear;
    private int front;
    private int size;
    private int capacity;
    private void increase_capacity() {
        Object[] temp = new Object[capacity = capacity + capacity/2];
        for (int i = 0;i < queue.length ;i++) {
            temp[i] = queue[i];
        }
        queue = temp;
    }
    public Queue() {
        rear = front = -1;
        size = 0;
        queue = new Object[capacity = 10];
    }

    public Queue(int init_capacity) {
        rear = front = -1;
        size = 0;
        if (init_capacity > 2) {
            queue = new Object[capacity = init_capacity];
        }
        else {
            queue = new Object[capacity = 10];
        }
    }

    void enqueue(T item) {
        if (rear == -1) {
            queue[++rear] = item;
            front = 0;
            size++;
        }
        else if (rear != (capacity-1)) {
            queue[++rear] = item;
            size++;
        }
        else {
            increase_capacity();
            enqueue(item);
        }
    }

    T dequeue() {
        if (front < 0 || front > rear) {
            front = rear = -1;
            return null;
        }

        else {
            size--;
            return (T) queue[front++];
        }
    }

    T peek() {
        if (front < 0 || front > rear) {return null;}
        else {return (T) queue[front];}
    }
    int queue_size() {return size;}

    int getCapacity() {return capacity;}

}
