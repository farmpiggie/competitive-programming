// taken from https://github.com/VeryAmazed/My_Comp-Programming_Template/blob/main/Templates/graph.cpp, thanks Alan!
// slight modifications from me

// Djikstra's (from CPH)
vector<vector<pll>> vec; // adjacency list, pairs are {node, weight}
vector<ll> dist; // distance to all nodes, needs to be initialized to LLONG_MAX
vector<bool> visited; // keeps track if a node is visited, initialized to zero

void djik(int start){
	dist[start] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq; // elements inserted via {weight, node}
	pq.push(mp(0, start));
	while (!pq.empty()) {
		int a = pq.top().second; 
		pq.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto e : vec[a]) {
			int b = e.first, w = e.second;
			if (dist[a]+w < dist[b]) {
				dist[b] = dist[a]+w;
				pq.push(mp(distsb],b));
			}
		}
	}
}


// Bellman-Ford (from CPH)
/*
on each of the iterations from i to n-1, dists will contain the shortest path 
from the starting node to any node that goes through i edges or less
*/
// To check for a negative cycle, go through the edges an n-th time and if any distance gets reduced, there is a negative cycle
vector<vector<pll>> vec; // the graph
vector<ll> dists; // intialized to INF

dists[x] = 0;
for (int i = 1; i <= n-1; i++) {
	for(int a = 1; a <= n; a++){
		for(auto e : vec[a]){
			b = e.f;
			w = e.s;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}
}

// from cp-algos
// Find a cycle in a directed graph
// if DFS visits a gray node, we have a backedge (and thus a cycle)
// grab nodes in the cycle using the parent[] array
int n;
vector<vector<int>> adj; // adjacency list
vector<char> color; // color: 0 is white (unvisited), 1 is gray (visited), 2 is black (DFS exited)
vector<int> parent; // parent of each node in the DFS
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

// from cp-algos
// find cycle in an undirected graph
int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

// from cp-algos
// EULER PATH
// "A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle."
// "The problem is to find the Eulerian path in an undirected multigraph with loops."
/*
An Eulerian cycle exists if and only if the degrees of all vertices are even. 
And an Eulerian path exists if and only if the number of vertices with odd degrees is two (or zero, in the case of the existence of a Eulerian cycle). 
In addition, of course, the graph must be sufficiently connected (i.e., if you remove all isolated vertices from it, you should get a connected graph).

// TODO: this is inefficient (with adjacency list). can we rewrite this using adjacency list to improve time complexity?
*/

int n;
vector<vector<int>> g(n, vector<int>(n));
// reading the graph in the adjacency matrix

vector<int> deg(n);
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
        deg[i] += g[i][j];
}

int first = 0;
while (first < n && !deg[first])
    ++first;
if (first == n) {
    cout << -1;
    return 0;
}

int v1 = -1, v2 = -1;
bool bad = false;
for (int i = 0; i < n; ++i) {
    if (deg[i] & 1) {
        if (v1 == -1)
            v1 = i;
        else if (v2 == -1)
            v2 = i;
        else
            bad = true;
    }
}

if (v1 != -1)
    ++g[v1][v2], ++g[v2][v1];

stack<int> st;
st.push(first);
vector<int> res;
while (!st.empty()) {
    int v = st.top();
    int i;
    for (i = 0; i < n; ++i)
        if (g[v][i])
            break;
    if (i == n) {
        res.push_back(v);
        st.pop();
    } else {
        --g[v][i];
        --g[i][v];
        st.push(i);
    }
}

if (v1 != -1) {
    for (size_t i = 0; i + 1 < res.size(); ++i) {
        if ((res[i] == v1 && res[i + 1] == v2) ||
            (res[i] == v2 && res[i + 1] == v1)) {
            vector<int> res2;
            for (size_t j = i + 1; j < res.size(); ++j)
                res2.push_back(res[j]);
            for (size_t j = 1; j <= i; ++j)
                res2.push_back(res[j]);
            res = res2;
            break;
        }
    }
}

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        if (g[i][j])
            bad = true;
    }
}

if (bad) {
    cout << -1;
} else {
    for (int x : res)
        cout << x << " ";
}

// Lowest Common Ancestor
// Given a Tree G, and queries in the form (v1, v2), find the lowest common ancestor of v1 and v2 on the tree.
// taken from mr. eric k zhang, solve from my usaco 2019 competition (milk visits)
// binary lifting method
#define MAXN 100001
#define MAXLG 17 // log(MAXN)

int N, M;
vector<int> adj[MAXN]; // adjacency list
int L[MAXLG][MAXN]; // sparse table, initalized to zeros
int depth[MAXN]; // depth of each node, initalized to zeros

void dfs(int n, int p) {
    depth[n] = depth[p] + 1;
    L[0][n] = p;
    for (int i = 0; i < MAXLG - 1; i++)
        L[i + 1][n] = L[i][L[i][n]];
    for (int v : adj[n]) if (v != p) {
        dfs(v, n);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = MAXLG - 1; i >= 0; i--)
        if (depth[v] - (1 << i) >= depth[u])
            v = L[i][v];
    for (int i = MAXLG - 1; i >= 0; i--)
        if (L[i][u] != L[i][v])
            u = L[i][u], v = L[i][v];
    return u == v ? u : L[0][u];
}

// find bridges in undirected graph in O(n + m)
// bridge = edge such that if edge is removed, # of connected components increases
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

// finding articulation points in O(n + m)
// given an undirected graph, find all verticies, which when removed, increases the # of connected components in a graph
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}



