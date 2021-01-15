#pragma once
#include <string>
#include <iostream>

using std::string;

class human
{
private:
	string surname;
	string name;
	int age;
public:
	human();
	human(string t_surname, string t_name, int t_age);
	~human();

	string get_surname();
	string get_name();
	int get_age();

	friend std::ostream& operator<<(std::ostream& out, const human& right);
};

