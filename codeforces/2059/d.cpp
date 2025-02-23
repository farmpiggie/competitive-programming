/*
 * ans != -1 if there exists some node x s.t:
 * we can reach x at the same time
 * (x, y) exists in both graphs.
 *
 * dp[x][y] = min cost to get to x in graph 1, and y in graph 2.
 * transition should be O(n^2 log(n^2) + m^2)
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, s1, s2; cin >> n >> s1 >> s2;
                --s1; --s2;

                vector<vector<int>> adj1(n), adj2(n);
                vector<vector<int>> mat1(n, vector<int>(n, 0)), mat2(n, vector<int>(n, 0));
                
                int m1, m2;
                cin >> m1;
                for (int i = 0; i < m1; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj1[u].push_back(v);
                        adj1[v].push_back(u);
                        mat1[u][v] = mat1[v][u] = 1;
                }
                cin >> m2;
                for (int i = 0; i < m2; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj2[u].push_back(v);
                        adj2[v].push_back(u);
                        mat2[u][v] = mat2[v][u] = 1;
                }
                vector<vector<ll>> dp(n, vector<ll>(n, INF));
                priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
                pq.push({0ll, {s1, s2}});
                        
                while (!pq.empty()) {
                        ll dist = pq.top().first;
                        int u1 = pq.top().second.first, u2 = pq.top().second.second;
                        pq.pop();
                        if (dp[u1][u2] != INF) continue;
                        dp[u1][u2] = dist;
                        for (int v1 : adj1[u1]) {
                                for (int v2 : adj2[u2]) {
                                        pq.push({dist + abs(v1 - v2), {v1, v2}});
                                }
                        }
                }
                ll ans = INF;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                if (mat1[i][j] && mat2[i][j]) {
                                        ans = min(ans, min(dp[i][i], dp[j][j]));
                                }
                        }
                }

                cout << (ans == INF ? -1 : ans) << '\n';

        }
}
