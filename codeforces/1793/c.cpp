#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left = 0, right = n - 1;

	set<int> s;
	for (int i = 0; i < n; i++) s.insert(arr[i]);

	while (left < right) {
		if (arr[left] == *s.begin() || arr[left] == *s.rbegin()) {
			s.erase(s.find(arr[left]));
			left++;
		} else if (arr[right] == *s.begin() || arr[right] == *s.rbegin()) {
			s.erase(s.find(arr[right]));
			right--;
		} else {
			cout << left + 1 << " " << right + 1 << endl;
			return;
		}
	}
	cout << -1 << endl;




}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}