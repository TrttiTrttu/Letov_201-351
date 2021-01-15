#include <iostream>
#include <queue>

using std::queue;
using std::cin;
using std::cout;

int min(int num1, int num2) //фун-ция для нахождения минимума
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

void PaD(int tmp, queue<int>& q2, queue<int>& q3, queue<int>& q5) { // печатает число кроме 1 и пушит его в соотв-ие очереди
	if (tmp != 1) {
		cout << tmp << ' ';
	}
	q2.push(tmp * 2);
	q3.push(tmp * 3);
	q5.push(tmp * 5);
}

int main()
{
	cout << "Input number:\n";
	int num;
	cin >> num;
	queue<int> que2, que3, que5;
	PaD(1, que2, que3, que5); // пушим первоначальные 2 3 и 5
	int counter = 0;
	while (counter != num) {
		int x = min(min(que2.front(), que3.front()), que5.front()); //нахождение минимального
		PaD(x, que2, que3, que5);
		counter++;
		if (x == que2.front()) // удаляем найденный минимум
			que2.pop();
		if (x == que3.front())
			que3.pop();
		if (x == que5.front())
			que5.pop();
	}
}
