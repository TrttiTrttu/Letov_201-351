#include <iostream>

using std::cout;
using std::cin;

int main() {
	double a;
	int b;
	cin >> a >> b;
	if (b == 0) {
		cout << "x = 0";
	}
	else {
		cout << "x = " << a << "/" << b << "\nx = " << a/b;
	}
	return  0;

}