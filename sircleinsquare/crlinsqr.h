#pragma once
#include "C:\GITHUB\Letov_201_351\circle\circle.h"
#include "C:\GITHUB\Letov_201_351\square\square.h"

using std::cin;
using std::cout;

class crlinsqr :
	public circle, public square
{
public:
	crlinsqr();
	crlinsqr(int loc_x, int loc_y, int loc_radius, int loc_lng);

	friend std::istream& operator>>(std::istream& in, crlinsqr& tmp);
	friend std::ostream& operator<<(std::ostream& out, const crlinsqr& tmp);
};

