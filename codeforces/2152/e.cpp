#include <bits/stdc++.h>
using namespace std;

vector<int> ask(set<int>& s) {
        cout << "? " << (int) s.size() << " ";
        for (int x : s) cout << x << ' ';
        cout << endl;
        int n; cin >> n;
        vector<int> ans(n);
        for (int &x : ans) cin >> x;
        return ans;
}


int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                int N = n * n + 1;
                vector<vector<int>> adj(N + 1); // directed graph
                set<int> s;
                for (int i = 1; i <= N; i++) { // between 1 and N
                        s.insert(i);
                }
                bool found = false;
                for (int k = 0; k < n && (int) s.size() > 0; k++) {
                        vector<int> a(s.begin(), s.end());
                        vector<int> b = ask(s);
                        if (b.size() >= n + 1) {
                                cout << "! ";
                                for (int i = 0 ; i < n + 1; i++) {
                                        cout << b[i] << ' ';
                                }
                                cout << endl;
                                found = true;
                                break;
                        }
                        int j = 0;
                        for (int i = 1; i < (int) a.size(); i++) {
                                if (j + 1 < (int) b.size() && a[i] == b[j + 1]) {
                                        j++;
                                } else {
                                        adj[b[j]].push_back(a[i]);
                                }
                        }
                        for (int x : b) s.erase(x);
                }

                if (found) continue;

                vector<int> visited(N + 1, 0);
                vector<int> cur, path;
                auto dfs = [&](this auto dfs, int u) -> void {
                        if (visited[u]) return;
                        visited[u] = 1;
                        cur.push_back(u);
                        if ((int) cur.size() == n + 1) {
                                path = cur;
                        }
                        for (int v : adj[u]) dfs(v);
                        cur.pop_back();
                };

                for (int i = 1; i <= N; i++) dfs(i);
                assert((int) path.size() == n + 1);

                cout << "! ";
                for (int x : path) cout << x << ' ';
                cout << endl;
        }
}







