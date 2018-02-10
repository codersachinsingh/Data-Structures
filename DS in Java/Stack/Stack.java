/**
 * Data Structures : Stack
 * Filename : stack.java
 * @author Sachin Singh
 * Email : sachinsingh.sk13@gmail.com
 * Description : basic stack class with push() , pop() , peek() and size() methods.
 * */

public class Stack<T> {
    Object[] stack;
    int tos;
    int capacity;

    /*increase stack capacity by 50% */
    private void increase_capacity() {
        Object[] temp = new Object[capacity = capacity + capacity/2];
        for (int i = 0;i < stack.length ;i++) {
            temp[i] = stack[i];
        }
        stack = temp;
    }

    public Stack() {
        stack = new Object[10];
        tos = -1;
        capacity = 10;
    }

    public Stack(int init_capacity) {
        tos = -1;
        if (init_capacity>2) {
            stack = new Object[init_capacity];
            capacity = init_capacity;
        }
        else {
            stack = new Object[10];
            capacity = 10;
        }
    }

    public void push(T item) {
        if (tos != capacity - 1) {
            stack[++tos] = item;
        }
        else {
            increase_capacity();
            stack[++tos] = item;
        }
    }

    public T pop() {
        if (tos != -1) {
            return (T) stack[tos--];
        }
        else {
            return null;
        }
    }

    public T peek() {
        if (tos != -1) {
            return (T) stack[tos];
        }
        else {
            return null;
        }
    }

    public int size() {
        return tos+1;
    }

    public void empty() {
        stack = null;
        // reinitialize with capacity 10
        stack = new Object[10];
        capacity = 10;
        tos = -1;
    }
}
