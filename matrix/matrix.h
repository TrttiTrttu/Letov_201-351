#pragma once
class matrix
{
private:
	int columns;
	int rows;
	double* elem;
public:
	matrix();
	~matrix();
	void input();
	void print();
	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
};

