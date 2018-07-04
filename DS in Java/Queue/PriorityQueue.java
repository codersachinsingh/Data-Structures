package ds.heaps;
/**
 * Priority Queue is a data structure in which values can be be added in any order but they are removed on
 * the the basis of priority. Highest value get higher priority over others.
 *
 * @author Sachin Singh
 * @version 1.0
 * */


public class PriorityQueue {

    private int[] maxHeap;
    private final int MaxQueueSize;
    private int currentSize;

    /**
     * Default Constructor of Priority Queue
     * Sets the default capacity of 10.
     * */

    public PriorityQueue() {
        MaxQueueSize = 10;
        maxHeap = new int[MaxQueueSize];
        currentSize = 0;
    }

    /**
     *
     * @param capacity specifies the storage capacity of the priority queue.
     * */
    public PriorityQueue(int capacity) {
        currentSize = 0;
        if (capacity >= 2) {
            MaxQueueSize = capacity;
            maxHeap = new int[MaxQueueSize];
        }
        else {
            MaxQueueSize = 10;
            maxHeap = new int[MaxQueueSize];
        }
    }

    /**
     * This method inserts a value into the priority queue
     * @param value value to be inserted in the priority queue.
     * */
    public void insert(int value) {
        if (currentSize != MaxQueueSize - 1) {
            int newValueIndex = currentSize++;
            maxHeap[newValueIndex] = value; // store the value at the last position.
            boolean heapMaintainFlag = true;
            while (heapMaintainFlag && newValueIndex != 0) {
                int parentIndex = (newValueIndex - 1) / 2;
                if (maxHeap[newValueIndex] > maxHeap[parentIndex]) {
                    // swap values if child value is greater than parent value.
                    int tempVar = maxHeap[newValueIndex];
                    maxHeap[newValueIndex] = maxHeap[parentIndex];
                    maxHeap[parentIndex] = tempVar;
                    newValueIndex = parentIndex;
                } else // value reached at proper position.
                    heapMaintainFlag = false; // come out of loop.
            }
        } else {

            System.out.println("Can't Insert Items. Queue is Full.");
        }
    }

    /**
     * This method returns the highest priority value without removing it from the queue.
     * @return highest priority value
     * */
    public int peek() {
        if (currentSize != 0)
            return maxHeap[0];
        else
            return -1;
    }
    /**
     * This mehtod returns the highest priority value and removes it from the queue.
     * @return highest priority value.
     * */
    public int remove() {
        if (currentSize != 0) {
            //store the root value (highest value in heap) for return.
            int value = maxHeap[0]; 
            // replace the last value with root value
            maxHeap[0] = maxHeap[--currentSize]; 
            boolean loopFlag = true;
            int index = 0;
            while(loopFlag && index <= currentSize) {
                int maxChildIndex; // to store the index of child with maximum value.
                int leftChildIndex = index * 2 + 1;

                // if left child index is out of index then halt the loop
                // it means value is reached its correct position.
                if(leftChildIndex > currentSize) 
                    break;
                int rightChildIndex = index * 2 + 2;
                // if right child is out of index then it means parent node has 
                // only left child and so assign left child index to max child index.
                // otherwise compare the both left and right child value and assign max to max child index.
                if (rightChildIndex > currentSize)
                    maxChildIndex = leftChildIndex;
                else
                    maxChildIndex = (maxHeap[leftChildIndex] > maxHeap[rightChildIndex]?leftChildIndex:rightChildIndex);
                if (maxHeap[index] < maxHeap[maxChildIndex]) {
                    int tempVar = maxHeap[index];
                    maxHeap[index] = maxHeap[maxChildIndex];
                    maxHeap[maxChildIndex] = tempVar;
                    index = maxChildIndex;
                }
                else
                    loopFlag = false;
            }
            return value;
        }
        else {
            System.out.println("Queue is empty now.");
            return -1;
        }
    }
    /**
     * This method returns the number of values that are currently stored in the queue.
     * @return total number of values currently in queue
     * */
    public int size() {
        return currentSize;
    }
}
