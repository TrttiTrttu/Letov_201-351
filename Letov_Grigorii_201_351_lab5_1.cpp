#include <iostream>
#include "C:\GITHUB\Letov_201_351\matrix\mat.h"

using std::cin;
using std::cout;

int main()
{
	matrix MatrA;
	matrix MatrB;
	MatrA.input();
	MatrA.print();
	cout << MatrA.det();
	return 0;
}