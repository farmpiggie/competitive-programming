#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                pair<int, int> p = {-1, -1};
                int ans = 0;
                int l = 1, r = n;
                while (l <= r) {
                        int m = (l + r) / 2;
                        vector<int> pre(n + 1, 0);
                        for (int i = 1; i <= n; i++) {
                                pre[i] = pre[i - 1] + (a[i - 1] >= m ? 1 : -1);
                        }
                        int mn = 1e6;
                        int lft = 0, rht = 0;
                        bool works = false;
                        int sum = 0;
                        for (int i = 1; i <= n; i++) {
                                if (i - k >= 0) {
                                        if (pre[i - k] < mn) {
                                                lft = i - k;
                                                mn = pre[i - k];
                                        }
                                }
                                sum += (a[i - 1] >= m ? 1 : -1);
                                if (sum - mn >= 0) {
                                        rht = i;
                                        works = true;
                                        break;
                                }
                        }
                        if (works) {
                                if (m > ans) {
                                        ans = m;
                                        p = {lft + 1, rht};
                                }
                                l = m + 1;
                        } else {
                                r = m - 1;
                        }
                }
                cout << ans << ' ' << p.first << ' ' << p.second << '\n';
        }
}


                                


