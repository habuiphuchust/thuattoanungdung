#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int INF = 20000;
vector<int> adj[MAXN];
vector<int> newadj[MAXN];
int dist[MAXN][MAXN];
int iDist[MAXN] = {20000};
int C[MAXN];
int D[MAXN];
queue<int> q;
stack<int> stk;
int n, m;




void add_new_adj(int a, int di){
	q.push(a);
	dist[a][a] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(dist[v][a] == -1){
				dist[v][a] = dist[u][a] + 1;
				if(dist[v][a] > di)
					break;
				newadj[a].push_back(v);
				q.push(v);
			}
		}
	}
}

void Dijkstra(int start)
{
	iDist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >,
		greater<pair<int, int> > > PQ;
	PQ.push(make_pair(iDist[start], start));
	while (!PQ.empty()) {
		int u = PQ.top().second;
		PQ.pop();
		for (auto v : newadj[u])
		{
			int w = C[u];
			if ( w + iDist[u] < iDist[v]) 
			{
				iDist[v] = w + iDist[u];
				PQ.push(make_pair(iDist[v], v));
			}
		}
	}
}


void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		iDist[i] = 20000;
		for (int j = 1; j <= n; j ++)
		{
			dist[i][j] = -1;
		}
	}
	int u, v;
	for(int i = 1; i <= n; i++){
		cin >> C[i] >> D[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void solve()
{
	for (int i = 1; i < n; i++)
	{
		add_new_adj(i, D[i]);
	}
//	for (int i = 1; i <n; i ++)
//	{	
//		cout << i<<": " ;
//		for (auto v : newadj[i])
//		{
//			cout << v<< " ";
//		}
//		cout << endl;
//	}
	Dijkstra(1);
//	for (int i = 1; i <= n; i++) {
//		cout << iDist[i] << " ";
//	}
	cout << iDist[n];
}
int main(){
	freopen("innercity.txt", "r", stdin);
	input();
	solve();
	return 0;
}
//Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
//Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
//Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất