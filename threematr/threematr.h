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
	threematr(const threematr& mat2);
	~threematr();

	void input();
	void input(int i);
	void input(int i, const double* arr);
	void print();

	int get_size();
	double get_elem(int i, int j);
	void set_elem(int i, int j, double temp);

	void mult_by_num(double num);
	bool mult(const threematr* mat2);
	bool mult(const double* arr, int loc_size);
	bool msum(const threematr* mat2);

	void copy(threematr* mat2);
	
	
	friend std::ostream& operator<<(std::ostream& out, const threematr& right);
	friend std::istream& operator>>(std::istream& in, threematr& right);
	
	friend threematr operator+(const threematr& left, const threematr& right);
	friend threematr operator-(const threematr& left, const threematr& right);
	
	friend threematr operator*(const threematr& left, const threematr& right);
};

threematr operator-(const threematr& mat);

threematr operator*(const threematr& left,const int& num);
threematr operator*(const int& num, const threematr& left);

