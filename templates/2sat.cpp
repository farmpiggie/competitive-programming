/* Taken from cp-algos page on 2SAT
 * Usage notes:
 * N is the number of total nodes in the graph (should be 2 * (number of variables)), as we need to account for each variable and its negation
 * the ith node is at pos (2 * i), its negation is at pos (2 * i + 1)
 * Note when using disjunction: booleans are set IF WE WANT A NEGATION (might change this later tbh)
 */

int N;
vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(N, -1);
    for (int i = 0, j = 0; i < N; ++i) {
        int v = order[N - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(N / 2, false);
    for (int i = 0; i < N; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

// na and nb signify whether a and b are to be negated 
void add_disjunction(int a, bool na, int b, bool nb) {
    a = 2*a ^ na;
    b = 2*b ^ nb;

    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

// if we want to enter in disjunctions with (2 * a + 1) form instead
void add_disjunction(int a, int b) {
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}
