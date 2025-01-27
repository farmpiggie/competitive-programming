#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		ll evensum = 0, oddsum= 0;
		for (int i = 0; i < n; i++) {
			if (i % 2) oddsum += a[i];
			else evensum += a[i];
		}
		int even = (n + 1) / 2;
		int odd = n - even;
		bool works = (evensum % even == 0 && oddsum % odd == 0 && evensum / even == oddsum / odd);
		cout << (works ? "YES" : "NO") << '\n';	
	}	
}



