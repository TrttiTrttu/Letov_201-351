#include <iostream>
#include "C:\GITHUB\Letov_201_351\threematr\threematr.h"

using std::cin;
using std::cout;

int main()
{
	double arr[7] = { 1,2,3,4,5,6,7 };
	threematr MatA;
	MatA.input(3,arr);
	threematr MatB(3,arr);
	cout << MatA;
	cout << MatB;
	cout << "-MatB = " << -MatB;
	cout << "MatA + MatB = \n" << MatA + MatB;
	cout << "MatA - MatB = \n" << MatA - MatB;
	cout << "MatA * MatB = \n" << MatA * MatB;
}