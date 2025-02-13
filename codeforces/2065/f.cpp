/*
 * majority paths can only be
 * 1 1
 * or 
 * 1 2 1
 * every majority path will have these two values in them.
 * 
 * for each node in tree, we can check its vertices for these two.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) {
                        cin >> x;
                        --x;
                }
                vector<vector<int>> adj(n);
                for (int i = 0; i < n - 1; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                
                vector<int> ans(n, 0);

                for (int i = 0; i < n; i++) {
                        map<int, int> mp;
                        for (int j : adj[i]) {
                                if (a[i] == a[j]) {
                                        ans[a[i]] = 1;
                                }
                                mp[a[j]]++;
                        }
                        for (auto &[x, y] : mp) {
                                if (y >= 2) {
                                        ans[x] = 1;
                                }
                        }
                }

                for (int x : ans) cout << x;
                cout << '\n';
        }
}

                
