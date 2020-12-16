#include <iostream>
#include "C:\GITHUB\Letov_201_351\threematr\threematr.h"

using std::cin;
using std::cout;

int main()
{
	double arr[7] = { 1,2,3,4,5,6,7 };
	threematr MatA;
	MatA.input(3,arr);
	threematr MatB(MatA);

	cout << "MatA = \n" << MatA
		<< "MatB = \n" << MatB
		<< "-MatB = \n" << -MatB
		<< "MatA + MatB = \n" << MatA + MatB
		<< "MatA - MatB = \n" << MatA - MatB
		<< "MatA * MatB = \n" << MatA * MatB
		<< "MatA * 3 = \n" << MatA * 3
		<< "3 * MatA = \n" << 3 * MatA;
}