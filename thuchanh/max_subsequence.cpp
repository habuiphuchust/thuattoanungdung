#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000004;
int a[MAX];
int sum[MAX];
int n;

void input()
{	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}

void solve()
{
	sum[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		sum[i] = max(a[i], sum[i-1] + a[i]);
	}
	int rs = 0;
	for (int i = 1; i <= n; i++)
	{
		rs = max(rs, sum[i]);
	}
	cout << rs;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}