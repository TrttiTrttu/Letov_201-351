#include "threematr.h"

using std::cin;
using std::cout;

threematr::threematr()
{
	size = 0;
	elem = nullptr;
}

threematr::threematr(int i)
{
	size = i;
	elem = new double[size * size]{ 0 };
}

threematr::threematr(int i, const double* arr)
{
	size = i;
	elem = new double[size * size]{ 0 };
	int arr_counter = 0;
	for (int i = 0; i < size - 1; i++,arr_counter++)
		elem[i * size + i + 1] = arr[arr_counter];
	for (int i = 0; i < size; i++, arr_counter++)
		elem[i * size + i] = arr[arr_counter];
	for (int i = 0; i < size-1; i++, arr_counter++)
		elem[(i + 1) * size + i] = arr[arr_counter];
}

threematr::threematr(const threematr& mat2)
{
	this->size = mat2.size;
	this->elem = new double[this->size * this->size]{ 0 };
	for (int i = 0; i < size * size; i++)
		this->elem[i] = mat2.elem[i];
}

threematr::~threematr()
{
	if (elem != nullptr)
		delete[] elem;
}

void threematr::input()
{
	cout << "Size:  ";
	cin >> size;
	if (elem != nullptr)
		delete[] this->elem;
	elem = new double[size * size]{ 0 };
	int arr_counter = 0;
	for (int i = 0; i < size - 1; i++, arr_counter++)
		cin >> elem[i * size + i + 1];
	for (int i = 0; i < size; i++, arr_counter++)
		cin >> elem[i * size + i];
	for (int i = 0; i < size - 1; i++, arr_counter++)
		cin >> elem[(i + 1) * size + i];
}

void threematr::input(int i)
{
	if (elem != nullptr)
		delete[] this->elem;
	size = i;
	elem = new double[size * size]{ 0 };
	for (int i = 0; i < size - 1; i++)
		cin >> elem[i * size + i + 1];
	for (int i = 0; i < size; i++)
		cin >> elem[i * size + i];
	for (int i = 0; i < size - 1; i++)
		cin >> elem[(i + 1) * size + i];
}

void threematr::input(int i, const double* arr)
{
	if (elem != nullptr)
		delete[] this->elem;
	size = i;
	elem = new double[size * size]{ 0 };
	int arr_counter = 0;
	for (int i = 0; i < size - 1; i++, arr_counter++)
		elem[i * size + i + 1] = arr[arr_counter];
	for (int i = 0; i < size; i++, arr_counter++)
		elem[i * size + i] = arr[arr_counter];
	for (int i = 0; i < size - 1; i++, arr_counter++)
		elem[(i + 1) * size + i] = arr[arr_counter];
}

void threematr::print()
{
	cout << "matrix = \n";
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
			cout << elem[i * size + j] << '\t';
		cout << "\n";
	}		
	cout << "\n";
}

int threematr::get_size()
{
	return size;
}

double threematr::get_elem(int i, int j)
{
	return elem[i * size + j];
}

void threematr::set_elem(int i, int j, double temp)
{
	 elem[i * size + j] = temp;
}

void threematr::mult_by_num(double num)
{
	for (int i = 0; i < size * size; i++)
		this->elem[i] *= num;
}

bool threematr::mult(const threematr* mat2)
{
	if (this->size == mat2->size)
	{
		threematr MatrBuf;
		MatrBuf.copy(this);

		delete[] this->elem;
		this->size = mat2->size;
		this->elem = new double[this->size * this->size]{ 0 };

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				for (int k = 0; k < MatrBuf.size; k++)
					this->elem[i * size + j] += MatrBuf.elem[i * size + k] * mat2->elem[k * mat2->size + j];
		return true;
	}
	else
	{
		cout << "error \n";
		return false;
	}
}

bool threematr::mult(const double* arr, int loc_size)
{
	if (this->size != loc_size)
	{
		cout << "error\n";
		return false;
	}
	threematr MatrBuf(this->size, this->elem);

	delete[] this->elem;
	this->size = loc_size;
	this->elem = new double[this->size * this->size]{ 0 };

	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; j++)
			for (int k = 0; k < MatrBuf.size; k++)
				this->elem[i * size + j] += MatrBuf.elem[i * size + k] * arr[k * loc_size + j];
	return true;
}

bool threematr::msum(const threematr* mat2)
{
	if (size != mat2->size)
		return false;
	for (int i = 0; i < size * size; i++)
		this->elem[i] += mat2->elem[i];
	return true;
}

void threematr::copy(threematr* mat2)
{
	this->size = mat2->size;
	this->size = mat2->size;
	if (elem != nullptr)
		delete[] elem;
	this->elem = new double[this->size * this->size]{ 0 };
	for (int i = 0; i < size * size; i++)
		this->elem[i] = mat2->elem[i];
}





std::ostream& operator<<(std::ostream& out, const threematr& right)
{
	out << "Size = " << right.size << '\n';
	for (int rows = 0; rows < right.size; rows++)
	{
		for (int columns = 0; columns < right.size; columns++)
		{
			out << right.elem[rows * right.size + columns] << '\t';
		}
		out << '\n';
	}
	return out;
}

std::istream& operator>>(std::istream& in, threematr& right)
{
	if (right.elem != nullptr)
		delete[] right.elem;
	cout << "Enter size: \n";
	in >> right.size;
	
	cout << "Enter matr: \n";
	right.elem = new double[right.size * right.size]{ 0 };
	for (int i = 0; i < right.size - 1; i++)
		in >> right.elem[i * right.size + i + 1];
	for (int i = 0; i < right.size; i++)
		in >> right.elem[i * right.size + i];
	for (int i = 0; i < right.size - 1; i++)
		in >> right.elem[(i + 1) * right.size + i];
	return in;
}

threematr operator+(const threematr& left, const threematr& right)
{
	threematr MatrBuf(right);
	for (int rows = 0; rows < right.size; rows++)
	{
		for (int columns = 0; columns < right.size; columns++)
		{
			MatrBuf.elem[rows * MatrBuf.size + columns] = right.elem[rows * right.size + columns]+ left.elem[rows * left.size + columns];
		}
	}
	cout << MatrBuf;
	return MatrBuf;
}

threematr operator-(const threematr& left, const threematr& right)
{
	threematr MatrBuf(left);

	for (int rows = 0; rows < MatrBuf.size; rows++)
	{
		for (int columns = 0; columns < MatrBuf.size; columns++)
		{
			MatrBuf.elem[rows * left.size + columns] = left.elem[rows * left.size + columns] - right.elem[rows * right.size + columns];
		}
	}
	return MatrBuf;
}

threematr operator*(const threematr& left, const threematr& right)
{
	threematr MatrBuf(left.size);

	for (int i = 0; i < left.size; i++)
		for (int j = 0; j < left.size; j++)
			for (int k = 0; k < MatrBuf.size; k++)
				MatrBuf.elem[i * MatrBuf.size + j] += left.elem[i * left.size + k] * right.elem[k * right.size + j];
	
	return MatrBuf;
}

threematr operator-(const threematr& mat)
{
	threematr MatrBuf(mat);

	for (int i = 0; i < MatrBuf.get_size(); i++)
		for (int j = 0; j < MatrBuf.get_size(); j++)
		{
			if (MatrBuf.get_elem(i, j) != 0)
				MatrBuf.set_elem(i, j, -MatrBuf.get_elem(i, j));
		}
	
	return MatrBuf;
}