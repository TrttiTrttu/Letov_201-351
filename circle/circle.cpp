#include "circle.h"

circle::circle() : position()
{
	x = 0;
	y = 0;
	radius = 0;
}

circle::circle(int loc_x, int loc_y, int loc_rds)
{
	x = loc_x;
	y = loc_y;
	radius = loc_rds;
}

int circle::get_radius()
{
	return radius;
}

void circle::set_radius(int loc_rds)
{
	radius = loc_rds;
}

std::istream& operator>>(std::istream& in, circle& tmp)
{
	cout << "Enter x, y, radius: ";
	in >> tmp.x >> tmp.y >> tmp.radius;
	return in;
}

std::ostream& operator<<(std::ostream& out, const circle& tmp)
{
	out << "x = " << tmp.x << " y = " << tmp.y << " radius = " << tmp.radius << '\n';
	return out;
}
