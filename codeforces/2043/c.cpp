#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		long long ll = 0, lr = 0;
		long long cll = 0, clr = 0;
		for (int i = 0; i < n; i++) {
			if (abs(a[i]) != 1) break;
			cll = min(0ll, cll + a[i]); // never goes above zero
			clr = max(0ll, clr + a[i]); // never goes below zero
		//	cout << "cll and clr: " << cll << " " << clr << '\n';
			ll = min(ll, cll);
			lr = max(lr, clr);
		}

		long long rl = 0, rr = 0;
		long long crl = 0, crr = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (abs(a[i]) != 1) break;
			crl = min(0ll, crl + a[i]);
			crr = max(0ll, crr + a[i]);
			rl = min(rl, crl);
			rr = max(rr, crr);
		}

		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (abs(a[i]) != 1) {
				idx = i;
				break;
			}
		}
		//cout << "idx: " << idx << '\n';

		if (idx == -1) {
			cout << (rr - rl + 1) << '\n';
			for (long long i = rl; i <= rr; i++) {
				cout << i << " ";
			}
			cout << '\n';
			continue;
		}

		// interval
		long long o_l = cll + crl; 
		long long o_r = clr + crr;   
	       	o_l += a[idx];
		o_r += a[idx];

		long long l = min(ll, rl);
		long long r = max(lr, rr);
		//cout << "l and r: " << '\n';
		//cout << l << " " << r << '\n';
		//cout << "o_l and o_r: " << o_l << " " << o_r << '\n';
		// check overlap between o_l, o_r
		if (o_l <= r && l <= o_r) {
			long long x = min(l, o_l);
			long long y = max(r, o_r);
			cout << y - x + 1 << '\n';
			for (long long i = x; i <= y; i++) {
				cout << i << " ";
			}
			cout << '\n';
		} else {
			cout << (o_r - o_l + 1) + (r - l + 1) << '\n';
			if (l < o_l) {
				for (long long i = l; i <= r; i++) {
					cout << i << " ";
				}
				for (long long i = o_l; i <= o_r; i++) {
					cout << i << " ";
				} 
				cout << '\n';
			} else {
				for (long long i = o_l; i <= o_r; i++) {
					cout << i << " ";
				} 
				for (long long i = l; i <= r; i++) {
					cout << i << " ";
				}
				cout << '\n';
			}
		}
	}
	return 0;
}
				

			
			

