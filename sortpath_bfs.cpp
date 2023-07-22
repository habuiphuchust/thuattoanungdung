#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
vector<int> dist(MAXN, -1);
vector<int> parent(MAXN, -1);
queue<int> q;
stack<int> stk;
int n, m;

void trace(int u){
	if (u == -1) return;
	trace(parent[u]);
	cout << u << " --> ";
}

void display_shortest_path(int a, int b){
	trace(b);
}
// tìm cầu, a là đỉnh đầu b là đỉnh cuối; hàm trả về kc
int find_shortest_path(int a, int b){
	q.push(a);
	dist[a] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(dist[v] == -1){
				q.push(v);
				parent[v] = u;
				dist[v] = dist[u] + 1;
			}
		}
	}
	display_shortest_path(a, b);
	return dist[b];
}

// đồ thị có hướng
void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

int main(){
	freopen("sortpath.txt", "r", stdin);
	input();
	find_shortest_path(1, 10);
	cout << endl << dist[10];
//	cout << find_shortest_path(1, 10) << endl;
	return 0;
}
/*
11 17
1 2
1 3
2 5
3 2
3 4
4 1
5 6
6 3
6 4
6 9
6 7
6 8
7 8
7 9
8 11
9 10
10 9
*/