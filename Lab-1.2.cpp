#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;

int main() {
	int x;
	x = 1;
	cout << "min int = " << numeric_limits<int>::min() << ", max int = " << numeric_limits<int>::max() << ", size of int = " << sizeof(x) << std::endl;
	cout << "min unsigned int = " << numeric_limits<unsigned>::min() << ", max unsigned int = " << numeric_limits<unsigned>::max() << ", size of unsigned int = " << sizeof(unsigned(x)) << std::endl;
	cout << "min short  = " << numeric_limits<short>::min() << ", max short = " << numeric_limits<short>::max() << ", size of short = " << sizeof(short(x)) << std::endl;
	cout << "min unsigned short  = " << numeric_limits<unsigned short>::min() << ", max unsigned short = " << numeric_limits<unsigned short>::max() << ", size of unsigned short = " << sizeof(unsigned short(x)) << std::endl;
	cout << "min long  = " << numeric_limits<long>::min() << ", max long = " << numeric_limits<long>::max() << ", size of long = " << sizeof(long(x)) << std::endl;
	cout << "min long long  = " << numeric_limits<long long>::min() << ", max long long = " << numeric_limits<long long>::max() << ", size of long long= " << sizeof(long long(x)) << std::endl;
	cout << "min double  = " << numeric_limits<double>::min() << ", max double = " << numeric_limits<double>::max() << ", size of double = " << sizeof(double(x)) << std::endl;
	cout << "min char  = " << numeric_limits<char>::min() << ", max char = " << numeric_limits<char>::max() << ", size of char = " << sizeof(char(x)) << std::endl;
	cout << "min boolean  = " << numeric_limits<bool>::min() << ", max bool = " << numeric_limits<bool>::max() << ", size of bool = " << sizeof(bool(x)) << std::endl;
}