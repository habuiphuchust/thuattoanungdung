#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
bool visited[MAX][MAX];
int dis[MAX][MAX];
int a, b, c;

//pair<int, int> pour_a(pair<int, int> x) {
//	return {a, x.second};
//}
//pair<int, int> pour_b(pair<int, int> x) {
//	return {x.first, b};
//}
//pair<int, int> atob(pair<int, int> x) {
//	int mi = min(x.first, b-x.second);
//	return {x.first - mi, x.second + mi};
//}
//pair<int, int> btoa(pair<int, int> x) {
//	int mi = min(x.second, a-x.first);
//	return {x.first + mi, x.second - mi};
//}
//pair<int, int> empty_a(pair<int, int> x) {
//	return {0, x.second};
//}
//pair<int, int> empty_b(pair<int, int> x) {
//	return {x.first, 0};
//}
vector<pair<int, int>> adj(pair<int, int> x) {
	vector<pair<int, int>> adjacent;
	adjacent.push_back({a, x.second});
	adjacent.push_back({x.first, b});
	int miatob = min(x.first, b-x.second);
	adjacent.push_back({x.first - miatob, x.second + miatob});
	int mibtoa = min(x.second, a-x.first);
	adjacent.push_back({x.first + mibtoa, x.second - mibtoa});
	adjacent.push_back({0, x.second});
	adjacent.push_back({x.first, 0});
	return adjacent;
}
	

int pour() {
	queue<pair<int, int>> sequence;
	sequence.push({0, 0});
	visited[0][0] = true;
	dis[0][0] = 0;
	while (!sequence.empty()) {
		pair<int, int> x = sequence.front();
		sequence.pop();
		for (auto v : adj(x)) {
			if(!visited[v.first][v.second]) {
				visited[v.first][v.second] = true;
				cout << v.first << " " << v.second<<endl;
				dis[v.first][v.second] = 
				dis[x.first][x.second] + 1;
				sequence.push(v);
				if (v.first == c || v.second == c) 	
					return dis[v.first][v.second];
			}

		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(visited, false, sizeof(visited));
	cin >> a >> b >> c;
	cout << pour();
	return 0;
}