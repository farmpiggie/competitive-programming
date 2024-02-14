#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int t, n, a[N]; ll ans;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	stack<int> rightmost;
	set<int> seen;
	for (int i = n - 1, u; i >= 0; i--) {
		u = a[i];
		if (seen.find(u) == seen.end()) {
			seen.insert(u);
			rightmost.push(i);
		}
	}
	ans = 0;
	set<int> seen2;
	for (int i = 0, u; i < n; i++) {
		u = a[i];
		while (!rightmost.empty() && rightmost.top() < i) 
			rightmost.pop();
		if (seen2.find(u) == seen2.end()) {
			seen2.insert(u);
			ans += rightmost.size();
		}
	}
	cout << ans << '\n';
} 

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}