/*
 * suppose we are at node v, node u = par[par[v]]
 * assume d[v] = answer for vertex v, x = # of siblings of said node
 * assume x = # of "siblings" of node v.
 *
 * therefore d[v] = 2 * (x + 1) + d[u]
 *
 * calculate this for even and odd vertices, and compute each query by traversing up the tree towards the root
 */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vi>
#define ll long long

const ll MOD = 998244353;

ll binpow(ll x, ll y) {
    if (y == 0) return 1;
    else {
        ll res = binpow(x, y / 2);
        return res * res * (y % 2 ? x : 1);
    }
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        v2i adj(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vi par(n);
        vi depth(n);
        vi dp(n);

        auto dfs = [&](this auto dfs, int node, int p = -1) -> void {
           par[node] = p;
           if (p == -1) depth[node] = 0;
           else depth[node] = 1 + depth[p];

           if (depth[node] == 1) dp[node] = 1;
           else if (depth[node] > 1) dp[node] = dp[par[p]] + 2 * adj[p].size(); // mark children
           for (int nei : adj[node]) if (nei != p) dfs(nei, node);
        };

        dfs(0);
        while (q--) {
            int v, p; cin >> v >> p;
            v--;
            int res = dp[v];
            vector<int> arr;
            while (v != 0 && par[v] != 0) {
                arr.push_back(adj[par[v]].size());
                v = par[par[v]];
            }
            sort(arr.rbegin(), arr.rend());
            for (int i = 0; i < min(p, (int) arr.size()); i++) {
                res -= 2 * (arr[i] - 1); // turn into 2
            }
            cout << res << '\n';
        }

    }
    return 0;
}


