#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 0);
    dp[0] = a[0];

    for (int i = 1; i < n; i++) {
        int max_gold = 0;
        for (int j = max(0, i - L2); j <= i - L1; j++) {
            max_gold = max(max_gold, dp[j]);
        }
        dp[i] = max_gold + a[i];
    }

    int max_total_gold = *max_element(dp.begin(), dp.end());
    cout << max_total_gold << endl;

    return 0;
}
// 3/6 teskey
//Problem: Gold Mining
//Description
//
//The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. The warehouse i has amount of a
//i
// (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.
//Input
//Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
//Line 2 contains n integers a
//1
//,a
//2
//,…,a
//n
//Output
//Contains only one single integer denoting the total amount of golds of selected warehouses.
//Example
//Input
//6 2 3
//3 5 9 6 7 4
//
//Output
//19