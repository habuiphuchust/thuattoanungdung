#include <bits/stdc++.h>
using namespace std;
const int MAX = 10004;
int n;
vector<pair<int, int>> adj[MAX];
int visited[MAX];

void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
}
void dfs(int u) {
	visited[u] = 0;
	for (auto v : adj[u]) {
		if (visited[v.first] == -1) {
			dfs(v.first);
			visited[u] = max(visited[u], visited[v.first] + v.second);
		}
	}
}

void solve() {
	dfs(1);
	priority_queue<int> peak;
	for (auto v : adj[1]) {
		peak.push(visited[v.first] + v.second);
	}
	if (peak.size() == 1) {
		cout << peak.top();
	} else {
		int temp = peak.top();
		peak.pop();
		cout << peak.top() + temp;
	}
	
	 
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(visited, -1, sizeof(visited));
	input();
	solve();
//	for (int i = 1; i <= n; i++)
//		cout << visited[i] << " ";
	return 0;
}