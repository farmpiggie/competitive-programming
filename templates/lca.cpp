int N, M;
vector<int> adj[MAXN];
int L[MAXLG][MAXN];
int depth[MAXN];
int milk_path[MAXN][100];
int milk[MAXN];

void dfs(int n, int p) {
    depth[n] = depth[p] + 1;
    milk_path[n][milk[n]]++;
    for (int i = 0; i < 11; i++) {
        milk_path[n][i] += milk_path[p][i];
    }
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
