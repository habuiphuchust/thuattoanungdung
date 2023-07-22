#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100004;
int n, m, curnum = 0;
vector<int> adj[MAXN];
vector<int> Low(MAXN), Num(MAXN, -1);
vector<bool> connect(MAXN, false);
stack<int> cc_stack;
int ans = 0;

void find_scc(int u){
	// cout << u << endl;
	cc_stack.push(u);
	connect[u] = true;
	Low[u] = Num[u] = ++curnum;
	for(auto v: adj[u]){
		if(Num[v] == -1){
			find_scc(v);
			Low[u] = min(Low[u], Low[v]);
		} else if (connect[v]) {
			Low[u] = min(Low[u], Num[v]);
		}
	}

	if (Low[u] == Num[u]){
		while (1){
			int v = cc_stack.top();
			cc_stack.pop();
			connect[v] = false;
			if (v == u) break;
		}
		ans++;
	}
}

void input(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		// adj[v].push_back(u);
	}
    // cout << n << m << endl;
}

int main(){
	input();
	for(int u = 1; u <= n; u++)
		if (Num[u] == -1) find_scc(u);
	cout << ans;
	return 0;
}
