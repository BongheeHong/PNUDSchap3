#include "Stack_inheritance.h"

int main() {

	Stack b(4);
	b.Push(3);
	b.Push(5);
	b.Push(1);
	b.Push(6);
	b.Push(10);
	b.Push(19);

	if (b.IsEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}

	while (!b.IsEmpty()) {
		cout << b.Element() << endl;
		b.Pop();
	}
	//b.Pop();//실행시 오류 발생 - 소스코드 수정 필요
	system("pause");
	return 0;

}
