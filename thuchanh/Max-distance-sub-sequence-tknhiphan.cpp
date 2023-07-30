#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t;
int n, c, a[MAXN];
bool check (int distance) {
	int sl = 1;
	int i=1, j=2;
	while (i<n) {
		while (j<=n && a[j]-a[i] < distance)  ++j;		
		if (j<=n) sl++;
		if (sl>=c) return true;  // có th ly d c phn t 
		i = j;
		j++;
	}
	return false;
}
int MaxDistance () {
	int l = 0, r = a[n] - a[1];
	while (l<=r) {
		int mid = (l+r)/2;
		if (check(mid)) l = mid+1;   // tip tc th kt qu  na bên phi
		else r = mid-1; // tìm kt qu  na bên trái
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> c;
		for (int i=1; i<=n; i++)  cin >> a[i];
		sort(a+1, a+n+1);
		cout << MaxDistance() << endl;
	}
}