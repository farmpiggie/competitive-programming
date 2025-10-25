#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1 << 18;

const ll INF = (1 << 30) - 1;
const int MOD = 1e9 + 7;
//add on range, range sum
struct Seg
{
    int n;
    vector<ll> t;
    vector<ll> d;
    
    Seg (int _n)
    {
        n = _n;
        t = vector<ll> (2 * n);
        d = vector<ll> (n);
    }
    
    
    void build ()
    {
        for (int i = n-1; i > 0; i--)
        {
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }
    
    void apply (int p, ll v, int sz)
    {
        if (p < n)
        {
            d[p] = (d[p] + v);
        }
        t[p] = (t[p] + v * sz);
    }
    
    void pull (int p, int sz)
    {
        t[p] = (t[2 * p] + t[2 * p + 1]) + d[p] * sz;
    }
    
    
    void upd (int l, int r, ll v, int cl = 0, int cr = MAXN - 1, int p = 1)
    {
        
        //~ cout << cl << " " << cr << " " << p << " " << t[p] << " " << (p < n ? d[p] : 0) << "\n";
        if (cr < l || cl > r)
        {
            return;
        }
        
        //~ prop(p);
        
        if (l <= cl && cr <= r)
        {
            apply(p, v, cr - cl + 1);
            return;
        }
        int cm = (cl + cr)/2;
        
        upd(l, r, v, cl, cm, p * 2);
        upd(l, r, v, cm + 1, cr, p * 2 + 1);
        
        pull(p, cr - cl + 1);
    }
    
    
    ll query(int l, int r, int cl = 0, int cr = MAXN - 1, int p = 1)
    {
        //~ cout << cl << " " << cr << " " << p << " " << t[p] << " " << (p < n ? d[p] : 0) << "\n";
        if (cr < l || cl > r)
        {
            return 0;
        }
        
        if (l <= cl && cr <= r)
        {
            //~ prop(p);
            return t[p];
        }
        
        int cm = (cl + cr)/2;
        
        //~ pull(p);
        return (query(l, r, cl, cm, p * 2) + query(l, r, cm + 1, cr, p * 2 + 1)) + d[p] * (min(r, cr) - max(l, cl) + 1);
    }
};



int main()
{
    int n, q;
    cin >> n >> q;
    Seg t(MAXN);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<int> st;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i-1])
        {
            st.insert(i);
        }
    }

    st.insert(n);
    st.insert(0);

    for (int i = 0; i < n; i++)
    {
        t.upd(i, i, *st.upper_bound(i) - i);
    }


    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int l, r;
            cin >> l >> r;
            l--,r--;
            if (l > 0 && !st.count(l))
            {
                t.upd(*prev(st.lower_bound(l)), l - 1, -(*st.lower_bound(l) - l));
                st.insert(l);
            } else if (l > 0 && st.count(l))
            {
                t.upd(*prev(st.lower_bound(l)), l - 1, *st.upper_bound(l) - l);
                st.erase(l);
            }

            if (r + 1 < n && !st.count(r + 1))
            {
                t.upd(*prev(st.lower_bound(r + 1)), r, -(*st.lower_bound(r + 1) - (r+1)));
                st.insert(r + 1);
            } else if (r + 1 < n && st.count(r + 1))
            {
                t.upd(*prev(st.lower_bound(r + 1)), r, *st.upper_bound(r + 1) - (r+1));
                st.erase(r + 1);
            }


        } else
        {
            int l, r;
            cin >> l >> r;
            l--,r--;
            //have to count until the first set element less than r
            if (*prev(st.upper_bound(r)) <= l)
            {
                cout << 1ll * (r - l + 1) + 1ll * (r - l + 1) * (r - l)/2 << "\n";
            } else
            {
                auto it = prev(st.upper_bound(r));
                ll cnt = r - *it + 1;
                cout << t.query(l, *it - 1) + cnt + (cnt * (cnt - 1))/2 << "\n";
            }
        }
    }

    
 return 0;
}
