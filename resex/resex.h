#pragma once
#include <iostream>

class resex
{
private:
	int results;
	int id;
public:
	resex();
	resex(int a, int b);
	~resex();

	int get_id();
	int get_results();

	friend bool operator<(const resex& left, const resex& right);
};

