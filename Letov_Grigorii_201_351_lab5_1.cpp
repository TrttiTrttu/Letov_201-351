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
	MatrB.input();
	MatrB.print();
	MatrA.msum(&MatrB);
	MatrA.print();
	return 0;
}