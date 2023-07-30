#include <bits/stdc++.h>
using namespace std;
string a, b;
const int MAX = 100000004;
int MUL[MAX];

void multiply() {
	int begin = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		int idx = begin++;
		int remember = 0;
		for (int j = a.size() - 1; j >= 0; j--) {
			int mul = (b[i]-'0') * (a[j]-'0') 
				+ remember + MUL[idx];
			MUL[idx] = mul % 10;
			remember = mul / 10;
			idx++;
		}
		MUL[idx] = remember;
	}
}

void out() {
	int nums = 0;
	for (int i = a.size()*b.size(); i >= 0; i--) {
		if (MUL[i] != 0) {
			nums = i;
			break;
		};
	}
//	cout << nums << endl;
	for (int i = nums; i >=0; i--)
		cout << MUL[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	memset(MUL, 0, sizeof(MUL));
	multiply();
	out();
	
	return 0;
}