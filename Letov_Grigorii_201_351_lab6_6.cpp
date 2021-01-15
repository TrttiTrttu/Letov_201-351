#include <iostream>
#include <map>
#include <string>

using std::map;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string input = "";
	string tmp = "";
	map <string, int> words;

	cout << "enter text: ";
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		if (!ispunct(input[i]) && !isdigit(input[i]))
			tmp.push_back(tolower(input[i]));
	}
	tmp.push_back(' ');
	float k = 0;
	string word = "";
	char lastbuf = '_';

	for (int i = 0,  j = -1; i < tmp.length(); i++)
	{
		char buf = tmp[i];;
		if (buf == ' ' && lastbuf != ' ')
		{
			word = tmp.substr(j + 1, i - j);
			if (words.find(word) == words.end())
			{
				words.insert({ word, 1 });
			}
			else {
				words[word]++;
			}
			k++;
			j = i;
		}
		if (buf == ' ' && lastbuf == ' ')
			j++;
		lastbuf = buf;
	}
	cout << "total words: " << k << '\n';
	for (auto it = words.begin(); it != words.end(); it++) {
		cout << it->first << " " << it->second / k * 100 << "%\n";
	}

}
