// should go like 1 ..... 
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		vector<int> a(32);
		for (int i = 0; i < 30; i++) {
			a[i] = (x >> i) & 1; // LSB
		}
		for (int i = 1; i < 31; i++) {
			if (a[i] > 1) {
				a[i] -= 2;
				a[i + 1]++;
			}
			if (a[i] == 1 && a[i - 1] == 1) {
				a[i - 1] = -1;
				a[i] = 0;
				a[i + 1]++;
			}
		}
		cout << "32\n";
		for (int& x : a) cout << x << " ";
		cout << '\n';

	}
}
