#include <iostream>
#include <ctime>


using std::cin;
using std::cout;
using std::swap;
using std::endl;


const int n = 1000;
int len = 0;
int arr[n] = { 0 };
int buf[n] = { 0 };
char arr_ch[n]={ ' ' };


void init_massive(bool isint) {
	cout << "Enter length: ";
	cin >> len;
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
	int b1 = left;
	int counter = 0;
	int mid = left + (right - left) / 2;
	int b2 = mid + 1;

	while (b1 <= mid && b2 <= right) {
		if (arr[b1] <= arr[b2]) {
			buf[counter] = arr[b1];
			b1++;
		}
		else {
			buf[counter] = arr[b2];
			b2++;
		}
		counter++;
	}
	while (b1 <= mid) {
		buf[counter] = arr[b1];
		b1++;
		counter++;
	}
	while (b2 <= right) {
		buf[counter] = arr[b2];
		b2++;
		counter++;
	}
	for (b1 = 0; b1 < counter; b1++)
		arr[left + b1] = buf[b1];
}


void MergeSort(int* arr, int left, int right)
{
	if (left < right)
		if (right - left == 1) {
			if (arr[right] < arr[left]) 
				swap(arr[left], arr[right]);
		}
		else {
			MergeSort(arr, left, left + (right - left) / 2);
			MergeSort(arr, left + (right - left) / 2 + 1, right);
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
			MergeSort(arr, 0, len - 1);
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