#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n, a[MAXN], l[MAXN], r[MAXN], in[MAXN];

bool valid(int i) {
	if (i < 1 || i > n) return 0;
	else return a[l[i]] == a[i] - 1 || a[r[i]] == a[i] - 1;
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
		in[i] = 0;
		cin >> a[i];
	}
	
	a[0] = a[n + 1] = -2; // cannot match with 0

	auto cmp = [&a](int i, int j) {
		return a[i] < a[j];
	};

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	for (int i = 1; i <= n; i++) {
		if (valid(i)) {
			in[i] = 1;
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int i = pq.top(); pq.pop();
		r[l[i]] = r[i];
		l[r[i]] = l[i];
		if (!in[l[i]] && valid(l[i])) {
			in[l[i]] = 1;
			pq.push(l[i]);
		}
		if (!in[r[i]] && valid(r[i])) {
			in[r[i]] = 1;
			pq.push(r[i]);
		}
	}

	int bad = 0;
	int mn = n;
	for (int i = 1; i <= n; i++) {
		bad += !in[i];
		mn = min(mn, a[i]);
	}

	if (bad == 1 && mn == 0) {
		cout << "YES\n"; 
	} else {
		cout << "NO\n";
	}

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}