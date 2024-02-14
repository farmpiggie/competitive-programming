#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

typedef long long ll;

int t, n;
ll m[MAXN][MAXN], a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		a[i] = (1ll << 30) - 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			a[i] &= m[i][j];
			a[j] &= m[i][j];
		}
	}

	bool works = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((a[i] | a[j]) != m[i][j]) {
				works = false;
			}
		}
	}

	if (works) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "No\n";
	}


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}