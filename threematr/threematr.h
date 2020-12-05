#pragma once
#include <iostream>
#include <ctime>

class threematr
{
private:
	int size;
	double* elem;
public:
	threematr();
	threematr(int i);
	threematr(int i, const double* arr);
	~threematr();

	void input();
	void input(int i);
	void input(int i, const double* arr);
	void print();

	int get_size();
	void mult_by_num(double num);
	bool mult(const threematr* mat2);
	bool mult(const double* arr, int loc_size);
	bool msum(const threematr* mat2);
	//bool msum(const double* arr, int rows, int cols);

	//double trace();
	//double det();
	void copy(threematr* mat2);

	friend std::ostream& operator<<(std::ostream& out, const threematr& right);
	friend std::istream& operator>> (std::istream& in, threematr& right);
	friend threematr& operator+(threematr& left, const threematr& right);
	friend threematr& operator-(threematr& left, const threematr& right);
	friend threematr& operator-(threematr& mat);
	friend threematr& operator*(threematr& left, const threematr& right);
};

