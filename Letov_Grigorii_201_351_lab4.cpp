#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

const int len = 10;
int arr[1000] = { 0 };

void print(int* arr, int  n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void Merge(int arr[], int* d, int begin, int end)
{
	int i = begin;
	int t = 0;
	int sred = begin + (end - begin) / 2;
	int j = sred + 1;

	while (i <= sred && j <= end) {
		if (arr[i] <= arr[j]) {
			d[t] = arr[i];
			i++;
		}
		else {
			d[t] = arr[j];
			j++;
		}
		t++;
	}
	while (i <= sred) {
		d[t] = arr[i]; i++; t++;
	}
	while (j <= end) {
		d[t] = arr[j]; j++; t++;
	}
	for (i = 0; i < t; i++)
		arr[begin + i] = d[i];
}

void MergeSort(int* arr, int* d, int left, int right)
{
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
	int  t;
	if (left < right)
		if (right - left == 1) {
			if (arr[right] < arr[left]) {
				t = arr[left];
				arr[left] = arr[right];
				arr[right] = t;
			}
		}
		else {
			MergeSort(arr, d, left, left + (right - left) / 2);
			MergeSort(arr, d, left + (right - left) / 2 + 1, right);
			Merge(arr, d, left, right);
		}
}
void init_massiv() {
	srand(time(0));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100;
}
int main() {
	init_massiv();
	int d[1000] = { 0 };
	MergeSort(arr, d, 0, len - 1);
	print(arr, len);
	return 0;
}/*
 #include <iostream>
#include <cstdlib>
#include <ctime>


using std::cin;
using std::cout;
using std::swap;
using std::endl;

const int len = 10;
int arr[len];
int d[len] = { 0 };
char arr_ch[len];



void init_massiv() {
	srand(time(0));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100;
}

template <typename X>
void print_mas(X* arr) {
	for (int k = 0; k < len; k++)
		cout << arr[k] << '\t';
	cout << '\n';
}
void init_massiv_char() {
	srand(time(0));
	for (int i = 0; i < 10; i++)
		arr_ch[i] = char(rand() % 26 + 65);
}

void bubble_sort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void count_sort(char* arr, int len) {
	int const amount = 26;
	int counter[amount] = { 0 };
	int j = 0;
	for (int i = 0; i < len; i++) {
		j = int(arr_ch[i] - 'A');
		counter[j] += 1;
	}
	print_mas(counter);
	int i = 0;
	j = 0;
	while (j <= amount) {
		if (counter[j] > 0) {
			arr_ch[i] = char(int('A') + j);
			i++;
			counter[j]--;
		}
		else {
			j++;
		}
	}
}

void Merge(int* arr, int* d, int begin, int end)
{
	int i = begin;
	int t = 0;
	int sred = begin + (end - begin) / 2;
	int j = sred + 1;

	while (i <= sred && j <= end) {
		if (arr[i] <= arr[j]) {
			d[t] = arr[i];
			i++;
		}
		else {
			d[t] = arr[j];
			j++;
		}
		t++;
	}
	while (i <= sred) {
		d[t] = arr[i]; i++; t++;
	}
	while (j <= end) {
		d[t] = arr[j]; j++; t++;
	}
	for (i = 0; i < t; i++)
		arr[begin + i] = d[i];
}

void MergeSort(int* arr, int* d, int left, int right)
{
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
	int  t;
	if (left < right)
		if (right - left == 1) {
			if (arr[right] < arr[left]) {
				t = arr[left];
				arr[left] = arr[right];
				arr[right] = t;
			}
		}
		else {
			MergeSort(arr, d, left, left + (right - left) / 2);
			MergeSort(arr, d, left + (right - left) / 2 + 1, right);
			Merge(arr, d, left, right);
		}
}



int main() {
	init_massiv();
	MergeSort(arr,d,0,len - 1);
	print_mas(arr);
	return 0;
}*/