/*
if array is fully filled, let us check if max subarray sum = k.
check if impossible: if all a[i] = -INF and max subarray sum > k, then it is impossible.
keep all a[i] = -INF, and choose one position pos.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e13;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; ll k; cin >> n >> k;
                string filled; cin >> filled;
                vector<ll> a(n);
                for (ll &x : a) cin >> x;
                auto max_subarray_sum = [&]() {
                        ll sum = 0;
                        ll max_sum = 0;
                        for (int i = 0; i < n; i++) {
                                sum = max(0ll, sum + a[i]);
                                max_sum = max(max_sum, sum);
                        }
                        return max_sum;
                };

                if (filled.find('0') == string::npos) {
                        ll max_sum = max_subarray_sum();
                        if (max_sum == k) {
                                cout << "YES\n";
                                for (ll x : a) cout << x << " ";
                                cout << '\n';
                        } else {
                                cout << "NO\n";
                        }
                } else {
                        for (int i = 0; i < n; i++) if (filled[i] == '0') a[i] = -INF;
                        if (max_subarray_sum() > k) {
                                cout << "NO\n";
                                continue;
                        }
                        int pos = 0;
                        while (filled[pos] == '1') pos++;
                        ll left = 0, right = 0;
                        ll cur = 0;
                        for (int i = pos - 1; i >= 0; i--) {
                                cur += a[i];
                                left = max(left, cur);
                        }
                        cur = 0;
                        for (int i = pos + 1; i < n; i++) {
                                cur += a[i];
                                right = max(right, cur);
                        }
                        a[pos] = k - left - right;
                        cout << "YES\n";
                        for (ll &x : a) cout << x << " ";
                        cout << '\n';
                }
        }
}

