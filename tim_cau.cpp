#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n, m, curnum = 0;
vector<int> adj[MAXN];
vector<int> Low(MAXN), Num(MAXN, -1);
vector<pair<int, int> > bridges_list;
// tìm cầu
void find_bridges(int u, int p){
	Low[u] = Num[u] = ++curnum;
	for(int v: adj[u]){
		if (v == p) continue;
		if (Num[v] == -1){
			find_bridges(v, u);
			Low[u] = min(Low[v], Low[u]);
		}
		else {
			Low[u] = min(Low[u], Num[v]);
		}
		if (Low[v] > Num[u])
			bridges_list.push_back(make_pair(u,v));
	}
}
// đồ thị vô hướng
void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("timcau.txt", "r", stdin);
	input();
	for(int u = 1; u <= n; u++){
		if (Num[u] == -1) find_bridges(u, -1);
	}

	cout << "Danh sach cac canh cau: " << endl;
	for(auto e: bridges_list){
		cout << e.first << ' ' << e.second << endl; 
	}
	//Low[i] chinh la thanh phan lien thong khi xoa cau
	
	return 0;
}
/*
11 14
1 2
1 3
2 3
3 4
4 6
4 9
5 6
5 11
5 8
6 7
6 9
7 9
7 10
8 11
*/