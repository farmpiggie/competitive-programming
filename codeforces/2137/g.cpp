/*
 * start off all dp[i][0/1] = # of children with paths that lead to cry winning
 *
 * when u set a red node:
 * dp[i][0/1] = 0 if node is red
 *
 * propagate upwards if dp[i][j] = 0
 * dp[i][1] = min(dp[j][0]) for all i -> j (river picks a node to force cry to lose)
 * dp[i][0] = sum(dp[j][1]) for all i -> j (cry picks a path where he can win)
 *
 * if any values reach zero, propagate to their parents
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, q; cin >> n >> m >> q;
                vector<vector<int>> adj(n), adj2(n);
                for (int i = 0; i < m; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj2[v].push_back(u);
                }

                vector<vector<int>> dp(n, vector<int>(2, 0)); // values leading into
                vector<vector<int>> marked(n, vector<int>(2, 0)); // river wins
                for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = max(1, (int) adj[i].size());

                while (q--) {
                        int x, u; cin >> x >> u;
                        --u;
                        if (x == 1) {
                                queue<pair<int, int>> q;
                                q.push({u, 0});
                                q.push({u, 1});
                                while (!q.empty()) {
                                        auto [i, turn] = q.front(); q.pop();
                                        if (marked[i][turn]) continue;
                                        marked[i][turn] = 1;
                                        for (int j : adj2[i]) {
                                                if (turn == 0) {
                                                        q.push({j, 1});
                                                } else {
                                                        dp[j][1 - turn]--;
                                                        if (dp[j][1 - turn] == 0) {
                                                                q.push({j, 0});
                                                        }
                                                }
                                        }
                                }
                        } else {
                                // special case if we are end node and are not red
                                // otherwise we are either: end node and red (dp[i][0] = 0) or we are not end node
                                cout << (marked[u][0] ? "NO" : "YES") << '\n';
                        }
                }
        }
}
