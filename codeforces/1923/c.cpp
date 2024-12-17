#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>


int main() {
	send help
	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<int> cnt(n, 0);
		vector<ll> psum(n, 0);
		cnt[0] = (arr[0] == 1);
		psum[0] = arr[0];
		for (int i = 1; i < n; i++) {
			cnt[i] = cnt[i - 1] + (arr[i] == 1);
			psum[i] = psum[i - 1] + arr[i];
		}

		for (int i = 0; i < q; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			int len = (b - a + 1);
			int occ = cnt[b];
			ll sum = psum[b];
			if (a - 1 >= 0) {
				occ -= cnt[a - 1];
				sum -= psum[a - 1];
			}
			if (len == 1 || (occ * 2 > len && sum - occ - (len - occ) < occ)) {
				cout << "NO\n";
			} else {
				cout << "YES\n"; 
			}
		}

	}
	return 0;
}