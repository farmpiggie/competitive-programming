#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define v2i vector<vi>
#define v3i vector<v2i>

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, l; cin >> n >> m >> l;
                vector<int> a(l);
                for (int &x : a) cin >> x;
                v2i adj(n);
                for (int i = 0; i < m; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                v2i dist(n, vi(2, -1));
                priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
                pq.push({0, {0, 0}});
                while (!pq.empty()) {
                        int d = pq.top().first;
                        int u = pq.top().second.first, p = pq.top().second.second;
                        pq.pop();
                        if (dist[u][p] != -1) continue;
                        dist[u][p] = d;
                        for (int v : adj[u]) {
                                pq.push({d + 1, {v, 1 - p}});
                        }
                }

                ll sum = 0;
                int odd = 1e9;
                for (int x : a) {
                        sum += x;
                        if (x & 1) odd = min(odd, x);
                }

                ll biggest_even, biggest_odd;
                if (sum & 1) {
                        biggest_odd = sum;
                        if (odd != 1e9) {
                                biggest_even = sum - odd;
                        } else {
                                biggest_even = -1;
                        }
                } else {
                        biggest_even = sum;
                        if (odd != 1e9) {
                                biggest_odd = sum - odd;
                        } else {
                                biggest_odd = -1;
                        }
                }

                vector<int> ans(n);
                for (int i = 0; i < n; i++) {
                        ans[i] = (biggest_odd != -1 && dist[i][1] != -1 && biggest_odd >= dist[i][1]) || (biggest_even != -1 && dist[i][0] != -1 && biggest_even >= dist[i][0]);
                }
                for (int x : ans) cout << x;
                cout << '\n';
        }
}

                

