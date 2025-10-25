#include <bits/stdc++.h>
using namespace std;

int main() {
    //    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, 0);
        vector<int> path, cur; // path = nodes from 0...n - 1

        auto dfs = [&](this auto dfs, int u, int p = -1, int d = 0) -> void {
            dist[u] = d;
            cur.push_back(u);
            if (u == n - 1)
                path = cur;
            for (int v : adj[u])
                if (v != p) {
                    dfs(v, u, d + 1);
                }
            cur.pop_back();
        };

        dfs(0);

        set<int> path_set(path.begin(), path.end());

        deque<int> odd_leaves, even_leaves;
        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            degree[i] = (int)adj[i].size();
            if (!path_set.count(i) &&
                (int)adj[i].size() == 1) { // not on path and leaf
                if (dist[i] % 2 == 0)
                    even_leaves.push_back(i);
                else
                    odd_leaves.push_back(i);
            }
        }

        vector<pair<int, int>> moves;
        int cnt = 0;
        while (odd_leaves.size() > 0 || even_leaves.size() > 0) {
            if (cnt % 2 == 0 && !odd_leaves.empty()) {
                int u = odd_leaves.front();
                odd_leaves.pop_front();
                for (int v : adj[u]) {
                    degree[v]--;
                    if (degree[v] == 1 &&
                        !path_set.count(
                            v)) { // u is odd leaf, so v is even leaf
                        even_leaves.push_back(v);
                    }
                }
                moves.push_back({2, u});
            }
            if (cnt % 2 == 1 && !even_leaves.empty()) {
                int u = even_leaves.front();
                even_leaves.pop_front();
                //               cout << "even leaf: " << u + 1 << '\n';
                for (int v : adj[u]) {
                    degree[v]--;
                    if (degree[v] == 1 &&
                        !path_set.count(v)) { // u is even leaf, so v is odd
                        //                        cout << "adding: " << v + 1 <<
                        //                        " as odd leaf\n";
                        odd_leaves.push_back(v);
                    }
                }
                moves.push_back({2, u});
            }
            moves.push_back({1, -1}); // dont use the -1 value
            cnt++;
        }

        // we are left with only nodes from 1...n
        if (cnt % 2 == 0) { // might be on node 0, just move once
            moves.push_back({1, -1});
            cnt++;
        }

        // we are not on node 0. remove node 0 and move again, keep doing for
        // each on path
        for (int i = 0; i < (int)path.size() - 1; i++) {
            moves.push_back({2, path[i]});
            moves.push_back({1, -1});
        }

        cout << (int)moves.size() << '\n';
        for (auto [type, node] : moves) {
            cout << type << " " << (type == 2 ? to_string(node + 1) : "")
                 << '\n';
        }
    }
}