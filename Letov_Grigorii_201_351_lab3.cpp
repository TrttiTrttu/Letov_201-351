#include <iostream>
#include <cstdlib>
#include <ctime>


using std::cin;
using std::cout;
using std::swap;
using std::endl;


const int len = 10;
int arr[len] = { 0 };
int buf[len] = { 0 };
char arr_ch[len]={ ' ' };


void init_massive(bool isint) {
	if (isint) {
		srand(time(0));
		for (int i = 0; i < len; i++)
			arr[i] = rand() % 100;
	}
	else {
		srand(time(0));
		for (int i = 0; i < 10; i++)
			arr_ch[i] = char(rand() % 26 + 65);
	}
}


template <typename X>
void print_mas(X* arr) {
	for (int k = 0; k < len; k++)
		cout << arr[k] << '\t';
	cout << '\n';
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


void Merge(int* arr, int* buf, int left, int right)
{
	int i = left;
	int t = 0;
	int mid = left + (right - left) / 2;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			buf[t] = arr[i];
			i++;
		}
		else {
			buf[t] = arr[j];
			j++;
		}
		t++;
	}
	while (i <= mid) {
		buf[t] = arr[i]; i++; t++;
	}
	while (j <= right) {
		buf[t] = arr[j]; j++; t++;
	}
	for (i = 0; i < t; i++)
		arr[left + i] = buf[i];
}


void MergeSort(int* arr, int* buf, int left, int right)
{
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
			MergeSort(arr, buf, left, left + (right - left) / 2);
			MergeSort(arr, buf, left + (right - left) / 2 + 1, right);
			Merge(arr, buf, left, right);
		}
}



int main() {
	int choice;
	bool flag = true;
	while (flag) {
		cout << "Choose task: \n1.bubble sort \n2.count sort \n3.merge sort \n4.exit \n";
		cin >> choice;
		switch (choice) {
		case 1:
			init_massive(true);
			print_mas(arr);
			bubble_sort(arr, len);
			print_mas(arr);
			break;
		case 2:
			init_massive(false);
			print_mas(arr_ch);
			count_sort(arr_ch, len);
			print_mas(arr_ch);
			break;
		case 3:
			init_massive(true);
			print_mas(arr);
			MergeSort(arr, buf, 0, len - 1);
			print_mas(arr);
			break;
		case 4:
			flag = false;
			break;
		default:
			cout << "try again \n";
			break;
		}
	}
	return 0;
}