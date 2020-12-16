#include "crlinsqr.h"

crlinsqr::crlinsqr()
{
	x = 0;
	y = 0;
	radius = 0;
	side_length = 0;
}

crlinsqr::crlinsqr(int loc_x, int loc_y, int loc_rds, int loc_lng)
{
	x = loc_x;
	y = loc_y;
	radius = loc_rds;
	side_length = loc_lng;
}

crlinsqr::~crlinsqr()
{
}

std::istream& operator>>(std::istream& in, crlinsqr& tmp)
{
	cout << "Enter x, y, radius, side_length: ";
	in >> tmp.x >> tmp.y >> tmp.radius >> tmp.side_length;
	return in;
}

std::ostream& operator<<(std::ostream& out, const crlinsqr& tmp)
{
	out << "x = " << tmp.x << " y = " << tmp.y << " radius = " <<
		tmp.radius << " side_length = " << tmp.side_length <<'\n';
	return out;
}
