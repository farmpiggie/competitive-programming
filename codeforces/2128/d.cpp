#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);

        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> p(n);
                for (int &x : p) cin >> x;

                ll tot = 0;

                ll prev = 0;
                for (int i = 1; i <= n; i++) {
                        ll cur = prev + 1;
                        if (i > 1 && p[i - 2] > p[i - 1]) {
                                cur += i - 1;
                        }
                        tot += cur;
                        prev = cur;
                }

                cout << tot << '\n';
        }
}

