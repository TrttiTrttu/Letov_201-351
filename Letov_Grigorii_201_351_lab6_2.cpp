#include <deque>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::deque;

bool palindrom(string* str)
{
	deque<char> dq;
	for (int i = 0; i < str->length(); i++)
		if (str->at(i) != ' ')
			dq.push_back(tolower(str->at(i)));
	for (int i = 0, j = dq.size() - 1; i < j; i++, j--)
	{
		if (dq.front() != dq.back())
			return false;
		dq.pop_back();
		if (dq.size() != 1)
			dq.pop_front();
	}
	return true;
}

int main()
{
	string temp = {};
	cout << "enter string: ";
	getline(cin, temp);
	cout << palindrom(&temp);
}