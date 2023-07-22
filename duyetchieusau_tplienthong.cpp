#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
vector<int> adj[MAXN];
vector<int> compIdx(MAXN, -1);
int m, n;
void FindComp(int cur_comp, int u){
	if(compIdx[u] != -1) return;
	compIdx[u] = cur_comp;

	for(int v : adj[u]){
		FindComp(cur_comp, v);
	}
}
// đồ thị vô hướng
void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	int cur_comp = 0;
	// tim thanh phan lien thong
	for(int u = 1; u <= n; u++){
		if(compIdx[u] == -1){
			FindComp(cur_comp, u);
			cur_comp++;
		}
	}
// so hieu thanh phan lien thong cua cac dinh
	for(int u = 1; u <= n; u++)
		cout << compIdx[u] << ' ';

	cout <<"\nSo luong TPLT: " << cur_comp << endl;

	return 0;
}
/*
7 5
1 4
4 7
3 5
5 6
3 6
*/

