#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        set<array<int, 2>> s;
        s.insert({m, m});
        while (q--) {
            int x; cin >> x;
            set<array<int, 2>> ns;
            for (auto [l, r] : s) {
                if (x < l) ns.insert({max(1, l - 1), r});
                else if (x > r) ns.insert({l, min(r + 1, n)});
                else {
                    if (l < r) ns.insert({l, r});
                    ns.insert({1, 1});
                    ns.insert({n, n});
                }
            }
            
            // given set of intervals, combine them into disjoint intervals.
            // intervals that are adjacent should be combined. (1, 2) and (3, 4) -> (1, 4)
            auto coalesce = [&](const set<array<int, 2>> s) {
                vector<array<int, 2>> arr;
                for (auto [l, r] : s) arr.push_back({l, r});
                set<array<int, 2>> ns;
                array<int, 2> cur = arr[0];
                for (int i = 1; i < arr.size(); i++) {
                    if (cur[1] + 1 >= arr[i][0]) {
                        cur = {cur[0], arr[i][1]};
                    } else {
                        ns.insert(cur);
                        cur = arr[i];
                    }
                }
                ns.insert(cur);
                return ns;
            };

           
            ns = coalesce(ns);
            int ans = 0;
            for (auto [l, r] : ns) {
                ans += (r - l + 1);
            }
            cout << ans << ' ';
            s = ns;
        }
        cout << '\n';

    }
    return 0;
}
