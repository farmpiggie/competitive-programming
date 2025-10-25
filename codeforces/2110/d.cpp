#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pli pair<ll, int>
#define pll pair<ll, ll>

const ll MAX = 1e15;

void coalesce(set<pll>& s) {
        if (s.size() == 0) return;
        vector<pll> arr;
        for (pll p : s) arr.push_back(p);
        set<pll> t;
        pll cur = arr[0];
        for (int i = 1; i < arr.size(); i++) {
                if (cur.second + 1 >= arr[i].first) {
                        cur.first = min(cur.first, arr[i].first);
                        cur.second = max(cur.second, arr[i].second);
                } else {
                        t.insert(cur);
                        cur = arr[i];
                }
        }
        t.insert(cur);
        s = t;
}



int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m; cin >> n >> m;
                vector<ll> b(n);
                for (ll &x : b) cin >> x;
                vector<vector<pll>> adj(n); // {w, node}
                for (int i = 0; i < m; i++) {
                        int s, t, w; cin >> s >> t >> w;
                        --s; --t;
                        adj[t].push_back({1ll * w, s}); // edge from s -> t
                }

                vector<set<pll>> ranges(n); // ranges of (min, max) we can have
                ranges[0].insert({0, 0});
                for (int i = 1; i < n; i++) {
//                        cout << "i: " << i << endl;
                        for (auto [w, j] : adj[i]) {
                                for (pll range : ranges[j]) { // can this range hit?
 //                                       cout << "j: " << j << endl;
                                        if (range.second + b[j] < w) continue;
                                        ranges[i].insert({max(w, range.first), range.second + b[j]}); // range of taking this edge.
                                }
//                                cout << "end\n";
                                coalesce(ranges[i]);
//                                cout << "coalesce\n";
                        }
/*
                        for (pll p : ranges[i]) {
                                cout << p.first << ", " << p.second << '\n';
                        }
                        cout << '\n'u
*/
                }
                if (ranges[n - 1].size() == 0) {
                        cout << "-1\n";
                } else {
                        cout << ranges[n - 1].begin()->first << '\n';
                }
        }
}




                



