#include "Bag.h"


int main() {
	Bag<int> b(4);
	//Bag<float> fo(10);에 대하여도 구현할 것
	//화면에서 임의 숫자를 입력받아 Push() 호출하도록 수정
	b.Push(3);
	b.Push(5);
	b.Push(1);
	b.Push(6);

	if (b.IsEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}

	cout << "display the element in the bag:" << endl;
	while (!b.IsEmpty()) {
		cout << b.Element() << endl;
		b.Pop();
	}

	system("pause");
	return 0;
}
