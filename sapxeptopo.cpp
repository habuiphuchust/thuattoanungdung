#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
vector<int> visited(MAXN, false);
vector<int> order;
int n, m;

void topo_sort(int u){
	if (visited[u]) return;
	visited[u] = true;
	for (auto v : adj[u]){
		topo_sort(v);
	}
	order.push_back(u);
}

void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[v].push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("topo.txt", "r", stdin);
	input();
	for(int u = 1; u <= n; u++)
		if (!visited[u]) topo_sort(u);
	for(int u : order)
		cout << u << ' ';
	return 0;
}

//neu j phai hoan thanh truoc i thi them 1 canh co huong tu i den j
//khong co trinh tu thoa man neu co chu trinh
/*
10 6
6 4
7 6
9 6
9 7
10 7
5 6
*/
