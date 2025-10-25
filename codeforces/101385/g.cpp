#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

vector<int> topo;
vector<int> adj[2 * MAXN];
bool vis[2 * MAXN];
int in[2 * MAXN];
int d[2 * MAXN];
void dfs (int u)
{

    vis[u] = 1;
    for (auto x : adj[u])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
    topo.push_back(u);
}

int main()
{
    ifstream cin("powersum.in");
    ofstream cout("powersum.out");
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '1')
            {
                adj[n + j].push_back(i);
                in[i]++;
            } else if (a[i][j] == '0')
            {
                adj[i].push_back(n + j);
                in[n + j]++;
            }
        }
    }

    for (int i = 0; i < 2 * n; i++)
    {
        if (in[i] == 0)
        {
            dfs(i);
        }
    }
    //check for a cycle

    if (topo.size() != 2 * n)
    {
        cout << "NO" << "\n";
        return 0;
    }
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++)
    {
        d[topo[i]] = i;
    }

    for (int i = 0; i < 2 * n; i++)
    {
        for (auto x : adj[i])
        {
            if (d[x] < d[i])
            {
                //found a cycle
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    cout << "YES" << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << d[i] + 1 << " " << -(d[n + i] + 1) << "\n";
    }
    cout << "0" << "\n";
}