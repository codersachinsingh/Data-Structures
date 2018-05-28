/**
 * ---- Expression Bracket Validator------
 * Author : Sachin Singh
 * */

#include <iostream>
using namespace std;

/* Character Stack with push , pop and peek methods*/
class Stack {
private:
	char array[50];
	int tos;
	int total;
public:
	Stack() {
		tos = -1;
		total = 0;
		for (int i = 0 ; i < 50 ; i++) {
			array[i] = '\0';
		}
	}

	void push(char c) {
		if (tos != 49) {
			array[++tos] = c;
			total++;
		}
	}

	char peek() {
		if (tos != -1) {
			return array[tos];
		}
		return '\0';
	}
	char pop() {
		if (tos != -1) {
			total--;
			return array[tos--];
		}
		return '\0';
	}

	int size() {
		return total;
	}
};

/* Class that Checks and validate the Expression*/
class BracketChecker {
private:
	Stack stack;

	// returns a number assosiated with specific type of bracket.
	int bracketType(char b) {
		switch(b) {
		case '(' :
			return 1;
		case ')' :
			return 2;
		case '[' :
			return 3;
		case ']' :
			return 4;
		case '{' :
			return 5;
		case '}' :
			return 6;
		default :
			return 0;
		};
	}
public:

//	method that validates the Expression
//	parameter : expression char array
	int validator(char *exp) {
		for (int i = 0 ; exp[i] ; i++ ) {
			/*
			 * if current symbol is any open bracket , then push it into stack.
			 * */
			if ( (exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')) {   // if character is a any bracket
				cout<<exp[i]<<"  Found"<<endl;
				stack.push(exp[i]);
			}

			else if ( (exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) {
				/*
				 * if current symbol is any closing bracket , then check that its opening bracket is
				 * in stack or not.
				 * if same open-close bracket pair matches then pop the sysbol out and continue
				 * otherwise stop the procedure inform expression is invalid.
				 * */
				cout<<exp[i]<<"  Found"<<endl;
				if ( (bracketType(stack.peek()) + 1 ) == bracketType(exp[i])) {
					stack.pop();
					continue;
				}
				else
					return 0;
			}
		}

		return 1;
	}
};

// Driver Function
int main() {
	BracketChecker obj;
	cout<<"Enter a Expression with brackets : ";
	char str[100];
	cin.getline(str,100);
	if (obj.validator(str)) {
		cout<<"Expression is Valid"<<endl;
	}
	else {
		cout<<"Expression is Invalid"<<endl;
	}
	return 0;
}
