#include <iostream>
#include <set>
#include <C:\GITHUB\Letov_201_351\resex\resex.h>

using std::set;
using std::cin;
using std::cout;

void show_results(set<resex>& temp)
{
	for (auto i = temp.begin(); i != temp.end(); i++)
	{
		resex buf = *i;
		cout << buf.get_id() << ' ' << buf.get_results() << '\n';
	}
}

bool check(set<resex>& temp, resex stdnt)
{
	for (auto i = temp.begin(); i != temp.end(); i++)
	{
		resex buf = *i;
		if (buf.get_id() == stdnt.get_id())
			return false;
	}
	return true;
}

void add(set<resex>& temp)
{
	int id = 0;
	int res = 0;
	cout << "enter your id: ";
	cin >> id;
	cout << "enter your results: ";
	cin >> res;
	if (check(temp, resex(id, res)))
		temp.insert(resex(id, res));
	else
		cout << "error\n";
}

int main()
{
	set<resex> s;

	for (int i = 0; i < 3; i++)
		add(s);
	int choice;
	while (true)
	{
		cout << "1. show_results\n"
			<< "2. add\n" 
			<< "3. exit\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			show_results(s);
			break;
		}
		case 2:
		{
			add(s);
			break;
		}
		case 3:
		{
			return 0;
		}
		default:
		{
			cout << "try again";
		}
		}
	}
	
}