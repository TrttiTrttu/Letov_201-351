#include "iostream"
#include "string"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void task1() {
	int n;
	cout << "Выполнение 1-го задания:\nВведите n: ";
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
	int n;
	cout << "Выполнение 2-го задания:\nВведите n: ";
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << factorial(n) / (factorial(n - i)*factorial(i)) << " ";
	}
	cout << "\n";
}

void task3() {
	getchar();
	string something;
	bool more = true;
	cout << "Выполнение 3-го задания:\nВведите коор-ды точек(окончание ввода пустая строка):\n";
	double sum = 0;
	int counter = 0;
	while (more) {
		getline(cin, something);
		if (something.empty()) {
			break;
		}
		else {
			sum += int(something[0]) - 48;
			counter++;
		}
	}
	cout << "Среднее арифметическое = " << sum / counter << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice;
	bool flag = true;
	while (flag) {
		cout << "\nменю заданий:\n1 - \"пирамидка\"\n2 - бином коэф-фы\n3 - сред. арифм-ое\n4 - выход" << endl;
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
	cout << "нажмите любую клавишу для выхода\n";
}