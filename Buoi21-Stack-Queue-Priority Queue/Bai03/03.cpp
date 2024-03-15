#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

bool valid(char x, char y)
{
	return (x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']');
}

int main()
{
	string s;
	cin >> s;
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
		}
		else
		{
			if (st.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			//Kiem tra xem cac dau co di cap voi nhau khong
			char y = st.top();
			st.pop();
			if (!valid(y, s[i]))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (st.empty())
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}