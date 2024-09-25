#include <bits/stdc++.h>
using namespace std;

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

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    // cout << b << '\n';
    a = 2*a ^ na;
    b = 2*b ^ nb;
    // cout << "b after: " << b << '\n';

    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    // if (a >= N || b >= N || neg_a >= N || neg_b >= N) cout << "BEEPBOOP\n";
    // cout << "neg_a" << neg_a << '\n';
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

void add_implies(int a, bool na, int b, bool nb) {
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;

    adj[a].push_back(b);
    adj[neg_b].push_back(neg_a);
    adj_t[b].push_back(a);
    adj_t[neg_a].push_back(neg_b);
}


int n, p, M, m;


void run() {
    cin >> n >> p >> M >> m;
    N = 2 * (p + (M + 1)); // number of nodes
    adj.assign(N, {});
    adj_t.assign(N, {});

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        // cout << "we must have either station " << x << " or " << y << '\n';
        x--; y--;
        // cannot have x is false and y is false
        add_disjunction(x, false, y, false); // x or y
    }

    for (int i = 0; i < p; i++) {
        int l, r; cin >> l >> r;
        // x_i -> f >= l_i
        // x_i -> ~(f >= r_i + 1)
        // cout << "station " << i + 1 << " must be between power " << l << " and " << r << '\n';

        l--; r--;

        // if (i == 0) cout << p << " " << l << " " << p + l << '\n';
        // cannot have i = true, p + l false 
        // cannot have i = true, p + r + 1 true
        add_disjunction(i, true, p + l, false);
        add_disjunction(i, true, p + r + 1, true);
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        // cannot have both u and v
        add_disjunction(u, true, v, true);
    }

    for (int i = 0; i < M; i++) {
        // cannot have f < i, f >= i + 1
        add_disjunction(p + i, false, p + i + 1, true);
    }

    for (int i = 0; i < 2 * (p + M + 1); i++) {
        for (int j : adj[i]) {
            // cout << "edge between: " << i << ", " << j << '\n';
        }
    }

    int possible = solve_2SAT();

    if (!possible) {
        cout << "-1\n";
    } else {
        vector<int> arr;

        for (int i = 0; i < p; i++) {
            if (assignment[i]) {
                arr.push_back(i + 1);
            }
        }
        // greatest pwr level i s.t. f >= i is true.
        int pwr = 1;
        for (int i = p; i < (p + M + 1); i++) {
            if (assignment[i]) {
                pwr = i - p + 1;
            } else {
                break;
            }
        }
        cout << (int) arr.size() << " " << pwr << '\n';
        for (int num : arr) 
            cout << num << " ";
        cout << '\n';
    }


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}