#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		int cnt = 0;
		while (n >= 4) {
			n /= 4;
			cnt++;
		}
		cout << (1ll << cnt) << '\n';	
	}
	return 0;
}
