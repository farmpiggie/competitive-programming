#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
typedef pair<int,int> pii;
vector<int> adj[MAXN];
vector<int> g[MAXN];
vector<pii> br; //store all the bridges
bool vis[MAXN];
int d[MAXN], dp[MAXN];

struct DSU
{
    int n;
    vector<int> e;
    DSU () {}
    DSU (int _n)
    {
        n = _n;
        e = vector<int>(n, -1);
    }

    int get (int x)
    {
        return e[x] < 0 ? x : get(e[x]);
    }

    bool unite (int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);

        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int n, m;

DSU dsu;
void pre (int u, int p, int cd = 0)
{
	d[u] = cd;
	vis[u] = 1;
	for (auto x : adj[u])
	{
		if (!vis[x]) //must be further down in the tree
		{
			pre(x,u,cd + 1);
		}
	}
}
 
void dfs (int u, int p) //do you need p?
{
	vis[u] = 1;
	for (auto x : adj[u])
	{
		if (!vis[x])
		{
			dfs(x,u);
			//this is a direct child
			dp[u] += dp[x];
		} else if (x != p)
		{
			//this is a back edge, we need to do some computations
			dp[u] += (d[x] < d[u] ? 1 : -1);
		}
	}
	
	if (dp[u] == 0 && p != -1)
	{
		br.push_back({u, p});
	} else if (p != -1)
    {
        dsu.unite(u, p);
    }
}

int mx;

void gt (int u, int p, int cd = 0)
{
    vis[u] = 1;
    d[u] = cd;
    for (auto x : g[u])
    {
        if (x != p)
        {
            gt(x,u, cd + 1);
        }
    }

    if (d[u] > d[mx])
    {
        mx = u;
    }
}

int dim (int u, int p)
{
    int res = 0;
    for (auto x : g[u])
    {
        if (x != p)
        {
            res = max(res, dim(x, u) + 1);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dsu = DSU(n);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            pre(i,-1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1);
        }
    }

    for (auto [x,y] : br)
    {
        g[dsu.get(x)].push_back(dsu.get(y));
        g[dsu.get(y)].push_back(dsu.get(x));
        // cout << x << " " << y << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        d[i] = 0;
    }

    // cout << "got here" << "\n";
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << i << " " << vis[i] << " " << dsu.get(i) << "\n";
        if (!vis[i] && dsu.get(i) == i)
        {
            // cout << i << "\n";
            ans++;
            mx = i;
            gt(i, -1);
            ans += dim(mx,-1);
        }
    }

    cout << ans - 1 << "\n";
}