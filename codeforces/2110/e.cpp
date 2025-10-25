#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int) x.size()

vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
        vector<pii> ret, s = {make_pair(src, -1)};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
                int x = s.back().first, y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(s.back()); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; 
                        s.push_back(make_pair(y, e));
		}
        }
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<pii> a(n);

                set<int> xs, ys;
                for (auto &[x, y] : a) {
                        cin >> x >> y;
                        xs.insert(x);
                        ys.insert(y);
                }

                map<int, int> cx, cy;

                int cnt = 0;
                for (int x : xs) {
                        cx[x] = cnt++;
                }
                for (int y : ys) {
                        cy[y] = cnt++;
                }

                vector<vector<pii>> adj(cnt);
                vi degree(cnt);
                int idx = 0;
                for (auto [x, y] : a) {
                        adj[cx[x]].push_back({cy[y], idx});
                        adj[cy[y]].push_back({cx[x], idx});
                        degree[cx[x]]++;
                        degree[cy[y]]++;
                        idx++;
                }

                int start = 0;
                for (int i = 0; i < cnt; i++) {
                        if (degree[i] & 1) {
                                start = i;
                                break;
                        }
                }

                vector<pii> ans = eulerWalk(adj, n, start);
                if (ans.size() == 0) {
                        cout << "NO\n";
                } else {
                        cout << "YES\n";
                        for (auto [_, idx] : ans) {
                                if (idx != -1) cout << idx + 1 << " ";
                        }
                        cout << '\n';
                }
        }
}