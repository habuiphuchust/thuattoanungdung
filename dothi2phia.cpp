#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1000];
vector<int> iSide(1001, -1);
bool is_bipartite = true;
int n, m;
// 2 đỉnh kề nhau thì nằm ở 2 phía, nếu cùng phía thì
// ko phải đt 2 phía

void Check_Bipartite(int u) {
	for (int v : Adj[u]) {
		if (iSide[v] == -1) {
			iSide[v] = 1 - iSide[u];
			Check_Bipartite(v);
		} else if (iSide[u] == iSide[v]) {
			is_bipartite = false;
		}
	}
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	for (int u = 1; u <= n; u++) {
		if (iSide[u] == -1) {
			iSide[u] = 0;
			Check_Bipartite(u);
		}
	}
	cout << is_bipartite;
	return 0;
} 