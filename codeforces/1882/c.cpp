// if positive number is at odd position, we take it starting from the back
// after the first "good" position, we can sum all values after it
// for all positions where 
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>
#define ll long long

//dp[i][0/1] = max value given we have taken a parity of j elements
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		ll sum = 0;
		for (int& x : a) {
			cin >> x;
			sum += max(0, x);
		}
		if (n >= 2 && a[0] < 0 && a[1] > 0) cout << sum + max(a[0], -a[1]) << '\n'; 
		else cout << sum << '\n';
	}
	return 0;
}
