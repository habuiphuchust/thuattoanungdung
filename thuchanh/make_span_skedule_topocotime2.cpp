#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10004;
vector<int> adj[MAXN];
vector<int> visited(MAXN, false);
vector<int> order;
int n, m;
int F[MAXN], d[MAXN];

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
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[v].push_back(u);
	}
}

void solve()
{
	memset(F, 0, sizeof(F));
	for(int u = 1; u <= n; u++)
		if (!visited[u]) topo_sort(u);
	int ans = 0;
	for(int u : order)
	{
		for (int v : adj[u])
		{
			F[u] = max(F[u], F[v] + d[v]);
		}
		ans = max(ans, F[u] + d[u]);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	solve();

	return 0;
}

//neu j phai hoan thanh truoc i thi them 1 canh co huong tu i den j
//khong co trinh tu thoa man neu co chu trinh
