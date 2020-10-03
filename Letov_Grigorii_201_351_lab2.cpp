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
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << factorial(n) / (factorial(n - i)*factorial(i)) << " ";
	}
	cout << "\n";
}

void task3() {
	getchar();
	string S;
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
	cout << "arithmetic mean = " << sum / counter << endl;
}

int main() {
	int choice;
	bool flag = true;
	while (flag) {
		cout << "\nChoose your task:\n1 - \"pyramid\"\n2 - binomial coefficients\n3 - arithmetic mean\n4 - exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Task 1:\nenter number: ";
			task1();
			break;
		case 2:
			cout << "Task 2:\nenter numbers: ";
			task2();
			break;
		case 3:
			cout << "Task 3:\nenter numbers(end of input - empty string)\n";
			task3();
			break;
		case 4:
			flag = false;
			break;
		}
	}
	cout << "press any button\n";
}