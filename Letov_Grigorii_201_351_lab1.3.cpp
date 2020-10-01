#include <iostream>
#include <bitset>
using std::cin;
using std::cout;

int main() {	
	int num;
	cout << "Enter number: ";
	cin >> num;
	cout << num << std::endl;
	cout << "Binary: " << std::bitset<16>(num) << std::endl;
	cout << "Hex: " << std::hex << num << std::endl;
	cout << "Boolean: " << bool(num) << std::endl;
	cout << "Char: " << char(num);
	return 0;
}
