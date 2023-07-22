#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
vector<int> visited(MAXN, false);
vector<int> order;
int d[MAXN];
int times[MAXN] = {0};
int n, m;

int topo_sort(int u){
	int t = 0;
	for (auto v : adj[u]){
		if (times[v] > 0)
			t = max(times[v], t);
		else
			t = max(topo_sort(v), t);
	}
	times[u] = t + d[u];
	return times[u];
}

void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[v].push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	for(int u = 1; u <= n; u++)
		if (times[u] == 0) topo_sort(u);
	int ans = 0;
	for(int u = 1; u <= n; u++)
		ans = max(ans, times[u]);
	cout << ans;
	return 0;
}

//neu j phai hoan thanh truoc i thi them 1 canh co huong tu i den j
//khong co trinh tu thoa man neu co chu trinh
