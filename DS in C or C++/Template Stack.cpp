template <class T>
class Stack {
	private:
		T *stack;
		int tos;
		int size;

		bool isFull() {
			if (tos == (size-1) ) 
			return true;
			else 
			return false;
		}

		bool isEmpty() {
			if (tos == -1) 
			return true;
			else
			return false;
		}

	public:
		Stack() {
			stack = new T[10];
			tos = -1;
			size = 10;
		}

		void push(T item) {
			if (!isFull()) {
				*(stack + (++tos)) = item;
			}

			else {
				T *temp = new T[2*size];
				for (int i = 0 ; i < size ; i++){
					*(temp+i) =  *(stack + i);
				}
				delete[] stack;
				stack = temp;
				size = 2*size;
				*(stack + (++tos)) = item;
			}
		}

		T pop() {
				if (!isEmpty()) {
					return *(stack + (tos--));
				}

				else {
					cout<<"\nStack is Empty.";
				}
			}
		
		T peek() {
			if (!isEmpty()) {
				return *(stack + (--tos));
			}

			else {
				cout<<"\nStack is Empty.";
			}
		}
};
