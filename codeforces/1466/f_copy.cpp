/*
 * we can represent each number as an edge between two bits (x, y)
 * consider S' as the set of edges required.
 * obv 1: if there is a cycle in the graph, we can remove one edge from S' and be fine.
 * 
 * we want to remove most # of edges such that the graph is "still connected"
 * therefore we use kruskal's to create MST, edges weighted by indice
 *
 * for each forest, we then compute the # of possibilities for each, which is 2 ^ (num_edges)
 * if we have multiple self loops in a forest, choose the one with lowest index. this will allow us to make all others
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// sparse DSU
struct dsu {
    unordered_map<int, int, custom_hash> par, sz;

    void init(int x) {
        if (par.find(x) == par.end()) {
            par[x] = x;
            sz[x] = 1;
        }
    }

    int find(int x) {
        init(x);
        if (x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        init(x); init(y);
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};


ll binpow(ll a, ll b) {
    if (b == 0) return 1;
	ll res = binpow(a, b / 2);
	res = res * res % MOD;
	if (b % 2 == 1) res = res * a % MOD;
	return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges;
    unordered_set<int, custom_hash> nodes;
    unordered_set<int, custom_hash> unique;
    unordered_map<int, int> ind_to_unique;
    unordered_map<int, int, custom_hash> unique_to_ind;
    vector<int> ans;
    ll s_p = 0, t = 1;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k == 1) {
            int x; cin >> x;
            nodes.insert(x);
            unique.insert(x);
            unique_to_ind[x] = i + 1;
            ind_to_unique[i + 1] = x;
        } else {
            int x, y; cin >> x >> y;
            nodes.insert(x);
            nodes.insert(y);
            edges.push_back({i + 1, x, y});
        }
    }
    dsu uf;
    vector<vector<array<int, 2>>> adj(m + 1); // {node, weight in index}
    for (auto [ind, x, y] : edges) {
        if (unique.count(x) && unique.count(y)) continue; // no need to add said node.
        x = uf.find(x), y = uf.find(y);
        if (x == y) continue;
        uf.merge(x, y);
        adj[x].push_back({y, ind});
        adj[y].push_back({x, ind});
        s_p++;
    }

    unordered_map<int, int, custom_hash> ccs_to_unique_id;
    unordered_set<int> ccs;
    for (int node : unique) {
        int par = uf.find(node);
        ccs.insert(par);
        if (ccs_to_unique_id.find(par) == ccs_to_unique_id.end()) {
            ccs_to_unique_id[par] = unique_to_ind[node];
        } else {
            ccs_to_unique_id[par] = min(ccs_to_unique_id[par], unique_to_ind[node]);
        }
    }

    // get all CCs
    for (int node : nodes) {
        ccs.insert(uf.find(node));
    }

    


    auto dfs = [&](this auto dfs, int v, int p = -1, int edge = -1) -> void { // weight, index
 //       cout << "dfs: " << v << '\n';
        if (unique.count(v) && p != -1 && unique_to_ind[v] < edge) { // node is self loop, not root of tree, and index of self loop is less than edge to parent
            ans.push_back(unique_to_ind[v]);
        } else if (p != -1) {
            // push this edge
            ans.push_back(edge);
        } else if (unique.count(v)) { // we started here
            ans.push_back(unique_to_ind[v]);
        }
        // after pushing back edge, call dfs on others
        for (auto [nei, w] : adj[v]) if (nei != p) dfs(nei, v, w);
    };
    
    // dfs from each smallest node?
    for (int cc : ccs) {
        if (ccs_to_unique_id.find(cc) != ccs_to_unique_id.end()) {
//            cout << "new cc\n";
            dfs(ind_to_unique[ccs_to_unique_id[cc]]);
        } else {
            dfs(cc);
        }
    }

    sort(ans.begin(), ans.end());

    unordered_set<int, custom_hash> ccs1;
    for (int node : nodes) {
        node = uf.find(node);
        if (ccs1.count(node)) continue;
        ccs1.insert(node);
        t = (t * binpow(2, uf.sz[node] - 1)) % MOD; // if CC is size 1, this multiples by 1.
            
        if (ccs_to_unique_id.find(node) != ccs_to_unique_id.end()) {
            t = (t * 2) % MOD;
            s_p++;
        }
    }

    cout << t << " " << s_p << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
    return 0;
}
