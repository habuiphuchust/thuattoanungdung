#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, m, curnum = 0;
vector<int> adj[MAXN];
vector<int> Low(MAXN), Num(MAXN, -1);
vector<bool> connect(MAXN, false);
stack<int> cc_stack;
// tìm tp liên thông mạnh
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
		cout << "TPLT: ";
		while (1){
			int v = cc_stack.top();
			cc_stack.pop();
			cout << v << ' ';
			connect[v] = false;
			if (v == u) break;
		}
        cout << endl;
	}
}
// đồ thị có hướng
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
	return 0;
}
//Sau quá trình phân tích cây tại đỉnhumàLow[u]=Num[u]thì ta tìmđược một thành phần liên thông mạnh theo quá trình duyệt cây từuSử dụng mảngbConnect[]dùng để kiểm tra xem đỉnhvcó còn được“kết nối” trong đồ thị hay không ? Nếu phát hiện ra một thành phầnliên thông mạnh, và một đỉnhvcó trong thành phần liên thông mạnhđó, thì ta loại đỉnhvnày ra khỏi đồ thị bằng câu lệnhbConnect[v]= 0, điều này là quan trọng vì để tránh gây ảnh hưởng đến việc tínhmảngLow[]của những đỉnh khác vẫn còn nằm trong đồ thị
/*
11 15
1 2
2 3
3 1
3 4
4 6
5 8
6 5
6 7
6 9
7 10
7 9
8 11
9 4
11 5
7 11
*/