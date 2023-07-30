#include <bits/stdc++.h>
using namespace std;
int n, L, m;
set<string> keys;

void input() {
	cin >> n >> L >> m;
	for (int i = 1; i <= n; i++) {
		string key;
		cin >> key;
		keys.insert(key);
		
	}
}
string key_string(int i) {
	string k1;
	while(i != 0) {
		int modu, sc;
		modu = i%10;
		i = i/10;
		k1.push_back(modu+'0');
	}
	string k2;
	int length = k1.size();
	for (int i = length; i < L; i++)
		k2.push_back('0');
	for (i = length - 1; i >= 0; i--)
		k2.push_back(k1[i]);
	return k2;
}
void generate_key() {
	int count = 0;
	int i = 1;
	while (count < m) {
		auto result = keys.insert(key_string(i));
		i++;
		if (result.second) {
			count++;
		}
	}
	for (auto v : keys)
		cout << v << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	generate_key();
	return 0;
}