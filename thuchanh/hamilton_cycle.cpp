#include <bits/stdc++.h>
using namespace std;
const int MAX = 10004;
int n, m;
int visit;
vector<int> adj[MAX];
bool visited[MAX];
bool flag;

void input() {
	flag = false;
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
}

void dfs(int u) {
	visited[u] = true;
	visit++;
//	cout << u << ": "<<visit << endl;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	if(visit == n) {
		if (find(adj[u].begin(), adj[u].end(), 1) != adj[u].end()) {
			flag = true;
			memset(visited, true, sizeof(visited));
			return;
		}
			
	}
	visit--;
	if(!flag) visited[u] = false;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		dfs(1);
		cout << flag << endl;
	}
	return 0;
}