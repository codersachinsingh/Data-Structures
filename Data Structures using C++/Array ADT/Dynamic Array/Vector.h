/**
 * Dynamic Generic Array class.
 * filename : Vector.h
 * Date : 06-june-2018
 * Author : Sachin Singh
 * 
*/
#include <iostream>
#include<cmath>
using namespace std;
#ifndef VECTOR_H_
#define VECTOR_H_

// base class for all vector exceptions
class VectorException {
    public:
        VectorException(){}
};

// A MemeryAllocationException is thrown when a memory allocation request  fails.
class MemoryAllocationException : public VectorException {
    public:
        MemoryAllocationException(){}
};

// An InvalidIndexException is thrown when a invalid index is given to perform some action.
class InvalidIndexException : public VectorException {
    public:
        InvalidIndexException() {}
};


/**
 * A generic Array class that grows and shrinks dynamically
*/
template <typename Object>
class Vector {
    private:
        Object *array;
        int array_size;
        int capacity;
        void increaseCapacity();
        void checkAndShrinkCapacity();
        bool isVectorEmpty();
        bool isVectorFull();
    public:
        // Constructors
        Vector();
        Vector(int capacity);
        Vector(Vector<Object> &vector);
        ~Vector();
        // Methods
        bool pushBack(const Object&);
        Object& popOut();
        bool insert(const Object&);
        bool insert(int,const Object&);
        Object& get(int);
        Object remove(int);
        int currentCapacity() const;
        int size() const;
        int persentageFull();
        //Overloaded Operators
        Object& operator[](int);
};
// returns true if there is no element in vector;
template<typename Object> bool Vector<Object>::isVectorEmpty() {
    if (array_size == 0)
        return true;
    else
        return false;
}
// returns true if vector is full of its capacity.
template<typename Object> bool Vector<Object>::isVectorFull() {
    if (array_size == capacity)
        return true;
    else
        return false;
}

// returns the used capacity in persentage.
template<typename Object> int Vector<Object>::persentageFull() {
    if (array_size == 0)
        return 0;
    int per = (array_size  * 100) / capacity;
    return per;
}

/**
 * this method checks the size of vector and shrinks the capacity by 
 * 50% if vector using less than 30% of its total capacity.
 * 
*/
template<typename Object> void Vector<Object>::checkAndShrinkCapacity() {
    if (persentageFull() > 30)
        return;
    else {
        int currentCapacity = capacity;
        // Reduce capacity by 50% if array using less than 30 persent of capacity.
        capacity = currentCapacity/2;

        //
        Object *new_temp_array = new Object[capacity];
        // check for allocation failier

         if (new_temp_array == nullptr)
        throw(MemoryAllocationException());
    
          // copying elements to new array if allocation is succussful.
         for (int i = 0 ; i < array_size ; i++) {
             new_temp_array[i] = array[i];
           }

          // release memory occupied by old array.
          delete[] array;

          // assign new array to pointer

          array = new_temp_array;
    }
}
/**
 * Increases the vector capacity by 50%
*/
template<typename Object> void Vector<Object>::increaseCapacity() {
    int currentVectorCapacity = capacity;
    // increasing capacity by 50% of current capacity.
    capacity = currentVectorCapacity + currentVectorCapacity/2;

    // creating new array
    Object* new_temp_array = new Object[capacity];

    // check for allocation failier

    if (new_temp_array == nullptr)
        throw(MemoryAllocationException());
    
    // copying elements to new array if allocation is succussful.
    for (int i = 0 ; i < array_size ; i++) {
        new_temp_array[i] = array[i];
    }
    
    // release memory occupied by old array.
    delete[] array;

    // assign new array to pointer

    array = new_temp_array;
}

/**
 * Default Constructor :
 * Creates a Vector with 10 capacity.
*/
template <typename Object> Vector<Object>::Vector() {
    capacity = 10; // default capacity
    array = new Object[10];
    array_size = 0;
}

/**
 * this constructor takes one integer argument representing the initial size of the 
 * vector. 2 is the minimum size. if initial size is invalid , vector is created with 
 * initial capacity of 10. 
*/
template <typename Object> Vector<Object>::Vector(int init_capacity) {
    if (init_capacity >= 2)
        capacity = init_capacity;
    else
        capacity = 10;
    array = new Object[capacity];
    array_size = 0;
}
//Copy Constructor
template <typename Object> Vector<Object>::Vector(Vector<Object> &vector) {
    capacity = vector.capacity;
    array = new Object[capacity];
    array_size = vector.array_size;
    //Coping array
    for (int i = 0 ; i < array_size ; i++) {
        array[i] = vector.array[i];
    }
}

// Destructor deletes the allocated memory.
template <typename Object> Vector<Object>::~Vector() {
    // releasing the memory occupied by array
    delete[] array;
}

/**
 * A stack terminology push method that insert element at end of the stack.
*/
template <typename Object> bool Vector<Object>::pushBack(const Object &item) {
    if (isVectorFull())
        increaseCapacity();
    array[++array_size -1] = item;
    return true;
}

/**
 * A stack terminology pop method that returns the last inserted element and removes it from the array.
*/
template <typename Object> Object& Vector<Object>::popOut() {
    if (isVectorEmpty())
        throw (VectorException());
    else
        checkAndShrinkCapacity();
        array_size--;
        int index = array_size;
        return array[index];

}

// Insert an element at end of the array , same as push method
template <typename Object> bool Vector<Object>::insert(const Object &item) {
    if (isVectorFull())
        increaseCapacity();
    array[array_size] = item;
    array_size++;
    
    return true;
}

// Inserts an element at specified index , if index is invalid , an exception will be thrown.
template <typename Object> bool Vector<Object>::insert(int index , const Object &item) {
    if (index < 0 || index > array_size)
        throw(InvalidIndexException());
    else if (index == array_size) {
        if (isVectorFull())
            increaseCapacity();
        array[array_size] = item;
        array_size++;
        return true;
    }
    else {
        if(isVectorFull())
            increaseCapacity();
        int j = array_size - 1; 
        while (j >= index) {
            array[j+1] = array[j];
            j--;
        }
        array[index] = item;
        array_size++;
        return true;
    }
}

// Retrieve the element by index. throws exception if index is invalid.
template <typename Object> Object& Vector<Object>::get(int index) {
    if (index < 0 || index > (capacity-1))
        throw(InvalidIndexException());
    else
        return array[index];
}

// removes the element by index. throws exception if index is invalid.
template <typename Object> Object Vector<Object>::remove(int index) {
    if (index < 0 || index > (array_size - 1))
        throw(InvalidIndexException());
    else if (index == array_size - 1) {
        array_size--;
        checkAndShrinkCapacity();
        return array[array_size];
    }
    else {
        Object temp =  array[index];
        while(index <= array_size-1) {
            array[index] = array[index + 1];
            index++;
        }
        array_size--;
        checkAndShrinkCapacity();
        return temp;
    }
}
//Returns the current capacity of the vector.
template <typename Object> int Vector<Object>::currentCapacity() const {
    return capacity;
}

// returns the total no of elements .
template <typename Object> int Vector<Object>::size() const {
    return array_size;
}

// Overloading [] operator 
template <typename Object> Object& Vector<Object>::operator[](int index) {
    if (index < 0 || index > (capacity-1))
        throw(InvalidIndexException());
    else
        return array[index];
}


#endif  // VECTOR_H_