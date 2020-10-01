#include "iostream"
#include "string"
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void task1() {
	int n;
	cout << "���������� 1-�� �������:\n������� n: ";
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << j;
		}
		cout << "\n";
	}
}

int factorial(int num) {
	if (num == 0) return 1;
	else {
		return num * factorial(num - 1);
	}
}

void task2() {
	int  n;
	cout << "���������� 2-�� �������:\n������� n: ";
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << factorial(n) / (factorial(n - i)*factorial(i)) << " ";
	}
	cout << "\n";
}

void task3() {
	getchar();
	string S;
	cout << "���������� 3-�� �������:\n������� ����-�� �����(��������� ����� ������ ������):\n";
	double sum = 0;
	int counter = 0;
	int buf;
	while (true) {
		getline(cin, S);
		if (S.empty()) {
			break;
		}
		else {
			buf = atoi(S.c_str());
			sum += buf;
			counter++;
		}
	}
	cout << sum << " " << counter << endl;
	cout << "������� �������������� = " << sum / counter << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice;
	bool flag = true;
	while (flag) {
		cout << "\n���� �������:\n1 - \"���������\"\n2 - ����� ����-��\n3 - ����. �����-��\n4 - �����" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			flag = false;
			break;
		}
	}
	cout << "������� ����� ������� ��� ������\n";
}