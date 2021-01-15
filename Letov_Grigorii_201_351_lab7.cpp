#include <iostream>
#include <vector>
#include <C:\GITHUB\Letov_201_351\human\human.h>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void add(vector<human>& t_vec)
{
	string t_surname, t_name;
	int t_age;
	cout << "enter surname: ";
	cin >> t_surname;
	cout << "enter name: ";
	cin >> t_name;
	cout << "enter age: ";
	cin >> t_age;
	t_vec.push_back(human (t_surname, t_name, t_age));
}

template<typename S>
void add(vector<S>& t_vec)
{
	cout << "enter amount: ";
	int amount = 0;
	cin >> amount;
	S tmp;
	for (int i = 0; i < amount; i++)
	{
		cin >> tmp;
		t_vec.push_back(tmp);
	}
}

template<typename Y>
void print(vector<Y>& t_vec)
{
	for (int i = 0; i < t_vec.size(); i++)
	{
		cout << t_vec[i] << '\n';
	}
}

bool cmpr_surname(human& left, human& right)
{
	return left.get_surname() < right.get_surname();
}

bool cmpr_name(human& left, human& right)
{
	return left.get_name() < right.get_name();
}

bool cmpr_age(human& left, human& right)
{
	return left.get_age() < right.get_age();
}

template<typename A>
bool cmpr_default(A& left, A& right)
{
	return left < right;
}

template<typename H>
void qsort(vector<H>& t_vec, int low,int high, bool (*cmpr)(H&, H&))
{
	int begin = low;
	int end = high;
	H pivot = t_vec[(begin + end) / 2];
	H temp;

	while (begin <= end)
	{
		while (cmpr(t_vec[begin], pivot))
			begin++;
		while (cmpr(pivot,t_vec[end]))
			end--;
		if (begin <= end)
		{
			temp = t_vec[begin];
			t_vec[begin] = t_vec[end];
			t_vec[end] = temp;
			begin++;
			end--;
		}
	}
	if (end > low)
		qsort(t_vec, low, end, cmpr);
	if (begin < high)
		qsort(t_vec, begin, high, cmpr);
}


int main()
{	
	vector<human> vec_h;
	vector<int> vec_X;
	int choice;
	while (true)
	{
		cout << "1. Show_vector\n"
			<< "2. Add in human-vector\n"
			<< "3. Add in X-vector\n"
			<< "4. Sort by surname\n"
			<< "5. Sort by name\n"
			<< "6. Sort by age\n"
			<< "7. Sort X-vector\n"
			<< "8. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 1:
		{
			print (vec_h);
			print(vec_X);
			cout << '\n';
			break;
		}
		case 2:
		{
			add(vec_h);
			cout << '\n';
			break;
		}
		case 3:
		{
			add(vec_X);
			cout << '\n';
			break;
		}
		case 4:
		{
			qsort(vec_h,0 , vec_h.size() - 1, cmpr_surname);
			cout << '\n';
			break;
		}
		case 5:
		{
			qsort(vec_h, 0, vec_h.size() - 1, cmpr_name);
			cout << '\n';
			break;
		}
		case 6:
		{
			qsort(vec_h, 0, vec_h.size() - 1, cmpr_age);
			cout << '\n';
			break;
		}
		case 7:
		{
			qsort(vec_X, 0, vec_X.size() - 1, cmpr_default);
			cout << '\n';
			break;
		}
		case 8:
		{
			return 0;
		}
		default:
		{
			cout << "try again\n";
		}
		}
	}
}