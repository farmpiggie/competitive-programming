#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') a[i] = -1;
			else a[i] = 1;
		}

		vector<int> suf(n, 0);
		suf[n - 1] = a[n - 1];
		for (int i = n - 2; i > 0; i--) {
			suf[i] = suf[i + 1] + a[i];
		}

		sort(suf.rbegin(), suf.rend()); // descending
		int cnt = 0;
		int idx = 0;
		while (idx < n && cnt < k) {
			cnt += max(0, suf[idx]);
			idx++;
		}
		if (cnt < k) {
			cout << "-1\n";	
		} else {
			cout << idx + 1 << '\n';
		}
	}
}
