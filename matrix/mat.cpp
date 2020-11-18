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
	{
		for (int j = 0; j < columns; j++)
			cin >> elem[i * columns + j]; //= rand() % 10
		cout << '\n';
	}
}

void matrix::print()
{
	cout << "matrix = \n";
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

double matrix::det()
{
	matrix MatrBuf;
	MatrBuf.copy(this);
	int cols = 0;

	while (cols < MatrBuf.get_columns() - 1)
	{

		for (int i = 1; i < MatrBuf.get_rows(); i++)
		{
			if (MatrBuf.get_elem(0, 0) == 0)
			{
				if (MatrBuf.get_elem(i, 0) != 0)
				{
					for (int k = 0; k < MatrBuf.get_columns(); k++)
						MatrBuf.elem[k] -= MatrBuf.elem[i * columns + k];
					cout << "qwer ";
					MatrBuf.print();
				}
			}
			else
			{
				break;
			}
		}

		for (int rows = cols + 1; rows < MatrBuf.get_rows(); rows++)
		{
			if (MatrBuf.get_elem(rows, cols) != 0) {
				int counter = rows;
				while (MatrBuf.get_elem(counter, cols) == 0 && counter != MatrBuf.get_rows() - 1)
					counter++;
				double koef = MatrBuf.get_elem(counter, cols) / MatrBuf.get_elem(cols, cols);
				for (int i = 0; i < MatrBuf.get_columns(); i++)
				{
					MatrBuf.elem[rows * columns + i] -= koef * MatrBuf.get_elem(cols, i);
				}
			}
		}
		cols++;
	}

	double det = 1;

	for (int i = 0; i < MatrBuf.get_columns(); i++)
		det *= MatrBuf.get_elem(i, i);

	return det;
}

bool matrix::mult(const matrix* mat2)
{
	if (this->columns == mat2->rows)
	{
		matrix MatrBuf;
		MatrBuf.copy(this);

		delete[] this->elem;
		this->columns = mat2->columns;
		this->elem = new double[double(this->columns) * this->rows]{ 0 };

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				for (int k = 0; k < MatrBuf.columns; k++)
					this->elem[i * columns + j] += MatrBuf.get_elem(i, k) * mat2->elem[k * mat2->columns + j];
		return true;
	}
	else
	{
		cout << "error \n";
		return false;
	}
}

