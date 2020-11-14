#include "matrix.h"
#include <iostream>
#include <ctime>

using std::cin;
using std::cout;

matrix::matrix()
{
	columns = 0;
	rows = 0;
	elem = nullptr;
}

matrix::~matrix()
{
	if (elem != nullptr)
		delete[] elem;
}

void matrix::input()
{
	cout << "Columns:  " << '\n';
	cin >> columns;
	cout << "Rows:  " << '\n';
	cin >> rows;
	elem = new double[columns * rows];
	srand(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			elem[i * columns + j] = rand() % 21;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << elem[i * columns + j] << '\t';
		cout << '\n';
	}
}

int matrix::get_columns()
{
	return columns;
}

int matrix::get_rows()
{
	return rows;
}

double matrix::get_elem(int i, int j)
{
	return elem[i * columns + j];
}


