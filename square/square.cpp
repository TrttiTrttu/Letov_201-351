#include "square.h"

square::square() : position()
{
	side_length = 0;
}

square::square(int loc_x, int loc_y, int loc_lng) : position(loc_x, loc_y)
{
	side_length = loc_lng;
}

square::~square()
{
}

int square::get_lngth()
{
	return side_length;
}

void square::set_lngth(int loc_lng)
{
	side_length = loc_lng;
}

std::istream& operator>>(std::istream& in, square& tmp)
{
	cout << "Enter x, y, side_length: ";
	in >> tmp.x >> tmp.y >> tmp.side_length;
	return in;
}

std::ostream& operator<<(std::ostream& out, const square& tmp)
{
	out << "x = " << tmp.x << " y = " << tmp.y << " side_length = " << tmp.side_length << '\n';
	return out;
}
