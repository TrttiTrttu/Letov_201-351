#include <iostream>
#include <ctime>
#include "mat.h"

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
	cout << "Rows:  ";
	cin >> rows;
	cout << "Columns:  ";
	cin >> columns;
	elem = new double[double(this->columns) * this->rows]{ 0 };
	srand(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			elem[i * columns + j] = rand() % 10
;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << elem[i * columns + j] << '\t';
		cout << "\n";
	}
	cout << "\n";
}

int matrix::get_columns()
{
	return columns;
}

int matrix::get_rows()
{
	return rows;
}

void matrix::mult_by_num(double num)
{
	for (int i = 0; i < rows*columns; i++)
		this->elem[i] *= num;
}

double matrix::trace()
{
	double s = 0.0;
	for (int i = 0; i < rows; i++)
		s += this->get_elem(i, i);
	return s;
}

bool matrix::msum(const matrix* mat2)
{
	if (columns != mat2->columns || rows != mat2->rows)
		return false;
	for (int i = 0; i < columns * rows; i++)
		this->elem[i] += mat2->elem[i];
	return true;
}


double matrix::get_elem(int i, int j)
{
	return elem[i * columns + j];
}


void matrix::copy(const matrix* mat2)
{
	this->columns = mat2->columns;
	this->rows = mat2->rows;
	this->elem = new double[double(this->columns) * this->rows]{ 0 };
	for (int i = 0; i < columns * rows; i++)
		this->elem[i] = mat2->elem[i];
}

void matrix::mult(const matrix* mat2)
{
	if (this->columns == mat2->rows)
	{
		matrix MatrBuf;
		MatrBuf.copy(this);

		delete[] elem;
		this->columns = mat2->columns;
		this->elem = new double[double(this->columns) * this->rows]{ 0 };

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				for (int k = 0; k < MatrBuf.columns; k++)
					this->elem[i * columns + j] += MatrBuf.get_elem(i, k) * mat2->elem[k * mat2->columns + j];
	}
	else
		cout << "error \n";
}

