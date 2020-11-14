#include <iostream>
#include "C:\GITHUB\Letov_201_351\matrix\matrix.h"

using std::cin;
using std::cout;

int main()
{
	matrix MatrA;
	MatrA.input();
	MatrA.print();
	cout << MatrA.get_elem(0,1);
	return 0;
}