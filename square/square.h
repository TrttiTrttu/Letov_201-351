#pragma once
#include "C:\GITHUB\Letov_201_351\position\position.h"

using std::cin;
using std::cout;

class square :
	virtual public position
{
protected:
	int side_length;
public:
	square();
	square(int loc_x, int loc_y, int loc_lng);
	~square();

	int get_lngth();
	void set_lngth(int loc_lng);

	friend std::istream& operator>>(std::istream& in, square& tmp);
	friend std::ostream& operator<<(std::ostream& out, const square& tmp);
};

