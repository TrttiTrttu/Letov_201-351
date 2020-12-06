#include "position.h"
#include <iostream>

using std::cin;
using std::cout;

position::position()
{
	x = 0;
	y = 0;
}

position::position(int loc_x, int loc_y)
{
	x = loc_x;
	y = loc_y;
}

position::~position()
{
}

void position::set_coords(int loc_x, int loc_y)
{
	x = loc_x;
	y = loc_y;
}

int position::get_x()
{
	return x;
}

int position::get_y()
{
	return y;
}

std::istream& operator>>(std::istream& in, position& tmp)
{
	cout << "Enter x, y: ";
	in >> tmp.x >> tmp.y;
	return in;
}

std::ostream& operator<<(std::ostream& out, const position& tmp)
{
	out << "x = " << tmp.x << " y = " << tmp.y << '\n';
	return out;
}
