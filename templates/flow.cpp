/* Template implementations for flows & related problems */

// Edmonds-Karp
// O(VE^2)

int n;
vector<vector<int>> cap; // cap[i][j] = capacity of edge from i to j.
vector<vector<int>> adj; 

int bfs(int s, int t, vector<int>& par) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<pair<int, int>> q; 
        q.push({s, INF});

        while (!q.empty()) {
                int u = q.front().first;
                int f = q.front().second;
                q.pop();

                for (int v : adj[u]) {
                        if (par[v] == -1 && cap[u][v]) {
                                par[v] = u;
                                int nf = min(f, cap[u][v]); 
                                if (v == t) return nf;
                                q.push({v, nf});
                        }
                }
        }
        return 0;
}

int maxflow(int s, int t) {
        int f = 0;
        vector<int> par(n);
        int nf;
        while (nf = bfs(s, t, par)) {
                f += nf;
                int cur = t;
                while (cur != s) {
                        int prev = parent[cur];
                        capacity[prev][cur] -= nf;
                        capacity[cur][prev] += nf;
                        cur = prev;
                }
        }
        return flow;
}

// Dinic
// O(V^2E)

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
                        for (uint id : adj[v]) {
                                if (edges[id].cap == edges[id].flow) continue;
                                if (level[edges[id].u] != -1) continue;
                                level[edges[id].u] = leve[v] + 1;
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


