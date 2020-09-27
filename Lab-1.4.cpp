#include <iostream>

using std::cout;
using std::cin;

int main() {
	double a;
	int b;
	cout << "Введите коэффициенты a * x = b: " ;
	cin >> a >> b;
	cout << a << " * x "<< "= " << b << std::endl;
	if (b == 0) {
		cout << "x = 0";
	}
	else {
		cout << "x = " << a << "/" << b << "\nx = " << a/b;
	}
	return  0;
}

