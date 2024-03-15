#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<string> st;
	for (int i = s.size()-1; i >=0; i--)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.push(string(1,s[i]));//Chuyen char->string
		}
		else
		{
			string tmp1 = st.top(); st.pop();
			string tmp2 = st.top(); st.pop();
			string res = "(" + tmp1 + s[i] + tmp2 + ")";
			st.push(res);
		}
	}
	cout << st.top() << endl;
}