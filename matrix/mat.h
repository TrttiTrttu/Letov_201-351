#pragma once
class matrix
{
private:
	int columns;
	int rows;
	double* elem;
public:
	matrix();
	matrix(int i, int j);
	matrix(int i, int j, const double* arr);
	~matrix();

	void input();
	void input(int i,int j);
	void input(int i, int j, const double* arr);
	void print();

	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
	void mult_by_num(double num);
	bool mult(const matrix* mat2);
	bool mult(const double* arr, int rows, int cols);
	bool msum(const matrix* mat2);
	bool msum(const double* arr, int rows, int cols);

	double trace();
	double det();
	void copy(const matrix* mat2);
	

	friend std::ostream& operator<<(std::ostream& out, const matrix& right);
};

