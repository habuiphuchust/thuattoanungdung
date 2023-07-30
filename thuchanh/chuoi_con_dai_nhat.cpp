#include<bits/stdc++.h>
using namespace std;
int n, m;
const int MAX = 10004;
int x[MAX], y[MAX];
int sub[MAX][MAX];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> y[i];
	}
}

void solve() {
	sub[1][0] = 0;
	sub [0][1] = 0;
	sub[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(x[i] == y[j])
				sub[i][j] = sub[i-1][j-1]+1;
			else if (sub[i-1][j] > sub [i][j-1])
				sub[i][j] = sub[i-1][j];
			else sub[i][j] = sub[i][j-1];
		}
	}
	cout << sub[n][m];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}