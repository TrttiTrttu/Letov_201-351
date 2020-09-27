#include <iostream>

using std::cin;
using std::cout;
int main() {
	int x1;
	int x2;
	cout<< "Введите координаты отрезка на прямой: ";
	cin >> x1 >> x2;
	cout << "Середина отрезка находится в точке с координатой: " << (x1 + x2) / 2.0;
}
