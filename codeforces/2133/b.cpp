#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                sort(a.rbegin(), a.rend());
                
                ll ans = 0;
                for (int i = 0; i < n; i += 2) {
                        ans += a[i];
                }
                cout << ans << '\n';
        }
        
}