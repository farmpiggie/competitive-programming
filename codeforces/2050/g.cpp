/*
 * find path that maximizes (sum(edges going out from said nodes) - (num nodes - 1))
 * let us define dp[i] = max(sum(edges going out from some node in subtree i to i))
 *
 * ans = max(dp[i].size() - 2 + max(dp[j] + dp[k])) where j and k are children of i
 *     = max(dp[i] + (par[i] != -1)) // path from node in subtree i to i
 *
 * dp[i] = max(dp[child] + adj[i].size() - 1 - (par[i] != -1)) 
 *              or biggest child path.
 *
 * dp[leaf] = 0;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<vector<int>> adj(n);
                for (int i = 0; i < n - 1; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                
                int ans = 1;
                vector<int> dp(n, 0);
               
                // dp[u] = max subtraction path from subtree in u to u, not counting parent
                auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
                        vector<int> a;
                        bool not_root = (p != -1);
                        dp[u] = (int) adj[u].size() - not_root; // not counting parent
                        for (int v : adj[u]) if (v != p) {
                                dfs(v, u);
                                dp[u] = max(dp[u], dp[v] + (int) adj[u].size() - 1 - not_root); // not counting (u, v) or path to root
                                a.push_back(dp[v]);
                        }
                        sort(a.rbegin(), a.rend());
                        ans = max(ans, dp[u] + not_root); // if not root, add 1
                        if (a.size() >= 2) {
                                ans = max(ans, (int) adj[u].size() - 2 + a[0] + a[1]); // add root if we count u
                        }
                };


                dfs(0);

                cout << ans << '\n';
        }
}



                
