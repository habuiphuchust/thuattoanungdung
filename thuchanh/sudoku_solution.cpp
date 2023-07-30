#include<bits/stdc++.h>
using namespace std;
const int n = 9;
int c[n+1][n+1];
int solution = 0;

void input() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}

}

bool check(int num, int row, int col) {
	for (int j = 1; j <= n; j++)
		if (num == c[row][j] || num == c[j][col])
			return false;

    int start_row = 3 * (--row / 3)+1;
    int start_col = 3 * (--col / 3)+1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }
	return true;
}

void Try(int a) {
	// tính hàng và cột
	int col = a%n;
	if (col == 0) col = 9;
	int row = (a-col)/n + 1;
	
	if(c[row][col] == 0) {
		for (int i = 1; i <= 9; i++) {
			if(check(i, row, col)) {
				c[row][col] = i;
				if(a == n*n) solution++;
				else Try(a + 1);
				c[row][col] = 0;
			}
		}
		
	} else if (a == n*n) { 
		solution++;
	} else Try(a+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	Try(1);
	cout << solution;
	return 0;
}