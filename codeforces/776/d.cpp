#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
int n, m;


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
    used.assign(2 * m, false);
    for (int i = 0; i < 2 * m; ++i) {
        if (!used[i])
            dfs1(i);
    }
    
    comp.assign(2 * m, -1);
    for (int i = 0, j = 0; i < 2 * m; ++i) {
        int v = order[2 * m - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    
    assignment.assign(m, false);
    for (int i = 0; i < 2 * m; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void run() {
  cin >> n >> m;
  vector<vector<int>> rooms(n, vector<int>(0));
  vector<int> state(n,0);
  for (int &x : state) {
    cin >> x;
  }
  
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    for (int j = 0; j < x; j++) {
      int y; cin >> y; y--;
      rooms[y].push_back(i);
    }
  }
  
  adj.resize(2 * m);
  adj_t.resize(2 * m);
  for (int i = 0; i < n; i++) {
    // door open, a and b must equal
    int a = rooms[i][0], b = rooms[i][1];
    if (state[i]) {
      adj[a * 2].push_back(b * 2);
      adj[b * 2].push_back(a * 2);
      adj[a * 2 + 1].push_back(b * 2 + 1); 
      adj[b * 2 + 1].push_back(a * 2 + 1);
      
      adj_t[b * 2].push_back(a * 2);
      adj_t[a * 2].push_back(b * 2);
      adj_t[b * 2 + 1].push_back(a * 2 + 1);
      adj_t[a * 2 + 1].push_back(b * 2 + 1);
    } else {
      adj[a * 2 + 1].push_back(b * 2);
      adj[b * 2 + 1].push_back(a * 2);
      adj[a * 2].push_back(b * 2 + 1);
      adj[b * 2].push_back(a * 2 + 1);
      
      adj_t[b * 2].push_back(a * 2 + 1);
      adj_t[a * 2].push_back(b * 2 + 1);
      adj_t[b * 2 + 1].push_back(a * 2);
      adj_t[a * 2 + 1].push_back(b * 2);
    }
  }
    
  if (solve_2SAT()) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  run();
}
