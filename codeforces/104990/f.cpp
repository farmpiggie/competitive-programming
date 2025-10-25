#include <bits/stdc++.h>
 
using namespace std;
 
 
const int MAXN = 2e5 + 5, MAXK = 20;
const int INF = 1e9 + 7;
typedef pair<int, int> pii;
vector<int> adj[MAXN];
int d[MAXN];
int jp[MAXK][MAXN];
 
void dfs (int u, int p, int cd = 0)
{
    d[u] = cd;
    jp[0][u] = p;
    
    for (auto x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u, cd + 1);
        }
    }
}
 
 
int lca (int x, int y)
{
    if (x == y)
    {
        return x;
    }
    if (d[x] < d[y])
    {
        swap(x,y);
    }
    
    int z = d[x] - d[y];
    for (int i = 0; i < MAXK; i++)
    {
        if (z & (1 << i))
        {
            x = jp[i][x];
        }
    }
    
    if (x == y)
    {
        return x;
    }
    
    for (int i = MAXK - 1; i >= 0; i--)
    {
        if (jp[i][x] == jp[i][y])
        {
            continue;
        }
        x = jp[i][x], y = jp[i][y];
    }
    return jp[0][x];
}

int gd (int x, int y)
{
    return d[x] + d[y] - 2 * d[lca(x,y)];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;;
    
    for (int i = 0; i < n-1; i++)
    {
        int l, r;
        cin >> l >> r;
        l--,r--;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    
    
    for (int i = 0; i < MAXK; i++)
    {
        for (int j = 0; j < n; j++)
        {
            jp[i][j] = -1;
        }
    }
    
    dfs(0, -1);
    
    
    for (int i = 1; i < MAXK; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (jp[i-1][j] == -1)
            {
                continue;
            }
            jp[i][j] = jp[i-1][jp[i-1][j]];
        }
    }
    
    
    int q;
    cin >> q;
    while (q--)
    {
        vector<int> a(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i; j < 3; j++)
            {
                ans = max(ans, (gd(a[i], a[j]) + 1)/2);
            }
        }
        cout << ans << "\n";
    }
    
 return 0;
}
 
