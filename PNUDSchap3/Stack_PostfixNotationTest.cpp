#include "Stack_PostfixNotation.h"

int index = 0;

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

void Postfix(char* e)
{
	Stack<char> stack;
	stack.Push('#');
	for (char x = NextToken(e); x != NULL; x = NextToken(e))
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
			stack.Pop();
		}
		else
		{
			for (; isp(stack.Top()) >= icp(x); stack.Pop())
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

//void Eval (expression e);
void Eval(char* e){
	Stack<char> stack;
	for (char x = NextToken(e); x != '#'; x = NextToken(e)){
		if (x is operand) stack.Push(x);
		else {
			//remove the correct number of operands for operator x from stack;
			//perform the operation x and store the result onto the stack;
		}
	}
}

void main()
{
	Postfix("2+3*4+9");
	//165페이지, Exercises 1의 (a) ~ (f)에 대하여 동작하게 debugging
	Postfix("A/B-C+D*E-A*C");//bug 발생-debugging
	Eval("2*4 + 5*7");
	int end;
	cin >> end;
}

