#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL T, n, k;
const LL MAXN = 200005;
LL depth[MAXN];
LL marked[MAXN];
LL true_value[MAXN];
LL parent[MAXN];
LL children[MAXN];
vector<LL> adj[MAXN];

LL dfs(LL par = 0, LL node = 1) {
    depth[node] = depth[par] + 1;
    parent[node] = par;
    for (LL child : adj[node]) {
        if (child != par) {
            children[node] += dfs(node, child);
        }
    }
    children[node]++;
    return children[node];
}

bool cmp(LL a, LL b) {
    if (depth[a] - children[a] > depth[b] - children[b]) {
        return true;
    } else if (depth[a] - children[a] < depth[b] - children[b]) {
        return false;
    } else {
        return a < b;
    }
}

LL value(LL a) {
    if (a == 1) return 0;
    else if (true_value[a] != 0) return true_value[a];
    else {
        true_value[a] = (marked[parent[a]] + 1) % 2 + value(parent[a]);
        return true_value[a];
    }
}

int main() {
    cin >> n >> k;
    for (LL i = 0; i < n - 1; i++) {
        LL a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    
    vector<LL> v;
    for (LL i = 1; i <= n; i++) {
        v.push_back(i);
        depth[i]--;
        children[i]--;
    }
    sort(v.begin(), v.end(), cmp);
    for (LL i = 0; i < k; i++) {
        marked[v[i]] = 1;
        // cout << v[i] << endl;
    }
    LL sum = 0;
    for (LL i = 0; i < k; i++) {
        // cout << value(v[i]) << endl;
        sum += value(v[i]);
    }
    cout << sum << endl;
    return 0;
}