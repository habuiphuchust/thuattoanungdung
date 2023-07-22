#include <bits/stdc++.h>

using namespace std;
const int INF = 200000;
// danh sách kề
struct edge{
	int v;
	int weight;

	edge(int _v, int _w) : v(_v), weight(_w) {}
};

vector<edge> Adj[100];
vector<int> iDist(100, INF); // tạo 100 phần tử value INF
// end là gía trị đích, start là giá trị đầu
// trọng số không âm ExlogV
void Dijkstra(int start, int end) {
	iDist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >,
		greater<pair<int, int> > > PQ;
	PQ.push(make_pair(iDist[start], start));
	while (!PQ.empty()) {
		int u = PQ.top().second;
		if (u == end) break; // nếu tìm hết đỉnh comment
		PQ.pop();
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i].v;
			int w = Adj[u][i].weight;
			if (w + iDist[u] < iDist[v]) {
				iDist[v] = w + iDist[u];
				PQ.push(make_pair(iDist[v], v));
			}
		}
	}
}
// trọng số âm ExV
void Bellman_Ford(int n, int start) {
	iDist[start] = 0;
	for (int i = 1; i < n - 1; i++)
		for (int u = 1; u <= n; u++)
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;
				int w = Adj[u][j].weight;
				iDist[v] = min(iDist[v], w + iDist[u]);
			}
}
int n, m;

void input(){
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		Adj[u].push_back(edge(v, w));
		Adj[v].push_back(edge(u, w));
	}
}
void solve() {
	Dijkstra(1, 7);
//	Bellman_Ford(n, 1);
	for (int i = 1; i <= n; i++) {
		cout << iDist[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}
/*
7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/