#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

const ll MOD = 1e9 + 7;

struct dsu {
        int n;
        vector<int> par, sz, marked, cycle;
        
        dsu(int _n, set<int> &s) {
                n = _n;
                sz.assign(n, 1);
                marked.assign(n, 0);
                for (int node : s) marked[node] = 1;
                par.resize(n);
                iota(par.begin(), par.end(), 0);
                cycle.assign(n, 0);
        }

        int find(int x) {
                if (par[x] == x) return x;
                else return par[x] = find(par[x]);
        }

        void merge(int x, int y) {
                x = find(x), y = find(y);
                if (x == y) {
                        cycle[x]++;
                        return;
                }
                if (sz[x] < sz[y]) swap(x, y);
                sz[x] += sz[y];
                par[y] = x;
                marked[x] += marked[y];
                cycle[x] += cycle[y];
        }
};

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, k; cin >> n >> m >> k;
                vector<pii> p(k + 1);
                for (auto &[x, y] : p) {
                        cin >> x >> y;
                        --x; --y;
                }

                bool works = true;
                for (int i = 1; i <= k; i++) {
                        if (abs(p[i - 1].f - p[i].f) + abs(p[i - 1].s - p[i].s) != 2) {
                                works = false;
                                break;
                        }
                }

                if (!works) {
                        cout << "0\n";
                        continue;
                }

                map<int, vector<int>> adj;
                auto choices = [&](pii a, pii b) -> vector<int> {
                        if (abs(a.f - b.f) == 1 && abs(a.s - b.s) == 1) {
                                return {a.f * m + b.s, b.f * m + a.s};
                        } else if (a.f == b.f) {
                                return {a.f * m + (a.s + b.s) / 2};
                        } else return {(a.f + b.f) / 2 * m + a.s};
                };

  //              cout << "one\n";

                set<int> marked;
                vector<pii> edges;
                
                works = true;

                for (int i = 1; i <= k; i++) {
                        vector<int> ret = choices(p[i - 1], p[i]);
                        if (ret.size() == 1) {
                                if (marked.find(ret[0]) != marked.end()) works = false;
                                marked.insert(ret[0]);
                        } else {
                                adj[ret[0]].push_back(ret[1]);
                                adj[ret[1]].push_back(ret[0]);
                                edges.push_back({ret[0], ret[1]});
                        }
                }

                if (!works) {
                        cout << "0\n";
                        continue;
                }

 //               cout << "two\n";

                dsu uf(n * m, marked);
                for (auto [x, y] : edges) {
                        uf.merge(x, y);
                }

//                cout << "two.one\n";

                set<int> ccs;
                map<int, set<int>> cc_to_nodes;
                for (auto [x, y] : edges) {
                        int cc = uf.find(x);
                        ccs.insert(cc);
                        cc_to_nodes[cc].insert(x);
                        cc_to_nodes[cc].insert(y);
                }
 //               cout << "two.two\n";

                map<int, int> cc_to_start;

                for (auto &[node, neighbors] : adj) {
                        if (neighbors.size() == 1) {
                                cc_to_start[uf.find(node)] = node;
                        }
                }
//                cout << "three\n";

                map<int, array<ll, 2>> dp;

                auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
   //                     cout << "u and p: " << u << " " << p << '\n';
                        vector<int> children;
                        for (int v : adj[u]) if (v != p) {
                                dfs(v, u);
                                children.push_back(v);
                        }
                        if (children.size() == 0) {
                                dp[u][0] = 1;
                                dp[u][1] = 0;
                        } else if (children.size() == 1) {
                                int v = children[0];
                                dp[u][1] = (dp[v][0] + dp[v][1]) % MOD;
                                dp[u][0] = dp[v][0];
                        } else { // 2
                                int v = children[0], w = children[1];
                                dp[u][0] = dp[v][0] * dp[w][0] % MOD;
                                dp[u][1] = (dp[v][0] * (dp[w][0] + dp[w][1]) % MOD + dp[w][0] * (dp[v][0] + dp[v][1]) % MOD) % MOD;
                        }
                };

                ll ans = 1;
                for (int cc : ccs) {
                        cc = uf.find(cc);
//                        cout << "cc: " << cc << '\n';
                        if (uf.marked[cc] + uf.cycle[cc] > 1) {
 //                               cout << "marked and cycles: " << uf.cycle[cc] << " " << uf.marked[cc] << '\n';
                                ans *= 0;
                                break;
                        } else if (uf.cycle[cc] > 0) {
  //                              cout << "cycles: " << uf.cycle[cc] << '\n';
                                ans = (ans * 2) % MOD;
                        } else if (uf.marked[cc] == 0) {
   //                             cout << "dfs\n";
                                int u = cc_to_start[cc];
                                //cout << "Dfs: " << u << '\n';
                                dfs(u, -1);
                                ans = ans * (dp[u][0] + dp[u][1]) % MOD;
                        } // otherwise only one option, 
                }
                cout << ans << '\n';
        }
}



