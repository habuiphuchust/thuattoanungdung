#include <bits/stdc++.h>

using namespace std;
// cấu trúc cạnh
struct edge{
	int u, v; // cạnh u sang v, trọng lượng weight
	int weight;

	edge(int _u, int _v, int _w) : u(_u), v(_v), weight(_w) {}
};
// cấu trúc union find
struct Union_Find{
	vector<int> parent;
	Union_Find(int n){
		parent = vector<int>(n);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
// tìm vùng chứa x
	int Find(int x){
		if (parent[x] == x)
			return x;
		else {
			parent[x] = Find(parent[x]);
			return parent[x];
		}
	}
// hợp 2 vùng chứa x và y
	void Unite(int x, int y){
		parent[Find(x)] = Find(y);
	}
};
// tự viết hàm so sánh 2 cạnh
bool Edge_Cmp(const edge &a, const edge &b){
	return a.weight < b.weight;
}
// tìm cây khung nhỏ nhất
vector<edge> MST(int n, vector<edge> edges){
	Union_Find uf(n);
	// sắp xếp tăng dần weight
	sort(edges.begin(), edges.end(), Edge_Cmp);
	vector<edge> res;

	for(auto e : edges){
		int u = e.u;
		int v = e.v;
		if (uf.Find(u) != uf.Find(v)){
			uf.Unite(u, v);
			res.push_back(e);
		}
	}
	return res;
}

vector<edge> edges, res;
int n, m;

void input(){
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
	}
}

int main(){
//	freopen("kruskal.txt", "r", stdin);
	input();
	res = MST(n, edges);
	for (auto e : res)
		cout << e.u << ' ' << e.v << ' ' << e.weight << endl;
	return 0;
}
//input
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

