#include "group.h"

group::group()
{
	number = 0;
	surname = "blank";
}

group::group(int a, string b)
{
	number = a;
	surname = b;
}

group::~group()
{
}

int group::get_number()
{
	return number;
}

string group::get_surname()
{
	return surname;
}

bool operator<(const group& left, const group& right)
{
	return left.number < right.number;
}
