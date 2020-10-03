#include <iostream>
#include <limits>
#include <bitset>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::endl;

int main() {
	//task1
	cout << "Letov Grigrii Vasil`evich" << "\t201-351\n\n";


	//task2
	cout << "min int = " << numeric_limits<int>::min() << ", max int = " << numeric_limits<int>::max() << ", size of int = " << sizeof(int) << endl;
	cout << "min unsigned int = " << numeric_limits<unsigned>::min() << ", max unsigned int = " << numeric_limits<unsigned>::max() << ", size of unsigned int = " << sizeof(unsigned int) << endl;
	cout << "min short  = " << numeric_limits<short>::min() << ", max short = " << numeric_limits<short>::max() << ", size of short = " << sizeof(short) << endl;
	cout << "min unsigned short  = " << numeric_limits<unsigned short>::min() << ", max unsigned short = " << numeric_limits<unsigned short>::max() << ", size of unsigned short = " << sizeof(unsigned short) << endl;
	cout << "min long  = " << numeric_limits<long>::min() << ", max long = " << numeric_limits<long>::max() << ", size of long = " << sizeof(long) << endl;
	cout << "min long long  = " << numeric_limits<long long>::min() << ", max long long = " << numeric_limits<long long>::max() << ", size of long long= " << sizeof(long long) << endl;
	cout << "min double  = " << numeric_limits<double>::min() << ", max double = " << numeric_limits<double>::max() << ", size of double = " << sizeof(double) << endl;
	cout << "min char  = " << numeric_limits<char>::min() << ", max char = " << numeric_limits<char>::max() << ", size of char = " << sizeof(char) << endl;
	cout << "min boolean  = " << numeric_limits<bool>::min() << ", max bool = " << numeric_limits<bool>::max() << ", size of bool = " << sizeof(bool) << endl;


	//task3
	int num;
	cout << "\nEnter number: ";
	cin >> num;
	cout << num << endl;
	cout << "Binary: " << std::bitset<16>(num) << endl;
	cout << "Hex: " << std::hex << num << endl;
	cout << "Boolean: " << bool(num) << endl;
	cout << "Char: " << char(num) << endl;


	//task4
	double a;
	int b;
	cout << "\nEnter a and b a * x = b: ";
	cin >> a >> b;
	cout << a << " * x " << "= " << b << endl;
	if (b == 0) {
		cout << "x = 0";
	}
	else {
		cout << "x = " << a << "/" << b << "\nx = " << a / b << endl;
	}


	//task5
	int x1;
	int x2;
	cout << "\nEnter the coordinates: ";
	cin >> x1 >> x2;
	cout << "Coordinates of midpoint: " << (x1 + x2) / 2.0;
	return 0;
}
