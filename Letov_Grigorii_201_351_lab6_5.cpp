#include <iostream>
#include <list>
#include <C:\GITHUB\Letov_201_351\groups\group.h>

using std::list;
using std::cin;
using std::cout;

bool compare(group left, group right)
{
	return left < right;
}

void lists(list<group>& temp)
{
	for (auto i = temp.begin(); i != temp.end(); i++)
	{
		group buf = *i;
		cout << buf.get_number() << ' ' << buf.get_surname() << '\n';
	}
}

void add(list<group>& temp)
{
	int nmbr = 0;
	string srnm = " ";
	cout << "enter number: ";
	cin >> nmbr;
	cout << "enter surname: ";
	cin >> srnm;
	temp.push_back(group (nmbr, srnm));
}

int main()
{
	list<group> l;

	for (int i = 0; i < 3; i++)
		add(l);
	int choice;
	while (true)
	{
		cout << "1. show_results\n"
			<< "2. add\n"
			<< "3. sort\n"
			<< "4. exit\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			lists(l);
			break;
		}
		case 2:
		{
			add(l);
			break;
		}
		case 3:
		{
			l.sort(compare);
			break;
		}
		case 4:
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
