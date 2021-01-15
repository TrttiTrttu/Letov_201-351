#include <iostream>
#include <queue>

using std::queue;
using std::cin;
using std::cout;

int min(int num1, int num2) //���-��� ��� ���������� ��������
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

void PaD(int tmp, queue<int>& q2, queue<int>& q3, queue<int>& q5) { // �������� ����� ����� 1 � ����� ��� � �����-�� �������
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
	PaD(1, que2, que3, que5); // ����� �������������� 2 3 � 5
	int counter = 0;
	while (counter != num) {
		int x = min(min(que2.front(), que3.front()), que5.front()); //���������� ������������
		PaD(x, que2, que3, que5);
		counter++;
		if (x == que2.front()) // ������� ��������� �������
			que2.pop();
		if (x == que3.front())
			que3.pop();
		if (x == que5.front())
			que5.pop();
	}
}
