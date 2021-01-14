#include "resex.h"

resex::resex()
{
	results = 0;
	id = 0;
}

resex::resex(int a, int b)
{
	id = a;
	results = b;
}

resex::~resex()
{
}

int resex::get_id()
{
	return id;
}

int resex::get_results()
{
	return results;
}

bool operator<(const resex& left, const resex& right)
{
	return left.id < right.id;
}
