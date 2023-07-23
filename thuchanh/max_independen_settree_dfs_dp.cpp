#include <bits/stdc++.h>
using namespace std;
const int MAX = 100004;
int n, m;
int w[MAX];
int dp[MAX][2];
int weight = 0;
int sum = 0;
vector<int> adj[MAX];
bool check[MAX];

/*dp[i][0]: tổng trọng số lớn nhất của tập S trong
cây con của đỉnh i khi đỉnh i không được chọn
  dp[i][1]: đỉnh i được chọn
  dp[i][0] = sum(max(dp[child][0], dp[child][1])) đỉnh con child của i
  dp[i][1] = weigh[i] + sum(dp[child][0])
*/
void dfs(int node, int parent)
{
	for (int con : adj[node])
	{
		if (con == parent)
			continue;
		dfs(con, node);
		// duyệt xong đỉnh con, out ra
		dp[node][0] += max(dp[con][0], dp[con][1]);
		dp[node][1] += dp[con][0];
	}
	// duyệt xong hết đỉnh con
	dp[node][1] += w[node];
}



void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp, 0, sizeof(dp));
	input();
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}