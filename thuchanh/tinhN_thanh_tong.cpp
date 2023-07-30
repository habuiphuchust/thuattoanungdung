#include <bits/stdc++.h>
using namespace std;
int d[60];
int n;

int solve() {
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			d[j] += d[j-i];
		}
	}
	return d[n];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(d, 0, sizeof(d));
	cin >> n;
	cout << solve();
	
	return 0;
}
//   1    | 2        |3        |4 |  5
//1:1     |          |         |  |
//2:11    |2         |         |  |
//3:111   |21        |3        |  |
//4:1111  |211; 22   |31       |4 |
//5:11111 |2111; 221 |311; 32  |41|  5