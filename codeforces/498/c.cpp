/*
 * obv1: optimal value of v will always be a prime #
 * we can create a flow to impose restrictions on the # of operations formed.
 * create two "layers" in our graph, mainly:
 * (p, i) : some prime factor p of a[i]
 * (p, (i, j)): some prime factor p of gcd(a[i], a[j])
 *
 * capacity(s, (p, i)) = # of factors of p in a[i]
 * capacity((p, (i, j)), t) = # of factors of p in gcd(a[i], a[j])
 * capacity((p, i), (p, (i, j))) = INF if primes are same, otherwise 0.
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct FlowEdge {
        int v, u;
        ll cap, flow = 0;
        FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
        const ll flow_inf = 1e18;
        vector<FlowEdge> edges;
        vector<vector<int>> adj;
        int n, m = 0;
        int s, t;
        vector<int> level, ptr;
        queue<int> q;

        Dinic(int n, int s, int t) : n(n), s(s), t(t) {
                adj.resize(n);
                level.resize(n);
                ptr.resize(n);
        }

        void add_edge(int v, int u, long long cap) {
                edges.emplace_back(v, u, cap);
                edges.emplace_back(u, v, 0);
                adj[v].push_back(m);
                adj[u].push_back(m + 1);
                m += 2;
        }

        bool bfs() {
                while (!q.empty()) {
                        int v = q.front();
                        q.pop();
                        for (int id : adj[v]) {
                                if (edges[id].cap == edges[id].flow) continue;
                                if (level[edges[id].u] != -1) continue;
                                level[edges[id].u] = level[v] + 1;
                                q.push(edges[id].u);
                        }
                }
                return level[t] != -1;
        }

        ll dfs(int v, ll pushed) {
                if (pushed == 0) return 0;
                if (v == t) return pushed;
                for (int &cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
                        int id = adj[v][cid];
                        int u = edges[id].u;
                        if (level[v] + 1 != level[u]) continue;
                        long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
                        if (tr == 0) continue;
                        edges[id].flow += tr;
                        edges[id ^ 1].flow -= tr;
                        return tr;
                }
                return 0;
        }

        ll flow() {
                ll f = 0;
                while (true) {
                        fill(level.begin(), level.end(), -1);
                        level[s] = 0;
                        q.push(s);
                        if (!bfs()) break;
                        fill(ptr.begin(), ptr.end(), 0);
                        while (ll pushed = dfs(s, flow_inf)) {
                                f += pushed;
                        }
                }
                return f;
        }
};

int main() {
        vector<int> primes;
        const int MAXN = 32000; // sqrt(1e9)
        vector<int> marked(MAXN, 0);
        for (int i = 2; i < MAXN; i++) {
                if (!marked[i]) {
                        primes.push_back(i);
                        for (int j = 2 * i; j < MAXN; j += i) {
                                marked[j] = 1;
                        }
                }
        }
        cin.tie(0)->sync_with_stdio(0);
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<array<int, 2>> b(m);
        for (auto &[x, y] : b) {
                cin >> x >> y;
                --x; --y;
                if (y % 2 == 0) swap(x, y); // even on left side of matching
        }

        auto factorize = [&](int x, map<int, int>& ans) {
                for (int prime : primes) {
                        int cnt = 0;
                        while (x % prime == 0) {
                                x /= prime;
                                cnt++;
                        }
                        if (cnt > 0) ans[prime] = cnt;
                }
                // could have at most 1 prime > sqrt(1e9)
                if (x > 1) ans[x] = 1;
        };

        vector<map<int, int>> f(n); // f[i] = list of {prime, cnt} for a[i]
        for (int i = 0; i < n; i++) {
                factorize(a[i], f[i]);
        }
        vector<map<int, int>> g(m); // g[i] = list of {prime, cnt} for gcd(a[b[i][0]], a[b[i][1]])
        for (int i = 0; i < m; i++) {
                factorize(gcd(a[b[i][0]], a[b[i][1]]), g[i]);
        }
        map<array<int, 2>, int> compress1; // compress (p, i) nodes.
        map<array<int, 2>, int> compress2; // compress (p, (i, j)) nodes.
        int num_nodes = 1; // source
        for (int i = 0; i < n; i++) {
                for (auto& [p, _] : f[i]) {
                        compress1[{p, i}] = num_nodes++;
                }
        }
        for (int i = 0; i < m; i++) {
                for (auto& [p, _] : g[i]) {
                        compress2[{p, i}] = num_nodes++;
                }
        }
        num_nodes++; // sink
        Dinic graph(num_nodes, 0, num_nodes - 1);
        for (int i = 0; i < n; i += 2) { // add for even indices
                for (auto [p, cnt] : f[i]) {
                        graph.add_edge(0, compress1[{p, i}], cnt);
                }
        }
        for (int i = 1; i < n; i += 2) { // for odd indices
                for (auto [p, cnt] : f[i]) {
                        graph.add_edge(compress1[{p, i}], num_nodes - 1, cnt);
                }
        }
        for (int j = 0; j < m; j++) {
                int u = b[j][0], v = b[j][1];
                for (auto [prime, _] : g[j]) { // any prime in gcd(a[u], a[v]) must be a prime of a[u] and a[v]
                        graph.add_edge(compress1[{prime, u}], compress2[{prime, j}], 1e18);
                        graph.add_edge(compress2[{prime, j}], compress1[{prime, v}], 1e18);
                }
        }

        cout << graph.flow() << '\n';

}



