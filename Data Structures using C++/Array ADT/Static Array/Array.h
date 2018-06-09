/**
 * An Generic static array class.
 * filename : Array.h
 *
 *  Created on: Jun 6, 2018
 *      Author: Sachin Singh
 */

#ifndef ARRAY_H_
#define ARRAY_H_

// Exception class
// object of this class is thrown when an invalid index is given to the array
class ArrayIndexOutOfBoundException {
	public:
		ArrayIndexOutOfBoundException() {}
};


// Generic Array class
// Object = data type
// size = size of the array.
// default type is int and default size is 10.
template <typename Object = int , int size = 10>
class Array {
	Object array[size];
private:

public:
	Array();
	Object& operator[](int);
	int lenght();
};
template <typename Object , int size> Array<Object,size>::Array() {
}

template <typename Object , int size> Object& Array<Object,size>::operator[](int index) {
	if (index >= 0 && index < size)
		return this->array[index];
	else
	throw (ArrayIndexOutOfBoundException());
}
template <typename Object , int size> int Array<Object,size>::lenght() {
	return size;
}
#endif /* ARRAY_H_ */
