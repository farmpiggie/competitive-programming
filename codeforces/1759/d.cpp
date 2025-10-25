#include <bits/stdc++.h>
using namespace std;

int main() {
	// ifstream cin("makeitround.in");
	int t; cin >> t;
	while (t--) {
		long long n, m;
		cin >> n >> m; 
		long long n0 = n;
		
		long long k = 1;
		int cnt_2 = 0;
		while (n > 0 && n % 2 == 0) {
			cnt_2++;
			n /= 2;
		}
		int cnt_5 = 0;
		while (n > 0 && n % 5 == 0) {
			cnt_5++;
			n /= 5;
		}

		while (cnt_2 < cnt_5 && k * 2 <= m) {
			cnt_2++;
			k *= 2;
		}

		while (cnt_5 < cnt_2 && k * 5 <= m) {
			cnt_5++;
			k *= 5;
		}

		while (k * 10 <= m) {
			k *= 10;
		}
		if (k == 1) cout << n0 * m << endl;
		else {
			k *= (m / k);
			cout << n0 * k << endl;
		}
	
	}
}