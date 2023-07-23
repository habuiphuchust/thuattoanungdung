#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAX = 1000004;
int a[MAX];
int M[MAX][20];
// M[a][b]:  phần tử min dãy bd từ a, có 2 mũ b p tử
void tinhM()
{
	for (int i = 0; i < n; i++) 
		M[i][0] = a[i];
	int check = log2(n);
	for (int i = 1; i <= check; i++)
	{
		int check = n - (1<<i) + 1;
		for (int j = 0; j  <= check; j++ )
		{
			M[j][i] = min(M[j][i-1], M[j+(1<<(i-1))][i-1]);
//			cout << M[j][i];
		}
	}
}
int rmq(int i, int j)
{
	int check = log2(j - i + 1);
	return min(M[i][check], M[j - (1<<check) + 1][check]);
}
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cin >> m;
	tinhM();
//	for (int j = 0; j <= 4; j++)
//	{
//		for (int i = 1; i <= n; i++)
//		 cout << M[i][j] <<" ";
//		cout << endl;
//	}
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
//		cout << rmq(k1, k2) << " ";
		sum += rmq(k1, k2);
	}
	cout << sum;
}
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}