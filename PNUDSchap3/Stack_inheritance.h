#pragma once

#include "Bag_inheritance.h"

class Stack : public Bag
{
public:
	Stack(int stackCapacity = 10);
	~Stack();
	int Top() const;
	void Pop();
	//stack에 Push()는 no duplicate를 구현, 단 Bag::Push()를 재사용한 코딩 구현
};

Stack::Stack(int stackCapacity) : Bag(stackCapacity) {}

Stack::~Stack() {}

int Stack::Top() const
{
	if (IsEmpty()) throw "Stacak is empty";
	return array[top];
}

void Stack::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	top--;
}
