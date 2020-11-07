#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

string file_name(const string file_path_full)
{
	string rtrn;
	rtrn.assign(file_path_full, file_path_full.rfind('/') + 1, (file_path_full.rfind('.') - file_path_full.rfind('/') - 1));
	return rtrn;
}

int main()
{
	SetConsoleCP(1251); // ������� �� Windows.h 
	SetConsoleOutputCP(1251); // ��� ����������� �����\������ �������
	string file;
	getline(cin, file);
	cout << file_name(file);
}