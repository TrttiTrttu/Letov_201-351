#include <iostream>
#include "D:\visualka\letov 201_351\matrix\mat.h"

using std::cin;
using std::cout;

int main()
{
	double arr[9]{ 0,1,2,3,4,5,6,7,8 };
	matrix matA(3,3);
	matA.input(3, 3,arr);
	//matA.input(matA.get_rows(), matA.get_columns());
	int choice = 0;
	while (true)
	{
		cout << "choose task :\n" <<
			"1. input \n"
			"2. print\n"
			"3. get rows\n"
			"4. get columns\n"
			"5. get elem\n"
			"6. sum\n"
			"7. mult\n"
			"8. mult by num\n"
			"9. trace\n"
			"10. det\n"
			"11. exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			matA.input();
			break;
		}
		case 2:
		{
			cout << matA;
			break;
		}
		case 3:
		{
			cout << " rows = " << matA.get_rows() << '\n';
			break;
		}
		case 4:
		{
			cout << " cols = " << matA.get_columns() << '\n';
			break;
		}
		case 5:
		{
			int row_num = 0, col_num = 0;
			cout << "enter row_num :";
			cin >> row_num;
			cout << "enter col_num :";
			cin >> col_num;
			cout << "elem[" << row_num << ',' << col_num << "] = "
				 << matA.get_elem(row_num,col_num) << '\n';
			break;
		}
		case 6:
		{
			cout << "enter 2nd mat\n";
			matrix matB;
			matB.input();
			matA.msum(&matB);
			break;
		}
		case 7:
		{
			cout << "enter 2nd mat\n";
			matrix matB;
			matB.input();
			matA.mult(&matB);
			break;
		}
		case 8:
		{
			int num = 0;
			cout << "enter num :";
			cin >> num;
			matA.mult_by_num(num);
			break;
		}
		case 9:
		{
			cout << "trace = " << matA.trace() << '\n';
			break;
		}
		case 10:
		{
			cout << "det = " << matA.det() << '\n';
			break;
		}
		case 11:
		{
			cout << "exit...";
			return 0;
		}
		default:
		{
			cout << "try again \n";
			break;
		}
		}
	}
}