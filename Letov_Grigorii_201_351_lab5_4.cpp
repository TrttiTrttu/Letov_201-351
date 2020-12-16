#include <iostream>
#include "C:\GITHUB\Letov_201_351\position\position.h"
#include "C:\GITHUB\Letov_201_351\circle\circle.h"
#include "C:\GITHUB\Letov_201_351\square\square.h"
#include "C:\GITHUB\Letov_201_351\sircleinsquare\crlinsqr.h"

using std::cin;
using std::cout;

int main()
{
	crlinsqr crlin(99, 99, 99, 99);
	cout << crlin;
	cin >> crlin;
	cout << crlin;
	crlin.set_coords(5, 5);
	crlin.set_radius(5);
	crlin.set_lngth(5);
	cout << crlin;
}