#include<bits/stdc++.h>
using namespace std;
const int MAX = 1004;
int c[MAX][MAX];
int route[MAX];
int sum = 0;
int retun; // đường đi từ route[n] quay lại route[1]
int n, m;
// ý tưởng: nếu điều kiện tiên quyết 1 4 thì 
// c[4][1] = -1; xét phần tử i trong route, nếu 
// phần tử i+1 -> n mà đường bị chặn = -1 thì false
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> route[i];
	};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> c[i][j];
	retun = c[route[n]][route[1]];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int p, q;
		cin >> p >> q;
		c[q][p] = -1;
	}
	
//		for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) 
//			cout << c[i][j];
}
bool solve() {	
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// nếu bị chặn
			if (c[route[i]][route[j]] == -1)
				return false;
		}
	}


	for (int i = 2; i <= n; i++)
		if (c[route[i-1]][route[i]] == 0) return false;
		else sum += c[route[i-1]][route[i]];
	if (retun == 0) return false;
	else sum += retun;
	
	return true;
	
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(c, 0, sizeof(c));
	input();
	if (solve()) cout << sum;
	else cout << -1;
    return 0;
}

//4
//2 3 4 1
//0 2 4 3
//3 0 1 1
//2 3 0 5
//1 3 2 0
//3
//1 2
//3 4
//1 4