/*
 * x >= y if:
 * msb(x) > msb(y)
 * or
 * msb(x) == msb(y) and some x - msb(x) > y - msb(y)
 *
 * at each eating step, our slime either maintains its MSB or it gets decreases
 * MSB only gets decreased a max of 30 times (w < 2^30)
 *
 * for each number in set:
 * have their indices in lists separated by MSB.
 * 
 * we can calculate how far an element with MSB of x can go (x between 0 and 29).
 * it passes through all elements with MSB < x.
 * once we hit MSB > x, we stop.
 * if we hit MSB = x, we need to re-evaluate.
 *
 * dp[pos][MSB] = first pos j to the left s.t. MSB(j) >= MSB(MSB)
 */
#include <bits/stdc++.h>
using namespace std;

int get_msb(int num) {
	if (num == 0) return -1;
	return 31 - __builtin_clz(num);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> w(n);
		for (int &x : w) cin >> x;

		reverse(w.begin(), w.end());

		vector<int> msb(n);
		vector<int> pxor(n);
		for (int i = 0; i < n; i++) {
			msb[i] = get_msb(w[i]);
			pxor[i] = w[i] ^ (i ? pxor[i - 1] : 0);
		}

		auto xorsum = [&](int l, int r) {
			if (l > r) return 0;
			return pxor[r] ^ (l ? pxor[l - 1] : 0);
		};
		
		// dp[i][j] = nearest rightmost k s.t. msb[k] >= j, must be k > i
		vector<vector<int>> dp(n, vector<int>(30, 0));
		for (int j = 0; j < 30; j++) {
			int right = n;
			for (int i = n - 1; i >= 0; i--) {
				dp[i][j] = right;
				if (msb[i] >= j) right = i;
			}
		}

		while (q--) {
			int x; cin >> x;
			int pos = 0;
			//cout << "test\n\n\n";
			while (pos < n && x >= w[pos]) {
				//cout << "pos and w[pos]: " << pos << " " << w[pos] << '\n';
				//cout << "x: " << x << '\n';
				x ^= w[pos];
				//cout << "x after: " << x << '\n';
				//cout << "msb of x: " << get_msb(x) << '\n';
				if (x == 0) {
					pos++;
					break;
				}
				int npos = dp[pos][get_msb(x)]; // next position with possibly greater pos.

				//cout << "npos: " << npos << '\n';
				x ^= xorsum(pos + 1, npos - 1); // xor everything in between
				pos = npos; // set new position to test

				
			}
			cout << pos << ' ';
			//cout << "query ans: " << pos << '\n';
		}
		cout << '\n';
	}
}
				

			
			
		
