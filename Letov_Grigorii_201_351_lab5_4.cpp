#include <iostream>
#include "C:\GITHUB\Letov_201_351\position\position.h"
#include "C:\GITHUB\Letov_201_351\circle\circle.h"
#include "C:\GITHUB\Letov_201_351\square\square.h"
#include "C:\GITHUB\Letov_201_351\sircleinsquare\crlinsqr.h"

using std::cin;
using std::cout;

int main()
{
	crlinsqr srclin(99, 99, 99, 99);
	cout << srclin;
	cin >> srclin;
	cout << srclin;
	srclin.set_coords(5, 5);
	srclin.set_radius(5);
	srclin.set_lngth(5);
	cout << srclin;
}