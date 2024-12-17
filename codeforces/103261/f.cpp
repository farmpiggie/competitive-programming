#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
typedef pair<ll,ll> pii;
pair<int,int> a[MAXN];
vector<int> adj[MAXN];
set<pair<int,int>> e;

struct Angle
{
    int x, y;
    Angle (int x, int y) : x(x), y(y) {}
    int half() const {
        assert(x || y);
        return y < 0 || (y == 0 && x < 0);
    }
};

bool operator< (Angle a, Angle b)
{
    return pii(a.half(), 1ll * a.y * b.x) < pii(b.half(), 1ll * a.x * b.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--,r--;
        e.insert({l,r});
        e.insert({r,l});
        adj[l].push_back(r);
        adj[r].push_back(l);
    }


    for (int i = 0; i < n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), [&](int x, int y)
        {
            return Angle(a[x].first - a[i].first, a[x].second - a[i].second) < Angle(a[y].first - a[i].first, a[y].second - a[i].second);
        });
        // cout << "adj " << i << " " << adj[i].size() << "\n";
        // for (int j = 0; j < adj[i].size(); j++)
        // {
        //     cout << adj[i][j] << " ";
        // }
        // cout << "\n";

        for (int j = 0; j < adj[i].size(); j++)
        {
            
            // cout << i << " " << adj[i][j] << " " << adj[i][(j + 1) % adj[i].size()] << "\n";
            if (!e.count({adj[i][j], adj[i][(j + 1) % adj[i].size()]}))
            {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";



}
