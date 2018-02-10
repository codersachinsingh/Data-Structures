import java.util.Scanner;
class MyStack {
	char[] stack;
	int tos;
	int size;
	MyStack(int size) {
		stack = new char[size];
		this.size = size;
		tos = -1;
	}
	private boolean isFull() {
		if (tos == (size-1))
			return true;
		else
			return false;
	}

	private boolean isEmpty() {
		if (tos == -1)
			return true;
		else 
			return false;
	}

	public void push(char ch) {
		if (!isFull()) {
			stack[++tos] = ch;
		}

		else
			{
				size = size*2;
				char[] temp = new char[size];
				for (int i = 0 ; i< this.stack.length ; i++)
					{
						temp[i] = this.stack[i];
					}
				this.stack = temp;
				stack[++tos] = ch;
			}
	}

	char peek()
	{
		if (!isEmpty())
			{
				return stack[tos];
			}

		else 
			return '~';
	}
	char pop() {
		if (!isEmpty())
			{
				return this.stack[tos--];
			}
		else
			{
				System.out.println("Stack is Empty");
				return '~';
			}
	}
}
class PostFix extends MyStack {
	String infix;
	String postfix;
	PostFix() {
		super(10);
		super.push('(');
		infix = "";
		postfix = ""; 
	}
	void convert() {
		for (int i = 0 ; i < infix.length() ; i++)
			{
				if (this.isOperator(infix.charAt(i)))
					{
						if (infix.charAt(i)==')')
							{
								while(true)
									{
										if (super.peek()!='(')
											{
											postfix = postfix + super.pop();
										
											}
										else
											{
												super.pop();
												break;
											}
									}
							}

						else if (infix.charAt(i)=='(')
							{
								super.push(infix.charAt(i));
							}

						else if ( this.precedence(super.peek()) >= this.precedence(infix.charAt(i)))
							{
								postfix = postfix + super.pop();
								super.push(infix.charAt(i));
							}

						else 
							{
								super.push(infix.charAt(i));
							}
					}

				else
					{
							postfix = postfix + infix.charAt(i);
					}
			}
	}
	String getPostfix(String in)
	{
		this.infix = in + ')';
		this.convert();
		return postfix;
	}
	boolean isOperator(char sym) {
		switch(sym) {
			case '(':
			case '*':
			case '/':
			case '+':
			case '-':
			case '^':
			case ')':
				return true;
			default : 
				return false;
		}
	}
	int precedence(char sym) {
		switch(sym)
		{
			case '(' : 
				return 1;
			case '+':
			case '-':
				return 2;
			case '/':
			case '*': 
				return 3;
			case '^':
				return 4;
			case ')' :
				return 5;
			default: 
				return 0;  
		}
	}
}
public class Stack {
	public static void main(String[] args) {
		PostFix obj = new PostFix();
		Scanner in =  new Scanner(System.in);
		System.out.println("Enter a Infix Notation : ");
		String infix = in.nextLine();
		String post = obj.getPostfix(infix);
		System.out.println("Postfix : " + post);
	}
}
