#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		sort(a.rbegin(), a.rend());
		
		ll diff = 0;
		int i = 0;
		while (i < n && diff + a[i] <= k) {
			diff += a[i];
			i++;	
		}

		cout << k - diff << '\n';	
	}
}
