#include<bits/stdc++.h>
using namespace std;
int N;
const int MAX = 20;
const int INF = 100000000;
int C[MAX][MAX];
int iMem[MAX][1<<MAX];

int TSP(int i, int S) {
	if (S == ((1 << N) - 1)) 
	{
		iMem[i][S] = C[i][0];
		return C[i][0];
	}
	if (iMem[i][S] != -1) return iMem[i][S];

	int res = INF;
	for (int j = 0; j < N; j++) {
		if (S & (1 << j))
			continue;
		res = min(res, C[i][j] + TSP(j, S | (1 << j)));
	}
	iMem[i][S] = res;
	return res;
}

// truy vet
void Trace(int i, int S) {
	cout << i << " ";
	if (S == ((1 << N) - 1)) return;
	
	int res = iMem[i][S];
	for (int j = 0; j < N; j++) {
		if (S & (1 << j))
			continue;
		if (res == C[i][j] + iMem[j][S | (1 << j)]) {
			Trace(j, S | (1 << j));
			break;
		}
	}


}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> C[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	memset(iMem, -1, sizeof(iMem));
	// đang ở đỉnh 0 và đã thăm 1 đỉnh 0;
	cout << TSP(0, 1<<0) << endl;
	Trace(0, 1<<0);
	return 0;
}

/*
5
 0   10  15  20  25
 10  0   35  25  30
 15  35  0   30  40
  20  25  30  0   50
  25  30  40  50  0
*/