#include <bits/stdc++.h>
using namespace std;
const unsigned long long expt = 1000000007;
unsigned long long a, b;

int powexp(unsigned long long a, unsigned long long b) {
//	cout << b << endl;
	if (b == 1) return a % expt;
	if (b % 2 == 0) {
		unsigned long long c = powexp(a, b/2);
		return (c * c) % expt;
	} else {
		return ((a%expt) * powexp(a, b -1)) % expt;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	cout << powexp(a, b);
	return 0;
}