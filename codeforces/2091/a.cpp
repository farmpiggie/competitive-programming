#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(10);
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cnt[a[i]]++;
			if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1) {
				ans = i + 1;
				break;
			}
		}
		cout << ans << '\n';
	}
}

