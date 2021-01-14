#include <iostream>
#include <queue>

using std::queue;
using std::cin;
using std::cout;

int min(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

void print_and_add(int t, queue<int>& q2, queue<int>& q3, queue<int>& q5) {
	if (t != 1) {
		cout << t << ' ';
	}
	q2.push(t * 2);
	q3.push(t * 3);
	q5.push(t * 5);
}

int main()
{
	cout << "Input number:\n";
	int num;
	cin >> num;

	queue<int> q2;
	queue<int> q3;
	queue<int> q5;

	print_and_add(1, q2, q3, q5); 
		int k = 0;

	while (k != num) {
		int x = min(min(q2.front(), q3.front()), q5.front());
		print_and_add(x, q2, q3, q5);
		k++;
		if (x == q2.front())
			q2.pop();
		if (x == q3.front())
			q3.pop();
		if (x == q5.front())
			q5.pop();
	}
}
