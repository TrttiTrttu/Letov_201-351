#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::stack;

bool check(string& str)
{
	stack<char> stk;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			stk.push(str[i]);

        switch (str[i])
        {
        case ')':
        {
            if (stk.top() == '(')
                stk.pop();
            else
                return false;
            break;
        }
        case '}':
        {
            if (stk.top() == '{')
                stk.pop();
            else
                return false;
            break;
        }
        case ']':
        {
            if (stk.top() == '[')
                stk.pop();
            else
                return false;
            break;
        }
        }
	}
	if (stk.empty())
		return true;
	else
		return false;
}

int main()
{
	string str;
	cout << "Enter string: ";
	cin >> str;
	cout << check(str);
}