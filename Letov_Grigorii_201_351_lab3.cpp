#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using std::cin;
using std::cout;
using std::swap;

const int len = 10;
int arr[len];
char arr_ch[len];

template <typename X>

void print_mas(X* arr,int len) {
	for (int k = 0; k < len; k++)
		cout << arr[k] << '\t';
	cout << '\n';
}

void init_massiv() {
	srand(time(0));
	for (int i = 0; i < len; i++) 
		arr[i] = rand() % 20;
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

int length(int *arr) {
	int arrbuf[len];
	for (int i = 0; i < len; i++) {
		arrbuf[i] = arr[i];
	}
	cout << sizeof(arrbuf) << sizeof(*arrbuf) << '\n';
	return sizeof(arrbuf) / sizeof(*arrbuf);
}

void Merge(int* sumArr, int* arr1, int* arr2) {
	int arr1min = 0;
	int arr2min = 0;
	int sumArrmin = 0;
	
	while (arr1min < sizeof(arr1) / sizeof (*arr1) && arr2min < sizeof(arr2) / sizeof(*arr2)) {
		if (arr1[arr1min] <= arr2[arr2min]) {
			sumArr[sumArrmin] = arr1[arr1min];
			arr1min++;
		}
		else {
			sumArr[sumArrmin] = arr1[arr2min];
			arr2min++;
		}
		sumArrmin++;
	}
	while (arr1min < sizeof(arr1) / sizeof(*arr1)) {
		sumArr[sumArrmin] = arr1[arr1min];
		arr1min++;
	}
	while (arr2min < sizeof(arr2) / sizeof(*arr2)) {
		sumArr[sumArrmin] = arr1[arr2min];
		arr2min++;
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
	print_mas(counter,amount);
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

int main() {
	init_massiv();
	cout << sizeof(arr)/sizeof(*arr) << '\n';
	cout << length(arr) << '\n';
	return 0;
	/*
	int arr[] = { 10,20,30,40,50,60,70 };
	cout << sizeof(arr) << ' ' << sizeof(arr[0]) << '\n';
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	cout << "The size of the array is: " << arrSize;
	return 0;*/
}