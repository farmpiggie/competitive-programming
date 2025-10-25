#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii> // {min moves, {node, time}}
#define f first
#define s second

const int INF = 1e9;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m; cin >> n >> m;
                vector<vector<int>> adj(n);
                for (int i = 0; i < m; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                vector<int> dp(n, INF);
                dp[0] = 0;
                for (int t = 0; t < 4 * n; t++) { // total time t
                        vector<int> ndp(n);
                        for (int i = 0; i < n; i++) {
                                ndp[i] = dp[i] + 1;
                        }
                        for (int i = 0; i < n; i++) {
                                int k = adj[i][t % (int) adj[i].size()];
                                ndp[k] = min(ndp[k], dp[i]);
                        }
                        if (ndp[n - 1] < INF) {
                                cout << t + 1 << " " << ndp[n - 1] << '\n';
                                break;
                        }
                        dp = ndp;
                }
        }
}


