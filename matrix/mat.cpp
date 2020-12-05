
#include "mat.h"

using std::cin;
using std::cout;

matrix::matrix()
{
	columns = 0;
	rows = 0;
	elem = nullptr;
}


matrix::matrix(int i, int j)
{
	rows = i;
	columns = j;
	elem = new double[i * j]{ 0 };
}


matrix::matrix(int i, int j, const double* arr)
{
	rows = i;
	columns = j;
	elem = new double[i * j]{ 0 };
	for (int k = 0; k < i * j; k++)
		elem[k] = arr[k];
}


matrix::~matrix()
{
	if (elem != nullptr)
		delete[] elem;
}


/*void matrix::input()
{
	cout << "Rows:  ";
	cin >> rows;
	cout << "Columns:  ";
	cin >> columns;
	if (this->elem != nullptr)
		delete[] this->elem;
	this -> elem = new double[this->columns * this->rows]{ 0 };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cin >> elem[i * columns + j]; //= rand() % 10
	}
}

void matrix::input(int i, int j)
{
	if (this->elem != nullptr)
		delete[] this->elem;
	this ->elem = new double[i*j]{ 0 };
	cout << " enter matrix: \n";
	for (int k = 0; k < i*j; k++)
			cin >> elem[k]; //= rand() % 10
}

void matrix::input(int i, int j, const double* arr)
{
	if (this -> elem != nullptr)
		delete[] this -> elem;
	this->elem = new double[i * j]{ 0 };
	for (int k = 0; k < i * j; k++)
		this ->elem[k] = arr[k];
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


void matrix::copy(const matrix* mat2)
{
	this->columns = mat2->columns;
	this->rows = mat2->rows;
	if (elem != nullptr)
		delete[] elem;
	this->elem = new double[this->columns * this->rows]{ 0 };
	for (int i = 0; i < columns * rows; i++)
		this->elem[i] = mat2->elem[i];
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


void matrix::mult_by_num(double num)
{
	for (int i = 0; i < rows*columns; i++)
		this->elem[i] *= num;
}


bool matrix::mult(const matrix* mat2)
{
	if (this->columns == mat2->rows)
	{
		matrix MatrBuf;
		MatrBuf.copy(this);

		delete[] this->elem;
		this->columns = mat2->columns;
		this->elem = new double[this->columns * this->rows]{ 0 };

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

bool matrix::mult(const double* arr, int loc_rows, int loc_cols)
{
	if (this->columns != loc_rows)
	{
		cout << "error\n";
		return false;
	}
	matrix MatrBuf(this->rows,this->columns,this->elem);

	delete[] this->elem;
	this->columns = loc_cols;
	this->elem = new double[this->columns * this->rows]{ 0 };

	for (int i = 0; i < this ->rows; i++)
		for (int j = 0; j < this -> columns; j++)
			for (int k = 0; k < MatrBuf.columns; k++)
				this->elem[i * columns + j] += MatrBuf.get_elem(i, k) * arr[k * loc_cols + j];
	return true;
}


bool matrix::msum(const matrix* mat2)
{
	if (columns != mat2->columns || rows != mat2->rows)
		return false;
	for (int i = 0; i < columns * rows; i++)
		this->elem[i] += mat2->elem[i];
	return true;
}

bool matrix::msum(const double* arr,int loc_rows, int loc_cols)
{
	if (this->rows != rows && this->columns != loc_cols)
		return false;
	for (int i = 0; i < this -> columns * this -> rows; i++)
		this->elem[i] += arr[i];
	return true;
}


double matrix::trace()
{
	if (columns == rows)
	{
		double s = 0.0;
		for (int i = 0; i < rows; i++)
			s += this->get_elem(i, i);
		return s;
	}
	else
	{
		cout << " error \n";
		return -123;
	}

}


double matrix::det()
{
	if (this->get_columns() == this->get_rows()) {
		matrix MatrBuf;
		MatrBuf.copy(this);

		for (int cols = 0; cols < MatrBuf.get_columns() - 1;cols++)
		{

			for (int i = 1; i < MatrBuf.get_rows(); i++)
			{
				if (MatrBuf.get_elem(0, 0) == 0)
				{
					if (MatrBuf.get_elem(i, 0) != 0)
					{
						for (int k = 0; k < MatrBuf.get_columns(); k++)
							MatrBuf.elem[k] -= MatrBuf.elem[i * columns + k];
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
				cout << MatrBuf;
			}
		}

		double det = 1;

		for (int i = 0; i < MatrBuf.get_columns(); i++)
			det *= MatrBuf.get_elem(i, i);

		return det;
	}
	else
	{
		cout << "error: columns != rows\n";
		return -123;
	}
}



std::ostream& operator<<(std::ostream& out, const matrix& right)
{
	out << "Rows = " << right.rows << ' ' << "Columns = " << right.columns << '\n';
	for (int rows = 0; rows < right.rows; rows++ )
	{
		for (int columns = 0; columns < right.columns; columns++)
		{
			out << right.elem[rows * right.rows + columns] << '\t';
		}
		out << '\n';
	}
	return out;
}

//const matrix& operator+(const matrix& left, const matrix& right)
//{
//	matrix result;
//	result.rows = left.rows;
//	result.columns = left.columns;
//	result.elem = new double[result.rows * result.columns];
//	for (int rows = 0; rows < right.rows; rows++)
//	{
//		for (int columns = 0; columns < right.columns; columns++)
//		{
//			result.elem[rows * result.rows + columns] = ;
//		}
//	}
//	return out;
//}
