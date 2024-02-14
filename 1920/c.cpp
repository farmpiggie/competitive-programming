#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t, n, a[MAXN];

void solve() {
	cin >> n;
	set<int> divisors;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			divisors.insert(i);
			divisors.insert(n / i);
		}
	}

	int ans = 1;

	for (int divisor : divisors) {
		if (divisor == n) continue;
		// cout << "trying partition of size: " << divisor << '\n';
		

		vector<int> diff_gcd(divisor, -1);
		for (int i = divisor; i < n; i++) {
			if (diff_gcd[i % divisor] == -1) {
				diff_gcd[i % divisor] = abs(a[i] - a[i - divisor]);
			} else {
				diff_gcd[i % divisor] = gcd(diff_gcd[i % divisor], abs(a[i] - a[i - divisor]));
			}
		}
		// for (int num : diff_gcd) {
		// 	cout << num << ' ';
		// }
		// cout << '\n';
		
		int main_gcd = diff_gcd[0];
		for (int num : diff_gcd) {
			main_gcd = gcd(main_gcd, num);
		}
		if (main_gcd > 1 || main_gcd == 0) ans++;
		// cout << "main gcd: " << main_gcd << '\n';

		
	}

	cout << ans << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}