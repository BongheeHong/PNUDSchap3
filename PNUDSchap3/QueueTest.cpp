#include "Queue.h"

void main()
{
	Queue<int> s(3);
	s.Push(2);
	s.Push(1);
	s.Push(4);
	//s.Push(10); //구현시에 doubling 동작 가능한지 테스트
	if (s.IsEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}

	while (!s.IsEmpty()) {
		cout << s.Front() << endl;
		s.Pop();
	}
	//cout << s << endl;//가능하도록 필요한 함수를 추가 구현한다
	system("pause");
}

