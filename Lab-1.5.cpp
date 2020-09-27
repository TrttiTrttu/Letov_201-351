#include <iostream>

using std::cin;
using std::cout;
int main() {
	int x1;
	int x2;
	cout<< "Enter the coordinates: ";
	cin >> x1 >> x2;
	cout << "Coordinates of midpoint: " << (x1 + x2) / 2.0;
}
