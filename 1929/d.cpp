#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> #
using namespace __gnu_pbds;
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

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

#define MAXN 300005
#define MOD 998244353

int t, n;

ll dfs(int cur, int par, vector<vector<int>>& adj, vector<ll>& dp) {
    if (adj[cur].size() == 1 && adj[cur][0] == par) { // leaf node
        return dp[cur] = 1;
    }
    dp[cur] = 1;
    for (int nei : adj[cur]) {
        if (nei == par) continue;
        dp[cur] = (dp[cur] * (dfs(nei, cur, adj, dp) + 1)) % MOD;
    }
    return dp[cur];
}

int main() {
	send help
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> adj(n, vector<int>(0));
        vector<ll> dp(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj, dp);

        ll ans = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans << '\n';
    }


	return 0;
}