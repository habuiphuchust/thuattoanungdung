#include <bits/stdc++.h>
using namespace std;
int x[44];
int sum = 0;
int n, k;
void Try(int a) {
	for (int i = x[a-1]; i <= (n-sum)/(k-a+1); i++) {
		x[a] = i;
		sum += x[a];
		if (a == k) {
			if (sum == n) {
				for (int j = 1; j <= a; j++) 
					cout << x[j] << " ";
				cout << endl;
			}
		} else Try(a+1);
		sum -= x[a];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k >> n;
	x[0] = 1;
	Try(1);
	return 0;
}