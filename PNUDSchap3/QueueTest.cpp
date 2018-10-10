#pragma warning(disable : 4996)

#include "Queue.h"
#include <assert.h>

void test1() {
	Queue<int> s(3);
	s.Push(2);
	s.Push(4);//2, 4
	s.Pop();//4
	assert(s.Front() == 4);
	s.Push(2);//4, 2
	s.Push(1);
	s.Push(4);
	s.Push(10);
	s.Push(18);//4, 2, 1, 4, 10, 18

	s.Pop();
	assert(s.Front() == 2);//2, 1, 4, 10, 18
	s.Pop();
	s.Pop();
	s.Pop(); //
	assert(s.Front() == 10);//10, 18
	s.Pop();
	s.Pop();
	assert(s.IsEmpty() == true);
}

void test2() {
	Queue<int> s(3);
	s.Push(2);
	s.Push(1);
	s.Push(4);
	s.Push(10);
	s.Push(18);
	if (s.IsEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}

	int arr[] = {2, 1, 4, 10, 18};
	int index = 0;
	while (!s.IsEmpty()) {
		assert(arr[index++] == s.Front());
		cout << s.Front() << endl;
		s.Pop();
	}
}

void main()
{
	test1();
	test2();
	system("pause");
}

