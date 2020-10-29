#include <iostream>
#include <cstring>
#include <Windows.h>

using std::cin;
using std::cout;

void palindrom(char* str) // ��������� ��������� �� ������
{
	bool flag = true; // ����������-���� 
	
	for (int l = 0, r = strlen(str) - 1; l < r; ) // �� ��� ��� ���� ����������� ������� �� ���������� � ��������
		
		if (int(str[l]) == int(str[r]) || abs(int(str[l]) - int(str[r])) == 32) // �������� �� ������ �������� � ��������� �� ������� ASCII 
		{
			r--; l++; // ����� ��������� ����� � ������ �������
		}
		else if (str[l] == ' ' && str[r] != ' ')  // ���� ����� ������� ������
			l++; // ����� ������ ���������
		
		else if (str[l] != ' ' && str[r] == ' ') // ���� ������ ������� ������
			r--; // ����� ������� ��������

		else // ���� �������� �����������
		{
			flag = false; break; // ���� �� ���� � ����� �� �����
		}
	cout << ((flag) ? "���������" : "�� ���������"); // ��������� �������� � ��������� �� �������� �����
}

void cesar_code(char* str, int num) //��������� ��������� �� ������ � ��������� ����� �����
{
	num %= 26; // �������������� ����� �� �����, ���� �� ����� ������ ����� ��������
	char str_for_encrypt[255]{}; // ���������� ������ ������ ��� �������������� ������
	for (int i = 0; i < strlen(str); i++) 
	
		if (str[i] != ' ') // ���� ������� �� ������
		
			if(int(str[i]) + num < int('z') + 1) // �������� ��� ����� �� �������� �� ������� ��������
				str_for_encrypt[i] = char(int(int(str[i]) + num)); // ��������� �������� �� ������� ASCII ����� ����� ��������������
			
			else
				str_for_encrypt[i] = char(int('a' + int(str[i]) + num - 'z' - 1)); // ��������� ���� ����� ������� �� ������� ��������
	
	str_for_encrypt[strlen(str)] = '\0'; // ���������� ����-����������� � ����� ������
	cout << str_for_encrypt;
}

void names(char* str)
{
	char buf[255]{}; // ���������� ������ ������, � ������� ����� ������������ "��������"
	
	for (int i = 0; i < strlen(str); i++)
	{
		int counter = 0; // ������� �������  
		
		if (str[i] == '\"') // ���� ����������� ������ �������
		{
			counter++; // ���������� �������� �������
			i++; // ���������� ������� �������� ����� ���������� �������
			int j = 0; // ��������� ������� ��� ������-������
			
			while (counter < 2)
			{
				buf[j] = str[i]; // ����������� "��������" � �����
				i++; // ���������� �������� ����� for ( ������� �������� ������ )
				j++; // ���������� �������� ������
				if (str[i] == '\"') counter++; // ���� ����������� ������ �������
			}
			buf[j] = '\0'; // ���������� ����-����������� � ����� ������
			cout << buf << '\t';
		}
	}
}

void clear(char *str) // �������� ��������� �� ������  
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = '.'; // ��������� ������ �������
}

bool* find(char* str, char* substr) // ��������� ��������� �� ������ � ���������
{
	char* buf = new char[strlen(str)]{}; // ���������� �������� ������
	bool* index_arr = new bool[strlen(str)]{ false };
	
	for (int i = 0; i < strlen(str); )
	{
		int counter = 0; // ���������� ��������
		
		if (str[i] == substr[counter])
		{
			int index = i; // ���������� ���������, � ������� ����� �������� ����� ������� �������� �������������� ��������� 
			
			while (str[i] == substr[counter] && substr[counter] != '\0') // != \0 ����� ����� while �� ����� �� ������� ���������
			{
				buf[counter] = str[i]; // � buf ���������� �������� �� ������
				i++;
				counter++;
			}
			
			if (strcmp(substr, buf) == 0)// ���� ����� ����� ��������� 
				index_arr[index] = true;  // ������������ ����� � ���������, ������ ������� ��������� � �������� ��������� 
			
			clear(buf); // �������� ������
			
			continue; // ������� �� ��������� ��������, ����� �� ���� ������ ������������ �������� i
		}
		i++;
	}
	delete[] buf;
	return index_arr;
}

int main()
{
	SetConsoleCP(1251); // ������� �� Windows.h 
	SetConsoleOutputCP(1251); // ��� ����������� �����\������ �������
	char* pstr = new char[255]{}; // ���������� ������ ������
	char* psubstr = new char[255]{}; // ���������� ������ ��������� ��� 2-�� �������
	bool* index = nullptr; // ���������� ������� ��������� ��� �������� �������� ���������
	int choice = 0; 
	while (true)
	{
		cout << "choose your task:\n"
			"1. palindrom\n"
			"2. find substring\n"
			"3. cesar code\n"
			"4. \"names\"\n"
			"5. exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
		{
			cout << "������� ������ ��� ����������: \n";
			cin.get();
			cin.getline(pstr, 255);
			palindrom(pstr);
			cout << '\n';
			break;
		}
		case 2:
		{
			cout << "������� ������: \n";
			cin.get();
			cin.getline(pstr, 255);
			cout << "������� ��������� ��� ������: \n";
			cin.getline(psubstr, 255);
			index = find(pstr, psubstr);
			for (int i = 0; i < strlen(pstr); i++)
				if (index[i] != false)
					cout << "index = " << i << '\n';
			delete[] index;
			break;
		}
		case 3:
		{
			cout << "������� ������ ��� ����������: \n";
			cin.get();
			cin.getline(pstr,255);
			cout << "������� ���� �����: \n";
			int num = 0;
			cin >> num;
			cesar_code(pstr, num);
			cout << '\n';
			break;
		}
		case 4:
		{
			cout << "������� ������ ������ ��������: \n";
			cin.get();
			cin.getline(pstr, 255);
			names(pstr);
			cout << '\n';
			break;
		}
		case 5:
		{
			delete[] psubstr;
			delete[] pstr;
			cout << "exit";
			return 0;
		}
		default:
		{
			cout << "try again\n";
			break;
		}
		}
	}
}