#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
string s;
int n;
stack<char> st;
void input()
{
	cin >> s;
	n = s.length();

}
bool solve()
{
	for (int i = 0; i < n; i++)
	{
		switch (s[i])
		{
			case '(':
				st.push('(');
				break;
			case '[':
				st.push('[');
				break;
			case '{':
				st.push('{');
				break;
			case ')':
				if (st.empty())
					return false;
				else
				{
					char c = st.top();
					if (c != '(')
						return false;
					else
						st.pop();
				}
				break;
			case ']':
				if (st.empty())
					return false;
				else
				{
					char c = st.top();
					if (c != '[')
						return false;
					else
						st.pop();
				}
				break;
			case '}':
				if (st.empty())
					return false;
				else
				{
					char c = st.top();
					if (c != '{')
						return false;
					else
						st.pop();
				}
				break;
		}
	}
	if (!st.empty())
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	cout << solve();
	return 0;
}
// 5/5