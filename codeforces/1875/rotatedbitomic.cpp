#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 2) {
		cout << min(arr[0], arr[1]) << "\n";
		return 0;
	}

	// binary search on pivot
	// want to find pivot such that arr[0] < arr[1] and arr[n - 2] > arr[n - 1]
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
	}

	return 0;
}