#include "human.h"

human::human()
{
	surname = "blank";
	name = "blank";
	age = -1;
}

human::human(string t_surname, string t_name, int t_age)
{
	surname = t_surname;
	name = t_name;
	age = t_age;
}

human::~human()
{
}

string human::get_surname()
{
	return surname;
}

string human::get_name()
{
	return name;
}

int human::get_age()
{
	return age;
}

std::ostream& operator<<(std::ostream& out, const human& right)
{
	out << right.surname << " " << right.name << " " << right.age << '\n';
	return out;
}
