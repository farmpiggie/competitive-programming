// if there is one coin only, alice wins if it is face up. otherwise bob wins
// if there are two coins, alice wins if one is face up and the other is not. otherwise, bob wins
// if there are three coins, alice wins if one or three coins are face up. otherwise, bob wins
// if there are four coins, alice wants to flip it such that after the move, there are two coins face up. therefore, there must be only one coin face up, or three coins face up

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			if (c == 'U') cnt++;
		}
		if (cnt % 2 == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
