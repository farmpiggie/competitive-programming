/* sum of first n elements is always n * (n + 1) / 2.
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 5e5 + 5;

int main() {
	set<ll> squares;
	for (int i = 1; i <= MAXN; i++) {
		squares.insert(1ll * i * i);
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1) {
			cout << "-1\n";
		} else {
			vector<int> a(n);
			iota(a.begin(), a.end(), 1);
			bool works = true;
			ll sum = 0;
			for (int i = 0; i < n - 1; i++) {
				sum += a[i];
				if (squares.count(sum)) {
					sum += a[i + 1];
					swap(a[i], a[i + 1]);
					i++; 
				}
			}
			sum = 0;
			for (int i = 0; i < n; i++) {
				sum += a[i];
				if (squares.count(sum)) {
					works = false;
					break;
				}
			}
			if (works) {
				for (int x : a) cout << x << " ";
				cout << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}
}
