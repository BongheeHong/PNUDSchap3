#include "Stack_PostfixNotation.h"


class Postfix {
private:
	char * expression;
	int index = 0;
public:
	Postfix(char * expression) : expression(expression) {}

	void getPostfix()
	{
		Stack<char> stack;
		stack.Push('#');
		for (char x = NextToken(expression); x != NULL; x = NextToken(expression))
		{
			if (isOperand(x))
				cout << x;
			else if (x == ')')
			{
				while (stack.Top() != '(')
				{
					cout << stack.Top();
					stack.Pop();
				}
				if (!stack.IsEmpty()) stack.Pop();
			}
			else
			{
				for (; !stack.IsEmpty() && isp(stack.Top()) >= icp(x); stack.Pop())
					cout << stack.Top();
				stack.Push(x);
			}
		}

		char x;
		while ((x = stack.Top()) != '#')
		{
			cout << x;
			stack.Pop();
		}
		cout << endl;
	}

	char NextToken(char* e)
	{
		char token = e[index];
		index++;
		return token;
	}

	bool isOperand(char x)
	{
		if (x == '+' || x == '-' || x == '*' || x == '/' ||
			x == '(' || x == ')' || x == '%' || x == '#')
			return false;
		else
			return true;
	}

	int isp(char a)
	{
		if (a == '(')
			return 0;
		else if (a == ')')
			return 19;
		else if (a == '+' || a == '-')
			return 12;
		else if (a == '*' || a == '%' || a == '/')
			return 13;
		else
			return 0;
	}

	int icp(char a)
	{
		if (a == '(')
			return 20;
		else if (a == ')')
			return 19;
		else if (a == '+' || a == '-')
			return 12;
		else if (a == '*' || a == '%' || a == '/')
			return 13;
		else
			return 0;
	}
};




/*
void Eval(Expression e)
Stack<Token> stack;
for (Token x = NextToken(e); x != '#"; x = NextToken(e))
if (x is operand) stack.Push(x);
else {
//remove the correct number of operands for operator x from stack;
//perform the operation x and store the result onto the stack;
}
}
*/


void stackTest1() {
	Stack<int> s(2);
	s.Push(3);
	s.Push(2);
	s.Push(1);
	assert(s.Top() == 1);//3 2 1
	s.Pop();//3 2
	assert(s.Top() == 2);
	assert(s.IsEmpty() != true);
	s.Pop();
	s.Pop();
	assert(s.IsEmpty() == true);
	s.Push(4);
	s.Push(6);
	assert(s.Top() == 6);
	s.Pop();
	assert(s.Top() == 4);
}


void main()
{
	stackTest1();

	Postfix p1("2+3*4+9#");
	p1.getPostfix();

	//165페이지, Exercises 1의 (a) ~ (f)에 대하여 동작하게 debugging
	Postfix p2("A/B-C+D*E-A*C#");
	p2.getPostfix();

	Postfix p3("4*7+3-1#");
	p3.getPostfix();

	//Eval("2*4 + 5*7");
	int end;
	cin >> end;
}