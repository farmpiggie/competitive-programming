#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  greater_equal<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_multiset;

typedef pair<int, int> pii;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n), p(n);
        for (int& x : v) cin >> x;
        for (int& x : p) {
            cin >> x; --x;
        }

        ordered_multiset ms;
        for (int i = 0; i < n; i++) {
            ms.insert(v[i]);
        }

        ll ans = *ms.find_by_order(0); // 1 element
        int shrooms = 1;
        for (int i = 0; i < n; i++) {
            ms.erase(ms.find_by_order(ms.order_of_key(v[p[i]])));
            if ((int) ms.size() < i + 2) continue;
            ll cur = 1ll * *ms.find_by_order(i + 1) * min(i + 2, (int) ms.size());
            if (cur > ans) {
                ans = cur;
                shrooms = i + 2;
            }
        }
        cout << ans << " " << shrooms << '\n';

    }
}
