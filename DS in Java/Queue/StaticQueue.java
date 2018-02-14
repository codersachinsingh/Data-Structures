public class StaticQueue <T> {
    Object[] queue;
    int rear,front;
    private final int capacity;
    public StaticQueue() {
        this.capacity = 10;
        queue = new Object[10];
        rear = front = -1;
    }

    public StaticQueue(int capacity) {
        front = rear = -1;
        if (capacity > 2) {
            queue = new Object[this.capacity = capacity];
        }
        else {
            queue = new Object[this.capacity = 10];
        }
    }

    public void enqueue(T item) {
        if (rear == -1) {
            queue[++rear] = item;
            front = 0;
        }
        else if (rear != capacity - 1) {
            queue[++rear] = item;
        }
        else {
            System.out.println("Queue is Full");
        }
    }

    public T dequeue() {
        if (front < 0 || front > rear) {
            System.out.println("Queue is Empty");
            return null;
        }
        else {
            return (T) queue[front++];
        }
    }
}
