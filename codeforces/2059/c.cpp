/* easy to get mex = 1
 * how to get mex = 2? must have some suffix sum of a[i] = 1.
 * how to get mex = 3? must have some suffix sum of a[i] = 2.
 *
 * for the first pt in time, you gotta take some value = 1. (1)
 * at the second time, you have to take some value = 2. (1 + 1)
 * at the third time, you can only take (1 + 1 + 1)
 *
 * count # of 1s at end of each array.
 * sort values
 * check at which index does a[i] < i + 1.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a;
                for (int i = 0; i < n; i++) {
                        vector<int> b(n);
                        for (int &x : b) cin >> x;
                        reverse(b.begin(), b.end());
                        int j = 0;
                        for (; j < n; j++) {
                                if (b[j] != 1) break;
                        }
                        a.push_back(j);
                }
                sort(a.begin(), a.end());
                
                int ans = 0;
                for (int i = 0; i < n; i++) {
                        if (a[i] >= ans) {
                                ans++;
                        }
                }
                cout << ans << '\n';
        }
}
