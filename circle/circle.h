#pragma once
#include "C:\GITHUB\Letov_201_351\position\position.h"

using std::cout;
using std::cin;

class circle :
	virtual public position
{
protected:
	int radius;
public:
	circle();
	circle(int loc_x, int loc_y, int loc_rds);
	~circle();

	int get_radius();
	void set_radius(int loc_rds);

	friend std::istream& operator>>(std::istream& in, circle& tmp);
	friend std::ostream& operator<<(std::ostream& out, const circle &tmp);
};

