/* calculate two prefix sum arrays based on whether or not l is even or not
 * just go through it?
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        // all l s.t. l is even
        set<ll> s;
        s.insert(0);
        ll ans = 0;
        ll cur = 0;
        for (int i = 1; i < n; i++) {
                cur += 1ll * abs(a[i - 1] - a[i]) * (i & 1 ? 1 : -1);
                if (!(i & 1)) s.insert(cur);
                ans = max(ans, cur - *s.begin());
        }
        s = set<ll>();
        s.insert(0);
        cur = 0;
        for (int i = 2; i < n; i++) {
                cur += 1ll * abs(a[i - 1] - a[i]) * (i & 1 ? -1 : 1);
                if (i & 1) s.insert(cur);
                ans = max(ans, cur - *s.begin());
        }
        cout << ans << '\n';
}







