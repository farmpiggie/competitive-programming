#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 300005

int n, a[MAXN] = {}, d[MAXN] = {};

 
void solve() { 
 
	cin >> n;
	a[0] = a[n + 1] = 0;
	d[0] = d[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
 
	set<int> alive, candidates;

	for (int i = 0; i < n + 2; i++) {
		alive.insert(i);
		candidates.insert(i);
	}

	for (int i = 0; i < n; i++) {
		set<int> dead, new_candidates;
		for (int j : candidates) {
			auto it = alive.find(j);
			if (it == alive.end()) continue;
			int prv = *prev(it);
			int nxt = *next(it);
			if (a[prv] + a[nxt] > d[j]) {
				dead.insert(j);
				new_candidates.insert(prv);
				new_candidates.insert(nxt);
			}
		}
		cout << dead.size() << ' ';
		for (auto it : dead) alive.erase(it);
		candidates = new_candidates;
	}

	cout << '\n';
 
 
}
 
int main() {
	int t; cin >> t;
	while (t--) solve();
}
 