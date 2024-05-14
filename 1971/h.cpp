// can alice make it so that # of -1s in each grid <= 1
// 2-sat problem?
// for each column [a, b, c]
// if any element is false, the other two must be true

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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		N = 2 * n;
		adj.assign(N, {});
		adj_t.assign(N, {});
		vector<vector<int>> a(3, vector<int>(n, 0));
		for (auto& x : a) for (auto& y : x) cin >> y;

		for (int i = 0; i < n; i++) {
			add_implies(abs(a[0][i]) - 1, a[0][i] > 0, abs(a[1][i]) - 1, a[1][i] < 0);
			add_implies(abs(a[0][i]) - 1, a[0][i] > 0, abs(a[2][i]) - 1, a[2][i] < 0);
			add_implies(abs(a[1][i]) - 1, a[1][i] > 0, abs(a[0][i]) - 1, a[0][i] < 0);
			add_implies(abs(a[1][i]) - 1, a[1][i] > 0, abs(a[2][i]) - 1, a[2][i] < 0);
			add_implies(abs(a[2][i]) - 1, a[2][i] > 0, abs(a[0][i]) - 1, a[0][i] < 0);
			add_implies(abs(a[2][i]) - 1, a[2][i] > 0, abs(a[1][i]) - 1, a[1][i] < 0);
		}

		if (solve_2SAT()) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;
}
