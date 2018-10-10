#include "Stack.h"

int main() {

	Stack<int> s(4);
	//Stack<float> fo(10); 실수에 대하여도 구현
	//화면에서 입력받아 동작하도록 구현
	//stack이 full일 때 처리 기능을 구현
	s.Push(3);
	s.Push(6);
	s.Push(1);
	s.Push(2);
	s.Push(10);
	s.Push(17);

	cout << "is empty: ";
	if (s.IsEmpty()) {
		cout << "  yes" << endl;
	}
	else {
		cout << " no" << endl;
	}

	cout << "print all elements: " << endl;
	while (!s.IsEmpty()) {
		cout << s.Top() << "  ";
		s.Pop();
	}
	cout << endl;


	system("pause");

	return 0;
}
