#include <iostream>
#include <cstring>
#include <Windows.h>

using std::cin;
using std::cout;

void palindrom(char* str) // ��������� ��������� �� ������
{
	bool flag = true; // ����������-���� 
	for (int l = 0, r = strlen(str) - 1; l < r; ) // �� ��� ��� ���� ����������� ������� �� ���������� � ��������
		if (str[l] != ' ' && str[r] != ' ') // ���� ��� �������� �� ������� 
			if (int(str[l]) == int(str[r]) || abs(int(str[l]) - int(str[r])) == 32 || abs(int(str[l]) - int(str[r])) == 80) // �������� �� ������ �������� �� ������� ASCII
			{
				r--; l++; // ����� ��������� ����� � ������ �������
			}
			else // ���� �������� �����������
			{
				flag = false; break; // ���� �� ���� � ����� �� �����
			}
		else if (str[l] == ' ' && str[r] != ' ')  // ���� ����� ������� ������
			l++; // ����� ������ ���������
		else if (str[l] != ' ' && str[r] == ' ') // ���� ������ ������� ������
			r--; // ����� ������� ��������
		else if (str[l] == ' ' && str[r] == ' ') // ���� ��� �������� �������
		{
			l++; // ����� ������
			r--; // � ������� ��������
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

void find(char* str, char* substr) // ��������� ��������� �� ������ � ���������
{
	char buf[255]{}; // ���������� �������� ������
	char* pbuf = buf; 
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
			if (strcmp(substr, buf) == 0)
				cout << "index = " << index << '\t';
			clear(pbuf);
			continue;
		}
		i++;
	}
}

int main()
{
	SetConsoleCP(1251); // ������� �� Windows.h 
	SetConsoleOutputCP(1251); // ��� ����������� �����\������ �������
	char str[255]{}; // ���������� ������ ������
	char substr[255]{}; // ���������� ������ ��������� ��� 2-�� �������
	char* pstr = str; // ���������� ��������� �� ������
	char* psubstr = substr; // ���������� ��������� �� ���������
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
			cin.getline(str, 255);
			palindrom(pstr);
			cout << '\n';
			break;
		}
		case 2:
		{
			cout << "������� ������: \n";
			cin.get();
			cin.getline(str, 255);
			cout << "������� ��������� ��� ������: \n";
			cin.getline(substr, 255);
			find(pstr, psubstr);
			cout << '\n';
			break;
		}
		case 3:
		{
			cout << "������� ������ ��� ����������: \n";
			cin.get();
			cin.getline(str,255);
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
			cin.getline(str, 255);
			names(pstr);
			cout << '\n';
			break;
		}
		case 5:
		{
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