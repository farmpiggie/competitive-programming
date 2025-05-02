#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3200; // sqrt(1e7)

int main() {
	vector<int> primes, marked(MAXN, 0);
	for (int i = 2; i < MAXN; i++) {
		if (!marked[i]) {
			primes.push_back(i);
			for (int j = i; j < MAXN; j += i) {
				marked[j] = 1;
			}
		}
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n, 1);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			for (int p : primes) {
				int cnt = 0;
				while (x % p == 0) {
					x /= p;
					cnt++;
				}
				if (cnt & 1) {
					a[i] *= p;
				}
			}
			if (x > 1) a[i] *= x;
		}

		set<int> s;
		int ans = 1;
		for (int x : a) {
			if (s.count(x)) {
				ans++;
				s = {};
			}
			s.insert(x);
		}
		cout << ans << '\n';
	}
}



