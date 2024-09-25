#include <bits/stdc++.h>
using namespace std;

#define ll long long

void run() {
	ll n; cin >> n;
	cout << (1ll << (ll) log2(n)) << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
 	return 0;
}