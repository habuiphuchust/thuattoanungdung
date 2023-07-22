#include <bits/stdc++.h>
using namespace std;
int n;
int A[100005];
bool Visited[100005] = {false};
void prin()
{
	for (int i = 1; i <=n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void Try(int a)
{
	for (int i = 1; i <= n; i++) 
	{
		if (Visited[i]) 
			continue;
		A[a] = i;
		Visited[i] = true;
		if (a == n)
		{
			prin();
		}
		else
		{
			Try(a+1);
			
		}
	Visited[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	Try(1);
	return 0;
}