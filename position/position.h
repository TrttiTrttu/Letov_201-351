#pragma once
#include <iostream>

class position
{
protected:
	int x;
	int y;
public:
	position();
	position(int loc_x, int loc_y);
	~position();

	void set_coords(int loc_x, int loc_y);
	int get_x();
	int get_y();

	friend std::istream& operator>>(std::istream& in, position& tmp);
	friend std::ostream& operator<<(std::ostream& out, const position& tmp);
};

