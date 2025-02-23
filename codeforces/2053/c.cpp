#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n, k; cin >> n >> k;

                ll val = n + 1;
                ll sum = 0;
                ll cur = 1;
                while (n >= k) {
                        if (n & 1) sum += cur;
                        n >>= 1;
                        cur <<= 1;
                }
                cout << val * sum / 2 << '\n';
        }
}
                
