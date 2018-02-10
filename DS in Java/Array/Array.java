/**Data Structures : Array
 * Filename : array.java
 * @author Sachin Singh (7982858206)
 * Email : sachinsingh.sk13@gmail.com
 * Date : 10-02-2018
 * Description : Generic Array class in java.
 * */

public class Array<T> {
  private Object[] array; // to hold elements of any types
  private int upperBound;
  private int capacity;

  /*this method increases list capacity by 50% of current capacity*/
  private void increase_capacity() {
      Object[] temp;
     if (array==null && capacity == 0) { // in case of empty method called
          temp = new Object[10];
          capacity = 10;
     }
     else {
         temp = new Object[capacity = capacity + capacity/2];
         for (int i = 0 ; i < array.length ; i++) {
             temp[i] = array[i];
         }
     }
     array = temp;
  }
    /*Default constructor initializes Array object with initial capacity of 10 elements*/
    public Array() {
        array = new Object[10];
        upperBound = 0;
        capacity = 10;
    }

    /*User can specify the initial capacity of Array*/
    public Array(int init_capacity) {
        upperBound = 0;
        if (init_capacity>2) {
            array = new Object[init_capacity];
            capacity = init_capacity;
        }
        else {
            array = new Object[10];
            capacity = init_capacity;
        }
    }

    /*this method add's an element at the end of the array*/
    public void add(T item) {
        if (upperBound < capacity) { // check for if list is full
            array[upperBound++] = item;
        }
        else {
            increase_capacity(); //increase the list capacity
            array[upperBound++] = item;
        }
    }

    /*this method add's an element at specified index. if index is invalid it does nothing*/
    public void add(T item,int index) {
      if (upperBound==capacity) {
          increase_capacity();
      }
      if (index >= 0 && index <= upperBound) {
          int i = upperBound;
          while(i>index) {
              array[i] = array[i-1];
              i--;
          }
          array[index] = item;
          upperBound++;
      }
    }

    public void add(T[] arr) {
        for (T x : arr) {
            add(x);
        }
    }

    /*deletes the last element in array and returns it*/
    public T delete() {
      return (T) array[upperBound-- - 1];
    }

    /*deletes the element specified by index and returns the deleted element. if index is invalid it return null*/
    public T delete(int index) {
      if (index>=0 && index <=upperBound) {
          int i = index;
          T temp = (T) array[index];
          while(i<upperBound) {
              array[i] = array[i+1];
              i++;
          }
          upperBound--;
          return temp;
      }
      else {
          return null;
      }
    }
    /*to retrieve element specified index. if index is invalid it return null*/
    public T get(int index) {
      if (index>=0 && index < upperBound) {
          return (T)array[index];
      }
      else {
          return null;
      }
    }
    public void empty() {
        upperBound = 0;
        array = null;
        capacity = 0;
    }
    public int size() {
        return upperBound;
    }
}
