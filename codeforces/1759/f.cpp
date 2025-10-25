#include <bits/stdc++.h>

using namespace std;

int new_digit = -1;

bool check(set<int>& digits, int l, int r, bool useNewDigit) {
	for (int i = l; i <= r; i++) {
        if (useNewDigit && i == new_digit) {
            continue;
        }
        if (!digits.count(i)) {
            return false;
        }
    }
    return true;
}

int main() {
	// ifstream cin("allpossibledigits.in");
	int t; cin >> t;
	while (t--) {
		int n, p; cin >> n >> p;
		vector<int> a(n + 1);
		set<int> digits;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			digits.insert(a[i]);
		}
		if (digits.size() == p) {
			cout << 0 << endl;
			continue;
		}

		// get least sig digit that is not (p - 1)
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] < p - 1) {
				new_digit = a[i] + 1;
				break;
			}
		}

		int l = 0, r = p - 1;
		int ans = p - 1;
		int x = a[n];
		while (l <= r) {
			bool works = false;
			int m = (l + r) / 2;
			if (x + m >= p) { // crosses over zero, uses the new digit
				if (check(digits, x + m + 1 - p, x - 1, true)) {
					works = true;
				}
			} else {
				if (check(digits, 0, x - 1, false) && check(digits, x + m + 1, p - 1, false)) {
					works = true;
				}
			}
			if (works) {
				ans = min(m, ans);
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}