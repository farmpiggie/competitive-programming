#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	send help
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> psum(n, 0);
        psum[0] = a[0];
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i - 1] + a[i];
        }
        vector<int> end(n, 0);
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[start]) {
                for (int j = start; j < i; j++) {
                    end[j] = i - 1;
                }
                start = i;
            }
        }
        for (int j = start; j < n - 1; j++) {
            end[j] = n - 1;
        }

        for (int i = 0; i < n; i++) {
            // binary search for left
            int leftLen = n + 1;
            if (i - 1 >= 0 && a[i - 1] > a[i]) leftLen = 1;
            int lo = 0, hi = i - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                ll sum = psum[i - 1];
                if (mid - 1 >= 0) sum -= psum[mid - 1]; // mid to i - 1 inclusive
                
                if (sum > a[i] && (end[mid] < (i - 1))) {
                    lo = mid + 1;
                    leftLen = min(leftLen, i - 1 - mid + 1);
                } else {
                    hi = mid - 1;
                }
            }

            int rightLen = n + 1;
            if (i + 1 < n && a[i + 1] > a[i]) rightLen = 1;

            lo = i + 1, hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                ll sum = psum[mid] - psum[i]; // i + 1 to mid inclusive
                if (sum > a[i] && (end[i + 1] < mid)) {
                    hi = mid - 1;
                    rightLen = min(rightLen, mid - (i + 1) + 1);
                } else {
                    lo = mid + 1;
                }
            }
            if (leftLen == n + 1 && rightLen == n + 1) {
                cout << "-1 ";
            } else {
                cout << min(leftLen, rightLen) << " ";
            }
        }
        cout << '\n';

    }
	return 0;
}