// Hint 1: Let m be the value we want to find. What values can m take?
// 		Ans: m can only be multiples of max(a_i)
// Hint 2: Look at the maximum value in array a.
//		grab maximum of array with max(a_i) f(1, n) / n
// Hint 3: Can you find the maximum value in array?
// 		we can binary search for max(a_i)
// 			if ? l, r != max(a_i) * (r - l + 1), we know to search in the second half
//     		if ? l, r == max(a_i) * (r - l + 1), then we can continue to divide this segment
// 		this way we can find the max value.
//  	log2(n) comparisons
// Hint 4: Think about the segment containing the maximum value
// 		segment cannot be longer than n / k
//		segment must be at least of length m / max(a_i)
//		k * m / max(a_i) <= n
//		m <= n / k * max(a_i)
//		m <= n / k * max(a_i)
//		test the first (n / k) queries in O(k) each
//		takes O(n + n / k * k) = k time
// EDITORIAL:
// notice that the maximum value in the array is always going to be part of m
// all possible values of m are multiples of said maximum value
// trying to solve for all values of m would be O(n * k), too slow
// realize that the length of each segment must be >= m / mx (since at the shortest it will use mx as maximum of the segment, so mx * len = m)
// inequality that k * (m / mx) <= n (must fit k segments in), so m <= n / k * mx, so we only need to try (n/k) values k times
// comes out to O(n + k * n/k) = O(2n)
#include <bits/stdc++.h>
using namespace std;
//#define TEST

vector<int> a;

int calculate(int l, int x) {
	l--;
	int len = 0;
	int mx = -1;
	for (int i = l; i < (int) a.size(); i++) {
		len++;
		mx = max(mx, a[i]);
		if (len * mx == x) return i + 1;
	}
	return -1;
}

int ask(int l, int x) {
#ifdef TEST
	cout << "? " << l << " " << x << '\n';
	int res = calculate(l, x);
	cout << "res: " << res << '\n';
	return res;
#else
	cout << "? " << l << " " << x << '\n';
	int res; cin >> res;
	return res;
#endif
}



int main() {
	//cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int mx;
	#ifdef TEST
		a.resize(n);
		for (int& x : a) cin >> x;
		cout << '\n';
	#endif
		for (int i = 1; i <= n; i++) {
			int x = ask(1, (n * i));
			if (x == n) {
				mx = i;
				break;
			}	
		}
		
		int best = -1;
		for (int i = 1; i <= (n / k); i++) {
			int cur_m = mx * i;
			int l = 1;
			int j = 0;
			for (; j < k; j++) {
				if (l > n) break;
				int x = ask(l, cur_m);
				if (x == -1) break;
				else l = x + 1;	
			}
			if (j == k && l == n + 1) {
				best = cur_m;
			}	
		}
		cout << "! " << best << '\n';
	#ifdef TEST
	#else
		int success;
		cin >> success;
	#endif
	}
	return 0;
}

