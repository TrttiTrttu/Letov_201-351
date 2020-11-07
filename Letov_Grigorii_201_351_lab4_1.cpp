#include <iostream>
#include <cstring>
#include <Windows.h>

using std::cin;
using std::cout;

void palindrom(char* str) // принимает указатель на строку
{
	bool flag = true; // переменная-флаг 
	
	for (int l = 0, r = strlen(str) - 1; l < r; ) // до тех пор пока сдвиграемые границы не встретятся в середине
		
		if (int(str[l]) == int(str[r]) || abs(int(str[l]) - int(str[r])) == 32) // проверка на разные регистры и равенство по таблице ASCII 
		{ r--; l++; }// сдвиг счетчиков левой и правой границы
		
		else if (str[l] == ' ' && str[r] != ' ')  // если левая граница пробел
			l++; // сдвиг левого счеттчика
		
		else if (str[l] != ' ' && str[r] == ' ') // если правый элемент пробел
			r--; // сдвиг правого счетчика

		else // если элементы различаются
		{ flag = false; break; }// флаг на ложь и выход из цикла

	cout << ((flag) ? "Палиндром" : "Не палиндром"); // тернарный оператор в зависимости от значения флага
}

void cesar_code(char* str, int num) //принимает указатель на строку и константу ключа шифра
{
	num %= 26; // преобразование ключа на слуай, если он будет больше длины алфавита
	char str_for_encrypt[255]{}; // объявление пустой строки для декодированной строки
	for (int i = 0; i < strlen(str); i++) 
	
		if (str[i] != ' ') // если элемент не пробел
		{
			if (int(str[i]) + num < int('z') && str[i] + num > int('Z')) // проверка что сдвиг не вылезает за границу алфавита
				str_for_encrypt[i] = char(int(int(str[i]) + num)); // изменение элемента по таблице ASCII путем явных преобразований
			if (int(str[i]) + num > int('z') && str[i] + num > int('Z'))
				str_for_encrypt[i] = char(int('a' + int(str[i]) + num - 'z' - 1)); 
			if (int(str[i]) + num < int('z') && str[i] + num < int('Z')) 
				str_for_encrypt[i] = char(int(int(str[i]) + num)); 
			if (int(str[i]) + num < int('z') && str[i] + num > int('Z')) 
				str_for_encrypt[i] = char(int('A' + int(str[i]) + num - 'Z' - 1));
		}
	str_for_encrypt[strlen(str)] = '\0'; // добавление нуля-терминатора в конце строки
	cout << str_for_encrypt;
}

void names(char* str)
{
	char buf[255]{}; // объявление пустой строки, в которую будут записываться "названия"
	
	for (int i = 0; i < strlen(str); i++)
	{
		int counter = 0; // счетчик кавычек  
		
		if (str[i] == '\"') // если встретилась ПЕРВАЯ кавычка
		{
			counter++; // увеличение счетчика кавычек
			i++; // увеличение индекса элемента чтобы пропустить кавычку
			int j = 0; // отдельный счетчик для строки-буфера
			
			while (counter < 2 && str[i] != '\0')
			{
				buf[j] = str[i]; // копирование "названия" в буфер
				i++; // увеличение счетчика цикла for ( счетчик исходной строки )
				j++; // увеличение счетчика буфера
				if (str[i] == '\"') counter++; // если встретилась ВТОРАЯ кавычка
			}
			buf[j] = '\0'; // добавление нуля-терминатора в конце буфера
			cout << buf << '\t';
		}
	}
}

void clear(char *str) // принимет указатель на строку  
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = '.'; // заполянет массив точками
}

bool* find(char* str, char* substr, int pos) // принимает указатели на строку и подстроку
{
	char* buf = new char[strlen(str)]{}; // объявление буферной строки
	bool* index_arr = new bool[strlen(str)]{ false };
	
	for (int i = pos; i < strlen(str); )
	{
		int counter = 0; // объявление счетчика
		
		if (str[i] == substr[counter])
		{
			int index = i; // объявление перменной, в которой будет хранится номер первого элемента предполагаемой подстроки 
			
			while (str[i] == substr[counter] && substr[counter] != '\0') // != \0 нужно чтобы while не вылез за границу подстроки
			{
				buf[counter] = str[i]; // в buf копируются элементы из строки
				i++;
				counter++;
			}
			
			if (strcmp(substr, buf) == 0)// если буфер равен подстроке 
				index_arr[index] = true;  // переключения флага в элементах, инедкс которых совпадает с индексом вхождения 
			
			clear(buf); // очищение буфера
			
			continue; // переход на следующую итерацию, чтобы не было лишней инкременации счетчика i
		}
		i++;
	}
	delete[] buf;
	return index_arr;
}

int main()
{
	SetConsoleCP(1251);			// функции из Windows.h 
	SetConsoleOutputCP(1251);	// для локализации ввода\вывода консоли
	char* pstr = new char[255]{}; // объявление пустой строки
	char* psubstr = new char[255]{}; // объявление пустой подстроки для 2-го задания
	bool* index = nullptr; // объявление пустого указателя для подсчета индексов вхождения
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
			cout << "Введите строку для полиндрома: \n";
			cin.get();
			cin.getline(pstr, 255);
			palindrom(pstr);
			cout << '\n';
			break;
		}
		case 2:
		{
			cout << "Введите строку: \n";
			cin.get();
			cin.getline(pstr, 255);
			cout << "Введите подстроку для поиска: \n";
			cin.getline(psubstr, 255);
			int pos = 0;
			cout << "Введите стартовую позицию поиска: \n";
			cin >> pos;
			index = find(pstr, psubstr,pos);
			for (int i = 0; i < strlen(pstr); i++)
				if (index[i] != false)
					cout << "index = " << i << '\n';
			delete[] index;
			break;
		}
		case 3:
		{
			cout << "Введите строку для шифорвания: \n";
			cin.get();
			cin.getline(pstr,255);
			cout << "Введите ключ шифра: \n";
			int num = 0;
			cin >> num;
			cesar_code(pstr, num);
			cout << '\n';
			break;
		}
		case 4:
		{
			cout << "Введите строку поиска названий: \n";
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