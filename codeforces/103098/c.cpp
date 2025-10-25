#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> edge; // <<weight, graph>, <from, to>>

int group(int val, vector<int>& par);

void join(int a, int b, vector<int>& par, vector<int>& siz);

int main() {

    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    vector<edge> edges;
    for(int i = 0; i<m1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a;
        b;
        edges.emplace_back(make_pair(d, 1), make_pair(a, b));
    }

    for(int i = 0; i<m2; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a;
        b;
        edges.emplace_back(make_pair(d, 2), make_pair(a, b));
    }

    vector<int> par1(n1);
    vector<int> par2(n2);
    vector<int> siz1(n1, 1);
    vector<int> siz2(n2, 1);

    for(int i = 0; i<n1; i++) {
        par1[i] = i;
    }

    for(int i = 0; i<n2; i++) {
        par2[i] = i;
    }

    sort(edges.begin(), edges.end());

    int cnt1 = 0;
    int cnt2 = 0;
    ll ans = 0;
    for( edge& e : edges ) {
        ll w = e.first.first;
        ll g = e.first.second;
        ll x = e.second.first;
        ll y = e.second.second;

        if( g == 1 ) {
            if( group(x, par1) == group(y, par1) ) {
                continue;
            }
            ans += (n2-cnt2)*w;
            join(x, y, par1, siz1);
            cnt1++;
        } 
        else {
            if( group(x, par2) == group(y, par2) ) {
                continue;
            }
            ans += (n1-cnt1)*w;
            join(x, y, par2, siz2);
            cnt2++;
        }
    }

    cout << ans << endl;

}

int group(int val, vector<int>& par) {
    if(par[val] == val) return val;
    par[val] = group(par[val], par);
    return par[val];
}

void join(int a, int b, vector<int>& par, vector<int>& siz) {
    int pa = group(a, par);
    int pb = group(b, par);
    if(siz[pa] > siz[pb]) {
        siz[pa] += siz[pb];
        par[pb] = pa;
    }
    else {
        siz[pb] += siz[pa];
        par[pa] = pb;
    }
}
