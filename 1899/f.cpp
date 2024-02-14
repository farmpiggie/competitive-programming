#include <bits/stdc++.h>
using namespace std;

const int Q = 1e3 + 5;

int t, n, q, a[Q];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		cout << i - 1 << " " << i << '\n';
	}

	vector<int> b1, b2;
	for (int i = 0; i < n; i++) {
		b1.push_back(i);
	}
	b2.push_back(1);

	for (int i = 0; i < q; i++) {
		int d = a[i];
		d++;

		// cout << b1.size() << " " << d << endl;
		if (b1.size() == d) {
			cout << "-1 -1 -1\n";
		} else if (b1.size() < d) {
			d = d - ((int) b1.size());
			vector<int> qq(b2.end() - d, b2.end());

			int u = b2[b2.size() - d];
			int v1 = b2[b2.size() - d - 1];
			int v2 = b1.back();

			cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
			for (int i = 0; i < d; i++) 
				b2.pop_back();
			for (auto i : qq) 
				b1.push_back(i);
		} else {
			d = (int) b1.size() - d;
			vector<int> qq(b1.end() - d, b1.end());

			int u = b1[b1.size() - d];
			int v1 = b1[b1.size() - d - 1];
			int v2 = b2.back();

			cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
			for (int i = 0; i < d; i++) 
				b1.pop_back();
			for (auto i : qq) 
				b2.push_back(i);
		}
	}


}

int main() {
	cin >> t;
	while (t--) solve();

	return 0;
}