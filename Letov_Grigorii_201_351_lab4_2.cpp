#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::fstream;
using std::ifstream;
using std::ofstream;

string file_format(const string file_path_full)
{
	string rtrn;
	rtrn.assign(file_path_full, file_path_full.rfind('.') + 1, file_path_full.length());
	if (file_path_full.rfind('.') != -1)
		return rtrn;
	else
		return "-1";
}

string file_name(const string file_path_full)
{
	string rtrn;
	rtrn.assign(file_path_full, file_path_full.rfind('/') + 1, (file_path_full.rfind('.') - file_path_full.rfind('/') - 1));
	return rtrn;
}

string file_path(const string file_path_full)
{
	string rtrn;
	rtrn.assign(file_path_full, 0, file_path_full.rfind('/'));
	return rtrn;
}

char file_disk(const string file_path_full)
{
	const char* rtrn = { file_path_full.c_str() };
	return rtrn[0];
}

bool file_rename(string* file_path_full)
{
	string buf = *file_path_full;
	string new_name;
	cout << "Enter new name : ";
	getline(cin, new_name);
	if (file_format(*file_path_full) != "-1")
	{
		buf.replace(buf.find(file_name(*file_path_full)), file_name(*file_path_full).length(), new_name);
		*file_path_full = buf;
		return true;
	}
	else
	{
		cout << "no name" << '\n';
		return false;
	}
}


bool file_copy(string file_path_full)
{
	ifstream original(file_path_full, ifstream::in);// C:\\GITHUB\\desktop\\Letov_201-351\\files\\original.txt
		if (original.is_open()) 
		{
			ofstream copy;
			copy.open(file_path_full.replace(file_path_full.find('.'), 4 ,"_copy." + file_format(file_path_full)), ofstream::out | ofstream::app);
			string buf;
			getline(original, buf);
			copy << buf;
			copy.close();
			return true;
		}
		else
		{
			cout << "no file" << '\n';
			return false;
		}
}

int main()
{
	SetConsoleCP(1251); // функции из Windows.h 
	SetConsoleOutputCP(1251); // для локализации ввода\вывода консоли
	string file;
	string* pfile = &file;
	int choice = 0;
	while (true)
	{
		cout << "choose your task:\n"
			"1. file_format\n"
			"2. file_name\n"
			"3. file_path\n"
			"4. file_disk\n"
			"5. file_rename\n"
			"6. file_copy\n"
			"7. exit\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << file_format(file) << '\n';
			break;
		}
		case 2:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << file_name(file) << '\n';
			break;
		}
		case 3:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << file_path(file) << '\n';
			break;
		}
		case 4:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << file_disk(file) << '\n';
			break;
		}
		case 5:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << (file_rename(pfile) ? file : "error") << '\n';
			break;
		}
		case 6:
		{
			cout << "enter file_path_full: ";
			getline(cin, file);
			cout << file_copy(file) << '\n';
			break;
		}
		case 7:
		{
			cout << "exit...";
			return 0;
		}
		default:
		{
			cout << "try again" << '/n';
			break;
		}
		}
	}
}