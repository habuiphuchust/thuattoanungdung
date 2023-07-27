#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000004;
int a[MAX] = {0, 2, 7, 9, 11, 13};
int n, m;
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}
void solve() {
	int count = 0;
	sort(a+1, a+n);
	for (int i = 1; i < n; i++) {
		int fi = m - a[i];
		bool flag = binary_search(a+i+1, a+n+1, fi);
		if (flag) count++;
	}
	cout << count;
//	cout << lower_bound(a, a+6, 14) - a;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}