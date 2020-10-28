#include <iostream>
#include <Windows.h>

using std::cout;

int main()
{
	SetConsoleCP(1251); // функции из Windows.h 
	SetConsoleOutputCP(1251);
	for (int i = 0; i <= 255; i++)
	{
		cout << i << '\t' << char(i) << '\n';
	}
	
}