#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<vector>
using namespace std;

string s;
string tmp = "[](){}";
int n;

vector < string > v;

bool check(string s)
{
	stack<char>st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			st.push(s[i]);
		}
		else
		{
			if (st.empty())
			{
				return false;
			}
			char tmp = st.top();
			st.pop();
			if ((s[i] == ')' && tmp != '(') || (s[i] == ']' && tmp != '[') || (s[i] == '}' && tmp != '{'))
			{
				return false;
			}
		}
	}
	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Try(int i)
{
	for (int j = 0; j < tmp.size();j++)
	{
		s += tmp[j];
		if (s.size() == n)
		{
			if(check(s))
				v.push_back(s);
		}
		else
		{
			Try(i + 1);
		}
		s.pop_back();
	}
}

int main()
{
	cout << "N: ";
	cin >> n;
	if (n % 2 != 0)
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		Try(1);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
		cout << endl;
	}
}