/*
 * spiders form "components" with a cycle in the middle and paths leading to the cycle.
 * ans = max "tail length" leading to any cycle in graph
 * find all cycles, condense them to form DAG
 * ans = longest path on DAG.
 */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vi>

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi nxt(n);
        for (int& x : nxt) {
            cin >> x;
            --x;
        }
        vector<bool> cycle(n, 0), visited(n, 0);
        vector<int> path;
        set<int> onpath;
        auto dfs1 = [&](this auto dfs1, int node) -> void {
            if (onpath.count(node)) { // previously seen this node on this exact path
                cycle[node] = true;
                while (path.back() != node) {
                    cycle[path.back()] = true;
                    path.pop_back();
                }
            } else if (!visited[node]) { // node not yet seen on path, visiting for first time
                visited[node] = true;
                path.push_back(node);
                onpath.insert(node);
                dfs1(nxt[node]);
            }
        };

        for (int i = 0; i < n; i++) {
            path = {};
            onpath = {};
            dfs1(i);
        }
        
        // for non-cycle values, do this dfs.
        v2i prv(n);
        vi sources; // nodes that connect to cycle
        for (int i = 0; i < n; i++) {
            if (cycle[nxt[i]] && !cycle[i]) {
                sources.push_back(i);
            }
            prv[nxt[i]].push_back(i);
        }

        auto dfs2 = [&](this auto dfs2, int node) -> int {
            if (prv[node].size() == 0) return 1;
            else {
                int sum = 1;
                for (int nei : prv[node]) sum += dfs2(nei);
                return sum;
            }
        };

        int mx = 0;
        for (int node : sources) mx = max(mx, dfs2(node));
        cout << mx + 2 << '\n';
    }
    return 0;
}

