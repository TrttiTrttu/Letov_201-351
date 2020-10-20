#include <iostream>
#include <ctime>


using std::cin;
using std::cout;
using std::swap;


int even_num(int* arr, int i)
{
	int s = 0;
	int buf = arr[i];
	int counter = 0;
	while (buf > 0) 
	{
		counter++;
		buf /= 10;
	}
	buf = arr[i];
	while (buf > 0) 
	{
		if (counter % 2 == 0)
			s += buf % 10;
		buf /= 10;
		counter--; 
	}
	return s;
}


void input_mas(int *&arr, int *&buf, int *len) 
{
	if (arr != nullptr) delete[] arr;
	if (buf != nullptr) delete[] buf;
	cout << "enter length: ";
	cin >> *len;
	buf = new int[*len];
	arr = new int[*len];
	srand(time(0));
	for (int i = 0; i < *len; i++)
		arr[i] = rand() % 10000;
}


void print_mas(int* arr, const int len) 
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << '\t';
	cout << std::endl;
}


void Merge(int* arr, int* buf, int left, int right, bool iseven)
{

	int counter = 0;
	int b1 = left;
	int mid = left + (right - left) / 2;
	int b2 = mid + 1;

	while (b1 <= mid && b2 <= right) 
	{
		if (iseven) 
		{
			if (even_num(arr, b1) <= even_num(arr, b2)) 
			{
				buf[counter] = arr[b1];
				b1++;
			}
			else {
				buf[counter] = arr[b2];
				b2++;
			}
		}
		else {
			if (arr[b1] % 10 == arr[b2] % 10)
			{
				if (arr[b1] < arr[b2]) 
				{
					
					buf[counter] = arr[b2];
					b2++;
				}
				else 
				{
					buf[counter] = arr[b1];
					b1++;
				}
			}
			else {
				if (arr[b1] % 10 <= arr[b2] % 10) 
				{
					buf[counter] = arr[b1];
					b1++;
				}
				else {
					buf[counter] = arr[b2];
					b2++;
				}
			}
		}
		counter++;
	}
	while (b1 <= mid) 
	{
		buf[counter] = arr[b1];
		b1++;
		counter++;
	}
	while (b2 <= right) 
	{
		buf[counter] = arr[b2];
		b2++;
		counter++;
	}
	for (b1 = 0; b1 < counter; b1++)
		arr[left + b1] = buf[b1];
}



void MergeSort(int* arr,int* buf, int left, int right, int len, bool iseven)
{
	if (left < right)
		if (right - left == 1) 
			if (iseven)
			{
				if (even_num(arr, right) < even_num(arr, left))
				{
					swap(arr[left], arr[right]);
					//print_mas(arr,len);
				}
			}
			else {
				if (arr[right] % 10 == arr[left] % 10)
				{	
					if (arr[right] > arr[left])
					{
						swap(arr[left], arr[right]);
					}
				}
				else {
					if (arr[right] % 10 < arr[left] % 10)
					{
						swap(arr[left], arr[right]);
					}
				}
			}
			else 
			{
				MergeSort(arr, buf, left, left + (right - left) / 2, len, iseven);
				MergeSort(arr, buf, left + (right - left) / 2 + 1, right, len, iseven);
				Merge(arr, buf, left, right, iseven);
			}
}


int main() {
	int *arr = nullptr;
	int *buf = nullptr;
	int len;
	int choice;
	while (true) {
		cout << "1.input massive \n2.print_massive \n3.merge_even_sort \n4.last_num_sort \n5.exit\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			input_mas(arr, buf, &len);
			break;
		}
		case 2: {
			print_mas(arr, len);
			break;
		}
		case 3: {
			MergeSort(arr, buf, 0, len - 1, len, true);
			break;
		}
		case 4: {
			MergeSort(arr, buf, 0, len - 1, len, false);
			break;
		}
		case 5:
			return 0;
		default:
			cout << "try again\n";
		}
	}
}