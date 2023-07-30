#include <bits/stdc++.h> 
using namespace std;
const int MAX = 10000;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int p, q; 
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end()); 
	}
}
void DFS(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]) {
		if(!visited[v]) {
			DFS(v);
		}
	}
} 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	memset(visited, false, sizeof(visited));
	DFS(1);
	for (int i = 1; i <= n; i++)
		if(!visited[i]) 
			DFS(i);
	
	return 0;
}