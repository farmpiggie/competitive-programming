// previous solve: for a certain type, find the LCP through binary search for segments
// note: as k increases, f_k decreases
// can we use this monitonic property to our advantage?
// if k <= sqrt(n), then 0 <= LCP <= n
// 		calculate in O(sqrt(n) * n * log(n))
// if k >= sqrt(n), then 0 <= LCP <= sqrt(n)
// 		for each segment from length 0 to sqrt(n), find largest k 
// 		takes O(sqrt(n) * n) time
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int solve(vector<int>& z, int k, int n) {
	int best = 0;
	int lo = 1, hi = n;
	while (lo <= hi) {
		int cur = 0;
		int mi = lo + (hi - lo) / 2;
		int i = 0;
		while (i + mi - 1 < n) {
			if (z[i] >= mi) {
				cur++;
				i += mi;
			} else i++;
		}
		if (cur >= k) { // only compare to l
			best = max(best, mi);
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}
	return best;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, l, r; cin >> n >> l >> r;
		string s; cin >> s;
		vector<int> ans(n + 1, 0);
		vector<int> z = z_function(s);
		//cout << "z: ";
		//for (int i = 0; i < n; i++) cout << z[i] << ' ';
		//cout << '\n';
		z[0] = n;

		for (int i = l; i <= (int) sqrt(n); i++) {
			//cout << "ans[" << i << "]: " << solve(z, i, n) << '\n';
			ans[i] = solve(z, i, n);
		}

		for (int i = 1; i <= (int) sqrt(n); i++) {
			int j = 0;
			int cur = 0;
			while (j + i - 1 < n) {
				if (z[j] >= i) {
					cur++;
					j += i;
				} else j++;
			}
			ans[cur] = max(ans[cur], i); 
		}

		for (int i = n - 1; i >= 0; i--) {
			if (ans[i] == 0) ans[i] = ans[i + 1];
		}
		
		for (int i = l; i <= r; i++) cout << ans[i] << ' ';
		cout << '\n';

	}
	return 0;
}
