#pragma once
#include <string>

using std::string;

class group
{
private:
	int number;
	string surname;
public:
	group();
	group(int a, string b);
	~group();

	int get_number();
	string get_surname();

	friend bool operator<(const group& left, const group& right);
};

