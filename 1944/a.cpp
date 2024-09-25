#include <bits/stdc++.h>
using namespace std;

void run() {
	int n, k; cin >> n >> k;
	if (k < n - 1) cout << n << '\n';
	else cout << "1\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
}