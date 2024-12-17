#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

void run() {
	int n, k; cin >> n >> k;
	vector<int> arr(2 * n);
	for (int& x : arr) {
		cin >> x;
		x--;
	}	


	vector<pii> occ(n, {-1, -1});
	for (int i = 0; i < 2 * n; i++) {
		if (occ[arr[i]].f == -1) {
			occ[arr[i]].f = i;
		} else if (occ[arr[i]].s == -1) {
			occ[arr[i]].s = i;
		}
	}

	// cout << "----\n";
	// for (pii& p : occ) {
	// 	cout << p.first << " " << p.second << '\n';
	// }
	// cout << "----\n";

	
	vector<pii> leftSame, rightSame; //
	vector<pii> diff;

	for (int i = 0; i < n; i++) {
		if (occ[i].f < n && occ[i].s < n) {
			leftSame.push_back(occ[i]);
		} else if (occ[i].f >= n && occ[i].s >= n){
			rightSame.push_back(occ[i]);
		} else {
			diff.push_back(occ[i]);
		}
	}

	vector<int> left, right;
	int j = 0;
	int l = 0;
	for (int i = 0; i < k; i++) {
		if (j < min(leftSame.size(), rightSame.size())) {
			left.push_back(arr[leftSame[i].f]);
			left.push_back(arr[leftSame[i].s]);
			right.push_back(arr[rightSame[i].f]);
			right.push_back(arr[rightSame[i].s]);
			j++;
		} else {
			left.push_back(arr[diff[l].f]);
			right.push_back(arr[diff[l].s]);
			left.push_back(arr[diff[l + 1].f]);
			right.push_back(arr[diff[l + 1].s]);
			l += 2;
		}
	}

	for (int num : left) cout << num + 1 << " ";
	cout << '\n';
	for (int num : right) cout << num + 1 << " ";
	cout << '\n';

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
}