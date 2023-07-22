#include <bits/stdc++.h>

#define maxn 1000006

using namespace std;


int const MOD = 1e9+7;


int n, a[maxn];


int temp[maxn];
// Hàm hp nht 2 mng và tr v s lung cp nghch do khi hp nht.



int _merge(int left, int mid, int right)

{
	

	int i = left, j = mid + 1, k = left, inv_count = 0;
	

	while ((i <= mid) && (j <= right)) {
		

		if (a[i] <= a[j])   temp[k++] = a[i++];
		

		else {
			

			temp[k++] = a[j++];
			

			inv_count = (inv_count + (mid - i + 1)) % MOD;
			

		}

	}

	// Copy nhng phn t còn li ca na bên trái (nu còn) vào mng trung gian

	while (i <= mid) temp[k++] = a[i++];
	

	// Copy nhng phn t còn li ca na bên phi (nu còn) vào mng trung gian

	while (j <= right) temp[k++] = a[j++];
	

	// Copy nhng phn t dã duc hp nht vào mng gc

	for (i = left; i <= right; i++)     a[i] = temp[i];
	

	return inv_count;
	

}
// An recursive function that sorts the input array and returns the number of inversions in the array.



int mergeSort (int left, int right) {
	

	int mid, inv_count = 0;
	

	if (right > left) {
		

		// Divide the array into two parts and call mergeSort() for each of the parts

		mid = (right + left) / 2;
		

		// Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging

		inv_count = (inv_count + mergeSort(left, mid)) % MOD;
		

		inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
		

		inv_count = (inv_count + _merge(left, mid, right))% MOD;
		

	}

	return inv_count;
	

}



int main() {
	

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> n;
	

	for (int i=1; i<=n; i++)     cin >> a[i];
	

	cout << mergeSort(1, n);
	

	return 0;
	

}